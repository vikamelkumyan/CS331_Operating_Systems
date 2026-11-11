#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(void){
	int fd;
	char *text = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	ssize_t n;
        ssize_t total = 0;
        ssize_t len = strlen(text);
	off_t size;
        char buf[64];

	fd = open("data.txt",O_WRONLY|O_CREAT|O_TRUNC, 0644);
	if (fd < 0){
		perror("open");
		exit(1);
	}
        while (total < len){
                n = write(fd, text + total, len - total);
                if (n < 0){
                        perror("write");
                        close(fd);
                        exit(1);
                }
                total += n;
        }
        if (close(fd) < 0){
                perror("close");
                exit(1);
        }
	fd = open("data.txt", O_RDWR);
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
        printf("Size: %ld\n", size);

        if (ftruncate(fd, 10) < 0){
		perror("ftruncate");
		close(fd);
		exit(1);
	}
        size = lseek(fd, 0, SEEK_END);
        if (size < 0){
                perror("lseek");
                close(fd);
                exit(1);
        }
        printf("New size: %ld\n", size);
        if (lseek(fd, 0, SEEK_SET) < 0){
                perror("lseek");
                close(fd);
                exit(1);
        }
        n = read(fd, buf, sizeof(buf));
        if (n < 0){
                perror("read");
                close(fd);
                exit(1);
        }
        if (write(1, buf, n) != n){
                perror("write");
                close(fd);
                exit(1);
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
