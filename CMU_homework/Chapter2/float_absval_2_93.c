#include<stdio.h>

typedef unsigned float_bits;

float_bits float_absval(float_bits f);

int main(void){
	float_bits f1 = 0x8FFFFFFF;
	printf("0x%.2x\n",float_absval (f1));
	return 0;
}

float_bits float_absval(float_bits f){
	unsigned sign = f >> 31;
	unsigned exp = f >> 23 & 0xFF;
	unsigned frac = f & 0x7FFFFF;
	if(exp == 0xFF && frac != 0)
		return f;
	else
		return 0 << 31 | exp << 23 | frac;
	
}
