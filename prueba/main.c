#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main(){
        struct timeval stop, start;
        system("javac pruebajava/Prueba.java");
        gettimeofday(&start, NULL);
        system("java pruebajava.Prueba > log.txt 2>&1 0< input.txt");
        gettimeofday(&stop, NULL);
        printf("seg: %lf\n", stop.tv_sec - start.tv_sec + (double) (stop.tv_usec - start.tv_usec) / 1000000);
        system("javac pruebajava/PruebaBucle.java");
        gettimeofday(&start, NULL);
        system("java pruebajava.PruebaBucle > log.txt 2>&1 0< input.txt");
        gettimeofday(&stop, NULL);
        printf("seg: %lf\n", stop.tv_sec - start.tv_sec + (double) (stop.tv_usec - start.tv_usec) / 1000000);
        system("javac pruebajava/PruebaFor.java");
        gettimeofday(&start, NULL);
        system("java pruebajava.PruebaFor");
        gettimeofday(&stop, NULL);
        printf("seg: %lf\n", stop.tv_sec - start.tv_sec + (double) (stop.tv_usec - start.tv_usec) / 1000000);
        return 0;
}
