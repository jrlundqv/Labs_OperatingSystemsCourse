#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PageFrame{
     int Id; /* Page ID */
     int ArrivalTime; /* Time that the page arrives */
     int LastRefTime; /* the Last time that the page was refered in the past */
     int Rbit; /* Referenced(R) bit */
     int Mbit; /* Modified(M) bit */
};
struct PageFrame page[100];
void first_in_first_out(){
  /* Your code for FIFO algorithm here */
}

void least_recently_used(){
  /* Your code for LRU algorithm here */
}

void second_chance(){
  /* Your code for Second Chance algorithm here */
}

int main(){
   
     FILE *pFile= fopen("Testcase0.txt", "r");
     if (pFile == NULL) { 
        printf("Error! Could not open file\n"); 
        exit(-1);
    } 
    int i = 0;
    printf("Page\tArrival\tLastRef\tRbit\tMbit\n");
    while (fscanf(pFile, "%d%d%d%d%d", &page[i].Id, &page[i].ArrivalTime, &page[i].LastRefTime, &page[i].Rbit, &page[i].Mbit) != EOF){ 
        printf("%d\t%d\t%d\t%d\t%d\n", page[i].Id, page[i].ArrivalTime, page[i].LastRefTime, page[i].Rbit, page[i].Mbit);       
        i++;  
     }

    /* Run page replacement algorithms */
  printf("First-in-First-out...\n");
  first_in_first_out();

  printf("Least-Recently-Used...\n");
  least_recently_used();


  printf("Second-Chance...\n");
  second_chance();


  return 0;
}