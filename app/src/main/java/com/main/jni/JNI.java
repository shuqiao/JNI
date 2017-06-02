package com.main.jni;

/**
 * JAVA调用C代码
 * <p>
 * Created by shuqiao on 2017/5/16.
 */

public class JNI {

    /**
     * 定义native方法
     * 调用C代码对应的方法
     */

    //加法运算，返回结果
    public native int add(int x, int y);

    //传入字符串，C进行拼接并返回
    public native String sayHello(String s);

    //C将所有数加10
    public native int[] increaseArrayEles(int[] intArray);

    //检查密码是否正确，正确返回200，否则返回400
    public native int checkPwd(String pwd);

}
