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
#include <time.h>
#include <sys/time.h>
#include <sys/errno.h>
#include <omp.h>


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
#define EPSILON 1.0E-9







//Memory Macros
#define A(i) A[i]
#define B(i) B[i]
#define W(i,j) W[i][j]
#define T(i,j) T[i][j]
#define H(i,j) H[i][j]

#define score_verify() score_verify
#define var_score() score
#define var_score_verify() score_verify

//function prototypes
void MiniMFE(long, float*, float*, float**, float*);
void MiniMFE_verify(long, float*, float*, float**, float*);

//main
int main(int argc, char** argv) {
	//Check number of args
	if (argc <= 1) {
		printf("Number of argument is smaller than expected.\n");
		printf("Expecting N\n");
		exit(0);
	}
	
	char *end = 0;
	char *val = 0;
	//Read Parameters
	//Initialisation of N
	errno = 0;
	end = 0;
	val = argv[1];
	long N = strtol(val,&end,10);
	if ((errno == ERANGE && (N == LONG_MAX || N == LONG_MIN)) || (errno != 0 && N == 0)) {
		perror("strtol");
		exit(EXIT_FAILURE);
	}
	if (end == val) {
		fprintf(stderr, "No digits were found for N\n");
		exit(EXIT_FAILURE);
	}
	if (*end != '\0'){
		printf("For parameter N: Converted part: %ld, non-convertible part: %s\n", N, end);
		exit(EXIT_FAILURE);
	}
	
	
	///Parameter checking
	if (!((N >= 1))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
	
	
	//Memory Allocation
	int mz1, mz2;
	float* A = (float*)malloc(sizeof(float)*(N+1));
	mallocCheck(A, (N+1), float);
	float* B = (float*)malloc(sizeof(float)*(N+1));
	mallocCheck(B, (N+1), float);
	float* _lin_W = (float*)malloc(sizeof(float)*((N+1) * (N+1)));
	mallocCheck(_lin_W, ((N+1) * (N+1)), float);
	float** W = (float**)malloc(sizeof(float*)*(N+1));
	mallocCheck(W, (N+1), float*);
	for (mz1=0;mz1 < N+1; mz1++) {
		W[mz1] = &_lin_W[(mz1*(N+1))];
	}
	float score;
	#ifdef VERIFY
		float score_verify;
	#endif

	//Initialization of rand
	srand((unsigned)time(NULL));
	 
	//Input Initialization
	{
		#if defined (RANDOM)
			#define S0(i) (A(i) = rand()) 
		#elif defined (CHECKING) || defined (VERIFY)
			#ifdef NO_PROMPT
				#define S0(i) scanf("%f", &A(i))
			#else
				#define S0(i) printf("A(%ld)=",(long) i); scanf("%f", &A(i))
			#endif
		#else
			#define S0(i) (A(i) = 1)   //Default value
		#endif
		
		
		int c1;
		for(c1=0;c1 <= N;c1+=1)
		 {
		 	S0((c1));
		 }
		#undef S0
	}
	{
		#if defined (RANDOM)
			#define S0(i) (B(i) = rand()) 
		#elif defined (CHECKING) || defined (VERIFY)
			#ifdef NO_PROMPT
				#define S0(i) scanf("%f", &B(i))
			#else
				#define S0(i) printf("B(%ld)=",(long) i); scanf("%f", &B(i))
			#endif
		#else
			#define S0(i) (B(i) = 1)   //Default value
		#endif
		
		
		int c1;
		for(c1=0;c1 <= N;c1+=1)
		 {
		 	S0((c1));
		 }
		#undef S0
	}
	{
		#if defined (RANDOM)
			#define S0(i,j) (W(i,j) = rand()) 
		#elif defined (CHECKING) || defined (VERIFY)
			#ifdef NO_PROMPT
				#define S0(i,j) scanf("%f", &W(i,j))
			#else
				#define S0(i,j) printf("W(%ld,%ld)=",(long) i,(long) j); scanf("%f", &W(i,j))
			#endif
		#else
			#define S0(i,j) (W(i,j) = 1)   //Default value
		#endif
		
		
		int c1,c2;
		for(c1=0;c1 <= N;c1+=1)
		 {
		 	for(c2=c1;c2 <= N;c2+=1)
		 	 {
		 	 	S0((c1),(c2));
		 	 }
		 }
		#undef S0
	}
	
	//Timing
	struct timeval time;
	double elapsed_time;
	
	//Call the main computation
	gettimeofday(&time, NULL);
	elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000);
	
	MiniMFE(N, A, B, W, &score);

	gettimeofday(&time, NULL);
	elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000) - elapsed_time;

	// timing information
	printf("Execution time : %lf sec.\n", elapsed_time);
	
	#ifdef TIMING
		FILE * fp = fopen( "trace.dat","a+");
		if (fp == NULL) {
				printf("I couldn't open trace.dat for writing.\n");
				exit(EXIT_FAILURE);
		}
		fprintf(fp, "%ld\t%lf\n",N,elapsed_time);
		fclose(fp);
	#endif
	
	//Verification Run
	#ifdef VERIFY
		#ifdef TIMING
			gettimeofday(&time, NULL);
			elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000);
		#endif
    	MiniMFE_verify(N, A, B, W, &score_verify);
    	#ifdef TIMING
    		gettimeofday(&time, NULL);
			elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000) - elapsed_time;
			
			FILE * fp_verify = fopen( "trace_verify.dat","a+");
			if (fp == NULL) {
					printf("I couldn't open trace_verify.dat for writing.\n");
					exit(EXIT_FAILURE);
			}
			fprintf(fp, "%ld\t%lf\n",N,elapsed_time);
			fclose(fp_verify);
		#endif
	#endif
    	
	#ifdef CHECKING
    	//Print Outputs
		
		{
			#ifdef NO_PROMPT
				#define S0() printf("%0.2f\n",var_score())
			#else
				#define S0() printf("score=");printf("%0.2f\n",var_score())
			#endif
			S0();
			#undef S0
		}
	#elif VERIFY
		//Compare outputs for verification
		if (fabsf(1.0f - var_score_verify()/var_score()) > EPSILON) {
			printf("TEST for score FAILED result: %f expected: %f\n",var_score(), var_score_verify());
		} else {
			printf("TEST for score PASSED\n");
		}
    #endif
    
	//Memory Free
	free(A);
	free(B);
	free(_lin_W);
	free(W);
	#ifdef VERIFY
	#endif
	
	return EXIT_SUCCESS;
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
#undef EPSILON
