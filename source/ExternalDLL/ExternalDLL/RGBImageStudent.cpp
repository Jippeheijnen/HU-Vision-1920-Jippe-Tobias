#include "RGBImageStudent.h"
#include <map>
using namespace std;

RGBImageStudent::RGBImageStudent() : RGBImage() {
													//Empty constructor 						
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent& other) : RGBImage(other.getWidth(), other.getHeight()) {
	buffer = new std::map<pair<int, int>, RGB>;		//place buffer on the heap
	*buffer = *other.buffer;						//copy buffer from other object
}


RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height) {
	buffer = new map<pair<int, int>, RGB>;			//place buffer on the heap	
}

RGBImageStudent::~RGBImageStudent() {
	delete buffer;									//delete buffer from the heap
}

void RGBImageStudent::set(const int width, const int height) {
	RGBImage::set(width, height);					//call set function from parent class
	delete buffer;									//delete buffer from the heap
	buffer = new map<pair<int, int>, RGB>;			//place new buffer on the heap 
}

void RGBImageStudent::set(const RGBImageStudent& other) {
	RGBImage::set(other.getWidth(), other.getHeight());	//call set function from parent class
	delete buffer;										//delete buffer from the heap
	buffer = new map<pair<int, int>, RGB>;				//place new buffer on the heap
	*buffer = *other.buffer;							//copy buffer from other object
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	pair<int, int> temp = { x, y };					//create pair and fill with x and y axis
	buffer->insert(make_pair(temp, pixel));			//store pair as key and intensity value in the buffer
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	int x = 0;										//declare x variable
	int y = 0;										//declare y variable
	if (i != 0) {									//if given value is not (x = 0, y = 0)
		x = i % getWidth();							//get x axis
		y = (i - x) / getWidth();					//get y axis
	}
	pair<int, int> temp = { x, y };					//create pair and fill with x and y axis 
	buffer->insert(make_pair(temp, pixel));			//store pair as key and intensity value in the buffer
}

RGB RGBImageStudent::getPixel(int x, int y) const {
	pair<int, int> temp = { x,y };					//create pair and fill with x and y axis
	return buffer->at(temp);						//get and return intensity value with pair key
}

RGB RGBImageStudent::getPixel(int i) const {
	int x = 0;										//declare x variable
	int y = 0;										//declare y variable
	if (i != 0) {									//if given value is not (x = 0, y = 0)
		x = i % getWidth();							//get x axis
		y = (i - x) / getWidth();					//get y axis 
	}
	pair<int, int> temp = { x, y };					//create pair and fill with x and y axis
	return buffer->at(temp);						//get and return intensity value with pair key
}