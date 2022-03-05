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
#include <system.h>
#include <stdio.h>

#define ALT_CI_LPM_MULT1_0(A,B) __builtin_custom_inii(ALT_CI_LPM_MULT1_0_N,(A),(B))
#define ALT_CI_LPM_MULT1_0_N 0x0


int main()
{
	printf("Hello from Nios II!\n");

	int a, b, c, d;
	a = 2;
	b = 4;
	c = a*b;
	printf("Multiplication result: %d\n", c);

	d = ALT_CI_LPM_MULT1_0(a,b);

	printf("Multiplication result from custom instr: %d",d);
	return 0;
}
