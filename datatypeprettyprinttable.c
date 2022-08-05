#include <stdio.h>
#include <stdlib.h>
int main()
{
  system("clear");  
   printf(" _________________________ \n"); 
   printf("|    Integer Data Types   |\n"); 
   printf("|~~~~~~~~~~~~~~~~~~~~~~~~~|\n"); 
    printf("|   short int is %ld bytes  |\n", sizeof(short int));
	printf("|         int is %ld bytes  |\n", sizeof(int));
	printf("|       int * is %ld bytes  |\n", sizeof(int *));
	printf("|    long int is %ld bytes  |\n", sizeof(long int));
	printf("|  long int * is %ld bytes  |\n", sizeof(long int *));
	printf("|  signed int is %ld bytes  |\n", sizeof(signed int));
	printf("| unsigned int is %ld bytes |\n", sizeof(unsigned int));
   printf("|-------------------------|\n"); 
   printf("|     Float Data Types    |\n"); 
   printf("|~~~~~~~~~~~~~~~~~~~~~~~~~|\n"); 
	printf("|       float is %ld bytes  |\n", sizeof(float));
	printf("|     float * is %ld bytes  |\n", sizeof(float *));
	printf("|      double is %ld bytes  |\n", sizeof(double));
	printf("|    double * is %ld bytes  |\n", sizeof(double *));
	printf("| long double is %ld bytes |\n", sizeof(long double));
   printf("|-------------------------|\n"); 
   printf("|   Character Data Types  |\n"); 
   printf("|~~~~~~~~~~~~~~~~~~~~~~~~~|\n"); 
	printf("|  signed char is %ld bytes |\n", sizeof(signed char));
	printf("|         char is %ld bytes |\n", sizeof(char));
	printf("|       char * is %ld bytes |\n", sizeof(char *));
	printf("| unsigned char is %ld bytes| \n", sizeof(unsigned char));
   printf("|_________________________|\n"); 
   printf("\n");
return 0;
}
