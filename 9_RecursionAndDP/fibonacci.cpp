// please compile with c++11 standard
#include <iostream>
#include <utility>
#include <chrono>

/* return the ith fibonacci number
 * Runtime Analysis:
 *  computing the nth Fibonacci number depends on the previous n-1 numbers
 *  each call does 2 recursive calls => O(2^n)
 *  the runtime growes exponentially.
 */
int fibonacciRecursive(int i) {
    // base cases
    if (i == 1) return 1;
    if (i == 2) return 2;

    return fibonacciRecursive(i-1) + fibonacciRecursive(i-2);
}

/* Runtime Analysis:
 *  obviously, it's O(n), and in this case, it takes only O(1) space
 */
int fibonacciDP(int i) {
    // base cases
    if (i == 1) return 1;
    if (i == 2) return 2;

    std::pair<int, int> cache(1, 2);  // fibonacci only depend on previous two number
    int tmp;
    for (int j=2; j<i; j++) {
        tmp = cache.first + cache.second;
        cache.first = cache.second;
        cache.second = tmp;
    }
    return tmp;
}

int main() {

    for (int i=1; i<=10; i++)
        std::cout << fibonacciDP(i) << " ";
    std::cout << "\n";

    // time analysis 
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    fibonacciRecursive(30);
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    std::cout << "fibonacciRecursive: " << duration << " microseconds.\n";

    t1 = std::chrono::high_resolution_clock::now();
    fibonacciDP(30);
    t2 = std::chrono::high_resolution_clock::now();

    duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    std::cout << "fibonacciDP: " << duration << " microseconds.\n";

    t1 = std::chrono::high_resolution_clock::now();
    fibonacciDP(10000);
    t2 = std::chrono::high_resolution_clock::now();

    duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    std::cout << "fibonacciDP: " << duration << " microseconds.\n";


    return 0;
}
