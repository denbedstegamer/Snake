#include "classes.h"
#include <stdio.h>
#include <stdlib.h>
#include <cassert>
#include <iostream>

using namespace classes;

//Liste definitioner
Liste::Liste(float* tal, int length)
	: tal(tal), length(length){
}

Liste::Liste(int length)
	: length(length) {
	//tal = (float*) malloc(length*sizeof(float));
	tal = static_cast<decltype(tal)>(malloc(length*sizeof(float)));
}

void Liste::setTal(float NYTtal, int sted) {
	memcpy(tal+sted, &NYTtal, sizeof(float));
}

float Liste::getTal(int sted) {
	return *(tal + sted);
}

Liste Liste::operator+(Liste rhs) {
	assert(length = rhs.length);
	//float*resultData;
	//resultData = static_cast<decltype(resultData)>(malloc(length * sizeof(float)));
	Liste a(length);
	
	for (int i = 0; i < length; i++) {
		//*(resultData + i) = getTal(i)+rhs.getTal(i);
		a.setTal(getTal(i) + rhs.getTal(i), i);
	}

	//return Liste(resultData, length);
	return a;
}

Liste::Liste(const Liste& l) 
	: Liste(l.length) {
	memcpy(tal, l.tal, length * sizeof(float));
}


void Liste::operator=(const Liste& rhs) {
	length = rhs.length;
	tal = static_cast<decltype(tal)>(malloc(length * sizeof(float)));
	memcpy(tal, rhs.tal, length * sizeof(float));
}

Liste::~Liste() {
	free(tal);
}
//Box definitioner
Box::Box(Liste l){
	pos = Liste(l);
	makeEmpty();
}

void Box::makeSnake() {
	snakeIsInside = true;
	//måske noget her med at checke om der er et apple, og så måske kalde en function i snake som hedder eatApple() eller sådan noget
	appleIsInside = false;
}

void Box::makeEmpty() {
	snakeIsInside = false;
}

void Box::makeApple() {
	appleIsInside = true;
}

float Box::getX() {
	return pos.getTal(0);
}

float Box::getY() {
	return pos.getTal(1);
}

bool Box::getSnakeBool() {
	return snakeIsInside;
}

bool Box::getAppleBool() {
	return appleIsInside;
}

void Box::operator=(const Box& rhs) {
	pos = Liste(rhs.pos);
}

Box::~Box() {
	pos.~Liste();
}
//Snake definitioner
Snake::Snake(Liste l)
	: pos(l) {}
	
void Snake::move() {

}

void Snake::changeDir(int i) {
	//0 = up, og så er det med uret
	switch (i) {
	case 0:
		if (dirNum != 2) {
			dir.setTal(0.0f, 0);
			dir.setTal(-1.0f, 1);
			dirNum = 0;
		}
		break;
	case 1:
		if (dirNum != 3) {
			dir.setTal(1.0f, 0);
			dir.setTal(0.0f, 1);
			dirNum = 1;
		}
		break;
	case 2:
		if (dirNum != 0) {
			dir.setTal(0.0f, 0);
			dir.setTal(1.0f, 1);
			dirNum = 2;
		}
		break;
	case 3:
		if (dirNum != 1) {
			dir.setTal(1.0f, 0);
			dir.setTal(0.0f, 1);
			dirNum = 3;
		}
		break;
	}
}

void Snake::calculateNextBox() {
	//TODO if(nextBox != ude ved kanten)
	nextBox = Box(pos + dir);
}

Snake::~Snake() {
	pos.~Liste();
	dir.~Liste();
}
