#include <stdio.h>
#include <cjson/cJSON.h>
#include <libeval.h>

int main(int cantArgs, char** args){
  createSolution("x", "x");
  cJSON* result = getVeredict("WayTooLongWords", 1000);
  printf("%s\n", cJSON_Print(result));
  cJSON_Delete(result);
  return (EXIT_SUCCESS);
}
