#include <iostream>
#include "Canvas.h"

int main() {
    Canvas canvas = Canvas(50, 50);
    std::cout << "First canvas\n";
    canvas.DrawCircle(4, 4, 10, 'd');
    canvas.FillCircle(20, 20, 5, 'a');
    canvas.Print();
    canvas.Clear();

    std::cout << "\n\n---------------------\n\nSecond canvas\n";
    canvas.Print();
    canvas.DrawRect(2, 2, 6, 4, 'x');
    canvas.FillRect(20, 20, 30, 25, 'y');
    canvas.Print();
    canvas.Clear();

    std::cout << "\n\n---------------------\n\nThird canvas\n";
    canvas.DrawLine(10, 15, 18, 20, 'x');
    canvas.DrawLine(20, 25, 28, 30, 'y');
    canvas.SetPoint(30, 30, 'p');
    canvas.Print();
}