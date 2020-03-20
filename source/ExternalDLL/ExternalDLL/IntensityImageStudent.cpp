#include "IntensityImageStudent.h"
#include <map>

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
	//TODO: Nothing
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent& other) : IntensityImage(other.getWidth(), other.getHeight()) {
	buffer = new std::map<std::pair<int, int>, Intensity>;
	*buffer = *other.buffer;

	//TODO: Create a copy from the other object
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) {
	buffer = new std::map<std::pair<int, int>, Intensity>;
	//TODO: Initialize pixel storage
}

IntensityImageStudent::~IntensityImageStudent() {
	delete buffer;
	//TODO: delete allocated objects
}

void IntensityImageStudent::set(const int width, const int height) {
	IntensityImage::set(width, height);
	delete buffer;
	buffer = new std::map<std::pair<int, int>, Intensity>;
	//TODO: resize or create a new pixel storage (Don't forget to delete the old storage)
}

void IntensityImageStudent::set(const IntensityImageStudent& other) {
	IntensityImage::set(other.getWidth(), other.getHeight());
	delete buffer;
	buffer = new std::map<std::pair<int, int>, Intensity>;
	*buffer = *other.buffer;
	//TODO: resize or create a new pixel storage and copy the object (Don't forget to delete the old storage)
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	std::pair<int, int> temp = { x, y };
	buffer->insert(std::make_pair(temp, pixel));
	//TODO: no comment needed :)
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	int x = 0;
	int y = 0;
	if (i != 0) {
		x = i % getWidth();
		y = (i - x) / getWidth();
	}
	std::pair<int, int> temp = { x, y };
	buffer->insert(std::make_pair(temp, pixel));
	/*
	* TODO: set pixel i in "Row-Major Order"
	*
	*
	* Original 2d image (values):
	* 9 1 2
	* 4 3 5
	* 8 7 8
	*
	* 1d representation (i, value):
	* i		value
	* 0		9
	* 1		1
	* 2		2
	* 3		4
	* 4		3
	* 5		5
	* 6		8
	* 7		7
	* 8		8
	*/
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	Intensity pixel = buffer->at({ x, y });
	//TODO: no comment needed :)
	return pixel;
}

Intensity IntensityImageStudent::getPixel(int i) const {
	int x = 0; 
	int y = 0;
	if (i != 0) {
		x = i % getWidth();
		y = (i - x) / getWidth();
	}
	Intensity pixel = buffer->at({ x, y });
	//TODO: see setPixel(int i, RGB pixel)
	return pixel;
}