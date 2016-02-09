/*
	This file initializes LazyFact methods
*/

#include <stdio.h>
#include <lazyfactInclude/meth.h>
#include <gmp.h>


int initLazyFact(mpz_t *n)
{
	printf("[START ] Modulus: %s\n", mpz_get_str (0, 10, *n));

	if (trialDiv(n) == WIN)
		return 1;
	if (pollardsRho(n) == WIN)
		return 1;
	if (shankSquares(n) == WIN)
		return 1;
	/*if (openSSLGenTest(n) == WIN)
		return 1;*/

	return 0;
}

