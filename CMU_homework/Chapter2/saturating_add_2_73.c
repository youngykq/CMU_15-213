#include<stdio.h>
#include<limits.h>
int saturating_add(int x,int y);

int main(void){
	printf("%d\n",saturating_add(2100000000,1100000000));
	printf("%d\n",saturating_add(-2100000000,-1100000000));
	printf("%d\n",saturating_add(INT_MIN,INT_MIN));
	return 0;
}
int saturating_add(int x,int y){
	int Tmin = 1 << 31;
	int Tmax = Tmin - 1;
	int s = x + y;
	int neg_overflow = !(((x >> 31 & 1) ^ 1) ^ ((y >> 31 & 1) ^ 1) ^ ((s >> 31 & 1) ^ 0));
	int pos_overflow = !(((x >> 31 & 1) ^ 0) ^ ((x >> 31 & 1) ^ 0) ^ ((s >> 31 & 1) ^ 1));
	//return (~!neg_overflow + 1 | Tmin) | (!pos_overflow + ~0 & Tmax);
	return (~neg_overflow + 1 & Tmin) | (~pos_overflow + 1 & Tmax);
}
