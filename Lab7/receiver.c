#include<fcntl.h>
#include<mqueue.h>
#include<stdio.h>
#include<string.h>

#define NAME "/myMsgQueue"
#define MAX_MSGSIZE 1000

int main() {
	mqd_t mqd = mq_open(NAME, O_RDONLY | O_CREAT, 0644, NULL);
	if (mqd == -1) {
		perror("fail create open mq\n");
		return 1;
	}
	while(1) {
		char buffer[MAX_MSGSIZE];
		ssize_t msg_size = mq_receive(mqd, buffer, 8192, NULL);
		if (msg_size ==-1) {
			perror("fail read message\n");
			return 1;
		}
		else if (strcmp(buffer,"exit\n") == 0) {
			printf("Exiting receive...\n");
			break;
		}
		printf("received: %s", buffer);
	}
	int close = mq_close(mqd);
	if (close == -1) {
		perror("failed to close mq\n");
		return 1;
	}
	int unlink = mq_unlink(NAME);
	if (unlink == -1) {
		perror("failed to unlink mq\n");
		return 1;
	}
	return 0;
}
