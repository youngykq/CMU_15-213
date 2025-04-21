long swap_add(long *xp,long *yp){
	long x = *xp;
	long y = *yp;
	*xp = y;
	*yp = x;
	return x + y;
}
