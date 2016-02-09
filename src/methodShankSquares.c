/* https://en.wikipedia.org/wiki/Shanks'_square_forms_factorization */

#include <lazyfactInclude/meth.h>
#include <gmp.h>
#include <stdio.h>


int shankSquares(mpz_t *n)
{
	mpz_t myN, constA, constB, tmp, tmp2;
	mpz_t Pi, Qi, Plast, Qlast, Qnext, bi;
	long counter = 1;
	int status = FAIL;
	
	printf("[INFO ] Trying shank squares\n");


	mpz_init_set(myN, *n);

	mpz_init(tmp);	mpz_init(tmp2);
	mpz_init(bi);	mpz_init(Qnext);
	mpz_init(Pi);

	mpz_mul_ui(tmp, myN, SHANKQUAREK); // constA = k*N
	mpz_init_set(constA, tmp);

	mpz_sqrt(tmp, constA);	// constB = floor(sqrt(constA))
	mpz_init_set(constB, tmp);

	mpz_init_set(Plast, constB);


	mpz_pow_ui(tmp, Plast, 2);	// Qi = (constA) - (Pi**2)
	mpz_sub(tmp, constA, tmp);
	mpz_init_set(Qi, tmp);

	
	mpz_init_set_ui(Qlast, 1);


	while (counter < SHANKQUAREMAX)
	{

		mpz_add(tmp, constB, Plast);	//bi = floor( (constB) + (Plast) / Qi )
		mpz_fdiv_q(bi, tmp, Qi);

		mpz_mul(tmp, bi, Qi);			//Pi = (bi * Qi) - (Plast)
		mpz_sub(Pi, tmp, Plast);

		mpz_sub(tmp, Plast, Pi);		//Qnext = Qlast + (bi * (Plast - Pi))
		mpz_mul(tmp, tmp, bi);
		mpz_add(Qnext, Qlast, tmp);

		if (mpz_perfect_square_p(Qi) != 0 && counter % 2 == 0)
		{
			break;
		}
		else
		{
			mpz_set(Plast, Pi);
			mpz_set(Qlast, Qi);
			mpz_set(Qi, Qnext);	
		}

		counter += 1;
	}


	mpz_sub(tmp, constB, Plast);	//bi = floor( ( constB - Plast ) / sqrt(Qi) )
	mpz_sqrt(tmp2, Qi);
	mpz_fdiv_q(bi, tmp, tmp2);

	mpz_sqrt(tmp, Qi);				//Plast = (bi * sqrt(Qi)) + Plast
	mpz_mul(tmp, tmp, bi);
	mpz_add(Plast, tmp, Plast);

	mpz_sqrt(Qlast, Qi);

	mpz_pow_ui(tmp2, Plast, 2);		//Qnext = ((constA) - Plast**2) / Qlast
	mpz_sub(tmp, constA, tmp2);
	mpz_div(Qnext, tmp, Qlast);

	mpz_set(Qi, Qnext);

	counter = 0;

	while (counter < SHANKQUAREMAX)
	{
		mpz_add(tmp, constB, Plast);	//bi = floor( ( constB + Plast ) / Qi )
		mpz_fdiv_q(bi, tmp, Qi);

		mpz_mul(tmp, bi, Qi);			//Pi = (bi*Qi) - Plast
		mpz_sub(Pi, tmp, Plast);

		mpz_sub(tmp, Plast, Pi);		//Qnext = Qlast + (bi * (Plast - Pi))
		mpz_mul(tmp, tmp, bi);
		mpz_add(Qnext, Qlast, tmp);

		if (mpz_cmp(Pi, Plast) == 0)
		{
			break;
		}

		mpz_set(Plast, Pi);
		mpz_set(Qlast, Qi);
		mpz_set(Qi, Qnext);

		counter += 1;
	}

	mpz_gcd(tmp, myN, Pi);

	if (mpz_cmp_ui(tmp, 1) != 0 && mpz_cmp(tmp, myN) != 0)
	{
		printWin(&tmp, "Shanks squares");
		status = WIN;
	}

	mpz_clear(myN);		mpz_clear(constA);
	mpz_clear(constB);	mpz_clear(tmp);		mpz_clear(tmp2);
	mpz_clear(Pi);		mpz_clear(Qi);		mpz_clear(Plast);
	mpz_clear(Qlast);	mpz_clear(Qnext);	mpz_clear(bi);

	return status;

}
