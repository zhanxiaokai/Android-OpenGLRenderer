#include "com_phuket_tour_opengl_renderer_PngPreviewController.h"

#include <android/native_window.h>
#include <android/native_window_jni.h>
#include "./librenderer/pic_preview_controller.h"

#define LOG_TAG "PicPreviewController"

static ANativeWindow *window = 0;
static PicPreviewController *controller = 0;

JNIEXPORT void JNICALL Java_com_phuket_tour_opengl_renderer_PngPreviewController_init
(JNIEnv * env, jobject obj, jstring pngFilePathParam) {
	controller = new PicPreviewController();
	char* pngFilePath = (char*) env->GetStringUTFChars(pngFilePathParam, NULL);
	controller->start(pngFilePath);
	env->ReleaseStringUTFChars(pngFilePathParam, pngFilePath);
}

JNIEXPORT void JNICALL Java_com_phuket_tour_opengl_renderer_PngPreviewController_setSurface
(JNIEnv * env, jobject obj, jobject surface) {
	if (surface != 0 && NULL != controller) {
		window = ANativeWindow_fromSurface(env, surface);
		LOGI("Got window %p", window);
		controller->setWindow(window);
	} else if (window != 0) {
		LOGI("Releasing window");
		ANativeWindow_release(window);
		window = 0;
	}
}

JNIEXPORT void JNICALL Java_com_phuket_tour_opengl_renderer_PngPreviewController_resetSize
(JNIEnv * env, jobject obj, jint width, jint height) {
	if (NULL != controller) {
		controller->resetSize(width, height);
	}
}

JNIEXPORT void JNICALL Java_com_phuket_tour_opengl_renderer_PngPreviewController_stop
(JNIEnv * env, jobject obj) {
	if (NULL != controller) {
		controller->stop();
		delete controller;
		controller = NULL;
	}
}
