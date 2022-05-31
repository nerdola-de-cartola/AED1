#include <stdio.h>

typedef union {
  struct {
    int quarter;
    int dime;
    int nickel;
    int penny;
  };

  int coins[4];
} Coins_t ;
 

int main(void) {
    Coins_t a ;

    a.dime = 34 ;         // são operações equivalentes
    printf("%d\n", a.coins[1]);

    a.coins[1] = 34 ;
    printf("%d\n", a.dime);

    return 0;
}