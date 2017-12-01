#ifndef RGBA_FRAME_H
#define RGBA_FRAME_H
#include "./../libcommon/CommonTools.h"

class RGBAImgaeFrame {
public:
	float position;
	float duration;
	uint8_t * pixels;
	int width;
	int height;
	RGBAImgaeFrame();
	~RGBAImgaeFrame();
};

#endif //RGBA_FRAME_H

