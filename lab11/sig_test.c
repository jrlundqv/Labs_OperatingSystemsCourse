#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
void my_routine( ) {
     printf("You can't quite the program by using Ctrl C..........\n");

}
int main( ) {
     signal(SIGINT, my_routine);
     printf("Entering infinite loop...\n");
     while(1) {
        sleep(10);
     } 
     printf("Never get there\n");
}
