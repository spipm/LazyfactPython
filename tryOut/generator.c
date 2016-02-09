/* This file generates RSA moduli using OpenSSL */

#include <gmp.h>
#include <stdio.h>

#include <openssl/rsa.h>

#define OPENSSLGENBITS 128	// generate 128 bit moduli
#define OPENSSLGENEXPONENT 65537
#define OPENSSLGENMAX 1000



int main()
{
	mpz_t genN, tmp;
	long counter = 0;
	int status = -1;

	//printf("[INFO ] Trying OpenSSL generating\n");

	mpz_init(genN);		mpz_init(tmp);

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

		printf("%s\n", mpz_get_str (0, 10, genN));

		counter += 1;
	}


	BN_free(e);
	RSA_free(rsa);

	mpz_clear(genN);

	return status;
}



