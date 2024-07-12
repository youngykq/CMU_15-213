#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
#include<assert.h>

void *calloc(size_t nmemb,size_t size);

int main(void){
	void *p = calloc(8,1);
//	printf("%p\n",p);
	assert(p != NULL);
	free(p);
	p = calloc(SIZE_MAX,2);
	assert(p == NULL);
	free(p);
	return 0;
}
void *calloc(size_t nmemb,size_t size){
	size_t blocksize = nmemb * size;
	if(!(nmemb && size))
		return NULL;
	if(blocksize/nmemb == size){
		void *p = malloc(blocksize);
		if(p != 0){
			memset(p,0,blocksize);
			return p;
		}
		else
			return NULL;
	}
	return NULL;
}
