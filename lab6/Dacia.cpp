#include "Dacia.h"

double Dacia::GetTimeSpentOnTrackInHours(WeatherConditions weather, int lengthOfTrack) {
	double averageSpeed = GetAvergeSpeedByWeatherCondition(weather);

	double hours = lengthOfTrack / averageSpeed;

	return hours;
}

double Dacia::GetFuelConsumedOnTrackInLitres(WeatherConditions weather, int lengthOfTrack) {
	double hoursSpentOnTrack = GetTimeSpentOnTrackInHours(weather, lengthOfTrack);

	return fuelConsumption * hoursSpentOnTrack;
}

bool Dacia::DidCarFinishedTheTrack(WeatherConditions weather, int lengthOfTrack) {
	double fuelSpentOnTrack = GetFuelConsumedOnTrackInLitres(weather, lengthOfTrack);
		
	return fuelSpentOnTrack <= fuelLevel;
}

std::string Dacia::GetNameOfCar() {
	return "Dacia " + std::to_string(id);
}

