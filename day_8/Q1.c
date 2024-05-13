// one parent -- five child processes

#include<unistd.h>
#include<stdio.h>

int main(){
	int ret1, ret2, ret3, ret4, ret5;
	int s1, s2, s3, s4, s5, i;
	ret1 = fork();
	if (ret1 == 0){
        for(i=1; i<=5; i++) {
			printf("child: %d\n", i);
			sleep(1);
		}
		_exit(0);
	}	
    ret2 = fork();
    if (ret1 == 0){
        for(i=1; i<=5; i++) {
            printf("child: %d\n", i);
            sleep(1);
          }
          _exit(0);	
	}
	ret3 = fork();
	if (ret3 == 0){
        for(i=1;i<=5; i++){
            printf("child: %d\n",i);
			sleep(1);
		}
		   _exit(0);
	}

	ret4 = fork();
	if (ret4 == 0){
        for(i=1;i<=5; i++){
            printf("child: %d\n",i);
			sleep(1);
		}
		   _exit(0);
	}
    
	ret5 = fork();
	if (ret5 == 0){
        for(i=1;i<=5; i++){
            printf("child: %d\n",i);
			sleep(1);
		}
		   _exit(0);
	}
	else{
	  for(i=1; i<=10; i++) {
			printf("parent: %d\n", i);
			sleep(1);
			waitpid(ret1, &s1, 0);
			waitpid(ret2, &s2, 0);
			waitpid(ret3, &s3, 0);
			waitpid(ret5, &s4, 0);
			waitpid(ret5, &s5, 0);
	    }
	}

}	
