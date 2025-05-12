#ifndef LIBSTR_H
#define LIBSTR_H

//return length of string
#include <stdlib.h>
unsigned int strLen(const char* str);
//append str2 in str1
void concat(char** str1, const char* str2);
/*return 0 if str1 is equal to str2
* negative if is less
* positive if is greate
* lexicographic order
*/
int strComp(const char* str1, const char* str2);

char* intToStr(int num);

void strCopy(char** strDest, const char* str);
#endif
