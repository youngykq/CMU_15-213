#include<stdio.h>
#include<wait.h>
#include<errno.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main(void){
	if(fork() == 0){
		/*Child process*/
		printf("Child %d is terminated.\n",getpid());
		exit(0);
	}else{
		/*Parent process*/
		printf("Parent %d is terminted.\n",getppid());
		/*infinite loop*/
		while(1)
			;
	
	}

	exit(0);
}
