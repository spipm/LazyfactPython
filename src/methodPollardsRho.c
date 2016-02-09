/* https://en.wikipedia.org/wiki/Pollard's_rho_algorithm#The_Example_n_.3D_10403_.3D_101_._103 */

#include <lazyfactInclude/meth.h>
#include <gmp.h>
#include <stdio.h>


int pollardsRho(mpz_t *n)
{
	mpz_t myN, x_fixed, cycle_size, x, factor, count, tmp;
	long counter = 0;
	int status = FAIL;

	printf("[INFO ] Trying Pollards rho\n");

	mpz_init_set(myN, *n);
	mpz_init_set_ui(x_fixed, POLRHOXFIXED);	mpz_init_set_ui(cycle_size, POLRHOCYCLESIZE);
	mpz_init_set_ui(x, POLRHOX);			mpz_init_set_ui(factor, POLRHOFACTOR);
	mpz_init(tmp);							mpz_init(count);

	while (counter < POLRHOMAX)
	{

		mpz_set_ui(count, 1);
		while (mpz_cmp(count, cycle_size) <= 0 && mpz_cmp_ui(factor, 1) <= 0)
		{
			mpz_mul(x, x, x);				//x = (x*x+1)%number;
			mpz_add_ui(x, x, 1);
			mpz_mod(x, x, myN);
			
			mpz_sub(tmp, x, x_fixed);		//factor = gcd(x - x_fixed, number);
			mpz_gcd(factor, tmp, myN);			

			mpz_add_ui(count, count, 1);
		}

		if (mpz_cmp_ui(factor, 1) > 0)
		{
			printWin(&factor, "Pollards rho");
			status = WIN;
			break;
		}

		mpz_mul_ui(cycle_size, cycle_size, 2);		//cycle_size *= 2;
		mpz_set(x_fixed, x);		

		counter += 1;
	}


	mpz_clear(myN);
	mpz_clear(x_fixed);		mpz_clear(cycle_size);	mpz_clear(x);
	mpz_clear(factor);		mpz_clear(count);		mpz_clear(tmp);

	return status;

}











