
#include "Map.h"

int main()
{
    Map<int, const char*> m, m2;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    m[20] = "test22";
    m.Set(100, "haha");
    m.Delete(20);
    m.Delete(50);
    m2[10] = "something";
    m2[20] = "somethingElse";
    m2[100] = "100chract";
    m2[150] = "somet";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    m[20] = "result";

    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    std::cout << '\n' << m.Includes(m2);
    return 0;
}