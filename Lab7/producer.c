#include<fcntl.h>
#include<stdio.h>
#include<sys/mman.h>
#include<unistd.h>

#define NAME "/myShareMemory"
#define SMSIZE 1024

int main() {
	int fd = shm_open(NAME, O_CREAT | O_RDWR, 0666);
	if (fd == -1) {
		perror("fail open create sm\n");
		return 1;
	}
	if (ftruncate(fd, SMSIZE) == -1) {
		perror("fail resize\n");
		return 1;
	}
	void *map_addr = mmap(NULL, 1024, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if (map_addr == MAP_FAILED) {
		perror("fail create map\n");
		return 1;
	}
	char *ptr, buffer[SMSIZE];
	ptr = map_addr;
	printf("Enter a message:");
	fgets(buffer, SMSIZE, stdin);
	sprintf(ptr, "%s", buffer);
	
	if (munmap(map_addr, 1024) == -1) {
		perror("failed to unmap\n");
		return 1;
	}
	if (close(fd) == -1) {
		perror("failed close sm\n");
		return 1;
	}
	return 0;
}
