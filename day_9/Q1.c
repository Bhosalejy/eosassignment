#include<stdio.h>
#include <signal.h>
#include <stdlib.h>


int main(){
int pid, signum;
  
/*
  printf("signum: ");
	gets(signum);

  printf("pid: ");
	gets(pid);


if (kill(pid, signum) == -1) {
    perror("Error sending signal");
    exit(EXIT_FAILURE);
} else {
    printf("Signal %d sent to process %d", signum, pid); }

return 0;
}
*/
printf("signum: ");
scanf("%d", &signum);
printf("pid: ");
scanf("%d", &pid);

if (kill(pid, signum) == -1) {
    perror("Error sending signal");
    exit(EXIT_FAILURE);
} else {
    printf("Signal %d sent to process %d",signum, pid);
	}
return 0;
}
