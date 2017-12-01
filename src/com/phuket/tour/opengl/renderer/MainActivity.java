package com.phuket.tour.opengl.renderer;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;

public class MainActivity extends Activity {


	static {
		System.loadLibrary("songstudio");
	}
	private Button go_btn;
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		go_btn = (Button) findViewById(R.id.go_btn);
		go_btn.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View v) {
				Intent intent = new Intent(MainActivity.this, PngPreviewActivity.class);
				startActivity(intent);
			}
		});
	}

}
