#include<stdio.h>
unsigned srl(unsigned x,int k);
unsigned sra(int x,int k);
int main(void){
	unsigned test_unsigned = 1 << 31;
	int test_int = 1 << 31;
	if(srl(test_unsigned,31) == test_unsigned >> 31)
		printf("right! that is arth shift!\n");
	else
		printf("Wrong\n");
	if(sra(test_int,31) == test_int >> 31)
		printf("That is right!\n");
	else
		printf("Wrong!\n");
	return 0;
}
unsigned srl(unsigned x,int k){
	unsigned xsra = (int)x >> k;
	int w = sizeof(int) << 3;
	int mask = (~0 << (w - k));
	return xsra &~ mask;
}
unsigned sra(int x,int k){
	int xsrl = (unsigned) x >> k;
	int w = sizeof(int) >> 3;
	int mask = (~0 << (w - k));
	int Tmin = 1 << (w - 1);
	mask &= !(x & Tmin) - 1;
	return xsrl | mask;
}
