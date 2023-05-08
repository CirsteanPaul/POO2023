#include <iostream>
#include "Array.h"
#include "Compare.h"
int compare(const int& x, const int& y) {
    return x < y;
}
int compareEqual(const int& x, const int& y) {
    return x == y;
}
int main()
{
    Array<int> t;
    Array<int> d(20);
    t += 1;
    t += 2;
    t += 5;
   // Array<int> copy(d);
    try {
        int valu1 = 1;
        int valu2 = 2;
        d.Insert(5, valu1);
        d.Insert(3, 10);
        for (auto it : d) {

            std::cout << it << '\n';
        }
    }
    catch (IndexOutOfBound e) {
        std::cout << e.what();
    }
    d += 2;
    d += 2;
    d += 2;
    d += 2;
    d.Insert(3, 10);
    d.Insert(4, 20);
    d.Insert(5, t);
    for (auto it : d) {

        std::cout << it << '\n';
    }
    d.Delete(2);
    d.Delete(5);
    std::cout << "\n\n\n";
    for (auto it : d) {

        std::cout << it << '\n';
    }
    std::cout << "Elem 10 is found on index: " << d.Find(10, new CompareEqualInts()) << '\n';
    d.Sort(new CompareInts());
    std::cout << "\n\n\n";
    for (auto it : d) {

        std::cout << it << '\n';
    }
    /*try {
        t[10];
       // throw IndexOutOfBound();
    }
    catch (IndexOutOfBound e) {
        std::cout << e.what();
    }*/
}