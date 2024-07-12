#include<stdio.h>

int bad_int_size_is_32();
int bad_int_size_is_32_for_16_bit();
int main(void){
	printf("%d\n",bad_int_size_is_32());
	printf("%d\n",bad_int_size_is_32_for_16_bit());
	return 0;
}
int bad_int_size_is_32(){
	int set_msb = 1 << 31;
	/*int beyond_msb = 1 << 32; wrong operate!*/
	int beyond_msb = set_msb << 1;
	return set_msb && !beyond_msb;
}

int bad_int_size_is_32_for_16_bit(){
	int set_msb = 1 << 15;
	int beyond_msb = set_msb << 15;
	int third = beyond_msb << 2;
	return set_msb && beyond_msb && !third;
}
