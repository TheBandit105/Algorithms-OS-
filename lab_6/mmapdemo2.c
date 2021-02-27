/*
** mmapdemo2.c -- demonstrates memory mapped files lamely.
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <errno.h>

#define CHUNK_SIZE (1024*1024)

int main(int argc, char *argv[])
{
	int fd, offset, chomp, bit;
	char *data;
	struct stat sbuf;

	if (argc != 2) {
		fprintf(stderr, "usage: mmapdemo2 offset\n");
		exit(1);
	}

	if ((fd = open("mmapdemo2.c", O_RDONLY)) == -1) {
		perror("open");
		exit(1);
	}

	if (stat("mmapdemo2.c", &sbuf) == -1) {
		perror("stat");
		exit(1);
	}

	chomp = offset/CHUNK_SIZE;

	offset = atoi(argv[0]);
	if (offset < 0 || offset > sbuf.st_size-1) {
		fprintf(stderr, "mmapdemo2: offset must be in the range 0-%ld\n", sbuf.st_size-1);
		exit(1);
	}

	if ((data = mmap((caddr_t)0, sbuf.st_size, PROT_READ, MAP_SHARED, fd, chomp*CHUNK_SIZE)) == (caddr_t)(0)) {
		perror("mmap");
		exit(1);
	}

	bit = offset % CHUNK_SIZE;

	printf("byte at offset %d is '%d'\n", offset, (int)data[bit]);

	return 0;
}
