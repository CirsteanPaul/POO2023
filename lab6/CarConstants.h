#pragma once
class AverageSpeed {
public:
	double speedOnRainPerHour;
	double speedOnNormalPerHour;
	double speedOnHotSunPerHour;
	double speedOnSnowPerHour;
};

enum WeatherConditions {
	Rain,
	Normal,
	HotSun,
	Snow
};
