#include<stdio.h>

unsigned rotate_left(unsigned x,int n);

int main(void){
	unsigned x = 0x12345678;
	printf("0x%.2x\n",rotate_left(x,0));
	return 0;
}
unsigned rotate_left(unsigned x,int n){
	unsigned head = x >> ((sizeof(int) << 3) - n);
	unsigned tail = x << n;
	unsigned final = tail | head;
	return final;
}
