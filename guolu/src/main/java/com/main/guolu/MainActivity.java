package com.main.guolu;

import android.app.Activity;
import android.os.SystemClock;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;

public class MainActivity extends Activity {

    {
        System.loadLibrary("guolu");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        final PressureView view = new PressureView(this);
        setContentView(view);

        new Thread() {
            @Override
            public void run() {
                while (true) {
                    SystemClock.sleep(1000);
                    int pressure = Math.abs(getPressure());//0～250
                    Log.e("TEST", "pressure = " + pressure);
                    view.setPressure(pressure);
//                    if (pressure > 220) {
//                        break;
//                    }
                }
            }
        };
    }

    public native int getPressure();
}
