#ifndef LIBEVAL_H
#define LIBEVAL_H

#include <stdio.h>
#include <stdlib.h>
#include <libstr.h>
#include <sys/time.h>
#include <cjson/cJSON.h>
void setInputs(FILE* inputSource , FILE* inputTarget);
void getStatus(char** status, FILE* outputSource , FILE* outputTarget, int ms, int timeLimit);
int runSolution(const char* problemName);
void openFile(const char* problemName, FILE** inputFile, FILE** outputFile);
void createSolution(const char* problemName, const char* content);
cJSON* getVeredict(const char* problemName, int timeLimit);
#endif
