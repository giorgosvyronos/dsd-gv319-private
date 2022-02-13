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

// Test case 4
#define N 2323
#define RANDSEED 334
//=====================================================
//float taylor_cos(float x){
//	return (1 - (x*x/2) + (x*x*x*x/24) - x*x*x*x*x*x/720 + x*x*x*x*x*x*x*x/40320); //up to power of 8.
//}


void generateRandomVector(float x[N])
{
	int i;
	srand(RANDSEED);
	int MAXVAL = 255; // MAXVAL sets the maximum value that is output
					  // by the random generator in the function. You should set it at 255.
	for (i=0; i<N; i++)
	{
		x[i] = ((float) rand() / (float) RAND_MAX) * MAXVAL;


	}
}

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
	printf("Test Case 4 ----------------------------------------------\n");

	//Define input vector
	float x[N];

	//Returned result
	float y;

	 generateRandomVector(x);
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
