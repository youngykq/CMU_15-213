#include<stdio.h>

int divide_power2(int x,int k);

int main(void){
	int a = divide_power2(-12340,4);
	int b = divide_power2(-12340,8);
	int c = divide_power2(64,4);
	printf("%d %d %d\n",a,b,c);
	return 0;
}
int divide_power2(int x,int k){
/* calc x/2^k
 * 2s complement divide:x/2^k => (x + (1<<k) - 1) >> k*/
	int sign_x = x >> ((sizeof(int)<<3) - 1);
	//thai is right: int sign_x = x >> 31 & 1;
	int neg_divi = (x + (1<<k) - 1) >> k;
	int pos_divi = x >> k;
	return ((!sign_x + ~0) & neg_divi) | (~sign_x & pos_divi);
}
