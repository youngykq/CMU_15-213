#include<stdio.h>

int expr1(int x){
	return !(x ^ ~0);
}

int expr2(int x){
	return !(x ^ 0);
}

int expr3(int x){
	return !((x & 0xFF) ^ 0xFF); 
}

int expr4(int x){
	return !((x>>24) ^ 0);
}

int main(void){
	printf("%d\n",expr1(-1));
	printf("%d\n",expr2(0));
	printf("%d\n",expr3(0xFF));
	printf("%d\n",expr4(0xFFFFFF));
	return 0;
}
