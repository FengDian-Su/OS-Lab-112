#include<fcntl.h>
#include<stdio.h>
#include<sys/mman.h>

#define NAME "/myShareMemory"
#define SMSIZE 1024

int main() {
	int fd = shm_open(NAME, O_RDONLY, 0666);
	if (fd == -1) {
		perror("fail open create sm\n");
		return 1;
	}
	char *map_addr = mmap(NULL, 1024, PROT_READ, MAP_SHARED, fd, 0);
	if (map_addr == MAP_FAILED) {
		perror("fail read map\n");
		return 1;
	}
	printf("Message:");
	printf("%s", map_addr);
	return 0;
}
