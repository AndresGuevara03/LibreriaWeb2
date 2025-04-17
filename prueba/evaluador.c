#include <stdio.h>
#include <stdlib.h>
#include <libstr.h>
#include <sys/time.h>

void setInputs(FILE* inputSource , FILE* inputTarget);
void getStatus(char** status, FILE* outputSource , FILE* outputTarget, int exitCode, int ms, int timeLimit);

int main(int cantArgs, char** args){
  int numTest = 1;
  char** status = malloc(4 * sizeof(char*));
  FILE* inputs = fopen("inputs/WayTooLongWords.txt", "r");
  FILE* outputs = fopen("outputs/WayTooLongWords.txt", "r");
  int timeLimit = 1000;
  struct timeval stop, start;
  while(!feof(inputs)){
    FILE* input = fopen("inputs/input.txt", "w");
    setInputs(inputs, input);
    FILE* output = fopen("log.txt", "r");
    system("javac pruebajava/WayTooLongWords.java");
    gettimeofday(&start, NULL);
    int exitCode = system("java pruebajava.WayTooLongWords > log.txt 2>&1 0< inputs/input.txt");
    gettimeofday(&stop, NULL);
    int ms = (stop.tv_sec - start.tv_sec) * 1000 + (stop.tv_usec - start.tv_usec) / 1000;
    getStatus(status, outputs, output, exitCode, ms, timeLimit);
    printf("Test case #%d\n", numTest);
    printf("%s\r%s\r%s\r%s\r\n", status[0], status[1], status[2], status[3]);
    for(int i = 0; i < 3; i++){
      free(status[i]);
      status[i] = NULL;
    }
    numTest++;
  }
  free(status);
  status = NULL;
  fclose(inputs);
  fclose(outputs);
  return (EXIT_SUCCESS);
}

void setInputs(FILE* inputSource , FILE* inputTarget){
  char* line = NULL;
  size_t aux;
  while(getline(&line, &aux, inputSource) != -1 && strComp(line, "\n")){
    fputs(line, inputTarget);
  }
  fclose(inputTarget);
}

void getStatus(char** status, FILE* outputSource , FILE* outputTarget, int exitCode, int ms, int timeLimit){
  char* answer = NULL;
  char* out = NULL;
  size_t aux;
  while(getline(&answer, &aux, outputSource) != -1 && strComp(answer, "\n")){
    getline(&out, &aux, outputTarget);
    status[0] = concat("output: ", out);
    status[1] = concat("answer: ", answer);
    char* temp = concat("time: ", intToStr(ms));
    status[2] = concat(temp, " ms\n");
    free(temp);
    temp = NULL;
    if(ms >= timeLimit)
      status[3] = "status: Time limit exceeded\n";
    else if(strComp(answer, out))
      status[3] = "status: Wrong answer\n";
    else if(exitCode)
      status[3] = "status: Runtime exception\n";
    else
      status[3] = "status: Ok\n";
  }
  fclose(outputTarget);
}

