/*
	CCPal Example Code

	Author: Paolo Fabio Zaino

	Description:
	This simple little program shows you how to use CCPal.

	How this works is pretty simple, if you define the MACRO

	MONITOR_PERFORMANCE 

	then this exmaple code will include the ccpal.h library
	and will display performance monitor analysis per each
	sections of your code where you called ccpal library,
	while if you undef MONITOR_PERFORMANCE it will include
	the empty header, so your code will be compiled without
	ccpal extra code.

	This program is distributed under GPLv2 license

*/

#include <stdio.h>

#define CCPAL_MONITOR_PERFORMANCE 1

#ifdef CCPAL_MONITOR_PERFORMANCE
#include "ccpal.h"
#else
#include "ccpal-empty.h"
#endif

void my_function_to_measure(char *text_par) {
	
	fprintf (stdout, "%s", text_par);
	
}

int main() {
	char *the_usual_test = "Hello World!\n\n";
	
	/* 
	   Here all the stuff related to Performance analysis:
	*/
	
	/* 
	   This macro should be called  before  doing any measuring
	   it needs to be called only once at the beginning of your
	   principal function.
	*/
	CCPAL_INIT_LIB
    
	/* 
		The MACRO below should be called just before the code
		section you want to measure performance for
	*/
	CCPAL_START_MEASURING
		
	/* Now let's execute the code we want to measure: */
	my_function_to_measure( the_usual_test );

	/* Ok, we are done, now let's stop measuring: */
	CCPAL_STOP_MEASURING
    
	/* Last step, let print out the mesurement: */ 
	CCPAL_REPORT_ANALYSIS
	
	return 0;
}


