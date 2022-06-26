#ifndef IO_NAMESPACE
#define IO_NAMESPACE
    using std::cout;
    using std::cin;
    using std::endl;
#endif

class FCFS {

    protected:
        int numOfProcesses;
        int* arrivalTime;
        int* burstTime;
        int* turnAroundTime;
        int* waitingTime;
        int* completionTime;
        float avgWaitingTime = 0.0;
        float avgTurnAroundTime = 0.0;

    public:
        void fetchData() {
            for(int i = 0; i < numOfProcesses; i++) {
                cout << "Enter the arrival time for Process " << (i + 1) << ": ";
                cin >> arrivalTime[i];

                cout << "Enter the burst time for Process " << i + 1 << ": ";
                cin >> burstTime[i];

                cout << endl;
            }
        }

        void calculate() {
            for(int i = 0; i < numOfProcesses; i++) {
                if(i == 0) { //for first process
                    waitingTime[i] = 0; //for first process, waiting time is always 0
                    completionTime[i] = arrivalTime[i] + burstTime[i];
                    turnAroundTime[i] = waitingTime[i] + burstTime[i];
                } else {
                    waitingTime[i] = completionTime[i - 1] - arrivalTime[i];

                    if(waitingTime[i] < 0) waitingTime[i] = 0; //if waiting time turns out to be 0

                    completionTime[i] = arrivalTime[i] + waitingTime[i] + burstTime[i];
                    turnAroundTime[i] = waitingTime[i] + burstTime[i];
                }

                avgWaitingTime += (float) waitingTime[i];
                avgTurnAroundTime += (float) turnAroundTime[i];
            }

            avgWaitingTime /= (float) numOfProcesses;
            avgTurnAroundTime /= (float) numOfProcesses;
        }

        void printResults() {
            printf("Process | Arrival Time | Burst Time | Completion Time | Turnaround Time | Waiting Time\n");
            for(int i = 0; i < numOfProcesses; i++) {
                printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", (i + 1), arrivalTime[i], burstTime[i], completionTime[i], \
                turnAroundTime[i], waitingTime[i]);
                printf("---------------------------------------------------------------------------------------\n");
            }

            cout << endl;
            cout << "Average Waiting Time = " << avgWaitingTime << endl;
            cout << "Average Turn Around Time = " << avgTurnAroundTime << endl;
        }

        FCFS() {
            cout << "Enter the number of processes: ";
            cin >> numOfProcesses;

            arrivalTime = new int[numOfProcesses];
            burstTime = new int[numOfProcesses];
            turnAroundTime = new int[numOfProcesses];
            waitingTime = new int[numOfProcesses];
            completionTime = new int[numOfProcesses];

            cout << endl;
        }

        ~FCFS() {
            delete[] arrivalTime;
            delete[] burstTime;
            delete[] turnAroundTime;
            delete[] waitingTime;
            delete[] completionTime;
        }
};