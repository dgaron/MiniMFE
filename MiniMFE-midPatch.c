// This file is generated from test alphabets program by code generator in alphaz
// To compile this code, use -lm option for math library.

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <omp.h>
#include <immintrin.h>
#include <malloc.h>

#include "external_functions.h"

// Common Macros
#define max(x, y)   ((x)>(y) ? (x) : (y))
#define MAX(x, y)	((x)>(y) ? (x) : (y))
#define min(x, y)   ((x)>(y) ? (y) : (x))
#define MIN(x, y)	((x)>(y) ? (y) : (x))
#define CEILD(n,d)  (int)ceil(((double)(n))/((double)(d)))
#define ceild(n,d)  (int)ceil(((double)(n))/((double)(d)))
#define FLOORD(n,d) (int)floor(((double)(n))/((double)(d)))
#define floord(n,d) (int)floor(((double)(n))/((double)(d)))
#define CDIV(x,y)    CEILD((x),(y))
#define div(x,y)    CDIV((x),(y))
#define FDIV(x,y)    FLOORD((x),(y))
#define LB_SHIFT(b,s)  ((int)ceild(b,s) * s)
#define MOD(i,j)   ((i)%(j))
#define mallocCheck(v,s,d) if ((v) == NULL) { printf("Failed to allocate memory for %s : size=%lu\n", "sizeof(d)*(s)", sizeof(d)*(s)); exit(-1); }
// Reduction Operators
#define RADD(x,y)    ((x)+=(y))
#define RMUL(x,y)    ((x)*=(y))
#define RMAX(x,y)    ((x)=MAX((x),(y)))
#define RMIN(x,y)    ((x)=MIN((x),(y)))

// Common functions for min and max
//functions for integer max
inline int __max_int(int x, int y){
	return ((x)>(y) ? (x) : (y));
}

inline short __max_short(short x, short y){
	return ((x)>(y) ? (x) : (y));
}

inline long __max_long(long x, long y){
	return ((x)>(y) ? (x) : (y));
}

inline unsigned int __max_unsigned_int(unsigned int x, unsigned int y){
	return ((x)>(y) ? (x) : (y));
}

inline unsigned short __max_unsigned_short(unsigned short x, unsigned short y){
	return ((x)>(y) ? (x) : (y));
}

//function for float max
inline float __max_float(float x, float y){
	return ((x)>(y) ? (x) : (y));
}

//function for double max
inline double __max_double(double x, double y){
	return ((x)>(y) ? (x) : (y));
}

//function for integer min
inline int __min_int(int x, int y){
	return ((x)>(y) ? (y) : (x));
}

inline short __min_short(short x, short y){
	return ((x)>(y) ? (y) : (x));
}

inline long __min_long(long x, long y){
	return ((x)>(y) ? (y) : (x));
}

inline unsigned int __min_unsigned_int(unsigned int x, unsigned int y){
	return ((x)>(y) ? (y) : (x));
}

inline unsigned short __min_unsigned_short(unsigned short x, unsigned short y){
	return ((x)>(y) ? (y) : (x));
}

inline unsigned long __min_unsigned_long(unsigned long x, unsigned long y){
	return ((x)>(y) ? (y) : (x));
}

inline float __min_float(float x, float y){
	return ((x)>(y) ? (y) : (x));
}

inline double __min_double(double x, double y){
	return ((x)>(y) ? (y) : (x));
}

//Local Function Declarations
float reduce_MiniMFE_T_1(long, int, int, float**);
float reduce_MiniMFE_T_1_SPLIT(int, long, int, int, float**);

//Memory Macros
#define A(i) A[i]
#define B(i) B[i]
#define W(i,j) W[i][j]
#define T(i,j) T[i][j]
#define H(i,j) H[MOD(i + j, N + 1)]

#define BLOCK_SIZE 1024

void MiniMFE(long N, float* A, float* B, float** W, float* score){
	///Parameter checking
	if (!((N >= 1))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
	//Memory Allocation
	int mz1, mz2;
	
	float* _lin_T = (float*)malloc(sizeof(float)*((N+1) * (N+1)));
	mallocCheck(_lin_T, ((N+1) * (N+1)), float);
	float** T = (float**)malloc(sizeof(float*)*(N+1));
	mallocCheck(T, (N+1), float*);
	for (mz1=0;mz1 < N+1; mz1++) {
		T[mz1] = &_lin_T[(mz1*(N+1))];
	}
	
	float* H = (float*)malloc(sizeof(float*)*(N+1));
	mallocCheck(H, (N+1), float*);

	{
		//Domain
		//{i,j|i+j==N && N>=1 && N>=i && i>=0}
		//{i,j|i+j==N+1 && N>=1 && N>=i && i>=1}
		//{i,j|i+j>=N+2 && N>=1 && N>=i && i>=0 && N>=j && j>=0 && i+j>=1}
		//{i0,i1|i1==N+1 && i0==N+1 && N>=1}
		//{i,j|i+j==N && N>=1 && N>=i && i>=0}
		//{i,j|i+j>=N+1 && N>=1 && N>=i && N>=j && i+j>=1}
		int i,j,ii,jj;

		H(N, N) = foo(A(N), B(N));
		T(N, N) = __min_float(W(N, N), H(N, N));
		H(N - 1, N - 1) = foo(A(N - 1), B(N - 1));
		T(N - 1, N - 1) = __min_float(W(N - 1, N - 1), H(N - 1, N - 1));
		H(N - 1, N) = __min_float(foo(A(N - 1), B(N)), __min_float(H(N, N), H(N - 1,N - 1)));
		T(N - 1, N) = __min_float(__min_float(H(N - 1, N), W(N - 1, N)), reduce_MiniMFE_T_1(N, N - 1, N, T));

		for (ii = N - 2; ii >= 0; ii -= BLOCK_SIZE) {
			for(jj = max(ii - BLOCK_SIZE + 3, 2); jj <= N; jj += BLOCK_SIZE) {
				for(i = ii; i >= max(ii - BLOCK_SIZE + 1, 0); --i) {
					H(i, i) = foo(A(i), B(i));
					T(i, i) = __min_float(W(i, i), H(i, i));
					H(i, (i + 1)) = __min_float(foo(A(i), B(i + 1)), __min_float(H(i + 1, i + 1), H(i, i)));
					T(i, (i + 1)) = __min_float(__min_float(H(i, i + 1), W(i, i + 1)), reduce_MiniMFE_T_1(N, i, i + 1, T));

					for(j = i + 2; j <= min(jj + BLOCK_SIZE - 1, N); ++j) {
						H(i, j) = bar((foo(A(i), B(j))) + (T(i + 1, j - 1)), H(i + 1, j), H(i, j - 1));

						T(i, j) = reduce_MiniMFE_T_1_SPLIT(BLOCK_SIZE, N, i, j, T);
						T(i, j) = __min_float(__min_float(H(i, j), W(i, j)), T(i, j));
					}
				}
			} // end jj
		} // end ii 
		*score = T(0, N);
	}
	
	//Memory Free
	free(_lin_T);
	free(T);
	
	free(H);
}

float reduce_MiniMFE_T_1_SPLIT(int bs, long N, int ip, int jp, float** T) {

	// If all entries are within a tile, do it normally
	if (jp - ip <= bs - 2) {
		return reduce_MiniMFE_T_1(N, ip, jp, T);
	}

	float reduceVar_left, reduceVar_mid, reduceVar_bottom;
	float __temp1__, __temp2__, __temp3__;
	int k;
	// ip to (ip + BLOCK_SIZE - 2)
	reduceVar_left = FLT_MAX;
	for(k = ip; k <= ip + bs - 2; ++k) {
		__temp1__ = (T(ip, k)) + (T(k + 1, jp)); 
		reduceVar_left = __min_float(reduceVar_left, __temp1__);
	}

	// (ip + BLOCK_SIZE - 1) to (jp - BLOCK_SIZE)
	reduceVar_mid = FLT_MAX;
	for(k = ip + bs - 1; k <= jp - bs; ++k) {
		__temp2__ = (T(ip, k)) + (T(k + 1, jp)); 
		reduceVar_mid = __min_float(reduceVar_mid, __temp2__);
	}

	// (jp - BLOCK_SIZE + 1) to (jp - 1)
	// max(jp - bs + 1, ip + bs - 2) adjusts for when BLOCK_SIZE - 1 < jp - ip < 2 * (BLOCK_SIZE - 1)
	reduceVar_bottom = FLT_MAX;
	for(k = max(jp - bs + 1, ip + bs - 2); k <= jp - 1; ++k) {
		__temp3__ = (T(ip, k)) + (T(k + 1, jp)); 
		reduceVar_bottom = __min_float(reduceVar_bottom, __temp3__);
	}

	return __min_float(__min_float(reduceVar_left, reduceVar_mid), reduceVar_bottom);
}

// Unchanged
float reduce_MiniMFE_T_1(long N, int ip, int jp, float** T){
	float reduceVar = FLT_MAX;
	{
		//Domain
		//{i,j,k|jp>=ip+1 && N>=jp && ip>=0 && N>=1 && N+jp>=ip+1 && j>=k+1 && N+j>=i+1 && i>=0 && k>=i && N>=k && N>=j && k>=-1 && j>=i+1 && ip==i && jp==j}
		int k;
		for(k = ip; k <= jp - 1; ++k) {
			float __temp__ = (T(ip, k)) + (T(k + 1, jp)); 
			reduceVar = __min_float(reduceVar, __temp__);
		}
	}
	return reduceVar;
}

//Memory Macros
#undef A
#undef B
#undef W
#undef T
#undef H


//Common Macro undefs
#undef max
#undef MAX
#undef min
#undef MIN
#undef CEILD
#undef ceild
#undef FLOORD
#undef floord
#undef CDIV
#undef FDIV
#undef LB_SHIFT
#undef MOD
#undef RADD
#undef RMUL
#undef RMAX
#undef RMIN
