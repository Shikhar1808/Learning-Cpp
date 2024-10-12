//Input n processes with respective CPU burst time and arrival time
//System should display waiting time for each process, average waiting time and execution order of processes

#include <iostream>
using namespace std;

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
    Process processes[100];
    int numProcesses;

    public:
        Scheduler(){
            numProcesses = 0;
        }  

        void addProcess(int burstTime, int arrivalTime){
            processes[numProcesses] = Process(numProcesses+1, burstTime, arrivalTime);
            numProcesses++;
        }

        void calculateTime(){
            int currentTime = 0;
            for(int i = 0; i<numProcesses; i++){
                if(currentTime < processes[i].arrivalTime){
                    currentTime = processes[i].arrivalTime;
                }
                processes[i].waitingTime = currentTime - processes[i].arrivalTime;
                processes[i].completionTime = currentTime + processes[i].burstTime;
                processes[i].turnAroundTime = processes[i].completionTime - processes[i].arrivalTime;
                currentTime += processes[i].burstTime;
            }
        }

        void displayExecutionOrder(){
            cout<<"Execution order of processes: ";
            for(int i = 0; i<numProcesses; ++i){
                for(int j=0; j<numProcesses - i -1; j++){
                    if((processes[j].arrivalTime > processes[j+1].arrivalTime) ||(processes[j].arrivalTime == processes[j+1].arrivalTime && processes[j].pid > processes[j+1].pid)){
                        swap(processes[j], processes[j+1]);
                    }
                }
            }

            for(int i = 0; i<numProcesses; ++i){
                cout << "P" << processes[i].pid;
                if (i != numProcesses - 1) {
                    cout << " -> ";
                }
            }
            cout<<endl;
        }

        void displayResults() {
        int totalWaitingTime = 0;
        int totalTurnAroundTime = 0;

        cout << "Process Execution Order and Waiting Times:"<<endl;
        cout << "PID\tArrival Time\tBurst Time\tWaiting Time\t Completion Time\t Turnaround Time\n";

        for (int i = 0; i < numProcesses; ++i) {
            totalWaitingTime += processes[i].waitingTime;
            totalTurnAroundTime += processes[i].turnAroundTime;
            cout << processes[i].pid << "\t" 
            << processes[i].arrivalTime << "\t\t"
            << processes[i].burstTime << "\t\t"
            << processes[i].waitingTime << "\t\t"
            << processes[i].completionTime << "\t\t"
            << processes[i].turnAroundTime << "\n";
        }

        float avgWaitingTime = (float)totalWaitingTime / numProcesses;
        float avgTurnAroundTime = (float)totalTurnAroundTime / numProcesses;
        cout << "\nAverage Waiting Time: " << avgWaitingTime << endl;
        cout << "Average Turnaround Time: " << avgTurnAroundTime << endl;
    }
};

int main(){

    Scheduler scheduler;
    int n;
    cout<<"Enter number of processes: ";
    cin>>n;

    for(int i = 0; i<n; i++){
        int burstTime, arrivalTime;
        cout<<"Enter burst time and arrival time for process "<<i+1<<": ";
        cin>>burstTime>>arrivalTime;
        scheduler.addProcess(burstTime, arrivalTime);
    }

    scheduler.calculateTime();
    scheduler.displayExecutionOrder();
    scheduler.displayResults();

    return 0;
}