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



///Global Variables
static float* A;
static float* B;
static float** W;
static float** T;
static float** H;
static float score;
static char _flag_score;
static char** _flag_T;
static char** _flag_H;


//Local Function Declarations
float reduce_MiniMFE_verify_T_1(long, int, int);
float eval_T(long, int, int);
float eval_H(long, int, int);
float eval_score(long);

//Memory Macros
#define A(i) A[i]
#define B(i) B[i]
#define W(i,j) W[i][j]
#define T(i,j) T[i][j]
#define H(i,j) H[i][j]
#define _flag_T(i,j) _flag_T[i][j]
#define _flag_H(i,j) _flag_H[i][j]

void MiniMFE_verify(long N, float* _local_A, float* _local_B, float** _local_W, float* _local_score){
	///Parameter checking
	if (!((N >= 1))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
	//Copy to global
	A = _local_A;
	B = _local_B;
	W = _local_W;
	
	
	//Memory Allocation
	int mz1, mz2;
	
	float* _lin_T = (float*)malloc(sizeof(float)*((N+1) * (N+1)));
	mallocCheck(_lin_T, ((N+1) * (N+1)), float);
	T = (float**)malloc(sizeof(float*)*(N+1));
	mallocCheck(T, (N+1), float*);
	for (mz1=0;mz1 < N+1; mz1++) {
		T[mz1] = &_lin_T[(mz1*(N+1))];
	}
	
	float* _lin_H = (float*)malloc(sizeof(float)*((N+1) * (N+1)));
	mallocCheck(_lin_H, ((N+1) * (N+1)), float);
	H = (float**)malloc(sizeof(float*)*(N+1));
	mallocCheck(H, (N+1), float*);
	for (mz1=0;mz1 < N+1; mz1++) {
		H[mz1] = &_lin_H[(mz1*(N+1))];
	}
	
	_flag_score = 'N';
	
	char* _lin__flag_T = (char*)malloc(sizeof(char)*((N+1) * (N+1)));
	mallocCheck(_lin__flag_T, ((N+1) * (N+1)), char);
	_flag_T = (char**)malloc(sizeof(char*)*(N+1));
	mallocCheck(_flag_T, (N+1), char*);
	for (mz1=0;mz1 < N+1; mz1++) {
		_flag_T[mz1] = &_lin__flag_T[(mz1*(N+1))];
	}
	memset(_lin__flag_T, 'N', ((N+1) * (N+1)));
	
	char* _lin__flag_H = (char*)malloc(sizeof(char)*((N+1) * (N+1)));
	mallocCheck(_lin__flag_H, ((N+1) * (N+1)), char);
	_flag_H = (char**)malloc(sizeof(char*)*(N+1));
	mallocCheck(_flag_H, (N+1), char*);
	for (mz1=0;mz1 < N+1; mz1++) {
		_flag_H[mz1] = &_lin__flag_H[(mz1*(N+1))];
	}
	memset(_lin__flag_H, 'N', ((N+1) * (N+1)));
	#define S0() eval_score(N)
	{
		//Domain
		//{|}
		S0();
	}
	#undef S0
	//Copy scalars to output
	*_local_score = score;
	
	//Memory Free
	free(_lin_T);
	free(T);
	
	free(_lin_H);
	free(H);
	
	
	free(_lin__flag_T);
	free(_flag_T);
	
	free(_lin__flag_H);
	free(_flag_H);
}
float reduce_MiniMFE_verify_T_1(long N, int ip, int jp){
	float reduceVar = FLT_MAX;
	#define S0(i,j,k) {float __temp__ = (eval_T(N,i,k))+(eval_T(N,k+1,j)); reduceVar = __min_float(reduceVar,__temp__); }
	{
		//Domain
		//{i,j,k|jp>=ip+1 && N>=jp && ip>=0 && N>=1 && j>=k+1 && j>=i+1 && i>=0 && k>=i && N>=k && N>=j && k>=-1 && ip==i && jp==j}
		int c3;
		for(c3=ip;c3 <= jp-1;c3+=1)
		 {
		 	S0((ip),(jp),(c3));
		 }
	}
	#undef S0
	return reduceVar;
}
float eval_T(long N, int i, int j){
	if ( _flag_T(i,j) == 'N' ) {
		_flag_T(i,j) = 'I';
	//Body for T
		T(i,j) = (((j == i))?__min_float(W(i,j),eval_H(N,i,j)):(__min_float(__min_float(eval_H(N,i,j),W(i,j)),reduce_MiniMFE_verify_T_1(N,i,j))));
		_flag_T(i,j) = 'F';
	} else if ( _flag_T(i,j) == 'I' ) {
		printf("There is a self dependence on T at (%d,%d) \n",i,j);
		exit(-1);
	}
	return T(i,j);
}
float eval_H(long N, int i, int j){
	if ( _flag_H(i,j) == 'N' ) {
		_flag_H(i,j) = 'I';
	//Body for H
		H(i,j) = (((j == i))?foo(A(i),B(j)):(((j == i+1))?__min_float(foo(A(i),B(j)),__min_float(eval_H(N,i+1,j),eval_H(N,i,j-1))):(bar((foo(A(i),B(j)))+(eval_T(N,i+1,j-1)),eval_H(N,i+1,j),eval_H(N,i,j-1)))));
		_flag_H(i,j) = 'F';
	} else if ( _flag_H(i,j) == 'I' ) {
		printf("There is a self dependence on H at (%d,%d) \n",i,j);
		exit(-1);
	}
	return H(i,j);
}
float eval_score(long N){
	if ( _flag_score == 'N' ) {
		_flag_score = 'I';
	//Body for score
		score = eval_T(N,0,N);
		_flag_score = 'F';
	} else if ( _flag_score == 'I' ) {
		printf("There is a self dependence on score at () \n");
		exit(-1);
	}
	return score;
}

//Memory Macros
#undef A
#undef B
#undef W
#undef T
#undef H
#undef _flag_T
#undef _flag_H


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
