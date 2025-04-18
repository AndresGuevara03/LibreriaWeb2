#include <jni.h>
#include "libevaluador_Evaluador.h"
#include <libeval.h>
#include <cjson/cJSON.h>

/*
 * Class:     libevaluador_Evaluador
 * Method:    evaluar
 * Signature: (Ljava/lang/String;ILjava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_libevaluador_Evaluador_evaluar__Ljava_lang_String_2ILjava_lang_String_2
  (JNIEnv * env, jobject obj, jstring problemName, jint timeLimit, jstring content){
    const char* problemNameStr = (*env)->GetStringUTFChars(env, problemName, NULL);
    const char* contentStr = (*env)->GetStringUTFChars(env, content, NULL);
    createSolution(problemNameStr, contentStr);
    cJSON* veredict = getVeredict(problemNameStr, (int) timeLimit);
    jstring respuesta = (*env)->NewStringUTF(env, cJSON_Print(veredict));
    (*env)->ReleaseStringUTFChars(env, problemName, problemNameStr);
    (*env)->ReleaseStringUTFChars(env, content, contentStr);
    cJSON_Delete(veredict);
    return respuesta;
  }

/*
 * Class:     libevaluador_Evaluador
 * Method:    evaluar
 * Signature: (Ljava/lang/String;I[B)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_libevaluador_Evaluador_evaluar__Ljava_lang_String_2I_3B
  (JNIEnv * env, jobject obj, jstring problemName, jint timeLimit, jbyteArray content){
    const char* problemNameStr = (*env)->GetStringUTFChars(env, problemName, NULL);
    int contentLen = (*env)->GetArrayLength(env, content);
    char* contentStr = (char*) (*env)->GetByteArrayElements(env, content, NULL);
    /*char* contentStr = malloc((contentLen + 1) * sizeof(char));
    for(int i = 0; i < contentLen; i++)
      contentStr = (char)((jbyte)(*env)->GetByteArrayElement(env, content, i));*/
    createSolution(problemNameStr, contentStr);
    cJSON* veredict = getVeredict(problemNameStr, (int) timeLimit);
    jstring respuesta = (*env)->NewStringUTF(env, cJSON_Print(veredict));
    (*env)->ReleaseStringUTFChars(env, problemName, problemNameStr);
    cJSON_Delete(veredict);
    return respuesta;
  }
  
/*
 * Class:     libevaluador_Evaluador
 * Method:    cargarProblema
 * Signature: (Ljava/lang/String;ILjava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_libevaluador_Evaluador_cargarProblema__Ljava_lang_String_2ILjava_lang_String_2Ljava_lang_String_2
  (JNIEnv * env, jobject obj, jstring problemName, jint timeLimit, jstring inputs, jstring outputs){
    
  }
  
/*
 * Class:     libevaluador_Evaluador
 * Method:    cargarProblema
 * Signature: (Ljava/lang/String;I[B[B)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_libevaluador_Evaluador_cargarProblema__Ljava_lang_String_2I_3B_3B
  (JNIEnv *env, jobject obj, jstring problemName, jint timeLimit, jbyteArray inputs, jbyteArray outputs){
    
  }

