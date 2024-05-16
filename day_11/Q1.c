#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
int main() {
	int ret2, err2, s2,fd;
	int arr[2], ret;
	printf("parent started!\n");

	// create pipe
	ret = pipe(arr);
	if(ret < 0) {
		perror("pipe() failed");
		_exit(3);
	}
     

	// run "wc" command
	ret2 = fork();
	if(ret2 == 0) {
		// dup pipe read fd to stdin
		fd = open("in.txt",O_RDONLY);
		close(arr[1]);
		dup2(arr[0], 0);
		close(arr[0]);

		err2 = execlp("wc", "wc",NULL);
		if(err2 < 0) {
			perror("exec() failed to execute wc cmd");
			_exit(2);
		}
	}

	// close pipe both ends in parent (no write no read)
	close(arr[1]);
	close(arr[0]);
	waitpid(ret2, &s2, 0);
	printf("parent completed!\n");
	return 0;
}

