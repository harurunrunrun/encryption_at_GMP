#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <gmp.h>
#include "multiplerandom/randbit.h"
#include "multipleintegers/int_multiple.h"
using namespace std;
using namespace randbit;
using namespace multipleintegers;

bool prime(mpz_t pr,int l){
  mpz_t p1,a,c;
  //mpz_init(p2);
  mpz_init(a);
  mpz_init(c);
  mpz_init(p1);
  mpz_sub_ui(p1,pr,1);
  int i=0;
  while(i<40){
    mpz_set_str(a,rand_binary_bit(l).c_str(),2);
    mpz_powm(a,a,p1,pr);
    if(mpz_cmp_ui(a,1)!=0)return false;
    i++;
  }
  return true;
}


int main(){
  long l;
  mpz_t p,q,g,x,y,p2,q1,q2,c1;
  mpz_init(p);
  mpz_init(q);
  mpz_init(g);
  mpz_init(x);
  mpz_init(y);
  mpz_init(p2);
  mpz_init(q1);
  mpz_init(q2);
  mpz_init(c1);
  l=1024;
  while(true){
    mpz_set_str(q,rand_binary_bit(l).c_str(),2);
    if(prime(q,l)){
      mpz_mul_ui(p,q,2);
      mpz_add_ui(p,p,1);
      if(prime(p,l))break;
    }
  }
  mpz_sub_ui(p2,p,2);
	char s[2050];
	mpz_get_str(s,10,p2);
	string t=s;
  while(true){
    mpz_set_str(g,random_range("2",t).c_str(),10);
    mpz_powm(c1,g,q,p);
    if(mpz_cmp_ui(c1,1)==0)break;
  }
	char s2[2050];
	mpz_get_str(s2,10,q1);
	string t2=s2;
  mpz_set_str(x,random_range("1",t2).c_str(),10);
  mpz_powm(y,g,x,p);
  gmp_printf("p:\n%Zd\n\n",p);
  gmp_printf("q:\n%Zd\n\n",q);
  gmp_printf("g:\n%Zd\n\n",g);
  gmp_printf("y:\n%Zd\n\n",y);
  gmp_printf("x:\n%Zd\n\n",x);
  return 0;
}