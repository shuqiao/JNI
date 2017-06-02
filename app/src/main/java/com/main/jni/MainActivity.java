package com.main.jni;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    {
        System.loadLibrary("Hello");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        JNI jni = new JNI();

        //Java调用C
//        StringBuilder sb = new StringBuilder();
//        sb.append("3 + 2 = " + jni.add(3, 2));
//        sb.append("\n");
//        sb.append("ori: Java , now : " + jni.sayHello("Java"));
//        sb.append("\n");
//        int arr[] = {1, 2, 3, 4, 5};
//        jni.increaseArrayEles(arr);
//        sb.append("ori: 1,2,3,4,5  now:" + arr[0] + " , " + arr[1] + " , " + arr[2] + " , " + arr[3] + " , " + arr[4]);
//        sb.append("\n");
//        sb.append("pwd : 12345 , code = " + jni.checkPwd("12345"));
//        sb.append("\n");
//        sb.append("pwd : 123456 , code = " + jni.checkPwd("123456"));
//        sb.append("\n");
//        tv.setText(sb.toString());

        //C调用Java
//        CJNI cjni = new CJNI();
//        cjni.callbackAdd();
//        cjni.callbackHelloFromJava();
//        cjni.callbackPrintString();
//        cjni.callbackSayHello();
//        cjni.callbackShowToast();

        callbackShowToast();

    }


    public native void callbackShowToast();


    public void showToast() {
        Log.e("TAG", "showToast");
        Toast.makeText(this, "showToast", Toast.LENGTH_LONG).show();
    }
}
