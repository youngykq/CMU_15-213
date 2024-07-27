#include<stdio.h>
#include<limits.h>

int factor(void);

int main(void){
	printf("%d\n",factor());
	return 0;
}

int factor(void){
	int res= 1;
	int n = 1;
	while(res <= INT_MAX){
		res *= n;
		n++;
	}
	return n-2;
}
