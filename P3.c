/*
Daniel Hug
P3
CSI333
Fri 1:40
*/


#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
	char value[20]; //Each listNode contains a character
	int count;
	struct node *next; //Pointer to the next node

}; //end of stuct



//Creates the head node and tracks the current node
 struct node *head = NULL;
 struct node *curr = NULL;

//deletes node with value that matches input
void del(char input[]){

	char data[20];
	struct node *previous = head;
	struct node *temp = head;

	strcpy(data, input);
	while(strcmp(temp->value, data) != 0){

		if(temp->value != data){
			previous = temp;
			temp = temp->next;

		}
	}

	if(temp->count ==1){

		previous = temp->next;
		if(temp == curr){
			curr == previous;
		}
		else if (temp == head){
			head = temp->next;
		}
	}
	else{
		temp->count--;
	}
}



void ins(char input[20]){

	struct node *temp;
	struct node *test = head;
	struct node *previous = head;
	int testnum = 0;

	temp = (struct node*) malloc(sizeof(struct node));

	if(NULL == temp) {
		printf("Node allocation failed. \n "); fflush(stdout);
		exit(1);

	}

	strcpy(temp->value, input);
	temp->next = NULL;
	temp->count = 1;

	if(NULL == head){
		head = curr = temp;
	}
	else{
		while (NULL != test){
 
      if((strcmp(test->value, input)) == 0){
        test->count++;
        break;
 
      }
      else {
        if (test->next == NULL){
          break;
        }
        else {
          test = test->next;
        }
      }
    }
    if((strcmp(test->value, input)) != 0){
      curr->next = temp;
      curr = temp;

		}
	}
}


//deletes node with same count as inputted integer
void fde(int exco){
 
  struct node *temp = head;
  struct node *previous = temp;
 
  while (temp != NULL){
    if (temp->count <= exco){
      if (temp == head){
        head = head->next;
      }
      previous->next = temp->next;
      temp = temp->next;
    }
    else{
      temp = temp->next;
    }
  }
 
}
 
//prints statistics on the counts of the nodes
void pst(){
  int numnode = 0;
  int maxcount = 0;
  int mincount = 10;
  float average = 0;
  struct node *temp = head;
  if (head != NULL){
    while (temp != NULL){
      numnode++;
      average += temp->count;
      if ((temp->count) > maxcount){
        maxcount = temp->count;
      }
      else if ((temp->count) < mincount){
        mincount = temp->count;
      }
      temp = temp->next;
    }
    average /= numnode;
 
    printf("The number of nodes in the list is %d\n", numnode); fflush(stdout);
    printf("The maximum count is %d\n", maxcount); fflush(stdout);
    printf("The minimum count is %d\n", mincount); fflush(stdout);
    printf("The average count is %1.2f\n", average); fflush(stdout);
  }
  else {
    printf("This list is empty.\n"); fflush(stdout);
  }
}
 
//prints the linked list
void prl(){
  struct node *temp = head;
  struct node *previous = temp;
  int counter;
 
  if (head != NULL){
    while (temp != NULL){
      counter = temp->count;
      printf("%s \nCount: %d\n",  temp->value, counter); fflush(stdout);
      temp = temp->next;
    }
  }
  else{
    printf("This list is empty.\n"); fflush(stdout);
  }
}
 
//prints all of the nodes with a count within the range of numbers specified
void pcr(int input1, int input2){
  struct node *temp = head;
  int num = 0;
 
  while (temp != NULL){
    if ((temp->count >= input1) && (temp->count <= input2)){
 
      printf("%s\n", temp->value); fflush(stdout);
      num++;
    }
 
    temp = temp->next;
  }
  if (num == 0){
    printf("There is no values in this list.\n"); fflush(stdout);
  }
}

//finds the node that begins with the inputted prefix

void ppr(char input[]){
  int length;
    int i;
    char copy[20];
    struct node *temp = head;
    struct node *correct;
 
  if (head != NULL){
     while (temp != NULL){

      if(input[0]==temp->value[0]) {
      	for(i = 0; i < strlen(input); i++){
      		if(input[i]!=temp->value[i]){
      			temp = temp->next;
                printf("1\n");
            }
            else {
            	printf("Value: %s \n Count: %d \n", temp, temp->count);fflush(stdout);
            	//printf("2\n"); }
            }return;
            } //
            else {
            	temp = temp->next;
            	printf("3\n");
            }
        }
    }
  }
 
//finds the node that ends in the postfix inputted
//Not working
void psu(char input[]){
  /*if (head != NULL){
    int length;
    int i;
    char copy[20];
    struct node *temp = head;
    struct node *correct;
 
    if (head != NULL){
    printf("1"); fflush(stdout);
    length = strlen(input);
    printf("2"); fflush(stdout);
    while (temp != NULL){
    printf("3"); fflush(stdout);
    strcpy(copy, temp->value);
    printf("4"); fflush(stdout);
    for (i = 0; i < length; i++){
    if (copy[i] != input[i]){
    printf("5"); fflush(stdout);
    break;
    }
    else{
    temp = temp->next;
    if (i = (length -1)){
    printf("6"); fflush(stdout);
    correct = temp;
    }
    }
    }
    }
    printf("7"); fflush(stdout);
    printf("%s \nCount: %d \n", correct->value, correct->count); fflush(stdout);
    }
    }
    else {
    printf("This list is empty.\n"); fflush(stdout);
    }
  */
}
 
 
//the main function that takes all of the user input
int main(){
 
  void ins(char[]);
 
  char symbol [10];
  char symbolCopy[10];
  char data1[100];
  char data2[100];
  int help;
  int me;
  int stringcomp;
 
  printf("Command? "); fflush(stdout);
  scanf("%s", &symbol);
 
 
  stringcomp = strcmp(symbol, "end");
  while (stringcomp != 0){
    strcpy(symbolCopy, symbol);
    if (strcmp(symbolCopy, "ins") == 0){
      scanf("%s", &data1);
      ins(data1);
    }
    else if (strcmp(symbolCopy, "del") == 0){
      scanf("%s", &data1);
      del(data1);
 
    }
    else if (strcmp(symbolCopy, "fde") == 0){
      scanf("%d", &help);
      fde(help);
 
    }
    else if (strcmp(symbolCopy, "pst") == 0){
      pst();
    }
    else if (strcmp(symbolCopy, "prl") == 0){
      prl();
    }
    else if (strcmp(symbolCopy, "pcr") == 0){
      scanf("%d%d", &help, &me);
      pcr(help, me);
    }
    else if (strcmp(symbolCopy, "ppr") == 0){
      scanf("%s", data1);
      ppr(data1);
    }
    else if (strcmp(symbolCopy, "psu") == 0){
      scanf("%s", data1);
      psu(data1);
    }
    else {
      exit(0);
    }
    printf("Command? "); fflush(stdout);
    scanf("%s", &symbol);
    stringcomp = strcmp(symbol, "end");
  }
 
  return 0;
 
}






















