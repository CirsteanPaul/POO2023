#pragma once
#include "Car.h"
class Kia : public Car
{
public:
	int id;
	Kia(int id) : id(id), Car({ 50.0, 40.0, 80.0, 60.0 }, 8.0, 50.0, 30.0) {};

	double GetTimeSpentOnTrackInHours(WeatherConditions, int);
	double GetFuelConsumedOnTrackInLitres(WeatherConditions, int);
	bool DidCarFinishedTheTrack(WeatherConditions, int);
	std::string GetNameOfCar();

};

