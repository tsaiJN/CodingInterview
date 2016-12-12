#include <iostream>
int bitCounter(int diff) {
    int count = 0;
    do {
        count += diff & 1;
    } while(diff >>= 1);
    return count;
}

int diffBitCounter(int test1, int test2) {
    int count = 0;
    for (int c = test1 ^ test2; c != 0; c = c & (c-1)) { // this is a very neat technique to wipe out the least significant 1
        count++;
    }
    return count;
}

int main() {
    int test1 = 31;
    int test2 = 14;

    std::cout << (test1^test2) << "\n";
    std::cout << bitCounter(test1^test2) << "\n";
    std::cout << diffBitCounter(test1, test2) << "\n";
    return 0;
}
