# Redirección de flujos en Linux

Flujos estándar:

- **0** – `stdin` (entrada estándar)
- **1** – `stdout` (salida estándar)
- **2** – `stderr` (salida de errores)

A continuación se explica cómo redirigir cada uno de estos flujos:

## Redirección de salida

- `> log.txt`: redirige la salida estándar (`stdout`) al archivo `log.txt`.
- `2>&1`: redirige `stderr` al mismo destino que `stdout`.
- `0< input.txt`: redirige el contenido `input.txt` al `stdin`

## Comando para ejecutar los programas

### Copilar:
```bash
javac package/NombreClase.java
```
### Ejecutar:

```bash
java package.NombreClase
```

# Medicion de tiempo de ejecucion:

Se utilizó ```<sys/time.h>``` para medir el tiempo entre instrucciones utilizando la estructura ```struct timeval``` , donde los atributos ```tv_sec``` se emplean para los segundos y ```tv_usec``` para los microsegundos. El tiempo total en segundos se calcula de la siguiente manera:

```c
stop.tv_sec - start.tv_sec + (double)(stop.tv_usec - start.tv_usec) / 1000000
```
Se optó por ```<sys/time.h>``` en lugar de ```<time.h>```, ya que con ```clock()``` de ```<time.h>``` solo se obtiene el tiempo de CPU del proceso que ejecuta el programa, y no el tiempo total que tarda el programa en ejecutarse.

Como desventaja de ```<sys/time.h>``` es que mide el tiempo en el sistema del programa ejecutado, incluyendo tanto el tiempo de CPU como el tiempo de espera. Se investigará cómo obtener solo el tiempo de CPU del programa evaluado.

# Manejo de cadenas en C sin `string.h`

En C, las cadenas de caracteres terminan con un carácter nulo `'\0'`. Conociendo esto, obtener datos como el tamaño de una cadena es muy sencillo: simplemente se debe iterar hasta encontrar este carácter.

Por el momento, para la librería solo se consideró necesario implementar las siguientes funciones: obtener el tamaño, concatenar y comparar cadenas. A continuación, se presentan sus implementaciones.
 

## Tamaño de la cadena
```c
unsigned int strLen(const char* str){
        unsigned int length = 0;
        //while(*str) -> mientras el caracter no sea nulo
        //en c cualquier n!=0 es verdarero
        while(*str){
                length++;
                str++;
        }
        return length;
}
```
## Concatenar cadenas
```c
char* concat(const char* str1, const char* str2){
        int str1Len = strLen(str1);
        int str2len = strLen(str2);
        char* result = malloc((str1Len + str2len) * sizeof(char));
        for (int i = 0; i < str1Len; i++) {
                result[i] = str1[i];
        }
        
        for (int i = 0; i < str2len; i++) {
                result[i + str1Len] = str2[i];
        }

        result[str1Len + str2len] = 0;//marcar el fin de la cadena, '\0' = 0
        return result;
}
```

## Comparar cadenas
```c
int strComp(const char* str1, const char* str2){
        //*str1 && *str2 -> parar al encontrar el caracter nulo, basta con cualquiera de los dos
        //en c cualquier numero != 0 es verdarero
        while (*str1 && *str2 && *str1 == *str2) {
                str1++;
                str2++;
        }
        return *str1 - *str2;
}
```
