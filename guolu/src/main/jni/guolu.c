//
// Created by 舒乔 on 2017/5/17.
//

#include <stdio.h>
#include <stdlib.h>
#include <jni.h>

int getPressure() {
    return rand() % 250;
}

jint Java_com_main_guolu_MainActivity_getPressure(JNIEnv *env, jobject instance) {
    return getPressure();
}