#include <gmp.h>


#define VERSION "0.01"
#define FAIL -1
#define WIN 0

// Basic message methods

void printError(char *m);
void printWin(mpz_t *n, char *method);

// Initialization methods

int initLazyFact(mpz_t *n);

// Factoring methods

int trialDiv(mpz_t *n);
#define TRIALDIVMAX 1333333337

int pollardsRho(mpz_t *n);
#define POLRHOXFIXED 2
#define POLRHOCYCLESIZE 2
#define POLRHOX 2		// TODO: randomize x
#define POLRHOFACTOR 1
#define POLRHOMAX 25

int shankSquares(mpz_t *n);
#define SHANKQUAREK 1	// TODO: randomize k?
#define SHANKQUAREMAX 1333333337

int openSSLGenTest(mpz_t *n);
#define OPENSSLGENBITS 256	// TODO: automatically detect bits
#define OPENSSLGENEXPONENT 65537
#define OPENSSLGENMAX 31337


