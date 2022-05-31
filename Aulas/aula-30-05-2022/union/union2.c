#include <stdio.h>
    
typedef union {
    short  shortVal;
    int    intVal;
    long   longVal;
    float  floatVal;
    double doubleVal;
} numeric_t;
    
int main ()
{
    numeric_t a;
    
    a.shortVal = 741;
    printf("short : %d\n", a.shortVal);
    printf("float : %f\n\n", a.floatVal);
    
    a.floatVal = 327.5432;
    printf("float : %f\n", a.floatVal);
    printf("short : %d\n\n", a.shortVal);
    
    a.doubleVal = 327.5432;
    printf("double: %lf\n", a.doubleVal);
    printf("float : %f\n", a.floatVal);
    printf("short : %d\n", a.shortVal);
    return 0;
}

