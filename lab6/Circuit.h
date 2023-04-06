#pragma once
#include "Car.h"
#include <vector>
struct Result {
	double time;
	bool hasFinished;
	std::string carName;
};
class Circuit
{
	int circuitLength = 50;
	WeatherConditions weather = Rain;
	std::vector<Car*> cars;
	std::vector<Result> results;
public:
	void SetLength(int);
	void SetWeather(WeatherConditions);
	void AddCar(Car*);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};

