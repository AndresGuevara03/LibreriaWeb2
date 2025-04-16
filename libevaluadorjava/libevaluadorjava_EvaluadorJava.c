#include <jni.h>
#include "libevaluadorjava_EvaluadorJava.h"
/*
 * Class:     libevaluadorjava_EvaluadorJava
 * Method:    evaluar
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_libevaluadorjava_EvaluadorJava_evaluar
  (JNIEnv * env, jobject obj, jstring problemName, jstring content){
     const char* _problemName = (*env)->GetStringUTFChars(env, problemName, 0);
     
     FILE* file = fopen();
  }
