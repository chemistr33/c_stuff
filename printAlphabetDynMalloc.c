#include <stdio.h>
#include <stdlib.h>

#define MB 1024*1024
int uSel;

int introPrompt(){
printf("--------------- Print Alphabet ---------------\n");
printf("Enter a number between 0 and %d\n-> ", MB);
scanf("%d", &uSel);
printf("----------------------------------------------\n\n");
  if(uSel<0||uSel>MB){
    printf("Invalid argument\n");
    return 0;
  }
return 1;
}
char* buildArray(int bytes){
  char* ptr = (char*)malloc(bytes * sizeof(char));
  int i=0;
  do {
      for(int j=0;j<26;j++,i++){
        *(ptr+i)='A'+j;
      }
     }while(i<(bytes*sizeof(char)));
return ptr;
}
char* printArray(char* parray){
  for(int i=0; i<(uSel*sizeof(char));i++){
    printf("%c", *(parray+i));
  }
return parray;
}
void closerText(char* parray){
printf("\n\n----------------------------------------------\n");
}

int main() {
  system("clear");
  if(introPrompt()){
    closerText(printArray(buildArray(uSel)));
    return 0;
  }else return 1;
}

