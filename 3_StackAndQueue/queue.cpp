#include <iostream>
#include <queue>

int main() {
    std::queue<int> myqueue;
    std::cout << "current queue is empty: " << myqueue.empty() << "\n";
    for (int i=0; i<10; i++) {
        myqueue.push(i);
    }
    for (int i=0; i<10; i++) {
        std::cout << myqueue.front() << " ";
        myqueue.pop();
    }
    std::cout << "\n";
}
