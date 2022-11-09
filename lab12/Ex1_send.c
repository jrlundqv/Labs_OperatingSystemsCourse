#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <string.h>

int main()
{
	mqd_t mqd = mq_open("/Ex1", O_CREAT | O_WRONLY);

	char message[] = "Exercise 1";

	mq_send(mqd, message, strlen(message), 0);

	mq_close(mqd);

	return 0;
}

