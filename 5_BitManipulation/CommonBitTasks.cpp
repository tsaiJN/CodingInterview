#include<iostream>

// all the index starts with 0
// return the #i bit for int num
bool getBit(int num, int i) {
    return (num & (1 << i) != 0);
}

// set the #i bit for int num to 1
int setBit(int num, int i) {
    return num | (1<<i);
}

// clear the #i bit for in num <-- tricky
// this method is counting i from least significant bit
int clearBit(int num, int i) {
    int mask = ~(1<<i); 
    // 1 << i will produce 00000100000 with only the #i bit counting from left being 1
    // ~ operation make the mask 11111011111 with only the #i bit counting from the left being 0

    return num & mask;
}

// clear bits counting from most significant bit through #i (leaving only the last #i bits)
int clearBitsMSBThroughI(int num, int i) {
    int mask = (1<<i) - 1;
    // 1<<i will produce 00000100 if i == 2, minus 1 will produce 00000011

    return num & mask;
}

// clear bits from #i to 0
int clearBitsIThrough0(int num, int i) {
    int mask = ~((1<<i) - 1);
    return num & mask;
}

// update the #i bit to v
int updateBit(int num, int i, int v) {
    return clearBit(num, i) | (v << i);
}


