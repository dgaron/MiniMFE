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

//Memory Macros
#define A(i) A[i]
#define B(i) B[i]
#define W(i,j) W[i][j]
#define T(i,j) T[i][j]
#define H(i,j) H[i][j]

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
	
	float* _lin_H = (float*)malloc(sizeof(float)*((N+1) * (N+1)));
	mallocCheck(_lin_H, ((N+1) * (N+1)), float);
	float** H = (float**)malloc(sizeof(float*)*(N+1));
	mallocCheck(H, (N+1), float*);
	for (mz1=0;mz1 < N+1; mz1++) {
		H[mz1] = &_lin_H[(mz1*(N+1))];
	}

	{
		//Domain
		//{i,j|i+j==N && N>=1 && N>=i && i>=0}
		//{i,j|i+j==N+1 && N>=1 && N>=i && i>=1}
		//{i,j|i+j>=N+2 && N>=1 && N>=i && i>=0 && N>=j && j>=0 && i+j>=1}
		//{i0,i1|i1==N+1 && i0==N+1 && N>=1}
		//{i,j|i+j==N && N>=1 && N>=i && i>=0}
		//{i,j|i+j>=N+1 && N>=1 && N>=i && N>=j && i+j>=1}
		int c1,c2;

		H(N, N) = foo(A(N), B(N));
		T(N, N) = __min_float(W(N, N), H(N, N));
		H(N - 1, N - 1) = foo(A(N - 1), B(N - 1));
		T(N - 1, N - 1) = __min_float(W(N - 1, N - 1), H(N - 1, N - 1));
		H(N - 1, N) = __min_float(foo(A(N - 1), B(N)), __min_float(H(N, N), H(N - 1,N - 1)));
		T(N - 1, N) = __min_float(__min_float(H(N - 1, N), W(N - 1, N)), reduce_MiniMFE_T_1(N, N - 1, N, T));

		for(c1 = N; c1 >= 2; --c1) {
		 	H(c1 - 2, c1 - 2) = foo(A(c1 - 2), B(c1 - 2));
		 	T(c1 - 2, c1 - 2) = __min_float(W(c1 - 2, c1 - 2), H(c1 - 2, c1 - 2));
		 	H(c1 - 2, (c1 - 1)) = __min_float(foo(A(c1 - 2), B(c1 - 1)), __min_float(H(c1 - 1, c1 - 1), H(c1 - 2, c1 - 2)));
		 	T(c1 - 2, (c1 - 1)) = __min_float(__min_float(H(c1 - 2, c1 - 1), W(c1 - 2, c1 - 1)), reduce_MiniMFE_T_1(N, c1 - 2, c1 - 1, T));

		 	for(c2 = c1; c2 <= N; ++c2) {
		 	 	H(c1 - 2, c2) = bar((foo(A(c1 - 2), B(c2))) + (T(c1 - 1, c2 - 1)), H(c1 - 1, c2), H(c1 - 2, c2 - 1));
		 	 	T(c1 - 2, c2) = __min_float(__min_float(H(c1 - 2, c2), W(c1 - 2, c2)), reduce_MiniMFE_T_1(N, c1 - 2, c2, T));
		 	 }
		}
		*score = T(0, N);
	}
	
	//Memory Free
	free(_lin_T);
	free(T);
	
	free(_lin_H);
	free(H);
}
float reduce_MiniMFE_T_1(long N, int ip, int jp, float** T){
	float reduceVar = FLT_MAX;
	{
		//Domain
		//{i,j,k|jp>=ip+1 && N>=jp && ip>=0 && N>=1 && N+jp>=ip+1 && j>=k+1 && N+j>=i+1 && i>=0 && k>=i && N>=k && N>=j && k>=-1 && j>=i+1 && ip==i && jp==j}
		int c3;
		for(c3 = ip; c3 <= jp - 1; c3 += 1) {
			float __temp__ = (T(ip, c3)) + (T(c3 + 1, jp)); 
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
