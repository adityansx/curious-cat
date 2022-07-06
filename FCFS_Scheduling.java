import java.util.Scanner;
import java.lang.ArrayIndexOutOfBoundsException;

class FCFS {
    Scanner sc = new Scanner(System.in);

    int numOfProcesses;
    int[] arrivalTime;
    int[] burstTime;
    int[] turnAroundTime;
    int[] waitingTime;
    int[] completionTime;
    float avgWaitingTime = 0f;
    float avgTurnAroundTime = 0f;

    void fetchData() {
        for(int i = 0; i < numOfProcesses; i++) {
            System.out.print("Enter the arrival time for Process " + (i + 1) + ": ");
            this.arrivalTime[i] = sc.nextInt();

            System.out.print("Enter the burst time for Process " + (i + 1) + ": ");
            this.burstTime[i] = sc.nextInt();

            System.out.println();
        }
    }

    // completionTime[0] = 0;
    void calculate() {
        for(int i = 0; i < numOfProcesses; i++) {
            waitingTime[i] = 0;
            turnAroundTime[i] = 0;

            waitingTime[i] = completionTime[i] - arrivalTime[i];
            if(waitingTime[i] < 0) 
                waitingTime[i] = 0;
            completionTime[i + 1] = arrivalTime[i] + burstTime[i] + waitingTime[i];
            turnAroundTime[i] = waitingTime[i] + burstTime[i];

            this.avgWaitingTime += (float) this.waitingTime[i];
            this.avgTurnAroundTime += (float) this.turnAroundTime[i];

        }
        avgWaitingTime /= (float) numOfProcesses;
        avgTurnAroundTime /= (float) numOfProcesses;
    }
    

    FCFS() {
        System.out.print("Enter the number of processes: ");
        this.numOfProcesses = sc.nextInt();

        arrivalTime = new int[numOfProcesses];
        burstTime = new int[numOfProcesses];
        turnAroundTime = new int[numOfProcesses];
        waitingTime = new int[numOfProcesses];
        completionTime = new int[numOfProcesses + 1];

        completionTime[0] = 0;

        System.out.println();
    }
}

public class FCFS_Scheduling {
    public static void main(String[] args) throws ArrayIndexOutOfBoundsException {
        try {
            FCFS obj1 = new FCFS();

            obj1.fetchData();
            obj1.calculate();

            for(int i = 0; i < obj1.numOfProcesses; i++) {
                System.out.println("Completion Time for Process " + (i + 1) + ": " + obj1.completionTime[i + 1]);
                System.out.println("Turn Around Time for Process " + (i + 1) + ": " + obj1.turnAroundTime[i]);
                System.out.println("Waiting Time for Process " + (i + 1) + ": " + obj1.waitingTime[i]);
                System.out.println();
            }

            System.out.println();
            System.out.println("Average Waiting Time = " + obj1.avgWaitingTime);
            System.out.println("Average Turn Around Time = " + obj1.avgTurnAroundTime);
        } catch(ArrayIndexOutOfBoundsException exception) {
            System.err.println(exception);
        } finally {
            System.out.println("Exiting...");
        }
    }
}
