#include<stdio.h>
#include<limits.h>

int tsub_ok(int x ,int y);

int main(void){
	printf("%d\n",tsub_ok(INT_MIN,INT_MIN));//0
	printf("%d\n",tsub_ok(INT_MAX,INT_MAX));//1
	printf("%d\n",tsub_ok(INT_MAX,INT_MIN));//0
	printf("%d\n",tsub_ok(INT_MIN,INT_MAX));//0
	printf("%d\n",tsub_ok(0,0));//1
	printf("%d\n",tsub_ok(0,-10));//1
	printf("%d\n",tsub_ok(-10,0));//1
	printf("%d\n",tsub_ok(-10,-10));//1
	printf("%d\n",tsub_ok(-10,3));//1
	printf("%d\n",tsub_ok(3,3));//1
	return 0;
}
int tsub_ok(int x ,int y){
	int s = x - y;
	int sign_x = x >> 31 & 1;
	int sign_y = y >> 31 & 1;
	int sign_s = s >> 31 & 1;
	int y_is_tmin = !(y ^ (1<<31));
	int x_is_tmin = !(x ^ (1<<31));
	/*if x>0,y>0,never overflow
	 * if x < 0,y < 0 and y is not equal Tmin ,never overflow*/
	int pos_over = (!sign_x) & sign_y & sign_s;
	int neg_over = sign_x & (!sign_x) & sign_s;
	return !x_is_tmin && !y_is_tmin && !pos_over && !neg_over;
}
