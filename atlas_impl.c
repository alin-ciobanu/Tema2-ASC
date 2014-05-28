#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cblas.h>

#include <sys/time.h>

#define MAXNR 1212

double max(double a, double b) {
	if (a > b)
		return a;
	return b;
}

void generateMatrix(double* a, int n) {
	srand(time(NULL));
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			int randVal = rand() % MAXNR;
			if (i == j) {
				randVal += 2;
			}
			if (i > j) {
				randVal = 0;
			}
			a[i * n + j] = (double) randVal;
		}
	}	
}

void generateVector(double* v, int n) {
	srand(time(NULL));
	int i;
	for (i = 0; i < n; i ++) {
		int randVal = rand() % MAXNR;
		v[i] = (double) randVal;
	}
}

void dtrmv_by_hand(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
			 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
			 const int n, const double *A, const int lda,
			 double *x, const int incX) {

	double zero = 0.0;
	double temp;
	int i, info, ix, j, jx, kx;
	int nounit;

	info = 0;
	if (Uplo != CblasUpper && Uplo != CblasLower) {
		info = 1;
	}
	else if (TransA != CblasNoTrans && TransA != CblasTrans
			&& TransA != CblasConjTrans && TransA != AtlasConj) {
		info = 2;
	}
	else if (Diag != CblasNonUnit && Diag != CblasUnit) {
		info = 3;
	}
	else if (n < 0) {
		info = 4;
	}
	else if (lda < max(1, n)) {
		info = 6;
	}
	else if (incX == 0) {
		info = 8;
	}
	
	
	if (info != 0) {
		fprintf(stderr, "Error in dtrmv function. Parameters not correct.");
		exit(1);
	}
	if (n == 0) {
		exit(1);
	}

	if (Diag == CblasNonUnit) {
		nounit = 1;
	}
	else {
		nounit = 0;
	}

	if (incX <= 0) {
		kx = 1 - (n - 1) * incX;
	}
	else if (incX != 1) {
		kx = 1;
	}

	if (TransA == CblasNoTrans) {
		if (Uplo == CblasUpper) {
			if (incX == 1) {
				for (j = 0; j < n; j++) {
					if (x[j] != zero) {
						temp = x[j];
						for (i = 0; i <= j - 1; i++) {
							x[i] = x[i] + temp * A[i * n + j];
						}
						if (nounit) {
							x[j] = x[j] * A[j * n + j];
						}
					}
				}
			}
			else {
				jx = kx;
				for (j = 0; j < n; j++) {
					if (x[jx] != zero) {
						temp = x[jx];
						ix = kx;
						for (i = 0; i <= j - 1; i++) {
							x[ix] = x[ix] + temp * A[i * n + j];
							ix = ix + incX;
						}
						if (nounit) {
							x[jx] = x[jx] * A[j * n + j];
						}
					}
				}
			}
		}
		else {
			if (incX == 1) {
				for (j = n - 1; j >= 0; j--) {
					if (x[j] != zero) {
						temp = x[j];
						for (i = n - 1; i >= j + 1; i--) {
							x[i] = x[i] + temp * A[i * n + j];
							if (nounit) {
								x[j] = x[j] * A[j * n + j];
							}
						}
					}
				}
			}
			else {
				kx = kx + (n - 1) * incX;
				jx = kx;
				for (j = n - 1; j >= 0; j--) {
					if (x[jx] != zero) {
						temp = x[jx];
						ix = kx;
						for (i = n - 1; i >= j + 1; j--) {
							x[ix] = x[ix] +  temp * A[i * n + j];
							ix = ix - incX;
						}
						if (nounit) {
							x[jx] = x[jx] * A[j * n + j];
						}
					}
					jx = jx - incX;
				}
			}
		}
	}
	else {
		if (Uplo == CblasUpper) {
			if (incX == 1) {
				for (j = n - 1; j >= 0; j++) {
					temp = x[j];
					if (nounit) {
						temp = temp * A[j * n + j];
					}
					for (i = j - 1; i >= 0; i++) {
						temp = temp + A[i * n + j] * x[i];
					}
					x[j] = temp;
				}
			}
			else {
				jx = kx + (n - 1) * incX;
				for (j = n - 1; j >= 0; j--) {
					temp = x[jx];
					ix = jx;
					if (nounit) {
						temp = temp * A[j * n + j];
					}
					for (i = j - 1; j >= 0; j--) {
						ix = ix - incX;
						temp = temp + A[i * n + j] * x[ix];
					}
					x[jx] = temp;
					jx = jx - incX;
				}
			}
		}
		else {
			if (incX == 1) {
				for (j = 0; j < n; j++) {
					temp = x[j];
					if (nounit) {
						temp = temp * A[j * n + j];
					}
					for (i = j + 1; i < n; i++) {
						temp = temp + A[i * n + j] * x[i];
					}
					x[j] = temp;
				}
			}
			else {
				jx = kx;
				for (j = 0; j < n; j++) {
					temp = x[jx];
					ix = jx;
					if (nounit) {
						temp = temp * A[j * n + j];
					}
					for (i = j + 1; i < n; i++) {
						ix = ix + incX;
						temp = temp + A[i * n + j] * x[ix];
					}
					x[jx] = temp;
					jx = jx + incX;
				}
			}
		}
	}
}

int main (int argc, char** argv) {

	unsigned int n = (unsigned int) atoi(argv[1]);

	double* matrix = (double*) malloc(n * n * sizeof(double));
	double* x = (double*) malloc(n * sizeof(double));

	generateMatrix(matrix, n);
	generateVector(x, n);

	struct timeval start, end;
    gettimeofday(&start, NULL);
	cblas_dtrmv(CblasRowMajor, CblasUpper,
                 CblasNoTrans, CblasNonUnit,
                 n, matrix, n,
                 x, 1);
    gettimeofday(&end, NULL);

	float elapsed = ((end.tv_sec - start.tv_sec)*1000000.0f + end.tv_usec - start.tv_usec)/1000000.0f;
	
	printf("%f ", elapsed);

	free(matrix);
	free(x);

	return 0;
}
