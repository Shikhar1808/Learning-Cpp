#include <iostream>
#include <vector>
using namespace std;

int BURST_TIME_MAX = 1000;

class Process {
public:
    int pid;
    int burstTime;
    int arrivalTime;
    int remainingTime;
    int waitingTime;
    int completionTime;
    int turnAroundTime;

    Process() : pid(0), burstTime(0), arrivalTime(0), remainingTime(0), waitingTime(0), completionTime(0), turnAroundTime(0) {}

    Process(int pid, int burstTime, int arrivalTime) {
        this->pid = pid;
        this->burstTime = burstTime;
        this->arrivalTime = arrivalTime;
        this->remainingTime = burstTime;
        this->waitingTime = 0;
        this->completionTime = 0;
        this->turnAroundTime = 0;
    }
};

class Scheduler{
    vector<Process> processes;

    public:

    void addProcess(int burstTime, int arrivalTime){
        processes.emplace_back(processes.size() + 1, burstTime, arrivalTime);
    }

    int calculateTime(){
        int currentTime = 0;
        int completed = 0;
        int n = processes.size();
        int minRemainingTime;
        int idx = -1;
        bool found;

        while (completed < n) {
            minRemainingTime = BURST_TIME_MAX;
            found = false;

            // Find the process with the smallest remaining time at current time
            for (int i = 0; i < n; ++i) {
                if (processes[i].arrivalTime <= currentTime && processes[i].remainingTime > 0) {
                    if (processes[i].remainingTime < minRemainingTime) {
                        minRemainingTime = processes[i].remainingTime;
                        idx = i;
                        found = true;
                    } else if (processes[i].remainingTime == minRemainingTime && processes[i].arrivalTime < processes[idx].arrivalTime) {
                        idx = i;
                    }
                }
            }

            if (!found) {
                currentTime++;
                continue;
            }

            // Process the selected process for one unit of time
            processes[idx].remainingTime--;
            currentTime++;

            // If the process is completed
            if (processes[idx].remainingTime == 0) {
                completed++;
                processes[idx].completionTime = currentTime;
                processes[idx].turnAroundTime = processes[idx].completionTime - processes[idx].arrivalTime;
                processes[idx].waitingTime = processes[idx].turnAroundTime - processes[idx].burstTime;
            }
        }
    }

    void displayResults() {
        int totalWaitingTime = 0;
        int totalTurnAroundTime = 0;

        calculateTime();

        cout << "Process Execution Order and Waiting Times:\n";
        cout << "PID\tArrival Time\tBurst Time\tWaiting Time\tCompletion Time\tTurnaround Time\n";

        for (const auto& process : processes) {
            totalWaitingTime += process.waitingTime;
            totalTurnAroundTime += process.turnAroundTime;
            cout << process.pid << "\t"
                 << process.arrivalTime << "\t\t"
                 << process.burstTime << "\t\t"
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
    scheduler.addProcess(7, 0);
    scheduler.addProcess(2, 2);
    scheduler.addProcess(5, 4);
    scheduler.addProcess(3, 6);
    scheduler.addProcess(1, 8);

    scheduler.displayResults();

    return 0;
}