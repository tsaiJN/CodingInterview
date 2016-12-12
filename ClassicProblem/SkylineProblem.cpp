#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <stdlib.h> // qsort

class CriticalPoint {
public:
    int prev_id;
    int height;
    int pos;
    int id;

    CriticalPoint(int prev_id, int height, int pos, int id) {
        this->prev_id = prev_id;
        this->height = height;
        this->pos = pos;
        this->id = id;
    }
};

void buildData(int test_input[3][5], std::vector<CriticalPoint> &ret) {
    for (int i=0; i<5; i++) {
        CriticalPoint leftEdge = CriticalPoint(-1, test_input[2][i], test_input[0][i], i);
        ret.push_back(leftEdge);
        ret.push_back(CriticalPoint(i, test_input[2][i], test_input[1][i], i+5));
    }
}

bool pos_compare (CriticalPoint a, CriticalPoint b) { // compare the pos in CriticalPoint
    return a.pos < b.pos;
}

bool height_compare (CriticalPoint a, CriticalPoint b) { // compare the height in CriticalPoint
    return a.height < b.height;
}

void printSkyline(std::vector<CriticalPoint> &cPoints) {
    std::vector<CriticalPoint> heap = std::vector<CriticalPoint> ();
    std::make_heap(heap.begin(), heap.end(), height_compare);
    std::unordered_map<int, bool> valid_check;
    heap.push_back(CriticalPoint(-1, 0, 0, 100)); std::push_heap(heap.begin(), heap.end(), height_compare); // push ground into heap
    valid_check[100] = true; // always has one valid ground
    for (int i=0; i<cPoints.size(); i++) { // for each CriticalPoint
        if (cPoints[i].prev_id == -1) {  // left edge
            valid_check[cPoints[i].id] = true;
            if (cPoints[i].height > heap.front().height) {
                std::cout << "pos: " << cPoints[i].pos << ", height: " << cPoints[i].height << "\n";
            }
            heap.push_back(cPoints[i]); std::push_heap(heap.begin(), heap.end(), height_compare);        // push left edge into heap
        } else {                        // right edge
            valid_check[cPoints[i].prev_id] = false;
            if (cPoints[i].height == heap.front().height) {                              // probably going down
                int tmp = cPoints[i].height;
                valid_check[cPoints[i].prev_id] = false;
                while(!valid_check[heap.front().id]) {
                    // pop out disabled edge
                    std::pop_heap(heap.begin(), heap.end(), height_compare); heap.pop_back();
                }
                if (heap.front().height < tmp)
                    std::cout << "pos: " << cPoints[i].pos << ", height: " << heap.front().height << "\n";
            } else {                                                                      // not going down
                valid_check[cPoints[i].prev_id] = false;
                while(!valid_check[heap.front().id]) {                                        // ensure valid heap
                    std::pop_heap(heap.begin(), heap.end(), height_compare); heap.pop_back();
                }
            }
        }
    }
}

int main() {
    int test_input[3][5] = {
        {2, 3, 5, 15, 19},  // left
        {9, 7, 12, 20, 24}, // right
        {10, 15, 12, 10, 8} // height
    };
    std::vector<CriticalPoint> cPoints = std::vector<CriticalPoint> ();
    buildData(test_input, cPoints);
    // sort by pos
    std::sort(cPoints.begin(), cPoints.end(), pos_compare);
    
    printSkyline(cPoints);
    return 0;
}
