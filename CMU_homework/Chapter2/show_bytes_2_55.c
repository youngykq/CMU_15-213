#include<stdio.h>
typedef unsigned char* star_pointer;  
void show_bytes(star_pointer sp,size_t len);
int is_little_endain(star_pointer sp);

int main(void){
	int a = 0x12345678;
	show_bytes((star_pointer) &a,sizeof(int));
	if(is_little_endain((star_pointer) &a))
		printf("This is a little_endain System!\n");
	else
		printf("Big_endain System!\n");
	return 0;
}

void show_bytes(star_pointer sp,size_t len){
	for(int i = 0;i < len;i++)
		printf("%.2x",sp[i]);
	printf("\n");
}

int is_little_endain(star_pointer sp){
	if(sp[0] == 0x78 )
		return 1;
	else
		return 0;
}
