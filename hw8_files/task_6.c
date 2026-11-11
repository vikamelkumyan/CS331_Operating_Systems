#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(void){
        char *nums = "1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n";
	ssize_t n;
	int fd;
        char c;
        int newlines = 0;
        off_t pos = 0;
        char rest[256];
        ssize_t rest_len;
        char buf[256];

	fd = creat("numbers.txt", 0644);
	if (fd < 0){
		perror("creat");
		exit(1);
	}
	n = write(fd, nums, strlen(nums));
	if (n != (ssize_t)strlen(nums)){
		perror("write");
		close(fd);
		exit(1);
	}
	if (close(fd) < 0){
		perror("close");
		exit(1);
	}
	fd = open("numbers.txt", O_RDWR);
	if (fd < 0){
		perror("open");
		exit(1);
	}

        while (newlines < 3){
                if (read(fd, &c, 1) != 1){
                        perror("read");
                        close(fd);
                        exit(1);
                }
                pos++;
                if (c == '\n')
                        newlines++;
        }
        do {
                if (read(fd, &c, 1) != 1){
                        perror("read");
                        close(fd);
                        exit(1);
                }
        } while (c != '\n');

        rest_len = read(fd, rest, sizeof(rest));
        if (rest_len < 0){
                perror("read");
                close(fd);
                exit(1);
        }

        if (lseek(fd, pos, SEEK_SET) < 0){
                perror("lseek");
                close(fd);
                exit(1);
        }

        if (write(fd, "100\n", 4) != 4){
                perror("write");
                close(fd);
                exit(1);
        }
        if (write(fd, rest, rest_len) != rest_len){
                perror("write");
                close(fd);
                exit(1);
        }

        if (lseek(fd, 0, SEEK_SET) < 0){
                perror("lseek");
                close(fd);
                exit(1);
        }
        while ((n = read(fd, buf, sizeof(buf))) > 0){
                if (write(1, buf, n) != n){
                        perror("write");
                        close(fd);
                        exit(1);
                }
        }
        if (n < 0){
                perror("read");
                close(fd);
                exit(1);
        }

        if (close(fd) < 0){
                perror("close");
                exit(1);
        }
        return 0;
}
