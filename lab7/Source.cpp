#include<iostream>
#include "Tree.h"

constexpr float operator"" _Kelvin(long double temp) {
    return static_cast<float>(temp - 273.15);
}

constexpr float operator"" _Fahrenheit(long double temp) {
    return static_cast<float>((temp - 32) * 5 / 9);
}
/*
int main() {
    Tree<int> tree;
    tree.add_node(nullptr, 10);
    tree.add_node(nullptr, 5);
    tree.add_node(nullptr, 20);
    tree.add_node(tree.get_node(nullptr, 10), 30);
    tree.add_node(tree.get_node(nullptr, 10), 40);
    tree.add_node(tree.get_node(nullptr, 10), 50);
}
*/
int main() {
    float a = 300.0_Kelvin;
    float b = 120.0_Fahrenheit;

    Tree<int> x;

    x.add_node(nullptr);
    x.add_node(nullptr);
    x.add_node(nullptr);
    x.add_node(nullptr);

    std::cout << a << " Celsius" << std::endl;
    std::cout << b << " Celsius" << std::endl;
}