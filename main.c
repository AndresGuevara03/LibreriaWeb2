#include <stdio.h>
#include <stdlib.h>

int main(){
	system("gcc -o prueba prueba.c");
	system("./prueba > log.txt 2>&1 0< input.txt");
	return 0;
}
