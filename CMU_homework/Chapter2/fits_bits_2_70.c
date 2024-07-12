#include<stdio.h>

int fits_bits(int x,int n);

int main(void){
	printf("%d\n",fits_bits(13,4));
	return 0;
}
int fits_bits(int x,int n){
	return (((x >> 31) & 1) ^ 0) && (n == 32) || (((1 << n) & x) == 0);
}
