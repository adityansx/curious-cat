#include <iostream>
#include "FCFS.h"

class SJF: public FCFS {
    public:
        void sort() {
            bool swapped;
            for(int i = 0; i < numOfProcesses - 1; i++) {
                swapped = false;

                for(int j = 0; j < numOfProcesses - i - 1; j++) {
                    if(*(burstTime + j) > *(burstTime + j + 1)) {
                        int temp_1 = *(arrivalTime + j);
                        int temp_2 = *(burstTime + j);

                        *(arrivalTime + j) = *(arrivalTime + j + 1);
                        *(arrivalTime + j + 1) = temp_1;

                        *(burstTime + j) = *(burstTime + j + 1);
                        *(burstTime + j + 1) = temp_2;
                        swapped = true;
                    }
                }

                if(!swapped)
                    break;
            }
            for(int i = 0; i < numOfProcesses - 1; i++) {
                swapped = false;

                for(int j = 0; j < numOfProcesses - i - 1; j++) {
                    if(*(arrivalTime + j) > *(arrivalTime + j + 1)) {
                        int temp_1 = *(burstTime + j);
                        int temp_2 = *(arrivalTime + j);

                        *(burstTime + j) = *(burstTime + j + 1);
                        *(burstTime + j + 1) = temp_1;

                        *(arrivalTime + j) = *(arrivalTime + j + 1);
                        *(arrivalTime + j + 1) = temp_2;
                        swapped = true;
                    }
                }

                if(!swapped)
                    break;
            }
        }

        SJF(): FCFS() {}
};

int main() {
    SJF obj1;

    obj1.fetchData();
    obj1.sort();
    obj1.calculate();
    obj1.printResults();
}