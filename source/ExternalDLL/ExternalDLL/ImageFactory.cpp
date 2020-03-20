/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#include "ImageFactory.h"
#include "RGBImageStudent.h"
#include "RGBImagePrivate.h"
#include "IntensityImagePrivate.h"
#include "IntensityImageStudent.h"
#include <stdexcept>
#include <iostream>


//Student factory implementation
RGBImage* ImageFactory::ImplementationStudent::newRGBImage(const int width, const int height) const {
	return new RGBImageStudent(width, height);
}
IntensityImage* ImageFactory::ImplementationStudent::newIntensityImage(const int width, const int height) const {
	return new IntensityImageStudent(width, height);
}
RGBImage* ImageFactory::ImplementationStudent::newRGBImage() const {
	return new RGBImageStudent();
}
IntensityImage* ImageFactory::ImplementationStudent::newIntensityImage() const {
	return new IntensityImageStudent();
}


//Private factory implementation
RGBImage* ImageFactory::ImplementationPrivate::newRGBImage(const int width, const int height) const {
	return new RGBImageStudent(width, height);
}
IntensityImage* ImageFactory::ImplementationPrivate::newIntensityImage(const int width, const int height) const {
	return new IntensityImageStudent(width, height);
}
RGBImage* ImageFactory::ImplementationPrivate::newRGBImage() const {
	return new RGBImageStudent();
}
IntensityImage* ImageFactory::ImplementationPrivate::newIntensityImage() const {
	return new IntensityImageStudent();
}




//Static factory methods
RGBImage* ImageFactory::newRGBImage(const int width, const int height) {
	return getImplementation()->newRGBImage(width, height);
}

IntensityImage* ImageFactory::newIntensityImage(const int width, const int height) {
	return getImplementation()->newIntensityImage(width, height);
}

RGBImage* ImageFactory::newRGBImage() {
	return getImplementation()->newRGBImage();
}

IntensityImage* ImageFactory::newIntensityImage() {
	return getImplementation()->newIntensityImage();
}




IntensityImage* ImageFactory::newIntensityImage(const IntensityImage& other) {
	IntensityImage* image = ImageFactory::newIntensityImage(other.getWidth(), other.getHeight());
	int size = other.getHeight() * other.getWidth();
	for (int i = 0; i < size; i++) {
		image->setPixel(i, other.getPixel(i));
	}
	return image;
}

RGBImage* ImageFactory::newRGBImage(const RGBImage& other) {
	RGBImage* image = ImageFactory::newRGBImage(other.getWidth(), other.getHeight());
	int size = other.getHeight() * other.getWidth();
	for (int i = 0; i < size; i++) {
		image->setPixel(i, other.getPixel(i));
	}
	return image;
}



ImageFactory::Implementation& ImageFactory::DEFAULT = ImageFactory::ImplementationPrivate();
ImageFactory::Implementation& ImageFactory::STUDENT = ImageFactory::ImplementationStudent();



ImageFactory::Implementation* ImageFactory::implementation = NULL;

void ImageFactory::setImplementation(ImageFactory::Implementation& implementation) {
	ImageFactory::implementation = &implementation;
}

ImageFactory::Implementation* ImageFactory::getImplementation() {
	if (!implementation) {
		throw new std::invalid_argument("The factory methods can not be used because the current Implementation is null!");
	}
	return implementation;
}