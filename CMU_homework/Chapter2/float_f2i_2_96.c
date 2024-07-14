#include<stdio.h>

typedef unsigned float_bits;

float_bits float_f2i(float_bits f);

int main(void){
	float_bits f1 = 0x40000000;
	printf("0x%.2x\n",float_f2i (f1));
	return 0;
}

float_bits float_f2i(float_bits f){
	unsigned sign = f >> 31;
	unsigned exp = f >> 23 & 0xFF;
	unsigned frac = f & 0x7FFFFF;
	unsigned bias = 0x7F;
	int num;
	unsigned E;
	unsigned M;
	/*
	 *	consider postive numbers
	 *	case1: 0 <= f < 1
	 *		0 00000000 000..00000   ~  0 01111111 000..00000
	 *		get integer 0
	 *
	 *	case2: 1 <= f < 2^31
	 *		0 01111111 000..00000 ~ 0 (01111111+31) 000..00000
	 *		integer takes round to 0
	 *
	 *	case3: f >= 2^31
	 *		0 (01111111+31) 000..00000 ~ +oo
	 *		integer return 0x80000000
	 *
	 * */
	if(exp >= 0 && exp < bias)
		/*number less than 1*/
		num = 0;
	if(exp >= (bias+31))
		num = 0x80000000;
	else{
		E = exp - bias;
		M = frac | 0x8000000;
		if(E > 23)
			num = M << (E - 23);
		else{
			num = M >> (23 - E);
		}
	}
	return sign ? -num : num;
}
