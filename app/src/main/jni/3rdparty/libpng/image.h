#ifndef PNG_FUNCTION_LAB_DECODER_IMAGE_H
#define PNG_FUNCTION_LAB_DECODER_IMAGE_H

#include <assert.h>
#include <string.h>
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include "../libpng/png.h"

typedef struct {
	const int width;
	const int height;
	const int size;
	const GLenum gl_color_format;
	const void* data;
} RawImageData;

/* Returns the decoded image data, or aborts if there's an error during decoding. */
RawImageData get_raw_image_data_from_png(const void* png_data, const int png_data_size);
void release_raw_image_data(const RawImageData* data);

#endif //PNG_FUNCTION_LAB_DECODER_IMAGE_H
