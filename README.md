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
