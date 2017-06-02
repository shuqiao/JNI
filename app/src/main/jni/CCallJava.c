//
// Created by 舒乔 on 2017/5/16.
//

#include <stdio.h>
#include <stdlib.h>
#include <jni.h>
#include <android/log.h>

#define LOG_TAG "CCallJava"

void Java_com_main_jni_CJNI_callbackAdd
        (JNIEnv *env, jobject jobj) {
    //1.加载类获取class对象
    jclass jClass = (*env)->FindClass(env, "com/main/jni/CJNI");
    //2.获取对应方法的Method对象:最后一个参数是方法签名,javap -s
    jmethodID jM = (*env)->GetMethodID(env, jClass, "add", "(II)I");
    //3.创建类对象，实例化
    jobject jobject = (*env)->AllocObject(env, jClass);
    //4.调用方法
    jint result = (*env)->CallIntMethod(env, jobject, jM, 50, 50);

    __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "result = %d", result);
}

void Java_com_main_jni_CJNI_callbackHelloFromJava
        (JNIEnv *env, jobject jobj) {
    //1.加载类获取类对象
    jclass jC = (*env)->FindClass(env, "com/main/jni/CJNI");
    //2.获取方法id
    jmethodID jM = (*env)->GetMethodID(env, jC, "helloFromJava", "()V");
    //3.实例化对象
    jobject jO = (*env)->AllocObject(env, jC);
    //4.调用方法
    (*env)->CallVoidMethod(env, jO, jM);
    __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "helloFromJava");
}

void Java_com_main_jni_CJNI_callbackPrintString
        (JNIEnv *env, jobject jobj) {
    //1.加载类获取类对象
    jclass jC = (*env)->FindClass(env, "com/main/jni/CJNI");
    //2.获取方法id
    jmethodID jM = (*env)->GetMethodID(env, jC, "printString", "(Ljava/lang/String;)V");
    //3.实例化对象
    jobject jO = (*env)->AllocObject(env, jC);
    //4.调用方法
    jstring jS = (*env)->NewStringUTF(env, "From C");
    (*env)->CallVoidMethod(env, jO, jM, jS);
    __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "printString");

}

void Java_com_main_jni_CJNI_callbackSayHello
        (JNIEnv *env, jobject jobj) {
    //1.加载类获取类对象
    jclass jC = (*env)->FindClass(env, "com/main/jni/CJNI");
    //2.获取方法id
    jmethodID jM = (*env)->GetStaticMethodID(env, jC, "sayHello", "(Ljava/lang/String;)V");
    //3.调用方法
    jstring jS = (*env)->NewStringUTF(env, "From C");
    (*env)->CallStaticVoidMethod(env, jC, jM, jS);
    __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "sayHello");
}

void Java_com_main_jni_CJNI_callbackShowToast
        (JNIEnv *env, jobject jobj) {
    //1.加载类获取类对象
    jclass jC = (*env)->FindClass(env, "com/main/jni/MainActivity");
    //2.获取方法id
    jmethodID jM = (*env)->GetMethodID(env, jC, "showToast", "()V");
    //3.实例化对象
    jobject jO = (*env)->AllocObject(env, jC);
    //4.调用方法
    (*env)->CallVoidMethod(env, jO, jM);
    __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "showToast");

}

void Java_com_main_jni_MainActivity_callbackShowToast(JNIEnv *env, jobject instance) {
    //1.加载类获取类对象
    jclass jC = (*env)->FindClass(env, "com/main/jni/MainActivity");
    //2.获取方法id
    jmethodID jM = (*env)->GetMethodID(env, jC, "showToast", "()V");
    //3.调用方法
    (*env)->CallVoidMethod(env, instance, jM);
    __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "showToast");

}





