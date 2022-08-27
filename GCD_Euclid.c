#include <stdio.h>
#include <stdlib.h>
int main(){
  int a,b;
  printf("Enter two integers for GCD determination: ");
  scanf("%d %d", &a, &b);
  while(a!=b){
    if(b>a){b=b-a;}
    else a=a-b;
  }
  printf("GCD is %d\n", a);
  return 0;
}
