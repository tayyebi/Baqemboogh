package com.gordarg.rexa.baqemboogh;

import android.app.Dialog;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    // کتابخانه های سی‌پلاس‌پلاس را لود میکند
    static {
        System.loadLibrary("native-lib");
    }

    TextView textView;
    EditText editText;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Load();

        textView = (TextView) findViewById(R.id.textView);
        editText = (EditText) findViewById(R.id.editText);


        ((ImageView)findViewById(R.id.imageView)).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                final Dialog hint = new Dialog(MainActivity.this);
                hint.setContentView(R.layout.hint);
                TextView txt = (TextView)hint.findViewById(R.id.textView_hint);
                txt.setText(Hint());
                txt.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View v) {
                        hint.dismiss();
                    }
                });
                hint.show();
            }
        });

    }

    public native String Translate(String Word);
    public native void Load();
    public native String Hint();

    public void JustDoIt(View view) {
        textView.setText(Translate(String.valueOf(editText.getText())));
    }
}
