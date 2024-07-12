#include<stdio.h>
/*odd of ones*/
int odd_ones(unsigned x);

int main(void){
	unsigned x = 1;
	printf("%d\n",odd_ones(x));
	return 0;
}
int odd_ones(unsigned x){
	x ^= x >> 16;
	x ^= x >> 8;
	x ^= x >> 4;
	x ^= x >> 2;
	x ^= x >> 1;
	x &= 0x1;
	return x;
}
