#include "IntensityImageStudent.h"
#include <map>

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
																		//Empty constructor 
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent& other) : IntensityImage(other.getWidth(), other.getHeight()) {
	buffer = new std::map<std::pair<int, int>, Intensity>;				//place buffer on the heap
	*buffer = *other.buffer;											//copy buffer from other buffer 
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) {
	buffer = new std::map<std::pair<int, int>, Intensity>;				//place buffer on the heap
}

IntensityImageStudent::~IntensityImageStudent() {
	delete buffer;														//remove buffer from the heap 
}

void IntensityImageStudent::set(const int width, const int height) {
	IntensityImage::set(width, height);									//call parent class set function 
	delete buffer;														//remove buffer from the heap 
	buffer = new std::map<std::pair<int, int>, Intensity>;				//place new buffer on the heap
}

void IntensityImageStudent::set(const IntensityImageStudent& other) {
	IntensityImage::set(other.getWidth(), other.getHeight());			//call parent class set function  
	delete buffer;														//remove buffer from heap 
	buffer = new std::map<std::pair<int, int>, Intensity>;				//place new buffer on the heap 
	*buffer = *other.buffer;											//copy buffer from other buffer
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	std::pair<int, int> temp = { x, y };								//create pair object and fill with x and y axis 
	buffer->insert(std::make_pair(temp, pixel));						//place pair and intensity value in buffer
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	int x = 0;															//declare x variable 
	int y = 0;															//delclare y variable 
	if (i != 0) {														//if given value is not (x = 0, y = 0)
		x = i % getWidth();												//get x axis
		y = (i - x) / getWidth();										//get y axis 
	}
	std::pair<int, int> temp = { x, y };								//create pair object and fill with x and y axis 
	buffer->insert(std::make_pair(temp, pixel));						//place pair and given intensity value into buffer 
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	Intensity pixel = buffer->at({ x, y });								//get intensity value from buffer with x and y pair key 	
	return pixel;														//return intensity value 
}

Intensity IntensityImageStudent::getPixel(int i) const {	
	int x = 0;															//declare x variable
	int y = 0;															//declare y variable 
	if (i != 0) {														//if given value is not (x = 0, y = 0)
		x = i % getWidth();												//get x axis 
		y = (i - x) / getWidth();										//get y axis 
	}
	Intensity pixel = buffer->at({ x, y });								//get intensity value from buffer with x and y pair key 
	return pixel;														//return intensity value 
}