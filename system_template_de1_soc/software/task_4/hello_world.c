
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
//#define step 1/1024.0
//#define N 261121

// Generates the vector x and stores it in the memory
void generateVector(float x[261121]){
	int i;
	x[0] = 0;
	for(i=1;i<261121;i++){
		x[i] = x[i-1] + 0.0009765625;
	}

}

double sumVector(float x[261121]){
	//YOUR CODE GOES HERE
	double y1 = 0;
	double y2 = 0;
	double a = 0;
	for(int i=0;i<261121;i++){
		y1 += x[i];
	}
	for(int i=0;i<261121;i++){
//		a = x[i];
//		x[i] *= x[i];
//		x[i] *= cos((a-128)/128);
		y2 += x[i]*(x[i]*(cosf((x[i]-128)/128)));
	}
	return 0.5*y1 + y2;
}
int main()
{
	printf("Code Optimisation 11\n");

	//Define input vector
	float x[261121];

	//Returned result
	double y;

	generateVector(x);
	//The following is used for timing
	char buf[100];
	clock_t exec_t1, exec_t2;
	char *gcvt(double number, int ndigit, char *buf);

	exec_t1 = times(NULL); // get system time before starting the process

	// The code that you want to time goes here
	y = sumVector(x);

	// till here
	exec_t2 = times(NULL); // get system time after finishing the process

	printf("Result: %0.4f\n", y);
	gcvt((exec_t2 - exec_t1), 10 ,buf);

	alt_putstr("proc time = "); alt_putstr(buf); alt_putstr(" ticks \n");
	return 0;
}
