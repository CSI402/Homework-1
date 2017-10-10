#include <stdio.h>
#include <string.h>
//#include "functions1.c"
//#include "prototypes1.h"
//#include "functions2.c"
//#include "prototypes2.h"
//#include "structs.h"

#define MAX_LEN 100

typedef struct logLine{
  char level[20];
  char timeStamp[20];
  char message[100];
  //struct logLine *next;
} logLine_t;

typedef struct logList {
  logLine_t line;
  struct logList *next;
} logList_t;

logLine_t* parseLine(char* line);
void deleteList(logList_t* l);
void printLines(logList_t* l);
logList_t* mergeLists(logList_t* resultList, logList_t* inList);
logList_t* sortList(logList_t* inList);
char line[MAX_LEN];
int noOfLines = 0;

int main(int argc, char** argv){
  if (argc > 2){
    fprintf(stderr, "%s\n", "Error: Parameter number may not exceed one");
  }

  FILE *file1 = fopen("test.log", "r");
  FILE *file2 = fopen("test2.log", "r");

  if (file1 == NULL){
    printf("Error: File 'test.log' could not be opened.\n");
    return 0;
  }
  if (file2 == NULL){
    printf("Error: File 'test2.log' could not be opened.\n");
    return 0;
  }
  
  logList_t* list1;

  while(fgets(line, MAX_LEN, file1)){
    list1->line = parseLine(&line);
    list1 = list1->next;
    noOfLines++;
  }
printf("%d\n", noOfLines );
  
  //WE NEED TO ACTUALLY TEST THE GOD DAMN FUNCTIONS
  //SORRY FOR THE CAPS LOCK AND THE AGGRESSIVE LANGUAGE
  //BUT AT THIS POINT WE NEED CAPS LOCK AND AGGRESSIVE LANGUAGE
  //FUCK THIS SHIT
}

logLine_t * parseLine(char* line){
  logLine_t * finalLogLine;

  char *pt = strtok(line, ',');
  int i = 1;
  while(pt != NULL){
    if (i==1){
      strncpy(finalLogLine->level, pt, 20);
      i++;
    }
    else if (i==2){
      strncpy(finalLogLine->timeStamp, pt, 20);
 i++;
    }
    else
      strncpy(finalLogLine->message, pt, 100);
    pt = strtok(NULL, ",");
  }
  return finalLogLine;
}

void deleteList(logList_t* l){
  logList_t * current = l;
  logList_t * next;

  while(current != NULL){
    next = current->next;
    free(current);
    current = next;
  }

  l = NULL;
}
void printLines(logList_t* l){
  logList_t * current = l;
  while (current != NULL){
    printf("%s,%s,%s\n", current->line.level, current->line.timeStamp, current->line.message);
    current = current->next;
  }
}

struct logList* mergeLists(struct logList* resultList, struct logList* inList){
 
    struct logList* temp = resultList;
    
    while(resultList->next != NULL){
        resultList = resultList->next;
    }
    resultList->next = inList;
    return temp;
}

int listLength(struct logList* testList){
    int counter = 0;
    
    while(testList != NULL){
        counter++;
        testList = testList->next;
    }
    
    return counter;
}
void switcher(struct logLine* a, struct logLine* b){
    char temp1[20];
    char temp2[20];
    char temp3[20];
    
    //temp1 = a->level; temp2 = a->timeStamp; temp3 = a->message;
    strcpy(temp1, a->level); strcpy(temp2, a->level); strcpy(temp3, a->level);
    strcpy(a->level, b->level); strcpy(a->timeStamp, b->timeStamp); 
    strcpy(a->message, b->message); strcpy(b->level, temp1), strcpy(b->timeStamp, temp2);
    strcpy(b->message , temp3);    
   // a->level = b->level; a->timeStamp = b->timeStamp; a->message = b->message;
    //b->level = temp1; b->timeStamp = temp2; b->message = temp3;
    
} 

struct logList* sortList(struct logList* inList){
    
    int switched = 0;
    struct logLine *ptr1 = inList->line;
    struct logLine *ptr2 = NULL;
    struct logList *ptr3;
    struct logList *ptr4 = NULL;
    
    
    char year1[4]; char month1[2]; char date1[2]; char hours1[2]; char seconds1[2]; char minutes1[2];
    char year2[4]; char month2[2]; char date2[2]; char hours2[2]; char seconds2[2]; char minutes2[2];
    
    
    do{
        switched = 0;
        ptr1 = inList;
        
        while(ptr3->next != ptr2) {
            
            strcpy(year1, strtok(ptr1->timeStamp, "-"));
            strcpy(month1, strtok(NULL, "-"));
            strcpy(date1, strtok(NULL, "-"));
            strcpy(hours1, strtok(NULL, " "));
            strcpy(minutes1, strtok(NULL, ":"));
            strcpy(seconds1, strtok(NULL, ":"));
            
            strcpy(year2, strtok((ptr1->next)->timeStamp, "-"));
            strcpy(month2, strtok(NULL, "-"));
            strcpy(date2, strtok(NULL, "-"));
            strcpy(hours2, strtok(NULL, " "));
            strcpy(minutes2, strtok(NULL, ":"));
            strcpy(seconds2, strtok(NULL, ":"));
             
            if (strtol(year1) > strtol(year2)){
                switcher(ptr1, ptr1->next);
                switched = 1;
            }
            else if (strtol(year1) == strtol(year2)){
                if(strtol(month1) > strtol(month2)){
                    switcher(ptr3, ptr3->next);
                    switched = 1;
                }
                else if (strtol(month1) == strtol(month2)){
                    if(strtol(date1) > strtol(date2)){
                        switcher(ptr3, ptr3->next);
                        switched = 1;
                    }
                    else if(strtol(date1) == strtol(date2)){
                        if(strtol(hours1) > strtol(hours2)){
                            switcher(ptr3, ptr3->next);
                            switched = 1;
                        }
                        else if(strtol(hours1) == strtol(hours2)){
                            if(strtol(minutes1) > strtol(minutes2)){
                                switcher(ptr3, ptr3->next);
                                switched = 1;
                            }
                            else if (strtol(minutes1) == strtol(minutes2)){
                                if(strtol(seconds1) > strtol(seconds2)){
                                    switcher(ptr3, ptr3->next);
                                    switched = 1;
                                }
                            }
                        }
                    }
                }
                
            }
            ptr3 = ptr3->next;
        }
        ptr4 = ptr3;
    }
    while(switched);
    
    return ptr3;
}



