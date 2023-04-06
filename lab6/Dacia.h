#pragma once
#include "Car.h"
class Dacia: public Car
{
public:
	int id;
	Dacia(int id) : id(id), Car({ 20.0, 10.0, 40.0, 30.0 }, 8.0, 50.0, 30.0) {};

	double GetTimeSpentOnTrackInHours(WeatherConditions, int);
	double GetFuelConsumedOnTrackInLitres(WeatherConditions, int);
	bool DidCarFinishedTheTrack(WeatherConditions, int);
	std::string GetNameOfCar();
};

