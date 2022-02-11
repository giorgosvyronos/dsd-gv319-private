
#include <stdlib.h>
#include <sys/alt_stdio.h>
#include <sys/alt_alarm.h>
#include <sys/times.h>
#include <alt_types.h>
#include <system.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

// Values of x -> x[i] = 0:step:255 -> N iterations where step,N for each testcase.

// Test case 1
//#define step 5
//#define N 52


// Test case 2
//#define step 1/8.0
//#define N 2041

// Test case 3
#define step 1/1024.0
#define N 261121

// Test case 4
//#define N 2323
//#define RANDSEED 334



// Generates the vector x and stores it in the memory
void generateVector(float x[N]){
	int i;
	x[0] = 0;
	for(i=1;i<N;i++){
		x[i] = x[i-1] + step;
	}
}

//void generateRandomVector(float x[N])
//{
//	int i;
//	srand(RANDSEED);
//	for (i=0; i<N; i++)
//	{
//		x[i] = ((float) rand() / (float) RAND_MAX) * MAXVAL;
//	}
//}

float sumVector(float x[], int M){
	//YOUR CODE GOES HERE
	float y=0;
	for(int i=0;i<M;i++){
		y += 0.5*x[i] + x[i]*x[i]*cos((x[i]-128)/128);
	}
	return y;
}
int main()
{
	printf("Task 4\n");

	//Define input vector
	float x[N];

	//Returned result
	float y;

	generateVector(x);

	//The following is used for timing
	char buf[100];
	clock_t exec_t1, exec_t2;
	char *gcvt(double number, int ndigit, char *buf);

	exec_t1 = times(NULL); // get system time before starting the process

	// The code that you want to time goes here
	y = sumVector(x,N);

	// till here
	exec_t2 = times(NULL); // get system time after finishing the process

	printf("Result: %f\n", y);
	gcvt((exec_t2 - exec_t1), 10 ,buf);

	alt_putstr("proc time = "); alt_putstr(buf); alt_putstr(" ticks \n");
	return 0;
}
