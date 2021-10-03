#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main( int argc, char *argv[] )  {
	//check arguments for validity
   if( argc == 3 ) {
      printf("The arguments supplied are %s and %s\n", argv[1], argv[2]);
	  if (strcmp(argv[1], argv[2]) == 0) {
		  printf("Arguments are the same. Dont do this.\n");
		  return -1;
	  }
   }
   else if( argc > 3 ) {
      printf("Too many arguments supplied.\n");
	  return -1;
   }
   else {
      printf("Two arguments expected.\n");
	  return -1;
   }
   
   //open files
   printf("opening files now..\n");
   
   FILE *in_file = fopen(argv[1], "r");
   FILE *out_file = fopen(argv[2], "w");
   
   // test for files not existing. 
	if (in_file == NULL) {   
		printf("Error! Could not open file for reading\n"); 
		exit(-1);
	} 
	if (out_file == NULL) {   
		printf("Error! Could not open file for writing\n"); 
		exit(-1);
	} 
	
	//read input file
	char color[10];
	int amount, fullAmount;
	fullAmount = 0;
	while (fscanf(in_file, "%s %d", color, &amount) != EOF) {
		fullAmount += amount;
		fprintf(out_file, "scanned pencils color %s in amount %d\n", color, amount);
	}
	fprintf(out_file, "overall pencils in stock - %d\n", fullAmount);
}















