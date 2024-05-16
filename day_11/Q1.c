/*
Execute "wc" command from your program (using fork() + exec()).
The command should read data from the ﬁle "in.txt" (instead of terminal)
and output should be displayed on terminal.
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int main() {
	int ret2, err2, s2,fd;
	printf("parent started!\n");

	// run "wc" command
	ret2 = fork();
	if(ret2 == 0) {
		// dup pipe read fd to stdin
		fd = open("in.txt",O_RDONLY);
		close(0);
		dup(fd);
		close(fd);
        
		// in  redirection
		fd = read("in.txt", O_CREAT | O_TRUNC | O_WRONLY, 0644);
		dup2(fd, 0); // close stderr and copy fd on stderr
		close(fd);

		err2 = execlp("wc", "wc",NULL);
		if(err2 < 0) {
			perror("exec() failed to execute wc cmd");
			_exit(2);
		}
	}
     else
	// close pipe both ends in parent (no write no read)
	waitpid(-1, &s2, 0);
	printf("parent completed!\n");
	return 0;
}

