#pragma once

#include "ofConstants.h"
#include "ofUtils.h"
#include "ofColor.h"
#include "Poco/SharedPtr.h"


class ofPixels {
public:

	ofPixels();

	//void operator=(const ofPixels & mom);


	void allocate(int w, int h, int bitsPerPixel);
	void allocate(int w, int h, ofImageType type);
	void set(unsigned char val);
	void setFromPixels(unsigned char * newPixels,int w, int h, ofImageType newType);

	operator unsigned char*(){
		return data->pixels;
	}

	void swapRgb();

	void clear();

	unsigned char * getPixels();
	const unsigned char * getPixels() const;

	int getPixelIndex(int x, int y);
	ofColor getPixel(int x, int y);

	unsigned char & operator[](int pos);
	unsigned char & at(int pos);

	bool isAllocated() const;

	int getWidth() const;
	int getHeight() const;

	int getBytesPerPixel() const;
	int getBitsPerPixel() const;

	ofImageType getImageType() const;
	int getGlDataType() const;

	void convertToCopy();
private:

	struct Data{
		Data();
		~Data();

		unsigned char * pixels;
		int 			width;
		int 			height;

		int				bitsPerPixel;		// 8 = gray, 24 = rgb, 32 = rgba
		int				bytesPerPixel;		// 1, 3, 4 bytes per pixels
		GLint			glDataType;			// GL_LUMINANCE, GL_RGB, GL_RGBA
		ofImageType 	imageType;		// OF_IMAGE_GRAYSCALE, OF_IMAGE_COLOR, OF_IMAGE_COLOR_ALPHA
		bool			bAllocated;
	};

	Poco::SharedPtr<Data> data;

};


