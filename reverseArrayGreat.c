#include <stdio.h>
#include <stdlib.h>
int main() {
    const uint kSize = 26;
    char array [ kSize ];
    // load array with alphabet 
    for (int i = 0; i < kSize; i++){
     array[i]='a'+(char)i;
    }
    // print array z->a
    for (int i = 25; i >= 0; i--){
     printf("%c\n", array[i]);
    }
    // an array to hold the word 'great'
    char great[5]={0};
    // loop through alphabet array, for each element, test with switch statement 
    for (int i = 0; i<kSize; i++){
    switch (array[i])
    {
    case 'g':
        great[0]=array[i];
                printf("#%d -> {%c%c%c%c%c}\n",i+1,great[0],
                       great[1],great[2],great[3],great[4]);
        break;
    case 'r':
        great[1]=array[i];
                printf("#%d -> {%c%c%c%c%c}\n",i+1,great[0],
                       great[1],great[2],great[3],great[4]);
        break;
    case 'e':
        great[2]=array[i];
                printf("#%d -> {%c%c%c%c%c}\n",i+1,great[0],
                       great[1],great[2],great[3],great[4]);
        break;
    case 'a':
        great[3]=array[i];
                printf("#%d -> {%c%c%c%c%c}\n",i+1,great[0],
                       great[1],great[2],great[3],great[4]);
        break;
    case 't':
        great[4]=array[i];
                printf("#%d -> {%c%c%c%c%c}\n",i+1,great[0],
                       great[1],great[2],great[3],great[4]);
        break;
    default:
        if(great[4]){break;} 
        else {
                printf("#%d -> {%c%c%c%c%c}\n",i+1,great[0],
                       great[1],great[2],great[3],great[4]);
                break;
              }
    }
   } 
    // print the great[] array
    for(int i = 0; i<5; i++){
        printf("%c",great[i]);
    } printf("\n");
 
 return 0;
}
