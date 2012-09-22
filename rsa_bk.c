#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define NUM_MAX 30

int mdc(int a,int b);
int primo(p);
int rand_int(int op);

void cria_num_primos(int *p,int *q){
  do{
    *p = rand_int(NUM_MAX);
  }while(primo(*p) == 0);

  do{
    *q = rand_int(NUM_MAX);
  }while((primo(*q) == 0)&&(*p != *q));
  //printf("numero primos %ld %ld\n",*p,*q);
}

int escolha_e(fi_n){
  
  int e = 3;

  while((1>=e)&&(mdc(e,fi_n) != 1))
    e++;
  
  return e;
}

int calculo_d(int fi_n, int e){
  int d;
  d = 2;
  while ((d < fi_n) && (((e*d) % fi_n) != 1))
    d++;
  return d;
}

int main(){
  unsigned long int p,q,n,fi_n,e,d;
  char mensagem[10] = {};
  //try long int
  unsigned long int mensagem_c[10] = {0};
  char mensagem_d[10] = {};
  srand(time(NULL));
  //cria_num_primos(&p,&q);
  //teste
  p = 17;
  q = 19;

  //printf("numero primos %ld %ld\n",p,q);
  n = p * q;
  printf("N %ld",n);
  //printf("n = p x q = %ld\n",n);
  fi_n = (p - 1) * (q - 1);
  //printf("fi(n) = (p - 1) x (q - 1) = %ld\n",fi_n);
  e = escolha_e(fi_n);
  e = 5;
  printf("e: %ld\n",e);
  d = calculo_d(fi_n,e);
  d = 173;
  printf("d: %ld\n",d);
  
  printf("Chaves\n");

  printf("Publica: { %ld , %ld }\n",e,n);
  printf("Privada: { %ld , %ld }\n",d,n);

  printf("------------------------------\n");
  printf(" Digite sua mensagem: \n");
  scanf("%s",mensagem);

  int i=0;
  unsigned long int c_int;
  char c;

  //printf("pow_int 2^3 %ld\n",pow_int(2,3));

  //for(i=0;i<strlen(mensagem);i++){
  for(i=0;i<10;i++){
    printf("%c ",mensagem[i]);
    c_int = mensagem[i];
    printf(" : %ld n: %ld\n",c_int,n);
    mensagem_c[i] = pow_int(c_int,e) % n ;
    printf("%ld\n",mensagem_c[i]);
    printf("fu %d",pow_int_mod(c_int,e,n));
  }

  //puts(mensagem);
  
  for(i=0;i<10;i++){
    //c_int = pow_int(mensagem[i],d) % n;
    c_int = pow_int_mod(mensagem_c[i],d, n);
    // c_int = mensagem[i] * mensagem[i]) % n;
    // c_int = c_int *mensagem[i]) % n;
    printf("c_int %ld\n",c_int);
    c     = (char)c_int;
    printf("%c \n",c);
  }
  
  return 0;
}



/* Medoto de Euclides estendido
 * para calcular o MDC
 */
int mdc(int a,int b){
  if(b == 0) 
    return a;
  else
    return mdc(b,a%b);
}

/* Verificar se um número é
 * primo
 */
int primo(p){
  int k = 2;
  while ((p%k) != 0)
    k++;
  if (k == p) //numero primo
    return 1;
  else        //numero nao primo
    return 0;
}

/* Gera um numero aleatorio
 * maximo passado
 */
int rand_int(int max){
  return(1 + (rand() % max));
}


int pow_int(unsigned long int x,unsigned long int y){
  int i;
  unsigned long int result = x;
  for(i=2;i<=y;i++){
     result *= x;
  }
  return result;
}

int pow_int_mod(unsigned long int num,unsigned long int expo, int mod){
  int i = 0, f = 0;
  unsigned long int result = 0;

  if(expo % 2 == 0){
    result = 1;
    f = (num * num) % mod;
    for(i=1;i<=expo/2;i++){
      result = (f*result) % mod;
    }
  }else{
    result = num;
    f = (num * num) % mod;
    for(i=1;i<=expo/2;i++){
      result = (f*result) % mod;
    }    
  }

  return result;

}
