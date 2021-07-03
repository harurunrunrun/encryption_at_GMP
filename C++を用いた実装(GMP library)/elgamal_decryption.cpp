#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <gmp.h>
using namespace std;

int main(){
  mpz_t p,x,c1,c2,m;
  mpz_init(p);
  mpz_init(x);
  mpz_init(c1);
  mpz_init(c2);
  mpz_init(m);
  cout<<"p:";
  gmp_scanf("%Zd",p);
  cout<<"x:";
  gmp_scanf("%Zd",x);
  cout<<"c1:";
  gmp_scanf("%Zd",c1);
  cout<<"c2:";
  gmp_scanf("%Zd",c2);
  mpz_neg(x,x);
  mpz_powm(m,c1,x,p);
  mpz_mul(m,m,c2);
  mpz_mod(m,m,p);
  gmp_printf("m:\n%Zd\n\n",m);
  return 0;
}