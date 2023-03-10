#include <iostream>
#include "Math.h"

int main()
{
    std::cout << Math::Add(4, 8)<< '\n'; // 12
    std::cout << Math::Add(4, 8, 12)<<'\n'; // 24

    std::cout << Math::Add(4.2, 8.3)<<'\n'; // 12
    std::cout << Math::Add(4.0, 8.1, 12.0)<< '\n'; // 24

    std::cout << Math::Mul(4, 8)<< '\n'; // 32
    std::cout << Math::Mul(4, 8, 2)<< '\n'; // 64

    std::cout << Math::Mul(4.2, 8.3)<< '\n'; // 34
    std::cout << Math::Mul(4.1, 8.3, 2.4) << '\n'; // 81
    std::cout << Math::Add(7, 8, 2, 12, 13, 10, 0)<< '\n'; // 55

    try {
        std::cout << Math::Add("1334", "29") << '\n'; // 1363
    }
    catch (...) {
        std::cout << '\n' << "Input is invalid" << '\n';
    }

    std::cout << Math::Add("Hello", " world!"); // Hello world!
}