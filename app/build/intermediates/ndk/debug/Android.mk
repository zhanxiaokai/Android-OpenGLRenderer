LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := libsongstudio
LOCAL_LDFLAGS := -Wl,--build-id
LOCAL_SRC_FILES := \
	D:\Android\AndroidStudioProjects\OpenGLRender-as\app\src\main\jni\3rdparty\Android.mk \
	D:\Android\AndroidStudioProjects\OpenGLRender-as\app\src\main\jni\3rdparty\libpng\ANNOUNCE \
	D:\Android\AndroidStudioProjects\OpenGLRender-as\app\src\main\jni\3rdparty\libpng\CHANGES \
	D:\Android\AndroidStudioProjects\OpenGLRender-as\app\src\main\jni\3rdparty\libpng\CMakeLists.txt \
	D:\Android\AndroidStudioProjects\OpenGLRender-as\app\src\main\jni\3rdparty\libpng\configure \
	D:\Android\AndroidStudioProjects\OpenGLRender-as\app\src\main\jni\3rdparty\libpng\example.c \
	D:\Android\AndroidStudioProjects\OpenGLRender-as\app\src\main\jni\3rdparty\libpng\image.c \
	D:\Android\AndroidStudioProjects\OpenGLRender-as\app\src\main\jni\3rdparty\libpng\INSTALL \
	D:\Android\AndroidStudioProjects\OpenGLRender-as\app\src\main\jni\3rdparty\libpng\libpng-config.in \
	D:\Android\AndroidStudioProjects\OpenGLRender-as\app\src\main\jni\3rdparty\libpng\libpng-manual.txt \
	D:\Android\AndroidStudioProjects\OpenGLRender-as\app\src\main\jni\3rdparty\libpng\libpng.3 \
	D:\Android\AndroidStudioProjects\OpenGLRender-as\app\src\main\jni\3rdparty\libpng\libpng.pc.in \
	D:\Android\AndroidStudioProjects\OpenGLRender-as\app\src\main\jni\3rdparty\libpng\libpngpf.3 \
	D:\Android\AndroidStudioProjects\OpenGLRender-as\app\src\main\jni\3rdparty\libpng\LICENSE \
	D:\Android\AndroidStudioProjects\OpenGLRender-as\app\src\main\jni\3rdparty\libpng\png.5 \
	D:\Android\AndroidStudioProjects\OpenGLRender-as\app\src\main\jni\3rdparty\libpng\png.c \
	D:\Android\AndroidStudioProjects\OpenGLRender-as\app\src\main\jni\3rdparty\libpng\pngbar.jpg \
	D:\Android\AndroidStudioProjects\OpenGLRender-as\app\src\main\jni\3rdparty\libpng\pngbar.png \
	D:\Android\AndroidStudioProjects\OpenGLRender-as\app\src\main\jni\3rdparty\libpng\pngerror.c \
	D:\Android\AndroidStudioProjects\OpenGLRender-as\app\src\main\jni\3rdparty\libpng\pngget.c \
	D:\Android\AndroidStudioProjects\OpenGLRender-as\app\src\main\jni\3rdparty\libpng\pngmem.c \
	D:\Android\AndroidStudioProjects\OpenGLRender-as\app\src\main\jni\3rdparty\libpng\pngnow.png \
	D:\Android\AndroidStudioProjects\OpenGLRender-as\app\src\main\jni\3rdparty\libpng\pngpread.c \
	D:\Android\AndroidStudioProjects\OpenGLRender-as\app\src\main\jni\3rdparty\libpng\pngread.c \
	D:\Android\AndroidStudioProjects\OpenGLRender-as\app\src\main\jni\3rdparty\libpng\pngrio.c \
	D:\Android\AndroidStudioProjects\OpenGLRender-as\app\src\main\jni\3rdparty\libpng\pngrtran.c \
	D:\Android\AndroidStudioProjects\OpenGLRender-as\app\src\main\jni\3rdparty\libpng\pngrutil.c \
	D:\Android\AndroidStudioProjects\OpenGLRender-as\app\src\main\jni\3rdparty\libpng\pngset.c \
	D:\Android\AndroidStudioProjects\OpenGLRender-as\app\src\main\jni\3rdparty\libpng\pngtest.png \
	D:\Android\AndroidStudioProjects\OpenGLRender-as\app\src\main\jni\3rdparty\libpng\pngtrans.c \
	D:\Android\AndroidStudioProjects\OpenGLRender-as\app\src\main\jni\3rdparty\libpng\pngwio.c \
	D:\Android\AndroidStudioProjects\OpenGLRender-as\app\src\main\jni\3rdparty\libpng\pngwrite.c \
	D:\Android\AndroidStudioProjects\OpenGLRender-as\app\src\main\jni\3rdparty\libpng\pngwtran.c \
	D:\Android\AndroidStudioProjects\OpenGLRender-as\app\src\main\jni\3rdparty\libpng\pngwutil.c \
	D:\Android\AndroidStudioProjects\OpenGLRender-as\app\src\main\jni\3rdparty\libpng\png_decoder.cpp \
	D:\Android\AndroidStudioProjects\OpenGLRender-as\app\src\main\jni\3rdparty\libpng\README \
	D:\Android\AndroidStudioProjects\OpenGLRender-as\app\src\main\jni\3rdparty\libpng\TODO \
	D:\Android\AndroidStudioProjects\OpenGLRender-as\app\src\main\jni\Android.mk \
	D:\Android\AndroidStudioProjects\OpenGLRender-as\app\src\main\jni\Application.mk \
	D:\Android\AndroidStudioProjects\OpenGLRender-as\app\src\main\jni\librenderer\Android.mk \
	D:\Android\AndroidStudioProjects\OpenGLRender-as\app\src\main\jni\librenderer\egl_core.cpp \
	D:\Android\AndroidStudioProjects\OpenGLRender-as\app\src\main\jni\librenderer\pic_preview_controller.cpp \
	D:\Android\AndroidStudioProjects\OpenGLRender-as\app\src\main\jni\librenderer\pic_preview_render.cpp \
	D:\Android\AndroidStudioProjects\OpenGLRender-as\app\src\main\jni\librenderer\pic_preview_texture.cpp \
	D:\Android\AndroidStudioProjects\OpenGLRender-as\app\src\main\jni\librenderer\rgba_frame.cpp \
	D:\Android\AndroidStudioProjects\OpenGLRender-as\app\src\main\jni\PngPreviewController.cpp \

LOCAL_C_INCLUDES += D:\Android\AndroidStudioProjects\OpenGLRender-as\app\src\main\jni
LOCAL_C_INCLUDES += D:\Android\AndroidStudioProjects\OpenGLRender-as\app\src\debug\jni

include $(BUILD_SHARED_LIBRARY)
