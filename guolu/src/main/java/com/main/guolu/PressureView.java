package com.main.guolu;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.util.Log;
import android.view.View;

/**
 * Created by shuqiao on 2017/5/17.
 */

public class PressureView extends View {

    private int pressure;
    private Paint paint;

    public PressureView(Context context) {
        super(context);
        paint = new Paint();
        paint.setAntiAlias(true);//设置抗锯齿
    }

    public void setPressure(int pressure) {
        this.pressure = pressure;
        postInvalidate();
    }

    @Override
    protected void onDraw(Canvas canvas) {
        super.onDraw(canvas);

        //1.>220 爆炸

        //2.<220 >200 红色

        //3.<200 绿色


        if (pressure >= 220) {
            canvas.drawText("爆炸了", 10, getHeight() / 2, paint);
        } else if (pressure >= 200) {
            paint.setColor(Color.GRAY);
            canvas.drawRect(10, 10, 60, 260, paint);

            paint.setColor(Color.RED);
            canvas.drawRect(10, 10, 60, 260 - pressure, paint);
        } else {
            paint.setColor(Color.GRAY);
            canvas.drawRect(10, 10, 60, 260, paint);

            paint.setColor(Color.GREEN);
            canvas.drawRect(10, 10, 60, 260 - pressure, paint);
        }
    }
}
