#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(void){
	char path1[256], path2[256];
	char *msg1 = "Enter the first file path: ";
	char *msg2 = "Enter the second file path: ";
	char buf1[1024], buf2[1024];
	ssize_t n, n1, n2, min, i;
	int fd1, fd2;
	off_t offset = 0;

	n = write(1, msg1, strlen(msg1));
	if (n == -1){
		perror("write");
		exit(1);
	}
	n = read(0, path1, sizeof(path1));
	if (n <= 0){
		perror("read");
		exit(1);
	}
	path1[n-1] = 0;

	n = write(1, msg2, strlen(msg2));
	if (n == -1){
		perror("write");
		exit(1);
	}
	n = read(0, path2, sizeof(path2));
	if (n <= 0){
		perror("read");
		exit(1);
	}
	path2[n-1] = 0;

	fd1 = open(path1, O_RDONLY);
	if (fd1 < 0){
		perror("open first file");
		exit(1);
	}
	fd2 = open(path2, O_RDONLY);
	if (fd2 < 0){
		perror("open second file");
		close(fd1);
		exit(1);
	}

	while (1){
		n1 = read(fd1, buf1, sizeof(buf1));
		if (n1 < 0){
			perror("read first file");
			close(fd1);
			close(fd2);
			exit(1);
		}
		n2 = read(fd2, buf2, sizeof(buf2));
		if (n2 < 0){
			perror("read second file");
			close(fd1);
			close(fd2);
			exit(1);
		}

		if (n1 == 0 && n2 == 0)
			break;

		min = (n1 < n2) ? n1 : n2;
		for (i = 0; i < min; i++){
			if (buf1[i] != buf2[i]){
				printf("Files differ at byte %ld\n", offset + i);
				close(fd1);
				close(fd2);
				exit(1);
			}
		}

		if (n1 != n2){
			printf("Files differ at byte %ld\n", offset + min);
			close(fd1);
			close(fd2);
			exit(1);
		}

		offset += n1;
	}

	if (close(fd1) < 0){
		perror("close");
		exit(1);
	}
	if (close(fd2) < 0){
		perror("close");
		exit(1);
	}
	printf("Files are identical\n");
	return 0;
}
