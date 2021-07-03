#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <gmp.h>
#include <ctime>
using namespace std;

bool prime(mpz_t pr,gmp_randstate_t state){
  mpz_t p1,p2,a,c;
  mpz_init(p2);
  mpz_init(a);
  mpz_init(c);
  mpz_init(p1);
  mpz_sub_ui(p1,pr,1);
  mpz_sub_ui(p2,pr,3);
  int i=0;
  while(i<40){
    mpz_urandomm(a,state,p2);
    mpz_add_ui(a,a,2);
    mpz_powm(a,a,p1,pr);
    if(mpz_cmp_ui(a,1)!=0)return false;
    i++;
  }
  return true;
}

int main(){
  clock_t start,end;
  start=clock();
  long l;
  mpz_t p,q,g,x,y,q2,c1;
  mpz_init(p);
  mpz_init(q);
  mpz_init(g);
  mpz_init(x);
  mpz_init(y);
  mpz_init(q2);
  mpz_init(c1);
  l=1024;
  srand(time(NULL));
  gmp_randstate_t state;
  gmp_randinit_default(state);
  gmp_randseed_ui(state,(unsigned long int)rand());
  while(true){
    mpz_rrandomb(q,state,l);
    if(prime(q,state)){
      mpz_mul_ui(p,q,2);
      mpz_add_ui(p,p,1);
      if(prime(p,state))break;
    }
  }
  mpz_sub_ui(q2,q,4);
  while(true){
    mpz_urandomm(g,state,q2);
    mpz_add_ui(g,g,2);
    mpz_powm(c1,g,q,p);
    if(mpz_cmp_ui(c1,1)==0)break;
  }
  mpz_urandomm(x,state,q2);
  mpz_add_ui(x,x,2);
  mpz_powm(y,g,x,p);
  end=clock();
  gmp_printf("p:\n%Zd\n\n",p);
  gmp_printf("q:\n%Zd\n\n",q);
  gmp_printf("g:\n%Zd\n\n",g);
  gmp_printf("y:\n%Zd\n\n",y);
  gmp_printf("x:\n%Zd\n\n",x);
  cout<<static_cast<double>(end-start)/CLOCKS_PER_SEC<<endl;
  return 0;
}