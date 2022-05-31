#include <stdio.h>
    
typedef struct {
    union {
        short  shortVal;
        int    intVal;
        long   longVal;
        float  floatVal;
        double doubleVal;
    };
    enum {SHORT, INT, LONG, FLOAT, DOUBLE} type;
} numeric_t;
    
// imprime tipo numérico
void print_num (numeric_t n) {
    switch (n.type) {
        case SHORT  : printf("%d", n.shortVal); break;
        case INT    : printf("%d", n.intVal); break;
        case LONG   : printf("%ld", n.longVal); break;
        case FLOAT  : printf("%f", n.floatVal); break;
        case DOUBLE : printf("%lf", n.doubleVal); break;
        default     : printf("NaN");
    }

    printf("\n");
}
    
int main () {
    numeric_t a;
    
    a.shortVal = 119;
    a.type = SHORT;
    print_num(a);
    
    a.longVal = 3451212796756;
    a.type = LONG;
    print_num(a);
    
    a.doubleVal = 3.141592653589793;
    a.type = DOUBLE;
    print_num(a);
}
