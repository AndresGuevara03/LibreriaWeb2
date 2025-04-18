#include "libeval.h"
#include <stdio.h>
#include <stdlib.h>

void setInputs(FILE* inputSource , FILE* inputTarget){
  char* line = NULL;
  size_t aux;
  while(getline(&line, &aux, inputSource) != -1 && strComp(line, "\n")){
    fputs(line, inputTarget);
  }
  fclose(inputTarget);
}

void getStatus(char** status, FILE* outputSource , FILE* outputTarget, int ms, int timeLimit){
  char* answer = NULL;
  char* out = NULL;
  size_t aux;
  int wrong = 0;
  char* temp = NULL;
  strCopy(&status[0], "");
  strCopy(&status[1], "");
  while(getline(&answer, &aux, outputSource) != -1 && strComp(answer, "\n")){
    getline(&out, &aux, outputTarget);
    wrong |= strComp(answer, out);
    size_t outLen = strLen(out);
    out[outLen - 1] = ';';
    strCopy(&temp, out);
    concat(&status[0], temp);
    free(temp);
    temp = NULL;
    size_t answerLen = strLen(answer);
    answer[answerLen - 1] = ';';
    strCopy(&temp, answer);
    concat(&status[1], temp);
    free(temp);
    temp = NULL;
  }
  free(temp);
  temp = NULL;
  if(ms >= timeLimit)
    status[2] = "Time limit exceeded";
  else if(wrong)
    status[2] = "Wrong answer";
  else
    status[2] = "Ok";
  fclose(outputTarget);
}

int runSolution(const char* problemName){
  struct timeval stop, start;
  char* compile = NULL;
  const char* home = getenv("HOME");
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
  concat(&run, "/libreria-web/aplicacion/inputs/input.txt");
  gettimeofday(&start, NULL);
  int exitCode = system(run);
  gettimeofday(&stop, NULL);
  int ms = (stop.tv_sec - start.tv_sec) * 1000 + (stop.tv_usec - start.tv_usec) / 1000;
  free(compile);
  compile = NULL;
  free(run);
  run = NULL;
  return ms;
}

void openFile(const char* problemName, FILE** inputFile, FILE** outputFile){
  char* inputPath = NULL;
  const char* home = getenv("HOME");
  strCopy(&inputPath, home);
  concat(&inputPath,"/libreria-web/aplicacion/inputs/");
  concat(&inputPath, problemName);
  concat(&inputPath, ".txt");
  char* outputPath = NULL;
  strCopy(&outputPath, home);
  concat(&outputPath,"/libreria-web/aplicacion/outputs/");
  concat(&outputPath, problemName);
  concat(&outputPath, ".txt");
  *inputFile = fopen(inputPath, "r");
  *outputFile = fopen(outputPath, "r");
  free(inputPath);
  inputPath = NULL;
  free(outputPath);
  outputPath = NULL;
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

cJSON* getVeredict(const char* problemName, int timeLimit){
  int numTest = 1;
  int worstMs = 0;
  const char* home = getenv("HOME");
  char** statusTemp = malloc(4 * sizeof(char*));
  cJSON* veredict = cJSON_CreateObject();
  cJSON* statuses = cJSON_AddArrayToObject(veredict, "statuses");
  FILE* inputs;
  FILE* outputs;
  openFile(problemName, &inputs, &outputs);
  struct timeval stop, start;
  while(!feof(inputs)){
    cJSON* status = cJSON_CreateObject();
    char* inputPath = NULL;
    char* outputPath = NULL;
    strCopy(&inputPath, home);
    concat(&inputPath, "/libreria-web/aplicacion/inputs/input.txt");
    FILE* input = fopen(inputPath, "w");
    setInputs(inputs, input);
    strCopy(&outputPath, home);
    concat(&outputPath, "/libreria-web/aplicacion/log.txt");
    FILE* output = fopen(outputPath, "r");
    int ms = runSolution(problemName);
    if(ms > worstMs) worstMs = ms;
    getStatus(statusTemp, outputs, output, ms, timeLimit);
    cJSON_AddNumberToObject(status, "testCase", numTest);
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
      statusTemp = NULL;
      fclose(inputs);
      fclose(outputs);
      return veredict;
    }
    numTest++;
  }
  cJSON_AddStringToObject(veredict, "status", "Accepted");
      cJSON_AddNumberToObject(veredict, "time", worstMs);
  free(statusTemp);
  statusTemp = NULL;
  fclose(inputs);
  fclose(outputs);
  return veredict;
}
