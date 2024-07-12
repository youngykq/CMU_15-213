#include<stdio.h>
unsigned replace_byte(unsigned x,int pos,unsigned char b);

int main(void){
	unsigned res = replace_byte(0x12345678,0,0xAB);
	printf("0x%.2x\n",res);
	return 0;
}
unsigned replace_byte(unsigned x,int pos,unsigned char b){
	b = (unsigned) b;
	unsigned mask = 0xFF << (pos << 3);
	return (x & ~mask) |(b << (pos << 3));
}
