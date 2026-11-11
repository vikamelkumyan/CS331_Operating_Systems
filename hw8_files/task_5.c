#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(void){
	int fd;
	ssize_t n;
	off_t size;

	fd = open("sparse.bin", O_WRONLY|O_CREAT|O_TRUNC, 0644);
	if (fd < 0){
		perror("open");
		exit(1);
	}

	n = write(fd, "START", 5);
	if (n != 5){
		perror("write");
		close(fd);
		exit(1);
	}

	if (lseek(fd, 1024*1024, SEEK_CUR) < 0){
		perror("lseek");
		close(fd);
		exit(1);
	}

	n = write(fd, "END", 3);
	if (n != 3){
		perror("write");
		close(fd);
		exit(1);
	}

	if (close(fd) < 0){
		perror("close");
		exit(1);
	}

	fd = open("sparse.bin", O_RDONLY);
	if (fd < 0){
		perror("open");
		exit(1);
	}

	size = lseek(fd, 0, SEEK_END);
	if (size < 0){
		perror("lseek");
		close(fd);
		exit(1);
	}

	// The 1 MiB gap we skipped with lseek was never written, so the file
	// system does not allocate disk blocks for it (it is a "hole").
	// Reading the hole returns zeros, so the apparent size includes it,
	// but du counts only the blocks actually stored: the ones holding
	// "START" and "END". That's why du is much smaller than the size.
	printf("Apparent file size: %ld bytes\n", size);

	if (close(fd) < 0){
		perror("close");
		exit(1);
	}
	return 0;
}
