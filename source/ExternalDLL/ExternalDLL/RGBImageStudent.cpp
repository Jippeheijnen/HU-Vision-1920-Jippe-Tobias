#include "RGBImageStudent.h"
#include <map>
using namespace std;

RGBImageStudent::RGBImageStudent() : RGBImage() {
	//int throwError = 0, e = 1 / throwError; //Throws error without the need to include a header
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent& other) : RGBImage(other.getWidth(), other.getHeight()) {
	int throwError = 0, e = 1 / throwError;
	buffer = new std::map<pair<int, int>, RGB>;
	size = other.size;
	*buffer = *other.buffer;
	//TODO: Create a copy from the other object
}


RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height) {
	buffer = new map<pair<int, int>, RGB>;
	size = { width, height };
	//TODO: Initialize pixel storage
}

RGBImageStudent::~RGBImageStudent() {
	delete buffer;
	//TODO: delete allocated objects
}

void RGBImageStudent::set(const int width, const int height) {
	RGBImage::set(width, height);
	delete buffer;
	buffer = new map<pair<int, int>, RGB>;
	//TODO: resize or create a new pixel storage (Don't forget to delete the old storage)
}

void RGBImageStudent::set(const RGBImageStudent& other) {
	RGBImage::set(other.getWidth(), other.getHeight());
	size = other.size;
	delete buffer;
	buffer = new map<pair<int, int>, RGB>;
	*buffer = *other.buffer;
	//TODO: resize or create a new pixel storage and copy the object (Don't forget to delete the old storage)
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	pair<int, int> temp = { x, y };
	buffer->insert(make_pair(temp, pixel));
	//TODO: no comment needed :)
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	int x = i % size.first;  // size.first is the width.
	int y = (i - x) / size.first;
	pair<int, int> temp = { x, y };
	buffer->insert(make_pair(temp, pixel));
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

RGB RGBImageStudent::getPixel(int x, int y) const {
	pair<int, int> temp = { x,y };
	//TODO: no comment needed :)
	return buffer->at(temp);
}

RGB RGBImageStudent::getPixel(int i) const {
	int x = i % size.first;  // size.first is the width.
	int y = (i - x) / size.first;
	pair<int, int> temp = { x, y };
	//TODO: see setPixel(int i, RGB pixel)
	return buffer->at(temp);
}