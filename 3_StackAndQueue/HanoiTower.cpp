#include <iostream>
#include <stack>

using namespace std;

void moveDisks(int n, stack<int>& origin, stack<int>& destination, stack<int>& buffer) {
    if (n <= 0) return;

    // move n-1 disks to buffer
    moveDisks(n-1, origin, buffer, destination);
    
    // move base disk to destination
    int disk = origin.top();
    origin.pop();
    destination.push(disk);

    // move n-1 disks from buffer to destination
    moveDisks(n-1, buffer, destination, origin);
}

int main () {
    stack<int> stack1 = stack<int>();
    stack<int> stack2 = stack<int>();
    stack<int> stack3 = stack<int>();

    // initial the game
    stack1.push(7);
    stack1.push(6);
    stack1.push(5);
    stack1.push(4);
    stack1.push(3);
    stack1.push(2);
    stack1.push(1);

    moveDisks(stack1.size(), stack1, stack3, stack2);

    // test
    while(!stack1.empty()) {
        cout << stack1.top() << "\n";
        stack1.pop();
    }
    cout << "==================\n";

    while(!stack2.empty()) {
        cout << stack2.top() << "\n";
        stack2.pop();
    }
    cout << "==================\n";

    while(!stack3.empty()) {
        cout << stack3.top() << "\n";
        stack3.pop();
    }
    return 0;
}
