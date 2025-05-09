#include "libeval.h"
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

int getStatus(char** status, const char** outputSource, int cantOutput, FILE* outputTarget){
  char* out = NULL;
  size_t aux;
  int wrong = 0;
  char* temp;
  strCopy(&status[0], "");
  strCopy(&status[1], "");
  for(int i = 0; i < cantOutput; i++){
    getline(&out, &aux, outputTarget);
    size_t outLen = strLen(out);
    out[outLen - 1] = '\0';
    wrong |= strComp(outputSource[i], out);
    strCopy(&temp, out);
    concat(&status[0], temp);
    concat(&status[1], outputSource[i]);
    free(temp);
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
    int wrong = getStatus(statusTemp, outputs[i], outputsCant[i], output);
    if(ms >= timeLimit)
      statusTemp[2] = "Time limit exceeded";
    else if(wrong)
      statusTemp[2] = "Wrong answer";
    else
      statusTemp[2] = "Ok";
    cJSON_AddNumberToObject(status, "testCase", i + 1);
    cJSON_AddStringToObject(status, "output", statusTemp[0]);
    cJSON_AddStringToObject(status, "answer", statusTemp[1]);
    cJSON_AddNumberToObject(status, "time", ms);
    cJSON_AddStringToObject(status, "status", statusTemp[2]);
    cJSON_AddItemToArray(statuses, status);
    if(!strComp(statusTemp[2], "Wrong answer") 
        || !strComp(statusTemp[2], "Time limit exceeded")){
      cJSON_AddStringToObject(veredict, "status", statusTemp[2]);
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
