## LazyFact
###### Factoring RSA moduli using crazy luck ######

Lazyfact tries to factorise a RSA modulus using very basic methods.
This project is created for educational purposes and covers the following subjects:
- C, GMP
- C, OpenSSL
- Python, C extensions/packaging
- Python, threading using Queue
- Semiprime integer factorisation
	- Trial division
	- Pollards rho
	- Shanks squares
	- Findings another semiprime with a common GCD

**Usage - building/installing**

```
$ cd src
$ sudo python setup.py install
```

**Usage - using**

```
$ cd tryOut
$ gcc generator.c -o generator -lgmp -lcrypto 
$ ./generator > moduli.txt
$ python lazyfactThreading.py
```

**Sources / Reading**

- Factoring RSA moduli (semiprime integer factorisation)
	- [Integer factorisation on Wikipedia](https://en.wikipedia.org/wiki/Integer_factorization#Factoring_algorithms)
	- [Stanford Crypto course](https://class.coursera.org/crypto-010/lecture/preview)

- GMP
	- [GMP on Wikipedia](https://en.wikipedia.org/wiki/GNU_Multiple_Precision_Arithmetic_Library)
	- [GMP integer functions manual](https://gmplib.org/manual/Integer-Functions.html#Integer-Functions)
	
- OpenSSL
	- [OpenSSL RSA functions manual](https://www.openssl.org/docs/manmaster/crypto/RSA_generate_key.html)

- Python threading using Queue
	- [Python Queue manual](https://docs.python.org/2/library/queue.html)
	
- Creating a Python C extension and packaging
	- [Python manual - C extensions](https://docs.python.org/2/extending/extending.html#providing-a-c-api-for-an-extension-module)
	- [Python manual - C extensions building](https://docs.python.org/2/extending/building.html#building)
	- [Python manual - package setup](https://docs.python.org/2/distutils/apiref.html#distutils.core.setup)
	- [Article about Python C extensions and GIL thread locking](http://jessenoller.com/blog/2009/02/01/python-threads-and-the-global-interpreter-lock)
	
- Licensing
	- [Creative common license](http://creativecommons.org/choose/)
