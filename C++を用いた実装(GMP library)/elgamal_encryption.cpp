#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <gmp.h>
using namespace std;

int main(){
  mpz_t p,q,g,y,r,c1,c2,q2,m;
  mpz_init(p);
  mpz_init(q);
  mpz_init(g);
  mpz_init(y);
  mpz_init(r);
  mpz_init(c1);
  mpz_init(c2);
  mpz_init(q2);
  mpz_init(m);
  cout<<"p:";
  gmp_scanf("%Zd",p);
  cout<<"q:";
  gmp_scanf("%Zd",q);
  cout<<"g:";
  gmp_scanf("%Zd",g);
  cout<<"y:";
  gmp_scanf("%Zd",y);
  cout<<"m:";
  gmp_scanf("%Zd",m);
  mpz_sub_ui(q2,q,1);
  srand(time(NULL));
  gmp_randstate_t state;
  gmp_randinit_default(state);
  gmp_randseed_ui(state,(unsigned long int)rand());
  mpz_urandomm(r,state,q2);
  mpz_add_ui(r,r,1);
  mpz_powm(c1,g,r,p);
  mpz_powm(c2,y,r,p);
  mpz_mul(c2,c2,m);
  mpz_mod(c2,c2,p);
  gmp_printf("c1:\n%Zd\n\n",c1);
  gmp_printf("c2:\n%Zd\n\n",c2);
  return 0;
}