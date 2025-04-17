#include <stdio.h>
#include <stdlib.h>
#include <libstr.h>

int main(int cantArgs, char** args){
  FILE* inputs = fopen("inputs/theatreSquare.txt", "r");
  FILE* outputs = fopen("outputs/theatreSquare.txt", "r");
  char* line;
  size_t lineLen;
  while(getline(&line, &lineLen, inputs) != -1){
    FILE* input = fopen("inputs/input.txt", "w");
    FILE* output = fopen("log.txt", "r");
    fputs(line, input);
    fclose(input);
    system("javac pruebajava/theatreSquare.java");
    system("java pruebajava.theatreSquare > log.txt 2>&1 0< inputs/input.txt");
    char* answer;
    char* out;
    getline(&answer, &lineLen, outputs);
    getline(&out, &lineLen, output);
    fclose(output);
    if(!strComp(answer, out)){
      printf("answer: %s\routput: %s\rstatus: ok\n", answer, out);
    }else{
      printf("answer: %s\routput: %s\rstatus: wrong\n", answer, out);
    }

    free(out);
    free(answer);
    out = NULL;
    answer = NULL;
  }
  free(line);
  return (EXIT_SUCCESS);
}
