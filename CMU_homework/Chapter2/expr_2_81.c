#include<stdio.h>

int expr1(int k);

int expr2(int j,int k);


int main(void){
	int a = expr1(16);
	int b = expr2(15,1);
	printf("%.2x %.2x\n",a,b);
	return 0;
}

int expr1(int k){
	int w = sizeof(int) << 3;
	int Tmin = 1<<31;
	return Tmin >> (w - k);
}

int expr2(int j, int k){
	int w = sizeof(int) << 3;
	int Tmin = 1 << 31;
	unsigned Utmin = (unsigned) Tmin;
	return Utmin >> (w - k - j);
}
