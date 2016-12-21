#include <iostream>
#include <vector>

#define TEST_LEN 10 

void printArray(int *array) {
    for (int i=0; i<10; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}

void swap(int* a, int* b) {
    int tmp = a[0];
    a[0] = b[0];
    b[0] = tmp;
}

// time: O(n^2), space: O(1)
void bubbleSort(int *array) {
    for (int i=0; i < TEST_LEN; i++) {
        for (int j=0; j < TEST_LEN-i-1; j++) {
            if (array[j] > array[j+1]) {
                swap (array+j, array+j+1);
            }
        }
    }
}

// time: O(n log(n)) average and worst case, space: O(n) 
// [if we use linked list as data structure, O(1) space is possible]
void mergeSort(int *array, int start, int end) {
    if (start == end) return;

    int mid = (start + end) / 2;
    mergeSort(array, start, mid);
    mergeSort(array, mid+1, end);

    // merge
    int pivot1 = start;
    int pivot2 = mid+1;

    int tmp[TEST_LEN];
    for (int i=0; i<end - start + 1; i++) {
        if (pivot1 > mid) {tmp[i] = array[pivot2]; pivot2++; }
        else if (pivot2 > end) {tmp[i] = array[pivot1]; pivot1++; }
        else if (array[pivot1] > array[pivot2]) {tmp[i] = array[pivot2]; pivot2++; }
        else {tmp[i] = array[pivot1]; pivot1++; }
    }

    for (int i=0; i<end - start + 1; i++) { array[start+i] = tmp[i]; }
}

// time: O(n log(n)) average, O(n^2) worst case, space: O(log(n))
// worst case is O(n^2) since the partitioned element is not guarantted
// to be the median (or anywhere near median)
void quickSort(int *array, int start, int end) {
    if (start >= end) return;

    int left = start + 1; // use the first element as pivot
    int right = end;

    int pivot = array[start];

    while (true) {
        while (array[left] < pivot) left++;
        while (array[right] > pivot) right--;

        if (left >= right) break;

        swap(array+left, array+right);
        left++;
        right--;
    }

    swap(array+start, array+right);
    quickSort(array, start, right-1);
    quickSort(array, right+1, end);
}

// Bucket sort; time: O(kn), k is the number of round we need
// benefit if the values are in a fixed range
// and the data amount is huge
// Especially efficient if the underlying data structure
// is a linked list
void radixSort(int *array) {
    //std::vector<std::vector<int> > buckets = std::vector<std::vector<int> > ();
    std::vector<std::vector<int> > buckets; // short cut for calling constructor (if no param needed)
    for (int i=0; i<10; i++) {  // 10 possible digits
        buckets.push_back(std::vector<int> ());
    }

    for (int round=0, base=1; round < 2; round++, base*=10) { // from LSD to MSD, assume only two digits
        
        // clear buckets
        for (int i=0; i<10; i++) {
            buckets[i] = std::vector<int> ();
        }

        // fill buckets
        for (int i=0; i<TEST_LEN; i++) {
            buckets[(array[i] / base) % 10].push_back(array[i]);
        }

        // dump buckets
        int idx = 0;
        for (int i=0; i<10; i++) {
            for (int j=0; j<buckets[i].size(); j++) {
                array[idx] = buckets[i][j];
                idx++;
            }
        }
    }

}

void resetTestSet(int *array) {
    int tmp[] = {3, 4, 1, 2, 7, 10, 9, 8, 5, 6};
    std::copy(tmp, tmp+TEST_LEN, array);
}

int main() {
    int test_set[] = {3, 4, 1, 2, 7, 10, 9, 8, 5, 6};

    std::cout << "bubble sort\n";
    bubbleSort(test_set);
    printArray(test_set);

    std::cout << "merge sort\n";
    resetTestSet(test_set);
    mergeSort(test_set, 0, TEST_LEN-1);
    printArray(test_set);

    std::cout << "quick sort\n";
    resetTestSet(test_set);
    quickSort(test_set, 0, TEST_LEN-1);
    printArray(test_set);

    std::cout << "radix sort\n";
    resetTestSet(test_set);
    radixSort(test_set);
    printArray(test_set);

    return 0;
}
