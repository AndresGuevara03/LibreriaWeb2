#ifndef LIBEVAL_H
#define LIBEVAL_H

#include <stdio.h>
#include <stdlib.h>
#include <libstr.h>
#include <sys/time.h>
#include <cjson/cJSON.h>
void setInputs(const char** lines, int cantLines, FILE* inputTarget);
int getStatus(char** status, const char** outputSource, int cantOutput, FILE* outputTarget);
int runSolution(const char* compile, const char* run);
void createSolution(const char* problemName, const char* content);
cJSON* getVeredict(const char* problemName, const char*** inputs, const char*** outputs,int cantTest, int* inputsCant, int* outputsCant, int timeLimit);
#endif
