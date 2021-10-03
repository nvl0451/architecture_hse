//main.c is all about input/output and bubble sort processing

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "shape_defined.h"

//set up a basic container
int maxSize = 10000;
struct container {
    int size; //current size
    struct shape shapes[10000];
};

int main(int argc, char * argv[]) {
	int randomMode = 0;
	int randomNum = 0;
	
    //check arguments for validity
    if (argc == 5) {
        printf("Output filenames supplied are %s and %s\n", argv[3], argv[4]);
        if (strcmp(argv[3], argv[4]) == 0) {
            printf("Output filenames are the same. Aborting.\n");
            return -1;
        }
    } else if (argc > 5) {
        printf("Too many arguments supplied. Mode and three arguments expected: main <-f in_file/-r rand_key> out_file1 out_file2\n");
        return -1;
    } else {
        printf("Not enough arguments. Mode and three arguments expected: main <-f in_file/-r rand_key> out_file1 out_file2\n");
        return -1;
    }
	
	//switch to random mode if "-r"
	if (strcmp(argv[1], "-r") == 0) {
		printf("Switching to random mode...\n");
		randomMode = 1;
		randomNum = atoi(argv[2]);
		if ((randomNum < 1) || (randomNum > 10000)) {
			printf("Random mode failure: please input rand_key in range[1, 10000]\n");
			return -1;
		}
		printf("Random mode initiated %d\n", randomNum);
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
		exit(-1);
	} 
	if ((out_file == NULL) || (out_file_sort == NULL)) {   
		printf("Error! Could not open files for writing\n"); 
		exit(-1);
	}
	
	printf("files opened successfully\n");
	
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
	float totalVol = 0.0;
	
	/*algorithm to generating or reading a shape container
	create a tempShape:
		get enumerated type: sphere, paral, or tetra
		get float of range (0; 10000) for density 
		get 1 or 3 or 1 ints of range (0; 10000) for dimensions
		process dimensions into volume through volume()
	put tempShape into container
	*/
	
	//in case of randomMode, generate the container
	if (randomMode == 1) {
		//init var for temporary shape dimensions
		int tempA, tempB, tempC;
		float tempDens;
	}
	
	//read input file into container, get statistics
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
				printf("shape damaged");
				damagedData++;
				break;
		}
		if (eType != WRONG) {
			tempShape.vol = volume(&tempShape);
			cont.shapes[cont.size] = tempShape;
			cont.size++;
		}
	}
	
	//bubble sorting by volume
	int iter1, iter2, len = cont.size;
	//struct shape tempShape is already here
	//commenting it to bring it back
	for (iter1 = 0; iter1 < len - 1; iter1++) {
		for (iter2 = 0; iter2 < len - iter1 - 1; iter2++) {
			if (cont.shapes[iter2].vol > cont.shapes[iter2 + 1].vol) {
				tempShape = cont.shapes[iter2];
				cont.shapes[iter2] = cont.shapes[iter2 + 1];
				cont.shapes[iter2 + 1] = tempShape;
			}
		}
	}
	
	//output into out_file
	//into console for debug, first
	fprintf(out_file, "total data damaged: %d\n", damagedData);
	for (iter1 = 0; iter1 < len; iter1++) {
		fprintf(out_file, "%s %f %f ", shapeToStr(cont.shapes[iter1].type),
			cont.shapes[iter1].dens, cont.shapes[iter1].vol);
		switch (cont.shapes[iter1].type) {
			case SPHERE:
				fprintf(out_file, "%d\n", cont.shapes[iter1].s.radius);
				break;
			case PARAL:
				fprintf(out_file, "%d %d %d\n", cont.shapes[iter1].p.a,
				cont.shapes[iter1].p.b, cont.shapes[iter1].p.c);
				break;
			case TETRA:
				fprintf(out_file, "%d\n", cont.shapes[iter1].t.a);
				break;
		}
		totalVol += cont.shapes[iter1].vol;
	}
	fprintf(out_file, "total shape vol is %f\n", totalVol);
	
	
	
	
	
	
	
	
	
}