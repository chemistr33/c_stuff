#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
char octet1[9]; 
char octet2[9];
char octet3[9];
char octet4[9];
void captureOctets (char* arg){
    int j; 
    for(int i=0; i<9; i++){
    if(*(arg+i)=='.'){
        j=i+1;
        break;
        }
    octet1[i]=*(arg+i);
    }
    for(int i=0; i<9; i++,j++){
    if(*(arg+j)=='.'){
        j++;
        break;
        }
    octet2[i]=*(arg+j);
    }
    for(int i=0; i<9; i++,j++){
    if(*(arg+j)=='.'){
        j++;
        break;
        }
    octet3[i]=*(arg+j);
    } 
    for(int i=0; i<9; i++,j++){
    if(*(arg+j)=='\0'){
        j--;
        break;}
    else octet4[i]=*(arg+j);
    }
}
void testOctet(char* arg){
int sum=0,quantity=0;
//if the first number is invalid, the octet is invalid 
//for each element in the octet, test...
 for(int i=0; i<4; i++){
//if it's a digit, accumulate total value and number of digits 
   if((isdigit(*(arg+i)))){
    sum+=*(arg+i);
    quantity++;
    }
//jump out of loop if period, null, or space is detected...
   if( *(arg+i)=='.' || *(arg+i)=='\0' || *(arg+i)==' '){break;}
 
 }
//the sum has to be valid
 if(sum>(156)){
    printf("Invalid IPv4 address\n");
    return;
 }
//the number of digits has to be valid
 if(quantity>4){
    printf("Invalid number of digits in octet.\n");
    return;
 }
}
int main(){
 char addr[36];
 char* pAddr = addr;
 printf("Enter IP Address\n->");
 scanf("%s",pAddr);
 printf("---------------------------------\n");
 captureOctets(pAddr);
 testOctet((char*)&octet1);
 testOctet((char*)&octet2);
 testOctet((char*)&octet3);
 testOctet((char*)&octet4);
 printf("Complete Address: %s.%s.%s.%s\n",octet1,octet2,octet3,octet4);
 printf("Last Three Parts: %s.%s.%s\n",octet2,octet3,octet4);
 printf("Last Two Parts: %s.%s\n",octet3,octet4);
 printf("Last Part: %s\n\n", octet4);
return 0;    
}
