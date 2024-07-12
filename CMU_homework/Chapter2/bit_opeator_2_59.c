#include <stdio.h>
int bit_operator(int x,int y);
int main(void){
	int x = 0x89ABCDEF;
	int y = 0x76543210;
	printf("0x%.2x\n",bit_operator(x,y));
	return 0;
}

int bit_operator(int x,int y){
	return (x&0xFF)|(y&0xFFFFFF00);
}

