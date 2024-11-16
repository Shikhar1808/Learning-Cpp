#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int BURST_TIME_MAX = 1000;

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
    int timeQuantum;

    public:
        Scheduler(int timeQuantum){
            this->timeQuantum = timeQuantum;
        }

        void addProcess(int burstTime, int arrivalTime){
            processes.emplace_back(processes.size() + 1, burstTime, arrivalTime);
        }

        void calculateTime(){
            queue<int> readyQueue;
            int currentTime = 0;
            int completed = 0;
            int n = processes.size();
            vector<bool> visited(n, false);

            for(int i=0; i<n; i++){
                if(processes[i].arrivalTime <= currentTime){
                    readyQueue.push(i);
                    visited[i]  = true;
                }
            }

            while(!readyQueue.empty()){
                int idx = readyQueue.front();
                readyQueue.pop();


                if (processes[idx].remainingTime > 0) {
                // Process execution for time quantum or remaining time
                int executionTime = min(timeQuantum, processes[idx].remainingTime);
                currentTime += executionTime;
                processes[idx].remainingTime -= executionTime;

                // Check for newly arrived processes and add them to the queue
                    for (int i = 0; i < n; ++i) {
                        if (!visited[i] && processes[i].arrivalTime <= currentTime) {
                            readyQueue.push(i);
                            visited[i] = true;
                        }
                    }
                }

                if (processes[idx].remainingTime > 0) {
                    readyQueue.push(idx);
                } else {
                    // Process completed
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
    Scheduler scheduler(2);
    scheduler.addProcess(5, 0);
    scheduler.addProcess(4, 1);
    scheduler.addProcess(2, 2);
    scheduler.addProcess(1, 3);
    scheduler.addProcess(6, 4);

    scheduler.displayResults();

    return 0;
}