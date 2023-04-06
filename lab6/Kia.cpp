#include "Kia.h"

double Kia::GetTimeSpentOnTrackInHours(WeatherConditions weather, int lengthOfTrack) {
	double averageSpeed = GetAvergeSpeedByWeatherCondition(weather);

	double hours = lengthOfTrack / averageSpeed;

	return hours;
}

double Kia::GetFuelConsumedOnTrackInLitres(WeatherConditions weather, int lengthOfTrack) {
	double hoursSpentOnTrack = GetTimeSpentOnTrackInHours(weather, lengthOfTrack);

	return fuelConsumption * hoursSpentOnTrack;
}

bool Kia::DidCarFinishedTheTrack(WeatherConditions weather, int lengthOfTrack) {
	double fuelSpentOnTrack = GetFuelConsumedOnTrackInLitres(weather, lengthOfTrack);

	return fuelSpentOnTrack <= fuelLevel;
}

std::string Kia::GetNameOfCar() {
	return "Kia " + std::to_string(id);
}