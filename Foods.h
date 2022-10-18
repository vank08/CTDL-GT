#pragma once

#include <iostream>

using namespace std;

class Foods {
private:
	string name;
	double weight;
	double calories;

public:
	Foods();
	Foods(string name);
	Foods(string name, double weight, double calories);

	void setName(string name);
	void setWeight(double weight);
	void setCalories(double calories);

	string getName();
	double getWeight();
	double getCalories();

	virtual ~Foods() = default;
};

