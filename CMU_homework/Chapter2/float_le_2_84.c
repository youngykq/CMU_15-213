#include<stdio.h>
/*test the first parameter whether <= the second parameter or not*/
int float_le(float x,float y);
unsigned f2u(float x);

int main(void){
	printf("%d\n",float_le(0.0,-0.0));
	printf("%d\n",float_le(-1.0,2.0));
	printf("%d\n",float_le(-4.0,-0.0));
	printf("%d\n",float_le(2.0,-1.1));
	return 0;
}
int float_le(float x,float y){
	unsigned ux = f2u(x);
	unsigned uy = f2u(y);
	/*Get the sign bits*/
	unsigned sx = ux >> 31;
	unsigned sy = uy >> 31;

	/*Give an expression using only ux,uy,sx,sy*/
	return 	((ux<<1 == 0) &&  (uy<<1 == 0)) || /*both 0*/
		(!(ux ^ uy)) || /* ux == uy*/
		(sx & !sy) || /*x < 0,y>0 */
		((sx == 1 && sy == 1) && (ux<<1) >= (uy<<1)) || /*x<0,y<0*/
		((sx == 0 && sy == 0) && (ux<<1) <= (uy<<1));  /*x>0,y>0*/
}

unsigned f2u(float x){
	return *(unsigned *)&x;
}
