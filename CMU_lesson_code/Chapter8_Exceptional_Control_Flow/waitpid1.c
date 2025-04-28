#include<stdio.h>
#include<wait.h>
#include<errno.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
#define N 2

int main(void){
	int status,i;
	pid_t pid;
	/*Parent creates N children*/
	for(i = 0;i < N;i++)
		if((pid = fork()) == 0) /*Child*/
			exit(100 + i);
	
	/*Parent reaps N children in no particular order*/
	while((pid = waitpid(-1,&status,0) > 0)){
		if(WIFEXITED(status))
			printf("child %d terminated normally with exit status = %d\n",pid,WEXITSTATUS(status));
		else
			printf("child %d terminated abnormally\n",pid);
	}

	/*The only normal termination is if there are no more children*/
	if(errno != ECHILD)
		printf("waitpid error");

	exit(0);
}
