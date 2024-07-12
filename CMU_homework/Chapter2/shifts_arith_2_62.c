#include<stdio.h>

int int_shifts_are_arithmetic();

int main(void){
	printf("%d\n",int_shifts_are_arithmetic());
	return 0;
}
int int_shifts_are_arithmetic(){
	int x = 1<<31;//Tmin
	return !((x>>31)+1);
}
