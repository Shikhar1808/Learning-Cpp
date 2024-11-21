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
    vector<string> ganttChart;

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

            ganttChart.push_back("(" + to_string(currentTime) + ")" + "P" + to_string(processes[minPriorityIdx].pid) + "(" + to_string(currentTime + processes[minPriorityIdx].burstTime) + ") ||");

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

        cout << "\nGantt Chart:\n";
        for (int i = 0; i< ganttChart.size(); i++){
            cout << ganttChart[i];
        }
        cout << endl;
        cout << endl;

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
    // int n;
    // cout << "Enter number of processes: ";
    // cin >> n;

    // for (int i = 0; i < n; i++) {
    //     int burstTime, arrivalTime, priority;
    //     cout << "Enter burst time, arrival time, and priority for process " << i + 1 << ": ";
    //     cin >> burstTime >> arrivalTime >> priority;
    //     scheduler.addProcess(burstTime, arrivalTime, priority);
    // }

    scheduler.addProcess(5, 0, 3);
    scheduler.addProcess(3, 1, 1);
    scheduler.addProcess(6, 2, 4);
    scheduler.addProcess(7, 3, 2);
    scheduler.addProcess(4, 4, 5);

    scheduler.displayResults();

    return 0;
}
