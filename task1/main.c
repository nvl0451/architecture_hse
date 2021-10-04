//main.c is all about input/output and bubble sort processing

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#include "shape_defined.h"

//set up a basic container
int maxSize = 10000;
struct container {
    int size; //current size
    struct shape shapes[10000];
};

//set up a basic timer
double timer = 0.0;
clock_t startMoment, finishMoment;
void startTimer() {
	startMoment = clock();
}
void noteTimer() {
	finishMoment = clock();
	printf("%f seconds", (float)(finishMoment - startMoment) / CLOCKS_PER_SEC);
}

int randomRange(int low, int high) {
	return ((rand() % (high - low + 1)) + low);
}

int main(int argc, char * argv[]) {
	startTimer();
	int randomMode = 0;
	int randomNum = 0;
	
	// LAUNCH
	
    //check arguments for validity
    if (argc == 5) {
        printf("Output filenames supplied are %s and %s\n", argv[3], argv[4]);
        if (strcmp(argv[3], argv[4]) == 0) {
            printf("ERROR: output filenames are the same. Aborting.\n");
            return -1;
        }
    } else if (argc > 5) {
        printf("ERROR: Too many arguments supplied. Mode and three arguments expected: main <-f in_file/-r rand_key> out_file1 out_file2\n");
        return -1;
    } else {
        printf("ERROR: Not enough arguments. Mode and three arguments expected: main <-f in_file/-r rand_key> out_file1 out_file2\n");
        return -1;
    }
	
	//switch to random mode if "-r"
	if (strcmp(argv[1], "-r") == 0) {
		printf("Switching to random mode...\n");
		srand(time(0));
		randomMode = 1;
		randomNum = atoi(argv[2]);
		if ((randomNum < 1) || (randomNum > 10000)) {
			printf("Random mode failure: please input rand_key in range[1, 10000]\n");
			return -1;
		}
		printf("Random mode %d initiated\n", randomNum);
	} else if (strcmp(argv[1], "-f") != 0) {
		printf("Unknown mode. Supported modes are: <-f> for file input and <-r> for random input\n");
	}
	
	//open files for reading, writing
	printf("opening files now..\n");
	
	FILE *in_file = NULL;
	if (randomMode == 0) {
		in_file = fopen(argv[2], "r");
	}
	FILE *out_file = fopen(argv[3], "w");
	FILE *out_file_sort = fopen(argv[4], "w");

	//test access to files
	if ((in_file == NULL) && (randomMode == 0)) {   
		printf("Error! Could not open file for reading\n"); 
		printf("%s might a bad filename\n", argv[2]); 
		exit(-1);
	} 
	if ((out_file == NULL) || (out_file_sort == NULL)) {   
		printf("Error! Could not open files for writing\n"); 
		exit(-1);
	}
	
	printf("files opened successfully\n");
	
	//INPUT CONTAINER
	
	//all arguments checked out, var init time
	//init container of 10000 shapes, set size to 0
	struct container cont;
	cont.size = 0;
	//init var for temporary shape headed for container
	char sType[20];
	enum shapeType eType;
	struct shape tempShape;
	//init tracking data
	int damagedData = 0;
	int cPos = 0;
	
	/*algorithm to generating a shape container
	create a tempShape:
		get enumerated type: sphere, paral, or tetra
		get float of range [1; 100] for density 
		get 1/3/1 int(s) of range [1; 100] for dimensions
		process dimensions into volume through volume()
	put tempShape into container
	*/
	
	//in case of random mode, generate the container
	if (randomMode == 1) {
		//loop
		for (cPos = 0; cPos < randomNum; cPos++) {
			//generate tempShape
			int tempT = randomRange(1, 3);
			//printf("generated %d\n", tempT);
			tempShape.dens = randomRange(1, 100) + (1.0 / (float)randomRange(1, 100));
			switch (tempT) {
				case 1:
					//sphere
					tempShape.type = SPHERE;
					tempShape.s.radius = randomRange(1, 100);
					break;
				case 2:
					//paral
					tempShape.type = PARAL;
					tempShape.p.a = randomRange(1, 100);
					tempShape.p.b = randomRange(1, 100);
					tempShape.p.c = randomRange(1, 100);
					break;
				case 3:
					//tetra
					tempShape.type = TETRA;
					tempShape.t.a = randomRange(1, 100);
					break;
				default:
					break;
			}
			tempShape.vol = volume(&tempShape);
			//put tempShape into container
			cont.shapes[cont.size] = tempShape;
			cont.size++;
		}
	}
	
	//in case of file mode, read input file into container, get statistics
	while ((randomMode == 0) && (fscanf(in_file, "%s", sType) != EOF)) {
		eType = strToShape(sType);
		tempShape.type = eType;
		//input data
		switch(eType) {
			case SPHERE:
				fscanf(in_file, "%f %d", &tempShape.dens, &tempShape.s.radius);
				break;
			case PARAL:
				fscanf(in_file, "%f %d %d %d", &tempShape.dens, &tempShape.p.a,
				&tempShape.p.b, &tempShape.p.c);
				break;
			case TETRA:
				fscanf(in_file, "%f %d", &tempShape.dens, &tempShape.t.a);
				break;
			case WRONG:
				printf("shape damaged\n");
				damagedData++;
				break;
		}
		if (eType != WRONG) {
			tempShape.vol = volume(&tempShape);
			cont.shapes[cont.size] = tempShape;
			cont.size++;
		}
	}
	
	//OUTPUT RAW
	
	//display special message if file did not produce any tangible shapes
	if (cont.size == 0) {
		fprintf(out_file, "No shapes found.\n");
		fprintf(out_file_sort, "No shapes found.\n");
		noteTimer();
		return 0;
	}
	
	//output raw container into out_file
	int iter1, iter2, len = cont.size;
	fprintf(out_file, "shapes successfully processed: %d\n", cont.size);
	fprintf(out_file, "shapes damaged: %d\n", damagedData);
	for (iter1 = 0; iter1 < len; iter1++) {
		fprintf(out_file, "entry %d: %s of density %.2f and volume of %.2f with ", iter1 + 1,
			shapeToStrFull(cont.shapes[iter1].type),
			cont.shapes[iter1].dens, cont.shapes[iter1].vol);
		switch (cont.shapes[iter1].type) {
			case SPHERE:
				fprintf(out_file, "radius of %d\n", cont.shapes[iter1].s.radius);
				break;
			case PARAL:
				fprintf(out_file, "edge lengths of %d x %d x %d\n", cont.shapes[iter1].p.a,
				cont.shapes[iter1].p.b, cont.shapes[iter1].p.c);
				break;
			case TETRA:
				fprintf(out_file, "edge length of %d\n", cont.shapes[iter1].t.a);
				break;
			case WRONG:
				//impossible to reach this
				//added just for fullness
				break;
		}
	}
	
	//OUTPUT SORTED
	
	//bubble sorting container by volume
	for (iter1 = 0; iter1 < len - 1; iter1++) {
		for (iter2 = 0; iter2 < len - iter1 - 1; iter2++) {
			if (cont.shapes[iter2].vol > cont.shapes[iter2 + 1].vol) {
				tempShape = cont.shapes[iter2];
				cont.shapes[iter2] = cont.shapes[iter2 + 1];
				cont.shapes[iter2 + 1] = tempShape;
			}
		}
	}
	
	//sorted output
	fprintf(out_file_sort, "%d shapes sorted in ascending order:\n", cont.size);
	for (iter1 = 0; iter1 < len; iter1++) {
		fprintf(out_file_sort, "entry %d: %s of density %.2f and volume of %.2f with ", iter1 + 1,
			shapeToStrFull(cont.shapes[iter1].type),
			cont.shapes[iter1].dens, cont.shapes[iter1].vol);
		switch (cont.shapes[iter1].type) {
			case SPHERE:
				fprintf(out_file_sort, "radius of %d\n", cont.shapes[iter1].s.radius);
				break;
			case PARAL:
				fprintf(out_file_sort, "edge lengths of %d x %d x %d\n", cont.shapes[iter1].p.a,
				cont.shapes[iter1].p.b, cont.shapes[iter1].p.c);
				break;
			case TETRA:
				fprintf(out_file_sort, "edge length of %d\n", cont.shapes[iter1].t.a);
				break;
			case WRONG:
				//impossible to reach this
				//added just for fullness
				break;
		}
	}
	noteTimer();
}