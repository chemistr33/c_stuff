//#include "sll.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct node{
  int data;
  struct node *next;
} node_t;

typedef struct legend{
  struct node *head;
  struct node *tail;
  int length;
} legend_t;

// Forward Declaration of Push
node_t* push(node_t **headref, int init);


// Check if list is empty
int test4empty(node_t *head){
  if(head==NULL){
    printf("test4empty: List Empty\n");
    return 1;}
  else {
    printf("test4empty: List Exists\n");
    return 0;
    }
}


// Print Linked List to Console
 void printll(node_t *head){
  node_t *cursor = head;
  
  int index = 0;
  
  if(cursor==NULL){
    printf("printll: Linked-List Empty\n");
  }

  printf("\t____________________\n");
  while(cursor != NULL){
    printf("\t|     [%d]={%d}\t   |\n",index,cursor->data);
    cursor=cursor->next; 
    index++;
  }
  printf("\t____________________\n");
}

// Build N Number of Nodes, Local Reference Version
node_t* buildList(int qty){

  node_t *head = NULL;
  node_t **headref = &head;

  int i;
  for(i=0; i<qty; i++){
    push(headref, i+1);
    headref=&((*headref)->next);
  }
  
 return head;
}

// Push Node and Initialize Data, Local Reference Version 
node_t* push(node_t **headref, int init){

  node_t *newnode = calloc(1, sizeof(node_t));
    newnode->data = init;
    newnode->next = *headref;
    *headref = newnode;
  return *headref;
}

// Pop Node Off the Front of Linked List
int pop(node_t **headref){
  
  node_t *coffin = *headref;
  int popdata;  
  if(coffin==NULL){
    printf("#####################################################\n");
    assert(coffin!=NULL);
    return EXIT_FAILURE;
  }

  popdata=coffin->data;
  *headref=coffin->next;

  free(coffin);

  return popdata;
}

// Append Node and Initialize Data, Local Refernce Version
node_t* append(node_t **headref, int init){

  node_t * cursor = *headref;

  if(cursor==NULL){
    push(headref, init);
  }
  else{
    while (cursor->next!=NULL){
      cursor=cursor->next;
    }
  push(&(cursor->next),init);
  }
 return *headref;
}

// Create Legend Node
legend_t* create_sll(){
  legend_t *sll = calloc(1, sizeof(legend_t));
  sll->head=NULL;
  sll->tail=NULL;
 return sll;
}
// Push Node, Legend Node
int addNode_head(legend_t *sll, int data){

if(!sll || !data) return -1;

node_t *newnode = calloc(1, sizeof(node_t));
  newnode->data = data;
  newnode->next = NULL;
  if(!sll->head){
    sll->head=newnode;
    return 0;
  }
  node_t *keeper = sll->head;
    newnode->next = keeper;
    sll->head = newnode;    
    return 0;

}

// Copy list using local references
node_t * copyList(node_t *head){
  node_t *current = head;
  node_t *duplicate = NULL;
  node_t **endptr;
  endptr = &duplicate;

  while(current != NULL) {
    push(endptr, current->data);
    endptr = &((*endptr)->next);
    current = current->next;
  }
  
  return duplicate;
}

// Returns number of occurences of search term 
int queryInt(node_t * head, int query){

  node_t *cursor = head;
  int searchHits = 0;

  while(cursor!=NULL){
    if(cursor->data==query){
      searchHits++;
    }
    cursor=cursor->next;
  }
  return searchHits;
}

// Length function
int llength(node_t *head){
  node_t *cursor=head;
  int count=0;
  while(cursor!=NULL){
    cursor=cursor->next;
    count++;
  }
return count;
}

// Return data from arbitrary node N
int getNth(node_t *head, int index){
  node_t *cursor = head;
if(index>llength(head)){
  printf("## Error: Index > Length (%d) ##\n", llength(head));
  return EXIT_FAILURE;
}
else if(index<0){
  printf("## Error: Index Negative ##\n");
  return EXIT_FAILURE;
} else{
  for(int i=0;i!=index;i++){
   cursor=cursor->next;
 }
}

return cursor->data;
}

// Delete List
void expunge(node_t **headref){
  node_t *cursor = *headref;
  node_t *next;

  while(cursor!=NULL){
    next = cursor->next;
    free(cursor);
    cursor = next;
  }
 *headref = NULL; 

}

node_t * insertNth(node_t **headref, int index, int init){

  node_t *cursor = *headref;

  if(index==0){
    push(headref, init);
    return *headref;
  }  
  if((index<=llength(cursor)))
  {
    // assert(index>llength(cursor));

  for(int i=1;i!=index;i++){
   cursor=cursor->next;
  }
  push(&(cursor->next), init);
  return *headref; 
 }
}

// Inserts node in the correct
node_t * sortedInsertAscend(node_t **headref, node_t *newnode){

  node_t **cursorref = headref;

  while((*cursorref!=NULL) && ((*cursorref)->data < newnode->data)){
    cursorref=&((*cursorref)->next); // double ptr equals the address of the following node's next member 
  }
  newnode->next = *cursorref;   // ... = value stored at pointee address
  *cursorref = newnode;         // the pointer *cursorref points to = ...
}

int main(){
  node_t *list = buildList(10);
  printll(&list);
  expunge(&list);   
  return 0;  
}
