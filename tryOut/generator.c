/* This file generates RSA moduli using OpenSSL */

#include <stdio.h>
#include <openssl/rsa.h>

#define OPENSSLGENBITS 64	// generate 128 bit moduli
#define OPENSSLGENEXPONENT 65537
#define OPENSSLGENMAX 1000

int main()
{
	BIGNUM *e = NULL;
	RSA *rsa = NULL;

	rsa = RSA_new();
	e = BN_new();
	BN_set_word(e, OPENSSLGENEXPONENT);

	long counter = 0;
	while (counter < OPENSSLGENMAX)
	{

		if (RSA_generate_key_ex(rsa, OPENSSLGENBITS, e, NULL) == 0)
			break;

		printf("%s\n", BN_bn2dec(rsa->n));

		counter += 1;
	}

	BN_free(e);
	RSA_free(rsa);

	return 0;
}
