// #ifndef IO_NAMESPACE
// #define IO_NAMESPACE
//     using std::std::cout;
//     using std::std::cin;
//     using std::std::endl;
// #endif

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
                std::cout << "Enter the arrival time for Process " << (i + 1) << ": ";
                std::cin >> arrivalTime[i];

                std::cout << "Enter the burst time for Process " << i + 1 << ": ";
                std::cin >> burstTime[i];

                std::cout << std::endl;
            }
        }

        void calculate() {
            for(int i = 0; i < numOfProcesses; i++) {
                waitingTime[i] = 0;
                turnAroundTime[i] = 0;

                waitingTime[i] = completionTime[i] - arrivalTime[i];
                if(waitingTime[i] < 0) 
                    waitingTime[i] = 0; //if waiting time turns out to be negative
                completionTime[i + 1] = arrivalTime[i] + waitingTime[i] + burstTime[i];
                turnAroundTime[i] = completionTime[i + 1] - arrivalTime[i];

                avgWaitingTime += (float) waitingTime[i];
                avgTurnAroundTime += (float) turnAroundTime[i];
            }
            avgWaitingTime /= (float) numOfProcesses;
            avgTurnAroundTime /= (float) numOfProcesses;
        }

        void printResults() {
            printf("Process | Arrival Time | Burst Time | Completion Time | Turnaround Time | Waiting Time\n");
            for(int i = 0; i < numOfProcesses; i++) {
                printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", (i + 1), arrivalTime[i], burstTime[i], completionTime[i + 1], \
                turnAroundTime[i], waitingTime[i]);
                printf("---------------------------------------------------------------------------------------\n");
            }

            std::cout << std::endl;
            std::cout << "Average Waiting Time = " << avgWaitingTime << std::endl;
            std::cout << "Average Turn Around Time = " << avgTurnAroundTime << std::endl;
        }

        FCFS() {
            std::cout << "Enter the number of processes: ";
            std::cin >> numOfProcesses;

            arrivalTime = new int[numOfProcesses];
            burstTime = new int[numOfProcesses];
            turnAroundTime = new int[numOfProcesses];
            waitingTime = new int[numOfProcesses];
            completionTime = new int[numOfProcesses + 1];

            *(completionTime) = 0;
            std::cout << std::endl;
        }

        ~FCFS() {
            delete[] arrivalTime;
            delete[] burstTime;
            delete[] turnAroundTime;
            delete[] waitingTime;
            delete[] completionTime;
        }
};