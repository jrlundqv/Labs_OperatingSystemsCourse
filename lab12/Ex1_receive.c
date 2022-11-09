#include <stdio.h>
#include <stdlib.h>
#include <mqueue.h>
#include <string.h>

int main()
{
	mqd_t mqd = mq_open("/Ex1", O_RDONLY);

	struct mq_attr attr;

	mq_getattr(mqd, &attr);

	char *buffer = malloc(attr.mq_msgsize);

	unsigned int priority = 0;

	mq_receive(mqd, buffer, attr.mq_msgsize, &priority);

	printf("Received message '%s' with priority %u\n", buffer, priority);

	free(buffer);

	mq_close(mqd);

	return 0;
}
