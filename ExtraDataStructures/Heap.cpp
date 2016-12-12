#include <iostream>
#include <algorithm> // std::make_heap(), std::pop_heap(), std::push_heap()
#include <vector>    // the container that can heapify

int main() {
    int test_set[] = { 2, 5, 3, 7, 6, 9, 10, 1};

    // default a max heap (simular priority queue)
    std::vector<int> container = std::vector<int>(test_set, test_set+8);
    std::make_heap(container.begin(), container.end());

    for (int i=0; i<8; i++) {
        std::cout << container.front() << " ";
        std::pop_heap(container.begin(), container.end()); container.pop_back();
    }
    std::cout << "\n";
    return 0;
}
