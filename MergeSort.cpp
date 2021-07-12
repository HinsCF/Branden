#include <iostream>
#include <random>
#include <iomanip>
using namespace std;



void printArray(double nums[], int size);
void mergeSort(double nums[], int start, int end);
void merge(double nums[], int start, int mid, int end);




int main() {
    const int ARRAY_SIZE = 5;
    const double max = 100.00;
    const double min = 1000.00;
    double nums[ARRAY_SIZE];
    auto nums_size = sizeof(nums) / sizeof(nums[0]);

    //Generate a random array
    for (int i = 0; i < nums_size; i++) {
        nums[i] = (max - min) * ((double)rand() / (double)RAND_MAX) + min;
    }
    // Test case for random double
    cout << "Before sorting: " << endl;
    printArray(nums, nums_size);

    // Merge Sort
    mergeSort(nums, 0, nums_size - 1);

    // text MergeSort
    cout << "after MergeSort: "<< endl;
    printArray(nums, nums_size);


    return 0;
}

void printArray(double nums[], int size) {
    for (int i = 0; i < size; i++) {
        cout << setprecision(5) << nums[i]<< "    ";
    }
    cout << endl;
}

void mergeSort(double nums[], int start, int end) {
    if (start >= end)
        return; // Returns recursivly
 
    auto mid = start + (end - start) / 2;
    mergeSort(nums, start, mid);
    mergeSort(nums, mid + 1, end);
    merge(nums, start, mid, end);
}

void merge(double nums[], int left, int mid, int right) {

    auto const sub1 = mid - left + 1;
    auto const sub2 = right - mid;
 
    auto *leftnums = new double[sub1];
    auto *rightnums = new double[sub2];
 
    // Copy data to leftnums[] and rightnums[]
    for (auto i = 0; i < sub1; i++)
        leftnums[i] = nums[left + i];
    for (auto j = 0; j < sub2; j++)
        rightnums[j] = nums[mid + 1 + j];
 
    auto i_sub1 = 0;
    auto i_sub2 = 0; 
    int i_nums = left; 
 
    // Merge
    while (i_sub1 < sub1 && i_sub2 < sub2) {
        if (leftnums[i_sub1] <= rightnums[i_sub2]) {
            nums[i_nums] = leftnums[i_sub1];
            i_sub1++;
        }
        else {
            nums[i_nums] = rightnums[i_sub2];
            i_sub2++;
        }
        i_nums++;
    }
    // Copy remaining left
    while (i_sub1 < sub1) {
        nums[i_nums] = leftnums[i_sub1];
        i_sub1++;
        i_nums++;
    }
    // Copy remaining right
    while (i_sub2 < sub2) {
        nums[i_nums] = rightnums[i_sub2];
        i_sub2++;
        i_nums++;
    }
}

