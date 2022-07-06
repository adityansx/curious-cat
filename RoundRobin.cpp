#include <iostream>
#include <vector>
#include "FCFS.h"

#define QUANTUM 2

class RoundRobin: public FCFS {
    protected:
        int* remBurstTime;
        int currentTime = 0;

    public:
        void calculate() {//Overriding void FCFS::calculate()
            for (int i = 0 ; i < numOfProcesses ; i++)
                remBurstTime[i] = burstTime[i];
        
            int t = 0; // Current time
        
            // Keep traversing processes in round robin manner
            // until all of them are not done.
            while (1)
            {
                bool done = true;
        
                // Traverse all processes one by one repeatedly
                for (int i = 0 ; i < numOfProcesses; i++)
                {
                    // If burst time of a process is greater than 0
                    // then only need to process further
                    if (remBurstTime[i] > 0)
                    {
                        done = false; // There is a pending process
        
                        if (remBurstTime[i] > QUANTUM)
                        {
                            // Increase the value of t i.e. shows
                            // how much time a process has been processed
                            t += QUANTUM;
        
                            // Decrease the burst_time of current process
                            // by QUANTUM
                            remBurstTime[i] -= QUANTUM;
                        }
        
                        // If burst time is smaller than or equal to
                        // QUANTUM. Last cycle for this process
                        else
                        {
                            // Increase the value of t i.e. shows
                            // how much time a process has been processed
                            t = t + remBurstTime[i];
        
                            // Waiting time is current time minus time
                            // used by this process
                            waitingTime[i] = t - burstTime[i];
        
                            // As the process gets fully executed
                            // make its remaining burst time = 0
                            remBurstTime[i] = 0;
                        }
                    }
                }
        
                // If all processes are done
                if (done == true)
                break;
            }
        }

        RoundRobin(): FCFS() {
            remBurstTime = new int[numOfProcesses];
        }

        ~RoundRobin() {
            delete[] remBurstTime;
        }
};

int main() {
    RoundRobin obj1;
    obj1.fetchData();
    obj1.calculate();
    obj1.printResults();

    return 0;
}

