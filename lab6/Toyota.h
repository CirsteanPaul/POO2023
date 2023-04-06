#pragma once
#include "Car.h"
class Toyota : public Car
{
	
public:
	int id;
	Toyota(int id) : id(id), Car({ 20.0, 10.0, 40.0, 30.0 }, 8.0, 40.0, 20.0) {};

	double GetTimeSpentOnTrackInHours(WeatherConditions, int);
	double GetFuelConsumedOnTrackInLitres(WeatherConditions, int);
	bool DidCarFinishedTheTrack(WeatherConditions, int);
	std::string GetNameOfCar();
};

