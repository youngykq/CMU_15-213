#include<stdio.h>

int any_odd_one(unsigned x);
int main(void){
	printf("%d\n",any_odd_one(0xAAAAAAAA));
	return 0;
}
int any_odd_one(unsigned x){
	int mask = 0x55555555;
	return !(x ^ mask);
}
