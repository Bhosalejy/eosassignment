#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

// p2 -- server
int main() {
	int fd, fd1, cnt;
	int num1, num2;
	int res;
	fd = open("/tmp/desd_fifo", O_RDONLY);
	if(fd < 0) {
		perror("open() failed");
		_exit(1);
	}

	printf("waiting for data...\n");
	cnt = read(fd, &num1, sizeof(num1));
	cnt = read(fd, &num2, sizeof(num2));
	printf("numbers received...\n");
    
	fd1 = open("/tmp/desd_fifo", O_WRONLY);
    res = num1 + num2;
	if(fd1 < 0) {
		perror("open() failed");
		_exit(1);
	}
	cnt = write(fd1, &res, sizeof(res));
	close(fd);
	close(fd1); 
	return 0;
}


