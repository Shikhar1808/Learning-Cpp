#include <iostream>
#include <vector>
using namespace std;

const int BURST_TIME_MAX = 1000;

class Process{
    public:
    int pid;
    int burstTime;
    int arrivalTime;
    int waitingTime;
    int completionTime;
    int turnAroundTime;

    Process() : pid(0), burstTime(0), arrivalTime(0), waitingTime(0), completionTime(0), turnAroundTime(0) {}

    Process(int pid, int burstTime, int arrivalTime){
        this->pid = pid;
        this->burstTime = burstTime;
        this->arrivalTime = arrivalTime;
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
            //Adds a new element to the end of the processes container.
            //emplace_back contains the object in place at the back of the container, avoiding unnecessary copies or moves (+ avoiding additional memory allocation if possible).
        }

        void calculateTime(){
            int currentTime = 0;
            int completed = 0;
            int n = processes.size();
            vector<bool> isCompleted(n, false);

            while(completed < n){
                int idx = -1;
                int minBurst = BURST_TIME_MAX;

                for(int i=0; i< n; i++){
                    if(processes[i].arrivalTime <= currentTime && !isCompleted[i]){
                        if(processes[i].burstTime < minBurst){
                            minBurst = processes[i].burstTime;
                            idx = i;
                        }
                        if(processes[i].burstTime == minBurst){
                            if(processes[i].arrivalTime < processes[idx].arrivalTime){
                                idx = i;
                            }
                        }
                    }
                }

                if(idx != -1){
                    processes[idx].waitingTime = currentTime - processes[idx].arrivalTime;
                    processes[idx].completionTime = currentTime + processes[idx].burstTime;
                    processes[idx].turnAroundTime = processes[idx].completionTime - processes[idx].arrivalTime;
                    currentTime += processes[idx].burstTime;
                    isCompleted[idx] = true;
                    completed++;
                }
                else{
                    currentTime++;
                }
            }
        }

        void displayExecutionOrder(){
            int totalWaitingTime = 0;
            int totalTurnAroundTime = 0;

            calculateTime();

            cout<<"Execution order of processes: ";
            cout<<"PID\tArrival Time\tBurst Time\tWaiting Time\tCompletion Time\tTurnaround Time\n";

            for(int i=0; i<processes.size(); i++){
                cout<<processes[i].pid<<"\t"<<processes[i].arrivalTime<<"\t\t"<<processes[i].burstTime<<"\t\t"<<processes[i].waitingTime<<"\t\t"<<processes[i].completionTime<<"\t\t"<<processes[i].turnAroundTime<<endl;
                totalWaitingTime += processes[i].waitingTime;
                totalTurnAroundTime += processes[i].turnAroundTime;
            }

            cout<<"Average waiting time: "<<(float)totalWaitingTime/processes.size()<<endl;

            cout<<"Average turnaround time: "<<(float)totalTurnAroundTime/processes.size()<<endl;
        }
};

int main(){
    Scheduler scheduler;
    scheduler.addProcess(5, 0);
    scheduler.addProcess(3, 1);
    scheduler.addProcess(6, 2);
    scheduler.addProcess(7, 3);
    scheduler.addProcess(4, 4);

    scheduler.displayExecutionOrder();

    return 0;
}