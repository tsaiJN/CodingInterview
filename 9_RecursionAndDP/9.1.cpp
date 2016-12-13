#include <iostream>
#include <chrono>
#include <string.h>  // memset

#define MAX 100
#define TEST 40

int totalPossibleWaysRecursive(int n) {
    // Base cases
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 4;

    return totalPossibleWaysRecursive(n-3) + totalPossibleWaysRecursive(n-2) + totalPossibleWaysRecursive(n-1);
}

int topDownCache[MAX];

void initialCache() {
    memset(topDownCache, -1, sizeof(int)*MAX);

    topDownCache[1] = 1;
    topDownCache[2] = 2;
    topDownCache[3] = 4;
}

int totalPossibleWaysDP_topDown_recursive(int n) {
    if (topDownCache[n] != -1) return topDownCache[n];
    
    topDownCache[n] =  totalPossibleWaysDP_topDown_recursive(n-3) +
                        totalPossibleWaysDP_topDown_recursive(n-2) +
                        totalPossibleWaysDP_topDown_recursive(n-1);
    return topDownCache[n];
}

int totalPossibleWaysDP_topDown(int n) {
    initialCache();
    return totalPossibleWaysDP_topDown_recursive(n);
}

// depends on only previous 3 elements
int totalPossibleWaysDP(int n) {
    // Base cases
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 4;
    
    int sum;
    int cache[3] = {1, 2, 4};

    for (int i=4; i<=n; i++) {
        sum = cache[0] + cache[1] + cache[2];
        cache[0] = cache[1];
        cache[1] = cache[2];
        cache[2] = sum;
    }
    return sum;
}

int main() {

    //std::cout << totalPossibleWaysRecursive(TEST) << ", " << totalPossibleWaysDP(TEST) << "\n";


    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    totalPossibleWaysRecursive(TEST);
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    std::cout << "totalPossibleWaysRecursive: " << duration << " microseconds.\n";

    t1 = std::chrono::high_resolution_clock::now();
    totalPossibleWaysDP(TEST);
    t2 = std::chrono::high_resolution_clock::now();

    duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    std::cout << "totalPossibleWaysDP: " << duration << " microseconds.\n";

    t1 = std::chrono::high_resolution_clock::now();
    totalPossibleWaysDP_topDown(TEST);
    t2 = std::chrono::high_resolution_clock::now();

    duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    std::cout << "totalPossibleWaysDP_topdown: " << duration << " microseconds.\n";

    return 0;
}
