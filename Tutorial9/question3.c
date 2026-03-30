#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <omp.h>

int main(int argc, char *argv[]) {
    long x[100000000];

    #ifdef _OPENMP
    omp_set_num_threads(10);
    #endif

    // #pragma omp parallel for
    //can't use parallelism on rand() as it requires a global lock
    for (long i = 0; i<100000000; i++) {
        long r = rand() % 101;
        x[i] = r;
    }

    double norm = 0;
    double start = omp_get_wtime();
    for (long i = 0; i < 100000000; i++) {
        norm += fabs(x[i]);
    }
    double end = omp_get_wtime();

    double serial_time = end - start;

    printf("The serial time taken: %lf\n", serial_time);

    norm = 0;
    start = omp_get_wtime();
    #pragma omp parallel for reduction(+:norm)
    for (long i = 0; i < 100000000; i++) {
        norm += fabs(x[i]);
    }
    end = omp_get_wtime();

    double parallel_time = end - start;

    printf("The parallel time taken: %lf\n", parallel_time);
}