#include "./pic_preview_controller.h"

#define LOG_TAG "PicPreviewController"

PicPreviewController::PicPreviewController() :
		_msg(MSG_NONE), previewSurface(0), eglCore(0) {
	LOGI("VideoDutePlayerController instance created");
	pthread_mutex_init(&mLock, NULL);
	pthread_cond_init(&mCondition, NULL);
	renderer = new PicPreviewRender();
	this->screenWidth = 720;
	this->screenHeight = 720;
	decoder = NULL;
}

PicPreviewController::~PicPreviewController() {
	LOGI("VideoDutePlayerController instance destroyed");
	pthread_mutex_destroy(&mLock);
	pthread_cond_destroy(&mCondition);
}

bool PicPreviewController::start(char* spriteFilePath) {
	LOGI("Creating VideoDutePlayerController thread");
	decoder = new PngPicDecoder();
	decoder->openFile(spriteFilePath);
	pthread_create(&_threadId, 0, threadStartCallback, this);
	return true;
}

void PicPreviewController::stop() {
	LOGI("Stopping VideoDutePlayerController Render thread");
	/*send message to render thread to stop rendering*/
	pthread_mutex_lock(&mLock);
	_msg = MSG_RENDER_LOOP_EXIT;
	pthread_cond_signal(&mCondition);
	pthread_mutex_unlock(&mLock);

	LOGI("we will join render thread stop");
	pthread_join(_threadId, 0);
	LOGI("VideoDutePlayerController Render thread stopped");
}

void PicPreviewController::setWindow(ANativeWindow *window) {
	/*notify render thread that window has changed*/
	pthread_mutex_lock(&mLock);
	_msg = MSG_WINDOW_SET;
	_window = window;
	pthread_cond_signal(&mCondition);
	pthread_mutex_unlock(&mLock);
}

void PicPreviewController::resetSize(int width, int height) {
	LOGI("VideoDutePlayerController::resetSize width:%d; height:%d", width, height);
	pthread_mutex_lock(&mLock);
	this->screenWidth = width;
	this->screenHeight = height;
	renderer->resetRenderSize(0, 0, width, height);
	pthread_cond_signal(&mCondition);
	pthread_mutex_unlock(&mLock);
}

void* PicPreviewController::threadStartCallback(void *myself) {
	PicPreviewController *controller = (PicPreviewController*) myself;
	controller->renderLoop();
	pthread_exit(0);
	return 0;
}

void PicPreviewController::renderLoop() {
	bool renderingEnabled = true;
	LOGI("renderLoop()");
	while (renderingEnabled) {
		pthread_mutex_lock(&mLock);
		/*process incoming messages*/
		switch (_msg) {
		case MSG_WINDOW_SET:
			initialize();
			break;
		case MSG_RENDER_LOOP_EXIT:
			renderingEnabled = false;
			destroy();
			break;
		default:
			break;
		}
		_msg = MSG_NONE;

		if (eglCore) {
			eglCore->makeCurrent(previewSurface);
			this->drawFrame();
			pthread_cond_wait(&mCondition, &mLock);
			usleep(100 * 1000);
		}

		pthread_mutex_unlock(&mLock);
	}
	LOGI("Render loop exits");

	return;
}

bool PicPreviewController::initialize() {
	eglCore = new EGLCore();
	eglCore->init();
	previewSurface = eglCore->createWindowSurface(_window);
	eglCore->makeCurrent(previewSurface);

	picPreviewTexture = new PicPreviewTexture();
	bool createTexFlag = picPreviewTexture->createTexture();
	if(!createTexFlag){
		LOGE("createTexFlag is failed...");
		destroy();
		return false;
	}

	this->updateTexImage();

	bool isRendererInitialized = renderer->init(screenWidth, screenHeight, picPreviewTexture);
	if (!isRendererInitialized) {
		LOGI("Renderer failed on initialized...");
		return false;
	}
	LOGI("Initializing context Success");
	return true;
}

void PicPreviewController::destroy() {
	LOGI("dealloc renderer ...");
	if (NULL != renderer) {
		renderer->dealloc();
		delete renderer;
		renderer = NULL;
	}
	if(eglCore){
		eglCore->releaseSurface(previewSurface);
		eglCore->release();
		eglCore = NULL;
	}
	return;
}

void PicPreviewController::updateTexImage() {
	if (decoder) {
		const RawImageData raw_image_data = decoder->getRawImageData();
		LOGI("raw_image_data Meta: width is %d height is %d size is %d colorFormat is %d", raw_image_data.width, raw_image_data.height, raw_image_data.size,
				raw_image_data.gl_color_format);
		LOGI("colorFormat is %d", GL_RGBA);
		picPreviewTexture->updateTexImage((byte*) raw_image_data.data, raw_image_data.width, raw_image_data.height);
		decoder->releaseRawImageData(&raw_image_data);
	}
}

void PicPreviewController::drawFrame() {
	renderer->render();
	if (!eglCore->swapBuffers(previewSurface)) {
		LOGE("eglSwapBuffers() returned error %d", eglGetError());
	}
}
