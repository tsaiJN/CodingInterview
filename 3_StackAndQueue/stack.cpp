#include <stdio.h>
#include <iostream>
#include <stack>

class TwoNum {
    public:
        int val1;
        int val2;
        char stringBuffer[100];
        TwoNum(int v1, int v2) {
            this->val1 = v1;
            this->val2 = v2;
        }
        void toString() {
            sprintf(stringBuffer, "val1: %d, val2: %d\n", this->val1, this->val2);
        }
};

int main() {
    std:: stack<TwoNum> mystack;
    for (int i=0; i<5; i++) {
        mystack.push(*(new TwoNum(i, i+1)));
    }
    std::cout << "Popping out elements...";

    while(!mystack.empty()) {
        mystack.top().toString();
        std::cout << ' ' << mystack.top().stringBuffer;
        mystack.pop();
    }
    std::cout << '\n';

    return 0;
}
