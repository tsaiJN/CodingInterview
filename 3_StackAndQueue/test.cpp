#include <iostream>
#include <vector>
#include <stack>

int main () {

    // test1
    std::vector<std::stack<int> > v = std::vector<std::stack<int> >();
    std::stack<int> *last = new std::stack<int>();
    v.push_back(*last);
    last = new std::stack<int>();
    v.push_back(*last);

    std::cout << (&(v[0]) == &(v[1])) << "\n";


    // test2
    v = std::vector<std::stack<int> >();
    v.push_back(std::stack<int> ());
    v.push_back(std::stack<int> ());

    std::cout << (&(v[0]) == &(v[1])) << "\n";


    // test3
    v = std::vector<std::stack<int> >();
    std::stack<int> l = std::stack<int>();
    v.push_back(l);
    l = std::stack<int>();
    v.push_back(l);

    std::cout << (&(v[0]) == &(v[1])) << "\n";
    return 0;
}
