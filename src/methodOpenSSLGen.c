#include <lazyfactInclude/meth.h>
#include <gmp.h>
#include <stdio.h>

#include <openssl/rsa.h>

/* Generate random moduli and check gcd */
int openSSLGenTest(mpz_t *n)
{
	mpz_t myN, genN, tmp;
	long counter = 0;
	int status = FAIL;

	printf("[INFO ] Trying OpenSSL generating\n");

	mpz_init_set(myN, *n);	mpz_init(genN);		mpz_init(tmp);

	BIGNUM *e = NULL;
	RSA *rsa = NULL;

	rsa = RSA_new();
	e = BN_new();
	BN_set_word(e, OPENSSLGENEXPONENT);

	while (counter < OPENSSLGENMAX)
	{

		if (RSA_generate_key_ex(rsa, OPENSSLGENBITS, e, NULL) == 0)
			break;

		mpz_set_str(genN, BN_bn2dec(rsa->n), 10);

		mpz_gcd(tmp, myN, genN);

		if (mpz_cmp_ui(tmp, 1) != 0)
		{
			printWin(&tmp, "OpenSSL gen");
			status = WIN;
			break;
		}

		counter += 1;
	}


	BN_free(e);
	RSA_free(rsa);

	mpz_clear(myN);		mpz_clear(genN);

	return status;
}







