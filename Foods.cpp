#include "Foods.h"

Foods::Foods() {
	this->name = "noName";
	this->weight = 0;
	this->calories = 0;
}

Foods::Foods(string name) {
	this->name = name;
	this->weight = 0;
	this->calories = 0;
}

Foods::Foods(string name, double weight, double calories) {
	this->name = name;
	this->weight = weight;
	this->calories = calories;
}

void Foods::setName(string name) {
	this->name = name;
}

void Foods::setWeight(double weight) {
	this->weight = weight;
}

void Foods::setCalories(double calories) {
	this->calories = calories;
}