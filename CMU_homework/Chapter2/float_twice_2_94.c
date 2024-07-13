#include<stdio.h>

typedef unsigned float_bits;

float_bits float_absval(float_bits f);

int main(void){
	float_bits f1 = 0x40000000;
	printf("0x%.2x\n",float_absval (f1));
	return 0;
}

float_bits float_absval(float_bits f){
	unsigned sign = f >> 31;
	unsigned exp = f >> 23 & 0xFF;
	unsigned frac = f & 0x7FFFFF;
	if(exp == 0xFF && frac != 0)
		return f;
	else if(exp == 0)
		return sign << 31| exp << 23 | frac << 1;
	else if(exp ==0xFF && frac == 0 )
		return f;
	else if(exp == 0xFF - 1){
		/*2 ^ 254 mult 2 will be 255,so the exp will be 0xFF, it is a +oo */
		exp = 0xFF;
		frac = 0;
		return sign << 31 | exp << 23 | frac;
	}
	else
		return sign << 31 | (exp + 1) << 23 | frac;	
	
}
