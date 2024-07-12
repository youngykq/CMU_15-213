#include<stdio.h>
#include<stdlib.h>

void copy_int(int val,void *buf,int maxbytes);

int main(void){

	return 0;
}
void copy_int(int val,void *buf,int maxbytes){
	if(maxbytes >= sizeof(val))
		memcpy(buf,(void *)&val,sizeof(val));
}
