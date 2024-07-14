#include<stdio.h>

typedef unsigned float_bits;

float_bits float_i2f(int i);

int main(void){
	int i = 0;
	printf("0x%.2x\n",float_i2f (i));
	return 0;
}

float_bits float_i2f(int i){
	unsigned sign = i >> 31 & 0x1;
	unsigned exp = i >> 23 & 0xFF;
	unsigned frac = i & 0x7FFFFF;
	unsigned bias = 0x7F;
	unsigned E,M;
	float_bits num;
	if(exp == 0){
		/*Denoramlized*/
		M = frac;	
	}else{
		/*Normalized*/
		M = frac | 0x8000000;
	}
	return sign << 31 | exp << 23 | M;	
}
