/*
 *	decode2:
 *		subq	%rdx,%rsi
 *		imulq	%rsi,%rdi
 *		movq	%rsi,%rax
 *		salq	$63,%rax
 *		sarq	$63,%rax
 *		xorq	%rdi,%rax
 *		ret
 * */

long decode2(long x,long y,long z){
	/*y = y - z;
	x *= y;
	long val = y;
	val <<= 63;
	val >>= 63;
	val ^= x;
	return val;*/
	long val = y -z;
	return (val * x) ^ (val << 63 >> 63);
}
