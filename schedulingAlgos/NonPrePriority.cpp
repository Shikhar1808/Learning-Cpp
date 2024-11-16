#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Process {
public:
    int pid;
    int burstTime;
    int arrivalTime;
    int priority;
    int waitingTime;
    int completionTime;
    int turnAroundTime;

    Process() : pid(0), burstTime(0), arrivalTime(0), priority(0), waitingTime(0), completionTime(0), turnAroundTime(0) {}

    Process(int pid, int burstTime, int arrivalTime, int priority) {
        this->pid = pid;
        this->burstTime = burstTime;
        this->arrivalTime = arrivalTime;
        this->priority = priority;
        this->waitingTime = 0;
        this->completionTime = 0;
        this->turnAroundTime = 0;
    }
};

class Scheduler {
    vector<Process> processes;

public:
    void addProcess(int burstTime, int arrivalTime, int priority) {
        processes.emplace_back(processes.size() + 1, burstTime, arrivalTime, priority);
    }

    void calculateTime() {
        int currentTime = 0;
        vector<bool> isCompleted(processes.size(), false);

        for (int count = 0; count < processes.size(); ++count) {
            int minPriorityIdx = -1;
            for (int i = 0; i < processes.size(); ++i) {
                if (!isCompleted[i] && processes[i].arrivalTime <= currentTime) {
                    if (minPriorityIdx == -1 || processes[i].priority < processes[minPriorityIdx].priority) {
                        minPriorityIdx = i;
                    }
                }
            }

            if (minPriorityIdx == -1) {
                // If no process is ready, move the time forward
                currentTime++;
                count--;
                continue;
            }

            Process& p = processes[minPriorityIdx];
            p.waitingTime = currentTime - p.arrivalTime;
            p.completionTime = currentTime + p.burstTime;
            p.turnAroundTime = p.completionTime - p.arrivalTime;

            currentTime += p.burstTime;
            isCompleted[minPriorityIdx] = true;
        }
    }

    void displayResults() {
        int totalWaitingTime = 0;
        int totalTurnAroundTime = 0;

        calculateTime();

        cout << "Process Execution Order and Waiting Times:\n";
        cout << "PID\tArrival Time\tBurst Time\tPriority\tWaiting Time\tCompletion Time\tTurnaround Time\n";

        for (const auto& process : processes) {
            totalWaitingTime += process.waitingTime;
            totalTurnAroundTime += process.turnAroundTime;
            cout << process.pid << "\t"
                 << process.arrivalTime << "\t\t"
                 << process.burstTime << "\t\t"
                 << process.priority << "\t\t"
                 << process.waitingTime << "\t\t"
                 << process.completionTime << "\t\t"
                 << process.turnAroundTime << "\n";
        }

        float avgWaitingTime = (float)totalWaitingTime / processes.size();
        float avgTurnAroundTime = (float)totalTurnAroundTime / processes.size();
        cout << "\nAverage Waiting Time: " << avgWaitingTime << endl;
        cout << "Average Turnaround Time: " << avgTurnAroundTime << endl;
    }
};

int main() {
    Scheduler scheduler;
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int burstTime, arrivalTime, priority;
        cout << "Enter burst time, arrival time, and priority for process " << i + 1 << ": ";
        cin >> burstTime >> arrivalTime >> priority;
        scheduler.addProcess(burstTime, arrivalTime, priority);
    }

    scheduler.displayResults();

    return 0;
}
