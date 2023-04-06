#include <iostream>
#include "Dacia.h"
#include "Circuit.h"
#include "Toyota.h"
#include "Kia.h"

int main()
{
    Circuit circ;
    circ.SetLength(100);
    circ.SetWeather(Snow);
    circ.AddCar(new Dacia(1));
    circ.AddCar(new Toyota(2));
    circ.AddCar(new Toyota(3));
    circ.AddCar(new Toyota(4));
    circ.AddCar(new Toyota(5));
    circ.AddCar(new Kia(6));
    circ.AddCar(new Kia(7));
    circ.Race();
    circ.ShowFinalRanks();
    circ.ShowWhoDidNotFinish();
}
