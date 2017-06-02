//
// Created by 舒乔 on 2017/5/16.
//

#include <string.h>
#include <jni.h>

//将jni中的jstring转换成C中的char*
char *_JString2CStr(JNIEnv *env, jstring jstr) {
    char *rtn = NULL;
    jclass clsstring = (*env)->FindClass(env, "java/lang/String");
    jstring strencode = (*env)->NewStringUTF(env, "utf-8");
    jmethodID mid = (*env)->GetMethodID(env, clsstring, "getBytes", "(Ljava/lang/String;)[B");
    jbyteArray barr = (jbyteArray) (*env)->CallObjectMethod(env, jstr, mid, strencode);
    jsize alen = (*env)->GetArrayLength(env, barr);
    jbyte *ba = (*env)->GetByteArrayElements(env, barr, JNI_FALSE);
    if (alen > 0) {
        rtn = (char *) malloc(alen + 1);
        memcpy(rtn, ba, alen);
        rtn[alen] = 0;
    }
    (*env)->ReleaseByteArrayElements(env, barr, ba, 0);
    return rtn;
}


/**
 * @param env
 * @param jobj
 * @param ja
 * @param jb
 * @return jint
 *
 *  */
jint Java_com_main_jni_JNI_add
        (JNIEnv *env, jobject jobj, jint ja, jint jb) {
    int result = ja + jb;
    return result;
}

jstring Java_com_main_jni_JNI_sayHello
        (JNIEnv *env, jobject jobj, jstring js) {

    char *java = _JString2CStr(env, js);//将jstring转换成char*

    char *c = " and C";

    strcat(java, c);//把拼接的结果放在第一个参数中

    return (*env)->NewStringUTF(env, java);
}

//?????error
jintArray Java_com_main_jni_JNI_increaseArrayEles
        (JNIEnv *env, jobject jobj, jintArray jarr) {
    //获取数组长度
    int size = (*env)->GetArrayLength(env, jarr);
    //将jintArray转换成jint*，false-直接操作原数组，true-复制一份操作
    jint *iArr = (*env)->GetIntArrayElements(env, jarr, JNI_FALSE);
    int i;
    for (i = 0; i < size; i++) {
        *(iArr + i) += 10;
    }

    return jarr;
}

jint Java_com_main_jni_JNI_checkPwd
        (JNIEnv *env, jobject jobj, jstring js) {

    char *ori = "12345";

    char *now = _JString2CStr(env, js);

    int result = strcmp(ori, now);//比较两个字符串是不是相等

    if (result == 0) {
        return 200;
    } else {
        return 400;
    }
}




