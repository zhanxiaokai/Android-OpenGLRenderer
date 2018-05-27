LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_CFLAGS += -D__STDC_CONSTANT_MACROS
LOCAL_C_INCLUDES := \
    $(LOCAL_PATH)/3rdparty/libpng 

LOCAL_SRC_FILES = \
./PngPreviewController.cpp 

LOCAL_STATIC_LIBRARIES := libpngdecoder librenderer

LOCAL_LDLIBS := -L$(SYSROOT)/usr/lib -llog 
LOCAL_LDLIBS += -lz 
LOCAL_LDLIBS += -landroid 
# Link with OpenGL ES
LOCAL_LDLIBS += -lGLESv2
LOCAL_LDLIBS += -lEGL

LOCAL_MODULE := libsongstudio
include $(BUILD_SHARED_LIBRARY)
include $(call all-makefiles-under,$(LOCAL_PATH))