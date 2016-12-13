#include <iostream>
#include <chrono>
#include <string.h> // memset

#define MAX 100

int totalPaths(int x, int y) {
    // base cases
    if (x<0 || y<0) return 0;
    if (x==0 && y==0) return 0;
    if (x==1 && y==0) return 1;
    if (x==0 && y==1) return 1;

    return totalPaths(x-1, y) + totalPaths(y-1, x);
}

int MAP[MAX][MAX];

// a top-down DP solution
int totalPathsDP_recursive(int x, int y) {
    if (x<0 || y<0) return 0;
    if (MAP[x][y] != -1) return MAP[x][y];

    MAP[x][y] = totalPathsDP_recursive(x-1, y) + totalPathsDP_recursive(y-1, x);
    return MAP[x][y];
}

void totalPathsDP_initial() {
    memset(MAP, -1, sizeof(int) * MAX * MAX);
    MAP[0][0] = 0;
    MAP[1][0] = 1;
    MAP[0][1] = 1;
}

int totalPathsDP(int x, int y) {
    totalPathsDP_initial();
    return totalPathsDP_recursive(x, y);
}


int main() {

    std::cout << totalPaths(10, 5) << "\n";

    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    totalPaths(20, 15);
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    std::cout << "totalPaths: " << duration << " microseconds.\n";

    t1 = std::chrono::high_resolution_clock::now();
    totalPathsDP(20, 15);
    t2 = std::chrono::high_resolution_clock::now();

    duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    std::cout << "totalPathsDP: " << duration << " microseconds.\n";

}
