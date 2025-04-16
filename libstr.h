#ifndef LIBSTR_H
#define LIBSTR_H

//return length of string
unsigned int strLen(const char* str);
//return a new string that begin with str1 and end with str2
char* concat(const char* str1, const char* str2);
/*return 0 if str1 is equal to str2
* negative if is less
* positive if is greate
* lexicographic order
*/
int strComp(const char* str1, const char* str2);

#endif
