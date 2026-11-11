#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(void){
	ssize_t n;
	char *msg = "Enter the path to an existing text file: ";
	int fd;
	char path[256];
	off_t size;
	off_t i;
	char c;

        n = write(1, msg, strlen(msg));
        if (n == -1){
                perror("write");
                exit(1);
        }
        n = read(0, path, sizeof(path));
        if (n<=0){
                perror("read");
                exit(1);
        }
        path[n-1] = 0;

	fd = open(path, O_RDONLY);
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

        for (i = size - 1; i >= 0; i--){
                if (lseek(fd, i, SEEK_SET) < 0){
                        perror("lseek");
                        close(fd);
                        exit(1);
                }
                if (read(fd, &c, 1) != 1){
                        perror("read");
                        close(fd);
                        exit(1);
                }
                if (write(1, &c, 1) != 1){
                        perror("write");
                        close(fd);
                        exit(1);
		}
        }
        if (write(1, "\n", 1) != 1){
                perror("write");
                close(fd);
                exit(1);
        }
        if (close(fd) < 0){
                perror("close");
                exit(1);
        }

        return 0;
}
