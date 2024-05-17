#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

// p1 -- client
int main() {
	int fd, fd1, cnt,res;
	int num1, num2;
	fd = open("/tmp/desd_fifo", O_WRONLY); 
	if(fd < 0) {
		perror("open() failed");
		_exit(1);
	}

	printf("enter two numbers : ");
	scanf("%d %d", &num1, &num2);

	cnt = write(fd, &num1, sizeof(num1));
	cnt = write(fd, &num2, sizeof(num2));
    
	fd1 = open("/tmp/desd_fifo", O_RDONLY);

	if(fd1 < 0) {
		perror("open() failed");
		_exit(1);
	}
	cnt = read(fd1, &res, sizeof(res));
	printf("result : %d\n",res);
	close(fd);
	close(fd1); 
	return 0;
}

