/*
  RSA in C
  Romulo Pereira (romuloccomp@gmail.com)
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define NUM_MAX 100
#define TAM_MSG 100

int mdc(int a,int b);
int primo(p);
int rand_int(int op);

void cria_num_primos(int *p,int *q){
  do{
    *p = 10 + rand_int(NUM_MAX);
  }while(primo(*p) == 0);

  do{
    *q = 10 + rand_int(NUM_MAX);
  }while((primo(*q) == 0)&&(*p != *q));
}


int escolha_e(fi_n){
  int e;
  e = 3;
  while ((e < fi_n) && (primo(e)))
    if ((fi_n % e) != 0) return e;
  else 
    e=e+2;
}
int calculo_d(int fi_n, int e){
  int d;
  d = 2;
  while ((d < fi_n) && (((e*d) % fi_n) != 1))
    d++;
  return d;
}

int main(){
  int p,q,n,fi_n,e,d;
  char mensagem[TAM_MSG]    = {};
  int  mensagem_c[TAM_MSG]  = {0};
  char mensagem_d[TAM_MSG]  = {};
  srand(time(NULL));
  cria_num_primos(&p,&q);
  //teste
  //p = 23;
  //q = 19;
  printf("-----------------------------------\n");
  printf("----            RSA         -------\n");
  printf("-----------------------------------\n");
  printf("numero primos %d %d\n",p,q);
  n = p * q;
  printf("N: %d\t",n);
  //printf("n = p x q = %d\n",n);
  fi_n = (p - 1) * (q - 1);
  //printf("fi(n) = (p - 1) x (q - 1) = %d\n",fi_n);
  e = escolha_e(fi_n);
  //e = 5;
  printf("e: %d\t",e);
  d = calculo_d(fi_n,e);
  //d = 173;
  printf("d: %d\n",d);
  
  printf("Chaves\n");

  printf("Publica: { %d , %d }\n",e,n);
  printf("Privada: { %d , %d }\n",d,n);

  printf("-----------------------------------\n");
  printf(" Digite sua mensagem: \n");
  scanf("%s",mensagem);

  int i=0;
  int c_int;
  char c;

  for(i=0;i<TAM_MSG;i++){
    mensagem_c[i] = pow_int_mod(mensagem[i],e,n);
  }
  
  printf("\nMensagem encryptada:\n");
  for(i=0;i<TAM_MSG;i++){
    printf("%d",mensagem_c[i]);
  }

  printf("\n\nMensagem descryptada:\n");
  for(i=0;i<TAM_MSG;i++){
    c_int = pow_int_mod(mensagem_c[i],d, n);
    mensagem_d[i] = (char)c_int;
  }

  puts(mensagem_d);
  getchar();
  getchar();
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


int pow_int_mod(int num,int expo, int mod){
  int i = 0, f = 0;
  int result = 0;

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
