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
	unsigned rest = f & 0x7FFFFFFF;
	unsigned exp = f >> 23 & 0xFF;
	unsigned frac = f & 0x7FFFFF;
	if(exp == 0xFF && frac != 0)
		return f;
	/*
	 *	floating point takes the rules ----"round to even"
	 *	so we only care the last 2 bits of frac ,such ax XXXXXXXX.YYYY00
	 *	case1:	00 => 0 just frac >> 1
	 *	case2: 	01 => 0 (round to even)just frac >> 1
	 *	case3:	10 => 1 just frac >> 1
	 *	case4:	11 =>1+1 (round to even) just frac >> 1 then plus 1
	 * */
	int addition = (frac & 0x3) == 0x3;
	
	if(exp == 0){
		/*Denoralized*/
		frac >>= 1;
		frac += addition;
	}
	else if(exp == 1 ){
		/*Normalized to Denormalized*/
		rest >>= 1;
		rest += addition;
		exp = rest >> 23 & 0xFF;
		frac = rest & 0x7FFFFF;
	}
	else 	
		/*Normalized*/
		exp -= 1;	
	return sign << 31 | exp << 23 | frac;	
}
