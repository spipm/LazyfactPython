#include <stdio.h>
#include <string.h>
#include <lazyfactInclude/meth.h>
#include <gmp.h>


void printError(char *m) {	
	if (m != NULL && strlen(m) > 1)
	{
		printf("[ERROR ] %s\n",m);
	}
	else
	{
		printf("[ERROR ] Some error\n");
	}
}

void printWin(mpz_t *n, char *method) {	
	printf("[WIN ] Found factor: %s\n", mpz_get_str (0, 10, *n));
	printf("[WIN ] Method used: %s\n", method);
}
