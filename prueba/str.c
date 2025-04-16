#include <stdio.h>
#include <stdlib.h>
#include <libstr.h>

int main(){
        struct timeval stop, start;
        
        char* str = concat("Hola ", "mundo!");
        char* aux = str;
        str = concat(aux, " esto es");
        free(aux);//liberar memoria anterior de str
        aux = str;
        str = concat(aux, " una prueba con cadenas");
        free(aux);//liberar memoria anterior de str
        printf("El tamaño de \"%s\" es %u\n", str, strLen(str));
        printf("\"%s\" cmp \"%s\" = %d\n", str, "Hola mundo! Esto es una prueba con cadenas", strComp(str, "Hola mundo! Esto es una prueba con cadenas"));
        free(str);//liberar memoria de str
        return 0;
}

