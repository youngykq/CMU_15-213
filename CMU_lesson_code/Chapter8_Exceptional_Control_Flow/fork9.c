#include<stdio.h>
#include<wait.h>
#include<errno.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main(void){
	int child_status;
	if(fork() == 0){
		printf("HC\n");
		exit(0);
	}else{
		/*Parent process*/
		printf("HP");
		wait(&child_status);
		printf("CT");	
	}
	printf("Bye\n");
	exit(0);
}
