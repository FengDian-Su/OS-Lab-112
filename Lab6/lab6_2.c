#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	if (fork()==0) {
		printf("I'm child process E\n");
		printf("Pid: %d, parent pid: %d\n", getpid(), getppid());
		return 0;
	}
	wait(NULL);
	if (fork()==0) {
		printf("I'm child process D\n");
		printf("Pid: %d, parent pid: %d\n", getpid(), getppid());
		return 0;
	}
	wait(NULL);
	if (fork()==0) {
		if (fork()==0) {
			printf("I'm child process C\n");
			printf("Pid: %d, parent pid: %d\n", getpid(), getppid());
			return 0;
		}
		wait(NULL);
		printf("I'm child process B\n");
		printf("Pid: %d, parent pid: %d\n", getpid(), getppid());
		return 0;
	}
	wait(NULL);
	printf("I'm parent process A\n");
	printf("Pid: %d, parent pid: %d\n", getpid(), getppid());
	return 0;
}
