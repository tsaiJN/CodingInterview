#include <iostream>
#include <bitset>

// using mathmatical solution
void printBinary(int num) {
    std::bitset<32> x = std::bitset<32>(num);
    std::cout << "bitset solution: " << x << "\n";
}

int main() {
    int test = 438278;
    std::cout << sizeof(test) << "\n";
    printBinary(test);
    printBinary(
        ((test & 0x55555555) << 1) | ((test & 0xaaaaaaaa) >> 1)
    );
    return 0;
}
