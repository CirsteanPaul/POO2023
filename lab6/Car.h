#pragma once
#include "CarConstants.h"
#include <iostream>
#include <string>

class Car
{
protected:
	double fuelCapacity, fuelLevel;
	double fuelConsumption;
	AverageSpeed averageSpeed;
	Car(AverageSpeed averageSpeed, double fuelConsumption, double fuelCapacity, double fuelLevel)
		: fuelConsumption(fuelConsumption), averageSpeed(averageSpeed), fuelCapacity(fuelCapacity), fuelLevel(fuelLevel) {};
	double GetAvergeSpeedByWeatherCondition(WeatherConditions weather) {
		switch (weather)
		{
		case Rain:
			return averageSpeed.speedOnRainPerHour;
		case Normal:
			return averageSpeed.speedOnNormalPerHour;
		case Snow:
			return averageSpeed.speedOnSnowPerHour;
		case HotSun:
			return averageSpeed.speedOnHotSunPerHour;
		default:
			return averageSpeed.speedOnNormalPerHour;
		}
	}
public:
	virtual double GetFuelConsumedOnTrackInLitres(WeatherConditions, int) = 0;
	virtual double GetTimeSpentOnTrackInHours(WeatherConditions, int) = 0;
	virtual std::string GetNameOfCar() = 0;
	virtual bool DidCarFinishedTheTrack(WeatherConditions, int) = 0;
	~Car();

};

