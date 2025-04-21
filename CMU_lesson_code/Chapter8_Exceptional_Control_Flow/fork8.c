#include<stdio.h>
#include<wait.h>
#include<errno.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main(void){
	if(fork() == 0){
		/*Child process*/
		printf("Child %d is running.\n",getpid());
		/*infinite loop*/
		while(1)
			;
		
	}else{
		/*Parent process*/
		printf("Parent %d is running.\n",getppid());
		exit(0);	
	}

	exit(0);
}
