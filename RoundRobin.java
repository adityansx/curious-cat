import java.util.Scanner;

public class RoundRobin {
    int numOfProcesses;
    int timeQuantum;
    int sumOfQuantum = 0;
    int temp;
    int count = 0;
    int[] burstTime, waitingTime, turnAroundTime, remainingTime;
    private static final Scanner sc = new Scanner(System.in);

    void fetchData() {
        for (int i = 0; i < numOfProcesses; i++) {
            System.out.print("Enter the burst time for Process " + (i + 1) + ": ");
            remainingTime[i] = burstTime[i] = sc.nextInt();
        }
    }

    void calculate() {
        while(count != numOfProcesses) {
            for(int i = 0; i < numOfProcesses; i++) {
                if(remainingTime[i] == 0) {
                    count++;
                    continue;
                }
                temp = timeQuantum;
                if(remainingTime[i] > timeQuantum) {
                    remainingTime[i] -= timeQuantum;
                } else if(remainingTime[i] >= 0) {
                    temp = remainingTime[i];
                    remainingTime[i] = 0;
                    turnAroundTime[i] = sumOfQuantum + temp;
                }
                sumOfQuantum += temp;
                // System.out.println("Process | Burst Time | Remaining BT");
                // System.out.println((i + 1) + "\t\t" + burstTime[i]+ "\t\t" + remainingTime[i]);
                // System.out.println("-----------------------------------------------------");
                // System.out.println("Current Time: " + sumOfQuantum + "\n" + "Loop Iteration " + i + "\n" + "Count: " + count);
            }
        }
        for (int i = 0; i < numOfProcesses; i++) {
            waitingTime[i] = turnAroundTime[i] - burstTime[i];
        }
    }

    void printResults() {
        System.out.println();
        System.out.println("Process | Burst Time | Turnaround Time | Waiting Time");
        for(int i = 0; i < numOfProcesses; i++) {
            System.out.println((i + 1) + "\t\t" + burstTime[i]+ "\t\t" + turnAroundTime[i] + "\t\t" + waitingTime[i]);
            System.out.println("-----------------------------------------------------");
        }
    }

    RoundRobin() {
        System.out.print("Enter the number of processes: ");
        numOfProcesses = sc.nextInt();
        System.out.print("Enter Time Quantum: ");
        timeQuantum = sc.nextInt();
        System.out.println();

        burstTime = new int[numOfProcesses];
        waitingTime = new int[numOfProcesses];
        turnAroundTime = new int[numOfProcesses];
        remainingTime = new int[numOfProcesses];
    }

    public static void main(String[] args) {
        RoundRobin obj1 = new RoundRobin();

        obj1.fetchData();
        obj1.calculate();
        obj1.printResults();
    }
}
