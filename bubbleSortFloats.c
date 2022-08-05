#include <stdio.h>
#include <stdlib.h>


void printSorted(float array[], int size){
    for(int i=0; i<size; ++i){
        printf("%.2f ", array[i]);
    }
    printf("\n");
}

void bubbleSort(float array [], int size) {
    //Accesses each element 
    for (int i = 0; i < size-1; i++){
        //Compares each two adjacent, legal elements
        for(int j = 0; j < size-i-1; j++){
            //Swap algorithm if needed
            if(array[j] < array[j+1]){
                float aux = array[j];
                array[j] = array[j+1];
                array[j+1] = aux;
            }
        }
    printSorted(array, size);
    }
}

int main()
{
 float numbers[10] = {5.6, 4.3, 6.2, 6.4, 7.3, 2.3, 8.3, 9.2, 0.1, 1.9};
 int size = sizeof(numbers) / sizeof (numbers[0]);

   bubbleSort(numbers, size);

 return 0;
}
