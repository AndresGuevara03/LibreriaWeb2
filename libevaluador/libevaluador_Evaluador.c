#include <jni.h>
#include "libevaluador_Evaluador.h"
#include <libeval.h>
#include <cjson/cJSON.h>
#include <stdlib.h>
/*
 * Class:     libevaluador_Evaluador
 * Method:    evaluar
 * Signature: (Ljava/lang/String;[[Ljava/lang/String;[[Ljava/lang/String;ILjava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_libevaluador_Evaluador_evaluar
  (JNIEnv *env, jobject obj, jstring problemName, jobjectArray outputs, jobjectArray inputs, jint timeLimit, jstring content){
    const char* problemNameStr = (*env)->GetStringUTFChars(env, problemName, NULL);
    const char* contentStr = (*env)->GetStringUTFChars(env, content, NULL);
    int cantTest = (*env)->GetArrayLength(env, outputs);
    const char*** cOutputs = malloc(cantTest * sizeof(char**));
    int* cantOutputs = malloc(cantTest * sizeof(int));
    for(int i = 0; i < cantTest; i++){
      jobjectArray jarrOut = (jobjectArray)(*env)->GetObjectArrayElement(env, outputs, i);
      cantOutputs[i] = (*env)->GetArrayLength(env, jarrOut);
      cOutputs[i] = malloc(cantOutputs[i] * sizeof(char*));
      for(int j = 0; j < cantOutputs[i]; j++){
        jstring jstr = (jstring) (*env)->GetObjectArrayElement(env, jarrOut, j);
        cOutputs[i][j] = (*env)->GetStringUTFChars(env, jstr, NULL);
      }
    }
    const char*** cInputs = malloc(cantTest * sizeof(char**));
    int* cantInputs = malloc(cantTest * sizeof(int));
    for(int i = 0; i < cantTest; i++){
      jobjectArray jarrIn = (jobjectArray)(*env)->GetObjectArrayElement(env, inputs, i);
      cantInputs[i] = (*env)->GetArrayLength(env, jarrIn);
      cInputs[i] = malloc(cantInputs[i] * sizeof(char*));
      for(int j = 0; j < cantInputs[i]; j++){
        jstring jstr = (jstring) (*env)->GetObjectArrayElement(env, jarrIn, j);
        cInputs[i][j] = (*env)->GetStringUTFChars(env, jstr, NULL);
      }
    }
    createSolution(problemNameStr, contentStr);
    cJSON* veredict = getVeredict(problemNameStr, cInputs, cOutputs, cantTest, cantInputs, cantOutputs, (int) timeLimit);
    jstring respuesta = (*env)->NewStringUTF(env, cJSON_Print(veredict));
    (*env)->ReleaseStringUTFChars(env, problemName, problemNameStr);
    (*env)->ReleaseStringUTFChars(env, content, contentStr);
    cJSON_Delete(veredict);
    return respuesta;
  }
