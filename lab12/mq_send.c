// Simple implementation of sending "HELLO" by using POSIX message queue APIs
#include <stdio.h>
#include <stdlib.h>
#include <mqueue.h>
#include <string.h>



int main(){
    // Create a new message queue

   mqd_t mqd = mq_open ("/Introduction2OS", O_CREAT | O_WRONLY, 0600, NULL);
    // check if message queue creation is succesful or not
    if (mqd == -1){
        perror ("mq_open");
        exit (1);
    }
    mq_send (mqd, "HELLO", 6, 15);
    // send a "HELLO" message using mq_send API
    // note that the size of this message is 6 including NULL at the end of the string
    // priority of the message is 15
    mq_close (mqd);
    // close after using
    return 0;
}
