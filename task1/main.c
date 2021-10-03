//main.c is all about input/output

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
    //check arguments for validity
    if (argc == 3) {
        printf("The filenames supplied are %s and %s\n", argv[1], argv[2]);
        if (strcmp(argv[1], argv[2]) == 0) {
            printf("Filenames are the same. Aborting.\n");
            return -1;
        }
    } else if (argc > 3) {
        printf("Too many arguments supplied. Two arguments expected.\n");
        return -1;
    } else {
        printf("Not enough arguments. Two arguments expected.\n");
        return -1;
    }
	
	//open files for reading, writing, test availability
	printf("opening files now..\n");
   
	FILE *in_file = fopen(argv[1], "r");
	FILE *out_file = fopen(argv[2], "w");

	if (in_file == NULL) {   
		printf("Error! Could not open file for reading\n"); 
		exit(-1);
	} 
	if (out_file == NULL) {   
		printf("Error! Could not open file for writing\n"); 
		exit(-1);
	}
	
	printf("files opened successfully\n");
	
	//read input file into container, get statistics
	char sType[20];
	enum shapeType eType;
	int a, b, c, r;
	int damagedData = 0;
	float tempDens;
	float totalVol = 0.0;
	struct container cont;
	cont.size = 0;
	struct shape tempShape;
	while (fscanf(in_file, "%s", sType) != EOF) {
		eType = strToShape(sType);
		//input data
		switch(eType) {
			case SPHERE:
				fscanf(in_file, "%f %d", &tempDens, &r);
				tempShape.type = eType;
				tempShape.s.radius = r;
				tempShape.dens = tempDens;
				tempShape.vol = volume(&tempShape);
				break;
			case PARAL:
				fscanf(in_file, "%f %d %d %d", &tempShape.dens, &tempShape.p.a,
				&tempShape.p.b, &tempShape.p.c);
				tempShape.type = eType;
				tempShape.vol = volume(&tempShape);
				break;
			case TETRA:
				fscanf(in_file, "%f %d", &tempDens, &a);
				tempShape.type = eType;
				tempShape.t.a = a;
				tempShape.dens = tempDens;
				tempShape.vol = volume(&tempShape);
				break;
			case WRONG:
				printf("shape damaged");
				damagedData++;
				break;
		}
		if (eType != WRONG) {
			cont.shapes[cont.size] = tempShape;
			//printf("%s %f %f\n", shapeToStr(cont.shapes[cont.size].type),
			//cont.shapes[cont.size].dens, cont.shapes[cont.size].vol);
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