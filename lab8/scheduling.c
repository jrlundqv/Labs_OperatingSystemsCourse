#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct process{
  /* Values initialized for each process */
  int id;
  int arrivaltime;  /* Time process arrives and wishes to start */
  int runtime;      /* Time process requires to complete job */

  /* Values algorithm may use to track processes */
  int starttime;
  int endtime; 
};

struct process proc[100];

int read_file (char fileName[14]) {
    FILE *pFile;
    pFile = fopen(fileName, "r");

    if (pFile == NULL) { 
        printf("Error! Could not open file\n"); 
        exit(-1);
    } 
    int i = 0;
    while (fscanf(pFile, "%d%d%d", &proc[i].id, &proc[i].arrivaltime, &proc[i].runtime) != EOF) {
        proc[i].starttime = 0;
        proc[i].endtime = 0;
        i++;
    }
    fclose(pFile);
    return i;
}

void first_come_first_served (char argv[14]) {
    char readFileName[14]= "";
    strcat(readFileName, argv); 
  
    int numberOfProcesses = read_file(readFileName);
  
    char writeFileName[] = "FCFS";
    strcat(writeFileName, readFileName);

    FILE *FCFSfile;

    FCFSfile = fopen(writeFileName, "w");
    // YOUR CODE FOR FCFS HERE
   

    fclose(FCFSfile);
}


void shortest_remaining_time (char argv[14]) {

    char readFileName[14]= "";
    strcat(readFileName, argv);    
  
    int numberOfProcesses = read_file(readFileName);
  
    char writeFileName[] = "STRN";
    strcat(writeFileName, readFileName);
    
    FILE *STRNfile; 

    STRNfile = fopen(writeFileName, "w");
   // YOUR CODE FOR SRTN HERE
    
    fclose(STRNfile);
}


int main(int argc, char *argv[]) {

    int i = 0;
    char readFileName0[14];

    /* Run scheduling algorithms */
    
    // how the output is supposed to look
    // printf("Process %d started at time %d and finished at time %d\n", proc[i].id, proc[i].starttime, proc[i].endtime);
    
    first_come_first_served(argv[1]);

    shortest_remaining_time(argv[1]);    

    return 0;
}