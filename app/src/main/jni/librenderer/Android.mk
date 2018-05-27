LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_ARM_MODE := arm 
LOCAL_C_INCLUDES := \
    $(LOCAL_PATH)/../3rdparty/libpng
     
LOCAL_STATIC_LIBRARIES := libpngdecoder

LOCAL_CFLAGS := -DHAVE_CONFIG_H -DFPM_ARM -ffast-math -O3 

LOCAL_SRC_FILES += \
./pic_preview_controller.cpp \
./pic_preview_render.cpp \
./rgba_frame.cpp \
./egl_core.cpp \
./pic_preview_texture.cpp 
    
LOCAL_MODULE := librenderer
include $(BUILD_STATIC_LIBRARY)