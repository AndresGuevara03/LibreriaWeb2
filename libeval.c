#include "libeval.h"
#include <cjson/cJSON.h>
#include <libstr.h>
#include <stdio.h>
#include <stdlib.h>

void setInputs(const char** lines, int cantLines, FILE* inputTarget){
  char* line;
  for(int i = 0; i < cantLines; i++){
    fputs(lines[i], inputTarget);
    fputc('\n', inputTarget);
  }
  fclose(inputTarget);
}

int getStatus(cJSON* status, const char** outputSource, int cantOutput, FILE* outputTarget){
  char* out = NULL;
  size_t aux;
  int wrong = 0;
  cJSON* outputs = cJSON_AddArrayToObject(status, "outputs");
  cJSON* answers = cJSON_AddArrayToObject(status, "answers");
  for(int i = 0; i < cantOutput; i++){
    getline(&out, &aux, outputTarget);
    size_t outLen = strLen(out);
    out[outLen - 1] = '\0';
    wrong |= strComp(outputSource[i], out);
    cJSON* outJson = cJSON_CreateString(out);
    cJSON* ansJson = cJSON_CreateString(outputSource[i]);
    cJSON_AddItemToArray(outputs, outJson);
    cJSON_AddItemToArray(answers, ansJson);
  }
  fclose(outputTarget);
  return wrong;
}

int runSolution(const char* run){
  struct timeval stop, start;
  gettimeofday(&start, NULL);
  system(run);
  gettimeofday(&stop, NULL);
  int ms = (stop.tv_sec - start.tv_sec) * 1000 + (stop.tv_usec - start.tv_usec) / 1000;
  return ms;
}

void createSolution(const char* problemName, const char* content){
  char* solutionPath = NULL;
  const char* home = getenv("HOME");
  strCopy(&solutionPath, home);
  concat(&solutionPath, "/libreria-web/aplicacion/");
  concat(&solutionPath, problemName);
  concat(&solutionPath, ".java");
  FILE* solutionFile = fopen(solutionPath, "w");
  fputs(content, solutionFile);
  fclose(solutionFile);
}

cJSON* getVeredict(const char* problemName, const char*** inputs, const char*** outputs,int cantTest, int* inputsCant, int* outputsCant, int timeLimit){
  int numTest = 1;
  int worstMs = 0;
  const char* home = getenv("HOME");
  char* compile = NULL;
  strCopy(&compile, "javac ");
  concat(&compile, home);
  concat(&compile, "/libreria-web/aplicacion/");
  concat(&compile, problemName);
  concat(&compile, ".java");
  system(compile);
  char* run = NULL;
  strCopy(&run, "java -cp ");
  concat(&run, home);
  concat(&run, "/libreria-web/aplicacion/ ");
  concat(&run, problemName);
  concat(&run, " > ");
  concat(&run, home);
  concat(&run, "/libreria-web/aplicacion/log.txt 2>&1 0< ");
  concat(&run, home);
  concat(&run, "/libreria-web/aplicacion/input.txt");
  char** statusTemp = malloc(4 * sizeof(char*));
  cJSON* veredict = cJSON_CreateObject();
  cJSON* statuses = cJSON_AddArrayToObject(veredict, "statuses");
  struct timeval stop, start;
  for(int i = 0; i < cantTest; i++){
    cJSON* status = cJSON_CreateObject();
    char* inputPath;
    char* outputPath;
    strCopy(&inputPath, home);
    concat(&inputPath, "/libreria-web/aplicacion/input.txt");
    FILE* input = fopen(inputPath, "w");
    setInputs(inputs[i],inputsCant[i], input);
    strCopy(&outputPath, home);
    concat(&outputPath, "/libreria-web/aplicacion/log.txt");
    FILE* output = fopen(outputPath, "r");
    int ms = runSolution(run);
    if(ms > worstMs) worstMs = ms;
    cJSON_AddNumberToObject(status, "testCase", i + 1);
    int wrong = getStatus(status, outputs[i], outputsCant[i], output);
    char* statusItem;
    if(ms >= timeLimit)
      strCopy(&statusItem,"Time limit exceeded");
    else if(wrong)
      strCopy(&statusItem,"Wrong answer");
    else
      strCopy(&statusItem,"Ok");
    cJSON_AddNumberToObject(status, "time", ms);
    cJSON_AddStringToObject(status, "status", statusItem);
    cJSON_AddItemToArray(statuses, status);
    if(!strComp(statusItem, "Wrong answer") 
        || !strComp(statusItem, "Time limit exceeded")){
      cJSON_AddStringToObject(veredict, "status", statusItem);
      cJSON_AddNumberToObject(veredict, "time", worstMs);
      free(statusTemp);
      return veredict;
    }
  }
  free(compile);
  free(run);
  cJSON_AddStringToObject(veredict, "status", "Accepted");
  cJSON_AddNumberToObject(veredict, "time", worstMs);
  free(statusTemp);
  return veredict;
}
