#include <stdio.h>
#include <omp.h>
int main (int argc, char *argv[])
{
    printf("This statement will always print.\n");
    //the print statement within the ifdef and endif will only run if omp.h is compiled
    #ifdef _OPENMP
    printf("This statement will only print when compiled with \"-fopenmp\"\n");
    #endif
    return 0;
}
