#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(void){
        char src[256], dst[256];
        ssize_t n;
        char *msg1 = "Enter the source path: ";
        char *msg2 = "Enter the destination path: ";
	int fd_1;
	int fd_2;
	char buf[1024];
        long total = 0;

        n = write(1, msg1, strlen(msg1));
        if (n == -1){
                perror("write");
                exit(1);
        }
        n = read(0, src, sizeof(src));
        if (n<=0){
                perror("read");
                exit(1);
        }
        src[n-1] = 0;

        n = write(1, msg2, strlen(msg2));
        if (n == -1){
                perror("write");
                exit(1);
        }
        n = read(0, dst, sizeof(dst));
        if (n<=0){
                perror("read");
                exit(1);
        }
        dst[n-1] = 0;

	fd_1 = open(src, O_RDONLY);
	if (fd_1 < 0){
		perror("open");
		exit(1);
	}

	fd_2 = open(dst, O_WRONLY|O_CREAT|O_TRUNC, 0644);
	if (fd_2 < 0){
		perror("open");
		close(fd_1);
		exit(1);
	}

        while ((n = read(fd_1, buf, sizeof(buf))) > 0){
                if (write(fd_2, buf, n) != n){
                        perror("write");
                        close(fd_1);
                        close(fd_2);
                        exit(1);
                }
                total += n;
        }
        if (n < 0){
                perror("read");
                close(fd_1);
                close(fd_2);
                exit(1);
        }
	if (close(fd_1) < 0){
		perror("close");
		exit(1);
	}
	if (close(fd_2) < 0){
		perror("close");
		exit(1);
	}
	printf("Total number of bytes copied %ld \n", total);
        return 0;
}
