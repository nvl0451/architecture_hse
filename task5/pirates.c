#include <pthread.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

/* generic variables */

struct order {
    int x;
    int y;
};

pthread_mutex_t ordersMutex;
pthread_cond_t ordersCV;

/* game variables */

//island
char islandMap[105][105];
int n = 7;

//orders
struct order orders[10020];
int currentOrder = 0;

//gold
int potenialMoney = 0;
int totalMoney = 0;

//pirates
int piratesInit = 5;
int piratesRemain;
bool pirateAlive[105];
bool pirateArmored[105];
int pirateMoney[105];

/* generic functions */

int randomNumber(int min_num, int max_num) {
    	int result = 0, low_num = 0, hi_num = 0;

    	if (min_num < max_num)
    	{
    		low_num = min_num;
    		hi_num = max_num + 1;	// include max_num in output
    	}
    	else
    	{
    		low_num = max_num + 1;	// include max_num in output
    		hi_num = min_num;
    	}

    	
    	result = (rand() % (hi_num - low_num)) + low_num;
    	return result;
    }
	
char getRandomCell() {
	int num = randomNumber(1, 100);
	if (num <= 50)
		return 'E';
	if (num <= 75)
		return 'M';
	if (num <= 90)
		return 'A';
	return 'T';
}

void reactToCell(char cell, int pirateID) {
	int foundMoney;
	switch (cell) {
		case 'A':
			pirateArmored[pirateID] = true;
			printf("pirate %d found spanish conquistador armor!\n", pirateID);
			break;
		case 'M':
			foundMoney = randomNumber(100, 200);
			pirateMoney[pirateID] += foundMoney;
			potenialMoney += foundMoney;
			printf("pirate %d found %d gold coins!\n", pirateID, foundMoney);
			break;
		case 'T':
			if (pirateArmored[pirateID]) {
				pirateArmored[pirateID] = false;
				printf("ancient mayan traps destroyed pirate %d armor!\n", pirateID);
			} else {
				printf("DEAD: pirate %d killed by ancient mayan traps!\n", pirateID);
				pirateArmored[pirateID] = false;
				pirateAlive[pirateID] = false;
				piratesRemain--;
				if (piratesRemain == 0) {
					pthread_cond_signal(&ordersCV);
				}
				pthread_exit(NULL);
			}
			break;
	}
}

void shuffle(struct order orders[], int n) {
    int i;
    for(i = n-1; i > 0; i--) {
        int j = rand() % (i+1);
		struct order tempOrder = orders[i];
		orders[i] = orders[j];
		orders[j] = tempOrder;
        //swap(&orders[i], &orders[j]);
    }
}

void printIsland() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%c", islandMap[i][j]);
		printf("\n");
	}
	printf("E - empty spot \nM - ancient treasure\nT - deadly trap\nA - conquistador armor\n");
}

/* pirate routine */

void *pirateActivity(void *threadID)
{
	long pirateID;
	struct order searching;
	pirateID = (long) threadID;
	printf("Yo ho ho! It's me, pirate %ld!\n", pirateID);
	while (currentOrder < n * n) {
		//get order
		pthread_mutex_lock (&ordersMutex);
		if (currentOrder >= n * n) {
			printf("no orders remain. pirate %ld returning\n", pirateID);
			pthread_mutex_unlock (&ordersMutex);
			pthread_cond_signal(&ordersCV);
			pthread_exit(NULL);
		}
		searching = orders[currentOrder];
		//printf("pirate %ld searching x:%d, y:%d\n", pirateID, searching.x, searching.y);
		currentOrder++;	
		pthread_mutex_unlock (&ordersMutex);
		
		//inspect the spot
		char spot = islandMap[searching.x][searching.y];
		//printf("pirate %ld inspecting char %c\n", pirateID, spot);
		reactToCell(spot, (int)pirateID);
		sleep(0.1);
	}
	printf("no orders found. pirate %ld returning\n", pirateID);
	pthread_cond_signal(&ordersCV);
	pthread_exit(NULL);
}

/* main - input, game Launch, output */ 

int main(int argc, char *argv[]) {
	printf("John S: Yarr! Welcome to the Pirate Island Lottery!\n");
	
	//generic init
	srand(time(NULL));
	pthread_mutex_init(&ordersMutex, NULL);
	pthread_cond_init(&ordersCV, NULL);
	
	//input
	if (argc == 3) {
		int iSide = atoi(argv[1]);
		int pAm = atoi(argv[2]);
		if (iSide > 0 && pAm > 0) {
			n = iSide;
			piratesInit = pAm;
			printf("John S: Closing in on an island with side of %d with a crew of %d pirates\n",
			n, piratesInit);
		} else {
			printf("John S: Invalid input! Closing in on an island with side of %d with a crew of %d pirates\n",
			n, piratesInit);
		}
	} else {
		printf("John S: Closing in on an island with side of %d with a crew of %d pirates\n",
			n, piratesInit);
	}
	
	//init island and orders, print island
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			islandMap[i][j] = getRandomCell();
			struct order newOrder;
			newOrder.x = i;
			newOrder.y = j;
			orders[currentOrder] = newOrder;
			currentOrder++;
		}
	}
	currentOrder = 0;
	shuffle(orders, n * n);
	printIsland();
	
	//init pirates
	pthread_t pirates[piratesInit];
	piratesRemain = piratesInit;
	for (long t = 0; t < piratesInit; t++)
	{
		//printf("John S: deploying pirate %ld\n", t);
		pirateAlive[t] = true;
		pirateArmored[t] = false;
		pirateMoney[t] = 0;
		pthread_create(&pirates[t], NULL, pirateActivity, (void*) t);
	}
	
	//wait for pirates or orders to run out
	pthread_mutex_lock(&ordersMutex);
	while (piratesRemain > 0 && currentOrder < n * n) {
		printf("John S: watching the crew work...\n");
		pthread_cond_wait(&ordersCV, &ordersMutex);
		printf("John S: emergency news\n");
	}
		
	//wait for pirates to return (join)
	void *status;
	for (long t = 0; t < piratesInit; t++)
	{
		//printf("John S: waiting for return of pirate %ld\n", t);
		pthread_join(pirates[t], &status);
	}
	
	int piratesReturned = 0;
	//report
	if (piratesRemain > 0) {
		for (int i = 0; i < piratesInit; i++) {
			if (pirateAlive[i] == true) {
				piratesReturned++;
				totalMoney += pirateMoney[i];
			}
		}
		printf("John S: %d out of %d pirates have survived and brought back %d coins out of the potential %d coins\n",
		piratesReturned, piratesInit, totalMoney, potenialMoney);
	} else {
		printf("John S: all pirates were killed! None of the potential %d coins returned\n", potenialMoney);
	}
	
	
	pthread_mutex_unlock(&ordersMutex);
	pthread_exit(NULL);
}