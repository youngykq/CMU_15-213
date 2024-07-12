#include<stdio.h>

int mul3div4(int x);

int main(void){
	int a = mul3div4(3);
	printf("%d\n",a);
	return 0;
}
int mul3div4(int x){
	return ((x<<1) + x) >> 2;
}
