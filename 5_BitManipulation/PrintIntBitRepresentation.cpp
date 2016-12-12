#include <bitset>
#include <string>
#include <iostream>
#include <algorithm> // for std::reverse

// using bitset
void bitsetSolution(int num) {
    std::bitset<32> x = std::bitset<32>(num);
    std::cout << "bitset solution: " << x << "\n";
}

// using mathmatical solution
void mathSolution(int num) {
    std::string s;
    do {
        s.push_back('0' + (num & 1));
    } while (num >>= 1);
    std::reverse(s.begin(), s.end());
    std::cout << "math solution: " << s << "\n";
}

int main() {
    
    int test_num = 128;

    bitsetSolution(test_num);
    mathSolution(test_num);
    return 0;
}
