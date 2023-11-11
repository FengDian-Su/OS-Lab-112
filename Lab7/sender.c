#include<fcntl.h>
#include<mqueue.h>
#include<stdio.h>
#include<string.h>

#define NAME "/myMsgQueue"
#define MAX_MSGSIZE 1000

int main() {
	mqd_t mqd = mq_open(NAME, O_WRONLY | O_CREAT, 0644, NULL);
	if (mqd == -1) {
		perror("open or create mq fail\n");
		return 1;
	}
	
	while (1) {
		printf("Send to receiver: \n");
		char buffer[MAX_MSGSIZE];
		for (int i=0;i<sizeof(buffer);i++)
			buffer[i]='\0';
		printf("> ");
		fgets(buffer, MAX_MSGSIZE, stdin);
		int send = mq_send(mqd, buffer, strlen(buffer)+1, 0);
		if (send == -1) {
			perror("Failed to send a message\n");
			return 1;
		}
		else if (strcmp(buffer,"exit\n") == 0)
			return 0;
	}
	return 0;
}
