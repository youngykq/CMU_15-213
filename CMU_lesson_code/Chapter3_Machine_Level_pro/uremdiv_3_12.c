#include<stdio.h>

void uremdiv(unsigned long x,unsigned long y,unsigned long *qp,unsigned long *rp);

int main(void){

	return 0;
}

void uremdiv(unsigned long x,unsigned long y,unsigned long *qp,unsigned long *rp){
	unsigned long q = x / y;
	unsigned long r = x % y;
	*qp = q;
	*rp = r;
}
