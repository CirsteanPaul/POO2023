#pragma once

class Compare {
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};

class CompareInts : public Compare {
public:
    int CompareElements(void* e1, void* e2) {
        int* x = (int*)e1;
        int* y = (int*)e2;

        return *x < *y;
    }
};

class CompareEqualInts : public Compare {
public:
    int CompareElements(void* e1, void* e2) {
        int* x = (int*)e1;
        int* y = (int*)e2;

        return *x == *y;
    }
};