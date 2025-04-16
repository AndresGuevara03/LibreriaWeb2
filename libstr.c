#include <stdlib.h>

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

int strComp(const char* str1, const char* str2){
        //*str1 && *str2 -> parar al encontrar el caracter nulo, basta con cualquiera de los dos
        //en c cualquier numero != 0 es verdarero
        while (*str1 && *str2 && *str1 == *str2) {
                str1++;
                str2++;
        }
        return *str1 - *str2;
}
