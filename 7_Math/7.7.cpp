/*
 * Design an algorithm to find the kth number such that the only prime factors are 3, 5, and 7.
 */

#include <iostream>
#include <queue>
#include <vector>

void findKth(int k) {

    std::queue<int> q3, q5, q7;
    q3.push(3);
    q5.push(5);
    q7.push(7);
    std::vector<std::queue<int> > queues;
    queues.push_back(q3);
    queues.push_back(q5);
    queues.push_back(q7);
    
    std::cout << "A1: 1\n";
    for (int i=0; i<k-1; i++) {
        int tmp_idx, min_val;
        tmp_idx = (queues[0].front() < queues[1].front()) ? 0: 1;
        tmp_idx = (queues[2].front() < queues[tmp_idx].front()) ? 2: tmp_idx;

        min_val = queues[tmp_idx].front();
        queues[tmp_idx].pop();

        // beware of duplication
        queues[2].push(min_val*7);
        if (tmp_idx == 0) {
            queues[0].push(min_val*3);
            queues[1].push(min_val*5);
        } else if (tmp_idx == 1)
            queues[1].push(min_val*5);

        std::cout << "A" << i+2 << ": " << min_val << "\n";
    }
}


int main () {
    findKth(20);
    return 0;
}
