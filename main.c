#include <stdio.h>
//#include "functions1.c"
//#include "prototypes1.h"
//#include "functions2.c"
//#include "prototypes2.h"
//#include "structs.h"

typedef struct logLine{
  char level[20];
  char timeStamp[20];
  char message[100];
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
  
  /* HAVEN'T TESTED ANY OF THIS YET
 char[143] line;
  logList_t* list1;

  while(fgets(line, sizeof(line), file1)){
    list1->line =  parseLine(&line);
    list1 = list1->next;
  }
  */
  
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
//////ADD JESS'S OTHER TWO FUNCTIONS OR ELSE YOU'RE GOING TO DIE
