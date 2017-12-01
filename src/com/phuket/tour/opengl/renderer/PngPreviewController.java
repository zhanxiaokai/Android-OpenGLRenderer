package com.phuket.tour.opengl.renderer;

import android.view.Surface;

public class PngPreviewController {

	public native void init(String picPath);

	public native void setSurface(Surface surface);

	public native void resetSize(int width, int height);

	public native void stop();

}
