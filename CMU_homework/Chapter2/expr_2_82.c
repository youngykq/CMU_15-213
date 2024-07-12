#include<stdio.h>
#include<stdlib.h>

int expr1();
int expr2();
int expr3();
int expr4();
int expr5();

int main(void){
	printf("%d\n",expr1());
	printf("%d\n",expr2());
	printf("%d\n",expr3());
	printf("%d\n",expr4());
	printf("%d\n",expr5());
	return 0;
}
int expr1(){
	int x = random();
	int y = random();
	return (x < y) == (-x > -y);
	/*return 0 ,because -Tmin still equal to Tmin*/
}

int expr2(){
	int x = random();
	int y = random();
	return ((x + y) << 4) + y - x == 17 * y + 15 * x;
	/*return 1,because commulative*/
}

int expr3(){
	int x = random();
	int y = random();
	return ~x + ~y + 1 == ~(x + y);
	/*return 1
	 *~x + ~y + 1 - 1 + 1 => -x + -y -1 => -(x + y) - 1; 
	 * ~(x + y) + 1 - 1 => -(x + y) - 1;
	 * */
}
int expr4(){
	int x = random();
	int y = random();
	unsigned ux = (unsigned)x;
	unsigned uy = (unsigned)y;
	return(ux - uy) == -(unsigned)(y - x);
	/*return 1
	 * ux - uy == -(unsigned)(y - x)
	 * ux -uy == unsingnd(x - y)*/
}
int expr5(){
	int y = random();
	return (x>>2) << 2 <= x;
	/*return 1 */
}
