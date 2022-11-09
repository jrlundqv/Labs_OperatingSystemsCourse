// Simple implementation of receiving "HELLO" by using POSIX message queue APIs
#include <stdio.h>
#include <stdlib.h>
#include <mqueue.h>
#include <string.h>
#include <assert.h>


int main(){
    // open an existing message queue to read
    mqd_t mqd = mq_open ("/Introduction2OS", O_RDONLY);
    
    assert (mqd != -1);
    struct mq_attr attr;
    
    // Get the attributes of the queue message
    assert (mq_getattr (mqd, &attr) != -1);
    
    char *buffer = calloc (attr.mq_msgsize, 1);
    
    assert (buffer != NULL);
    
    int priority = 0; // used to get the priority of the message queue
    
    if ((mq_receive (mqd, buffer, attr.mq_msgsize, &priority)) == -1)
        printf ("Failed to receive message!\n");
    else
        // print the message and its priority
        printf ("Received Message '%s': Priority %u\n", buffer, priority);
    
    free (buffer);
    // free buffer
    buffer = NULL;
    // clean queue
    mq_close (mqd);
    // close after using
    return 0;
}
