/*
 * "Hello World" example.
 *
 * This example prints 'Hello from Nios II' to the STDOUT stream. It runs on
 * the Nios II 'standard', 'full_featured', 'fast', and 'low_cost' example
 * designs. It runs with or without the MicroC/OS-II RTOS and requires a STDOUT
 * device in your system's hardware.
 * The memory footprint of this hosted application is ~69 kbytes by default
 * using the standard reference design.
 *
 * For a reduced footprint version of this template, and an explanation of how
 * to reduce the memory footprint for a given application, see the
 * "small_hello_world" template.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/alt_stdio.h>
#include <sys/alt_alarm.h>
#include <sys/times.h>
#include <alt_types.h>
#include <system.h>
#include <stdio.h>
#include <unistd.h>

int main()
{

//The following is used for timing
	char buf[50];
	clock_t exec_t1, exec_t2;
	char *gcvt(double number, int ndigit, char *buf);

	exec_t1 = times(NULL); // get system time before starting the process

	printf("Hello from Nios II!\n");

	exec_t2 = times(NULL); // get system time after starting the process

	gcvt((exec_t2 - exec_t1), 10 ,buf);

	alt_putstr("proc time = "); alt_putstr(buf); alt_putstr(" ticks \n");


	return 0;
}
