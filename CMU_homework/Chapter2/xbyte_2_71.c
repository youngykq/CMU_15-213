#include<stdio.h>

typedef unsigned packed_t;

int xbyte(packed_t word,int bytenum);

int main (void){
	packed_t a = 0xff112233;
	printf("0x%.2x\n",xbyte(a,0));
	printf("0x%.2x\n",xbyte(a,1));
	printf("0x%.2x\n",xbyte(a,2));
	printf("0x%.2x\n",xbyte(a,3));
	return 0;
}
int xbyte(packed_t word,int bytenum){
	int one = (word >> (bytenum << 3)) << 24;
	return one >> 24;
}
