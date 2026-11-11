#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(void){
	int fd;
	ssize_t n;
	char *msg = "Enter a log line: ";
	char line[256];
        char entry[300];
        int len;
	off_t pos;

	fd = open("log.txt", O_WRONLY|O_CREAT|O_APPEND, 0644);
	if (fd < 0){
		perror("open");
		exit(1);
	}
	n = write(1, msg, strlen(msg));
	if (n < 0){
		perror("write");
		close(fd);
		exit(1);
	}
	n = read(0, line, sizeof(line)-2);
	if (n <= 0){
		perror("read");
		close(fd);
		exit(1);
	}
	if (line[n-1] != '\n'){
		line[n] = '\n';
		n++;
	}

	line[n] = 0;

	len = snprintf(entry, sizeof(entry), "PID=%d: %s", getpid(), line);
        if (len < 0){
                write(2, "snprintf failed\n", 16);
                close(fd);
                exit(1);
        }

        n = write(fd, entry, len);
        if (n != len){
                perror("write");
                close(fd);
                exit(1);
        }

	pos = lseek(fd, 0, SEEK_CUR);
	if (pos < 0){
		perror("lseek");
		close(fd);
		exit(1);
	}
	// O_APPEND moves the offset to the end of the file before each write,
	// then write() moves it forward by the bytes written, as usual.
	// So SEEK_CUR returns the new end of the file, which grows with every
	// appended entry.
	printf("File position: %ld\n", pos);
	if (close(fd)< 0){
		perror("close");
		exit(1);
	}
	return 0;
}
