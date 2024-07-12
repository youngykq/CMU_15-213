#include<stdio.h>

int lower_one_mask(int n);
int main(void){
	int n = 6;
	printf("0x%8x\n",lower_one_mask(n));
	return 0;
}
int lower_one_mask(int n){
	int w = sizeof(int) << 3;
	return (unsigned) -1 >> (w - n);
}
