#include "Circuit.h"
#include <algorithm>

bool comparasion(Result const& a, Result const& b) {
	if (!b.hasFinished) {
		return a.hasFinished;
	}
	return a.time < b.time;
}

void Circuit::SetLength(int length) {
	if (length < 0) {
		return;
	}
	circuitLength = length;
}

void Circuit::SetWeather(WeatherConditions weather) {
	this->weather = weather;
}

void Circuit::AddCar(Car* newCar) {
	cars.push_back(newCar);
}

void Circuit::Race() {

	results.clear();
	for (Car* car : cars) {
		Result carResults;
		carResults.time = car->GetTimeSpentOnTrackInHours(weather, circuitLength);
		carResults.hasFinished = car->DidCarFinishedTheTrack(weather, circuitLength);
		carResults.carName = car->GetNameOfCar();
		results.push_back(carResults);
	}

	std::sort(results.begin(), results.end(), comparasion);
}

void Circuit::ShowFinalRanks() {
	std::cout << "\n\n\n\n---------------- Final Results ------------------\n\n";

	for (Result result : results) {
		if (result.hasFinished)
			std::cout << result.carName << "has finished the track in: " << result.time << " hours\n";
		else
			std::cout << result.carName << " could not finish the track\n";
	}
	std::cout << "\n\n\n\n -----------------------------------------------\n\n\n\n";
}

void Circuit::ShowWhoDidNotFinish() {
	std::cout << "\n\n\n\n---------------- Who couldn't finish ------------------\n\n";

	for (Result result : results) {
		if (!result.hasFinished)
			std::cout << result.carName << " could not finish the track\n";
	}
	std::cout << "\n\n\n\n ---------------------------------------------------------\n\n\n\n";
}