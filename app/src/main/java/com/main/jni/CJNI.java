package com.main.jni;

import android.util.Log;

/**
 * Created by shuqiao on 2017/5/16.
 */

public class CJNI {
    public static String TAG = "CJNI";

    /**
     * 当执行方法时，通知C回调Java的对应方法
     */
    public native void callbackAdd();

    public native void callbackHelloFromJava();

    public native void callbackPrintString();

    public native void callbackSayHello();

    public native void callbackShowToast();

    public int add(int x, int y) {
        Log.e(TAG, "add , " + (x + y));
        return x + y;
    }

    public void helloFromJava() {
        Log.e(TAG, "helloFromJava");
    }

    public void printString(String s) {
        Log.e(TAG, "printString , " + s);
    }

    public static void sayHello(String s) {
        Log.e(TAG, "static sayHello " + s);
    }
}
