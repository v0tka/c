#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void function(int a) {
  printf("Me llamo %d\n",a);
}

void leer(float number) {
  printf("Ingrese un numero: ");
  scanf("%f",&number);
  fflush(stdin);
}

void suma(float number_a, float number_b) {
  printf("La suma es: %f\n",number_a + number_b);
  fflush(stdout);
}

void resta(float number_a, float number_b) {
  printf("La resta es: %f\n",number_a - number_b);
  fflush(stdout);
}

void multiplicacion(float number_a, float number_b) {
  printf("La multiplicacion es: %f\n",number_a * number_b);
  fflush(stdout);
}

void division(float number_a, float number_b) {
  printf("La division es: %f\n",number_a/number_b);
  fflush(stdout);
}

int main(int argc, char const *argv[]) {
  printf("Mi pid es: %d\n",getpid());

  float valor_a = 0.0;
  float valor_b = 0.0;

  void (*leer)(float) = leer;
  void (*suma)(float,float) = suma;
  void (*resta)(float,float) = resta;
  void (*multiplicacion)(float,float) = multiplicacion;
  void (*division)(float,float) = division;


  (*test)(valor_a);

  // test(number_a);
  return 0;

  // signal(1, (*leer)(valor_a));
  // signal(2, (*leer)(valor_b));
  // signal(3, (*suma)(valor_a,valor_b));
  // signal(4, (*resta)(valor_a,valor_b));
  // signal(5, (*multiplicacion)(valor_a,valor_b));
  // signal(6, (*division)(valor_a,valor_b));

  while(1) {
    pause();
  }


  return 0;
}