#ifndef PIC_PREVIEW_CONTROLLER_H
#define PIC_PREVIEW_CONTROLLER_H

#include <queue>
#include <unistd.h>
#include <pthread.h>
#include <android/native_window.h>
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include "./pic_preview_render.h"
#include "./pic_preview_texture.h"
#include "./egl_core.h"
#include "rgba_frame.h"
#include "png_decoder.h"

class PicPreviewController {
public:
	PicPreviewController();
	virtual ~PicPreviewController();

	bool start(char* spriteFilePath);
	void stop();
	void setWindow(ANativeWindow* window);
	void resetSize(int width, int height);
private:
	PicPreviewRender* renderer;
	PicPreviewTexture* picPreviewTexture;

	PngPicDecoder* decoder;

	int screenWidth;
	int screenHeight;
	enum RenderThreadMessage {
		MSG_NONE = 0, MSG_WINDOW_SET, MSG_RENDER_LOOP_EXIT
	};

	pthread_t _threadId;
	pthread_mutex_t mLock;
	pthread_cond_t mCondition;
	enum RenderThreadMessage _msg;

	// android window, supported by NDK r5 and newer
	ANativeWindow* _window;

	EGLCore* eglCore;
	EGLSurface previewSurface;

	// Helper method for starting the thread
	static void* threadStartCallback(void *myself);
	// RenderLoop is called in a rendering thread started in start() method
	// It creates rendering context and renders scene until stop() is called
	void renderLoop();
	bool initialize();
	void updateTexImage();
	void drawFrame();
	void destroy();

};

#endif // PIC_PREVIEW_CONTROLLER_H
