#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int global = 10;
int main()
{
	int local = 10;
	pid_t new_pid;
	new_pid = fork();
	
	switch(new_pid)
	{
		case -1:
			printf("fork error\n");
			break;
		case 0:
			printf("I'm child process\n");
			printf("Pid: %d\tparent pid: %d\n", getpid(), getppid());
			printf("global = %d, local = %d\n", global, local);
			global+=1;
			local+=1;
			printf("Finally print: pid = %d, parent id = %d, global = %d, local = %d\n",getpid(),getppid(),global,local);
			printf("\n");
			break;
		default:
			printf("I'm parent process\n");
			printf("Pid : %d\tparent pid : %d\n", getpid(), getppid());
			printf("global = %d, local = %d\n", global, local);
			printf("Finally print: pid = %d, parent id = %d, global = %d, local = %d\n",getpid(),getppid(),global,local);
			printf("\n");
			wait(NULL);
			break;
	}
	printf("\n");
	return 0;
}
