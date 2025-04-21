#define N 16
typedef int fix_matrix[N][N];

int fix_prod_ele(fix_matrix A,fix_matrix B,long i,long k){
	long mult_sum = 0;
	for(long j = 0;j < N;j++){
		mult_sum += A[i][j] * B[j][k];
	}
	return mult_sum;
}
