/* https://en.wikipedia.org/wiki/Trial_division */

#include <lazyfactInclude/meth.h>
#include <gmp.h>
#include <stdio.h>


int trialDiv(mpz_t *n)
{
	mpz_t myN, nRoot, tmp;
	long counter = 0;
	int status = FAIL;
	
	printf("[INFO ] Trying trial division\n");

	mpz_init_set(myN, *n);
	mpz_init(nRoot);	mpz_init_set_ui(tmp, 1);

	// Start at (square root of modulus) + 1
	mpz_sqrt(nRoot, myN);
	mpz_add_ui(nRoot, nRoot, 1);

	// Starting point must be uneven
	// So add one if root is divisible by two
	mpz_mod_ui(tmp, nRoot, 2);
	if (mpz_cmp_ui(tmp, 0) == 0)
	{
		mpz_add_ui(nRoot, nRoot, 1);
	}

	while (counter < TRIALDIVMAX)
	{
		mpz_mod(tmp, myN, nRoot);

		// did it devide? Then this is polly the right number.
		if (mpz_cmp_ui(tmp, 0) == 0)
		{
			printWin(&nRoot, "Trial division");
			status = WIN;
			break;
		}

		mpz_sub_ui(nRoot, nRoot, 2);	// TODO: random hops?
		counter += 1;
	}
	
	return status;
}