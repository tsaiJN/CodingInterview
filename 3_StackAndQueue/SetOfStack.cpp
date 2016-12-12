#include <iostream>
#include <stack>
#include <vector>
#include <limits>

class SetOfStack {

public:
    int capacity;
    std::vector<std::stack<int> > SOS;
    std::stack<int> *last = NULL;

    SetOfStack(int capacity) {
        this->capacity = capacity;
        this->SOS = std::vector<std::stack<int> >();
    }

    void push(int value) {

        if (last == NULL || last->size() >= capacity) {
            //last = new std::stack<int>();
            SOS.push_back(std::stack<int>());
            last = &(SOS.back());
        }

        last->push(value);
        std::cout << "size of last: " << last->size() << "\n";
    }

    int pop() {

        if (last == NULL) return std::numeric_limits<int>::min();
        std::cout << "size of last: " << last->size() << "\n";
        int ret = last->top();
        last->pop();
        if (last->empty()) {
            SOS.pop_back();
            if (SOS.size() == 0) {
                last = NULL; // start over
            } else {
                last = &(SOS.back());
            }
        }
        return ret;
    }
};

int main() {
    SetOfStack test = SetOfStack(3);
    std::cout << "pushing 1 ...\n";
    test.push(1);
    std::cout << "pushing 2 ...\n";
    test.push(2);
    std::cout << "pushing 3, exceed stack limit\n";
    test.push(3);
    std::cout << "pushing 4, new stack, element #1\n";
    test.push(4);
    if(test.SOS[1] == test.SOS[0]) std::cout << "true\n";
    std::cout << test.pop() << "\n";
    std::cout << test.pop() << "\n";
    std::cout << "pushing back 3\n";
    test.push(3);
    std::cout << "pushing back 4\n";
    test.push(4);
    std::cout << test.pop() << "\n";
    std::cout << test.pop() << "\n";
    std::cout << test.pop() << "\n";
    std::cout << test.pop() << "\n";
    std::cout << "regenerability test\n";
    test.push(1);
    std::cout << "test completed.\n";
    return 0;
}
