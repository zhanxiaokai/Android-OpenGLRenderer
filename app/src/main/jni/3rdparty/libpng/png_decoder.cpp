#include "./png_decoder.h"

#define LOG_TAG "PngPicDecoder"

PngPicDecoder::PngPicDecoder() {
}

PngPicDecoder::~PngPicDecoder() {
}

int PngPicDecoder::openFile(char *pngFilePath) {
	pngFile = fopen(pngFilePath, "rb");

	fseek(pngFile, 0, SEEK_END);
	int data_length = ftell(pngFile);
	rewind(pngFile);
	compressedData = new byte[data_length];
	actualSize = fread(compressedData, 1, data_length, pngFile);
}

RawImageData PngPicDecoder::getRawImageData(){
	RawImageData data = get_raw_image_data_from_png((void*) compressedData, actualSize);
	return data;
}

void PngPicDecoder::releaseRawImageData(const RawImageData* data){
	release_raw_image_data(data);
}

void PngPicDecoder::closeFile(){
	delete[] compressedData;
	fclose(pngFile);
}
