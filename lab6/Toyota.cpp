#include "Toyota.h"

double Toyota::GetTimeSpentOnTrackInHours(WeatherConditions weather, int lengthOfTrack) {
	double averageSpeed = GetAvergeSpeedByWeatherCondition(weather);

	double hours = lengthOfTrack / averageSpeed;

	return hours;
}

double Toyota::GetFuelConsumedOnTrackInLitres(WeatherConditions weather, int lengthOfTrack) {
	double hoursSpentOnTrack = GetTimeSpentOnTrackInHours(weather, lengthOfTrack);

	return fuelConsumption * hoursSpentOnTrack;
}

bool Toyota::DidCarFinishedTheTrack(WeatherConditions weather, int lengthOfTrack) {
	double fuelSpentOnTrack = GetFuelConsumedOnTrackInLitres(weather, lengthOfTrack);

	return fuelSpentOnTrack <= fuelLevel;
}

std::string Toyota::GetNameOfCar() {
	return "Toyota " + std::to_string(id);
}