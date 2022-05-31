#include <stdio.h>
 
union ieee754_float {
  float f;
 
  /* This is the IEEE 754 single-precision format.  */
  struct {
    unsigned int mantissa:23;
    unsigned int exponent:8;
    unsigned int negative:1;
    /* Little endian.  */
  } ieee;
};

int main(void) {
    union ieee754_float a;

    a.f = 8.5;

    printf("Valor: %f\n", a.f);
    printf("Mantissa: %d\n", a.ieee.mantissa);
    printf("Expoente: %d\n", a.ieee.exponent);
    printf("Sinal: %d\n", a.ieee.negative);
    
    return 0;
}