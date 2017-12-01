#include "./rgba_frame.h"

#define LOG_TAG "RGBAImgaeFrame"

RGBAImgaeFrame::RGBAImgaeFrame() {
	position = 0.0f;
	duration = 0.0f;
	pixels = NULL;
	width = 0;
	height = 0;
}

RGBAImgaeFrame::~RGBAImgaeFrame() {
	if (NULL != pixels) {
		delete[] pixels;
		pixels = NULL;
	}
}
