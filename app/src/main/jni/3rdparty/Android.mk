LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
    
LOCAL_MODULE := libpngdecoder
LOCAL_SRC_FILES = ./libpng/png.c \
				  ./libpng/pngerror.c \
				  ./libpng/pngget.c \
				  ./libpng/pngmem.c \
				  ./libpng/pngpread.c \
				  ./libpng/pngread.c \
				  ./libpng/pngrio.c \
				  ./libpng/pngrtran.c \
				  ./libpng/pngrutil.c \
				  ./libpng/pngset.c \
				  ./libpng/pngtrans.c \
				  ./libpng/pngwio.c \
				  ./libpng/pngwrite.c \
				  ./libpng/pngwtran.c \
				  ./libpng/pngwutil.c \
				  ./libpng/image.c \
				  ./libpng/png_decoder.cpp 
				  
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)
LOCAL_C_INCLUDES += $(LOCAL_PATH)
LOCAL_EXPORT_LDLIBS := -lz

include $(BUILD_STATIC_LIBRARY)