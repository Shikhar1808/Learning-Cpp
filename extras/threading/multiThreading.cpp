#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <climits>

#define SIZE 10

// Shared data array
std::vector<int> data = {3, 7, 2, 9, 12, 5, 6, 8, 15, 4};

// Shared results
int sum = 0;
int maxVal = INT_MIN;
int minVal = INT_MAX;

// Mutex for thread safety
std::mutex mtx;

// Thread function to calculate sum
void calculateSum() {
    int localSum = 0;
    for (int val : data) {
        localSum += val;
    }

    // Protect shared variable with a mutex
    std::lock_guard<std::mutex> lock(mtx);
    sum = localSum;
}

// Thread function to find the maximum value
void findMax() {
    int localMax = INT_MIN;
    for (int val : data) {
        if (val > localMax) {
            localMax = val;
        }
    }

    // Protect shared variable with a mutex
    std::lock_guard<std::mutex> lock(mtx);
    maxVal = localMax;
}

// Thread function to find the minimum value
void findMin() {
    int localMin = INT_MAX;
    for (int val : data) {
        if (val < localMin) {
            localMin = val;
        }
    }

    // Protect shared variable with a mutex
    std::lock_guard<std::mutex> lock(mtx);
    minVal = localMin;
}

int main() {
    // Create threads
    std::thread sumThread(calculateSum);
    std::thread maxThread(findMax);
    std::thread minThread(findMin);

    // Wait for threads to complete
    sumThread.join();
    maxThread.join();
    minThread.join();

    // Print the results
    std::cout << "Sum of elements: " << sum << std::endl;
    std::cout << "Maximum value: " << maxVal << std::endl;
    std::cout << "Minimum value: " << minVal << std::endl;

    return 0;
}
