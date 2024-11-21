#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Process {
public:
    int pid;
    int burstTime;
    int remainingTime;
    int arrivalTime;
    int priority;
    int waitingTime;
    int completionTime;
    int turnAroundTime;

    Process() : pid(0), burstTime(0), remainingTime(0), arrivalTime(0), priority(0), waitingTime(0), completionTime(0), turnAroundTime(0) {}

    Process(int pid, int burstTime, int arrivalTime, int priority) {
        this->pid = pid;
        this->burstTime = burstTime;
        this->remainingTime = burstTime;
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
        int completed = 0;
        int n = processes.size();
        int lastExecuted = -1;

        while (completed < n) {
            int minPriorityIdx = -1;

            // Find the process with the highest priority (lowest numerical value) that has arrived
            for (int i = 0; i < n; ++i) {
                if (processes[i].arrivalTime <= currentTime && processes[i].remainingTime > 0) {
                    if (minPriorityIdx == -1 || processes[i].priority < processes[minPriorityIdx].priority) {
                        minPriorityIdx = i;
                    }
                }
            }

            if (minPriorityIdx == -1) {
                // No process is ready, move time forward
                currentTime++;
                continue;
            }

            // Execute the selected process for one unit of time
            processes[minPriorityIdx].remainingTime--;
            
            if (lastExecuted != processes[minPriorityIdx].pid) {
                cout << "Time " << currentTime << ": Process P" << processes[minPriorityIdx].pid << " started\n";
            }
            lastExecuted = processes[minPriorityIdx].pid;
            
            ganttChart.push_back("("  + to_string(currentTime) + ") " +  "P" + to_string(processes[minPriorityIdx].pid) + " (" + to_string(currentTime+1) + ") ||");
            
            currentTime++;

            // If the process finishes, calculate its completion time
            if (processes[minPriorityIdx].remainingTime == 0) {
                processes[minPriorityIdx].completionTime = currentTime;
                processes[minPriorityIdx].turnAroundTime = processes[minPriorityIdx].completionTime - processes[minPriorityIdx].arrivalTime;
                processes[minPriorityIdx].waitingTime = processes[minPriorityIdx].turnAroundTime - processes[minPriorityIdx].burstTime;
                completed++;
                cout << "Time " << currentTime << ": Process P" << processes[minPriorityIdx].pid << " finished\n";
            }
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

        cout << "\nProcess Execution Details:\n";
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
        cout << "\n\nAverage Waiting Time: " << avgWaitingTime << endl;
        cout << "Average Turnaround Time: " << avgTurnAroundTime << endl;
        cout<<endl;
    }
};

int main() {
    Scheduler scheduler;

    scheduler.addProcess(5, 0, 3);
    scheduler.addProcess(3, 1, 1);
    scheduler.addProcess(6, 2, 4);
    scheduler.addProcess(7, 3, 2);
    scheduler.addProcess(4, 4, 5);

    scheduler.displayResults();

    return 0;
}
