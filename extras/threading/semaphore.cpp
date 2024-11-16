#include <iostream>
#include <thread>
#include <semaphore>
#include <chrono>

using namespace std;

// Shared variable
int sharedVariable = 0;

// Semaphore to control access to the critical section
std::binary_semaphore semaphore(1); // Initial count of 1 means one thread can enter

// Function executed by threads
void updateSharedVariable(const string& threadName, int iterations) {
    for (int i = 0; i < iterations; ++i) {
        // Acquire the semaphore (enter critical section)
        semaphore.acquire();

        // Critical section
        cout << threadName << " entering critical section...\n";
        sharedVariable++;
        cout << threadName << " updated sharedVariable to: " << sharedVariable << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate work
        cout << threadName << " leaving critical section...\n";

        // Release the semaphore (exit critical section)
        semaphore.release();

        // Simulate some work outside the critical section
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}

int main() {
    // Create threads
    thread thread1(updateSharedVariable, "Thread1", 5);
    thread thread2(updateSharedVariable, "Thread2", 5);

    // Wait for threads to finish
    thread1.join();
    thread2.join();

    // Final value of shared variable
    cout << "Final value of sharedVariable: " << sharedVariable << endl;

    return 0;
}
