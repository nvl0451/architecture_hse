#include <stdio.h>
#include <string.h>

int main( int argc, char *argv[] )  {

   if( argc == 3 ) {
      printf("The arguments supplied are %s and %s\n", argv[1], argv[2]);
	  if (strcmp(argv[1], argv[2]) == 0) {
		  printf("Arguments are the same. Dont do this.\n");
		  return 0;
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
   printf("opening files now..\n");
}