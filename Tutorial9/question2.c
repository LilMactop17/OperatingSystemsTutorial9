#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <omp.h>


int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Not enough arguments");
        return -1;
    }
    else if (argc > 2) {
        printf("Too many arguments");
        return -1;
    }
    else {
        #ifdef _OPENMP
        omp_set_num_threads(atoi(argv[1]));
        #endif

        long n = 100000000;

        double y[100000000];

        double dx = 1/(n+1);

        //double *y = malloc(n * sizeof(double));
        #pragma omp parallel for
        for (long i = 0; i<n; i++) {
            double x = i*dx;
            y[i] = exp(x) * cos (x) * sin (x) * sqrt (5 * x + 6.0);
        }
        printf("Calculation finished. The value at index 500 is: %f\n", y[500]);
    }
}