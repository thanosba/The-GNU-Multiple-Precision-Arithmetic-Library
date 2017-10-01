#include <stdio.h>
#include <stdlib.h>
#include "gmp.h"
gmp_randstate_t stat;
int main(void)
{
int primetest;
long sd = 0;
mpz_t p1, p2, m;
mpz_t seed;
gmp_randinit(stat, GMP_RAND_ALG_LC, 120);
mpz_init(p1);
mpz_init(p2);
mpz_init(m);
mpz_init(seed);
srand( (unsigned) getpid());
sd=rand();
mpz_set_ui(seed, sd);
gmp_randseed(stat, seed);
mpz_urandomb(p1, stat, 150);
mpz_urandomb(p2, stat, 150);
printf("Generate two 150-bit random numbers:\n");
printf("p1 = "); mpz_out_str(stdout, 10, p1); printf("\n");
printf("p2 = "); mpz_out_str(stdout, 10, p2); printf("\n");
printf("Checking the primality of p1....\n");
primetest = mpz_probab_prime_p(p1, 10);
if (primetest != 0) {
printf("p1 is prime\n");
}
else {
printf("p1 is composite\n");
mpz_nextprime(m, p1);
printf("the first prime which is greater than p1 is \n");
printf("m = "); mpz_out_str(stdout, 10, m); printf("\n");
}
printf("m mod p1 =");
mpz_mod(p2, m, p1);
mpz_out_str(stdout, 10, p2); printf("\n");
mpz_clear(p1);
mpz_clear(p2);
mpz_clear(m);
mpz_clear(seed);
return 0;
}
