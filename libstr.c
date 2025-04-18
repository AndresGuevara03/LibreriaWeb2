#include <stdlib.h>

size_t strLen(const char* str){
        unsigned int length = 0;
        //while(*str) -> mientras el caracter no sea nulo
        //en c cualquier n!=0 es verdarero
        while(*str){
                length++;
                str++;
        }
        return length;
}

void concat(char** str1, const char* str2){
        size_t str1Len = strLen(*str1);
        size_t str2len = strLen(str2);
        char* aux = (char*) realloc((void*) *str1,(str1Len + str2len + 1) * sizeof(char));
        for (size_t i = 0; i < str2len; i++) {
                aux[i + str1Len] = str2[i];
        }
        aux[str1Len + str2len] = 0;//marcar el fin de la cadena, '\0' = 0
        *str1 = aux;
}

int strComp(const char* str1, const char* str2){
        //*str1 && *str2 -> parar al encontrar el caracter nulo, basta con cualquiera de los dos
        //en c cualquier numero != 0 es verdarero
        while (*str1 && *str2 && *str1 == *str2) {
                str1++;
                str2++;
        }
        return *str1 - *str2;
}

char* intToStr(unsigned int num){
        int aux = 1;
        size_t strSize = 1;
        while(num/aux >= 10){
                aux *= 10;
                strSize++;
        }
        char* str = malloc((strSize+1) * sizeof(char));
        for(int i = 0;i < strSize; i++){
                str[i] = (char)(num/aux + 48);
                num %= aux;
                aux /= 10;
        }
        str[strSize] = 0;
        return str;
}

void strCopy(char** strDest, const char* str){
        size_t strLength = strLen(str);
        char* aux = malloc((strLength + 1) * sizeof(char));
        int i;
        for(i = 0; i < strLength; i++){
                aux[i] = str[i];
        }
        aux[i] = 0;
        *strDest = aux;
}
