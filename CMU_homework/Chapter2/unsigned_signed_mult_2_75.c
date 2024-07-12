#include<stdio.h>

unsigned unsigned_high_prod(unsigned x,unsigned y);
unsigned another_unsigned_high_prod(unsigned x,unsigned y);
int signed_high_prod(int x,int y);

int main(void){

	return 0;
}
unsigned unsigned_high_prod(unsigned x,unsigned y){
	
	return
}
unsigned another_unsigned_high_prod(unsigned x,unsigned y){
	uint64_t z = (uint64_t)x * y;
	return z >> 32 & 0XFFFFFFFF;
}
int signed_high_prod(int x,int y){
	int64_t z = (int64_t)x * y;
	return z >> 32 & 0xFFFFFFFF;
}
