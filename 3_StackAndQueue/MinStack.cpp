/*
 * a stack which can returns the minimum element in O(1)
 * MORAL: the state of previous pushed elements in stack won't change much
 */

#include <iostream>
#include <stack>
#include <limits>

class MinStack: std::stack<int> {
    private:
        std::stack<int> _minStack;

    public:
        MinStack()
        : stack<int>() {
            this->_minStack = stack<int>();
            this->_minStack.push(std::numeric_limits<int>::max());
        }

        void push(int value) {
            if (!this->_minStack.empty() && value <= this->_minStack.top()) {
                this->_minStack.push(value);
            }
           stack<int>::push(value);            
        }

        void pop() {
            int to_be_pop = stack<int>::top();
            if (to_be_pop == this->_minStack.top()) {
                this->_minStack.pop();
            }
            stack<int>::pop();
        }

        int findMinInO1() {
            return this->_minStack.top();
        }
};

int main() {
    MinStack MS = MinStack();
    MS.push(5);
    MS.push(2);
    MS.push(3);
    MS.push(2);
    MS.push(4);
    std::cout << MS.findMinInO1() << "\n";
    MS.pop();
    std::cout << MS.findMinInO1() << "\n";
    MS.pop();
    std::cout << MS.findMinInO1() << "\n";
    MS.pop();
    std::cout << MS.findMinInO1() << "\n";
    MS.pop();
    std::cout << MS.findMinInO1() << "\n";

    return 0;
}
