#include<iostream>
#include<inttypes.h>

using namespace std;
// the variables in union will share a same memory space
union udouble {
    double d;
    uint64_t u;
}; // double is 64-bit wide

union ufloat {
    float f;
    uint32_t u;
}; // float is 32-bit wide

int main() {
    udouble checkDouble;
    checkDouble.d = -0.72;
    cout << bin << checkDouble.u << "\n";

    cout << "shifting\n";

    checkDouble.d = checkDouble.d * 2;

    cout << checkDouble.d << ", " << checkDouble.u << "\n";

    ufloat checkFloat;
    checkFloat.f = 0.72;
    cout << checkFloat.u << "\n";
}
