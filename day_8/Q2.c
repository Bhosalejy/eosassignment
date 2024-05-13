

#include<unistd.h>
#include<stdio.h>

int main(){
    int ret;
	int s, i, j;
	while(1){
	ret = fork();
	if(ret==0){
	for(i=1; i<=5; i++) {
			printf("child: %d\n", i);
			sleep(1);
		}
		_exit(0);
	}
	else if(ret== -1)
	   break;
	else{
       i++;
	   printf("child count: %d\n",i);
	}   
	}
	for(j=1;j<=i;i++)
	    wait(&s);
}
