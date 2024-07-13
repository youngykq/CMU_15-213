#include<stdio.h>

typedef unsigned float_bits;

float_bits float_negate(float_bits f);

int main(void){
	float_bits f = 0x7FFFFFFF;
	float_bits f2 = 0x7F1FFAFF;
	printf("0x%.2x\n",float_negate(f));
	printf("0x%.2x\n",float_negate(f2));
	return 0;
}

float_bits float_negate(float_bits f){
	unsigned sign = f >> 31;
	unsigned exp = f >> 23 & 0xFF;
	unsigned frac = f & 0x7FFFFF;
	if(exp == 0xFF && frac != 0)
		return f;
	else
		return (!sign << 31) | exp << 23 | frac;
}
