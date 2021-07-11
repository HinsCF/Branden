#include <iostream>
#include <random>
#include <iomanip>
using namespace std;


void quickSort(double nums[]);
void quickSort(double nums[], int p, int r);
//void mergeSort(double nums[]);
//void selectionSort(double nums[]);
//void insertionSort(double nums[]);
int partition(double nums[], int p, int r);
void swap(double *a, double *b);



int main() {
    const int ARRAY_SIZE = 5;
    const double LOWER_BOUND = 100.00;
    const double UPPER_BOUND = 1000.00;
    double nums[ARRAY_SIZE];

    random_device rd;
    default_random_engine eng(rd());
    uniform_real_distribution<double> distr(LOWER_BOUND, UPPER_BOUND);


    for (int i = 0; i < ARRAY_SIZE; i++) {
        nums[i] = distr(eng);
    }
    // Test case for random double
    
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << setprecision(5) << nums[i] << "  ";
    }
    cout << endl;
    

    quickSort(nums);
    //mergeSort(nums);
    //selectionSort(nums);
    //insertionSort(nums);

    // test case: print sorted array
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << setprecision(5) << nums[i] << "  ";
    }

    return 0;
}

void quickSort(double nums[]) {
    int p = 0;
    int r = sizeof(nums) ;
    quickSort(nums, p, r);
}

void quickSort(double nums[], int p, int r) {
    if (p < r) {
        int q = partition(nums, p, r);
        quickSort(nums, p, q - 1);
        quickSort(nums, q +1 , r);
    }
}


int partition(double nums[], int p, int r) {
    double x = nums[r];
    int i = p -1;
    for (int j = p ; j <= r - 1; j++) {
        if (nums[j] <= x) {
            i = i + 1;
            swap(&nums[i], &nums[j]);
        }
    }
    swap(&nums[i + 1], &nums[r]);

    // test case
    /*
    for (int i = 0; i < sizeof(nums); i++) {
        cout << setprecision(3) << nums[i] << "   ";
    }
    */

    return i + 1;
}

void swap(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

