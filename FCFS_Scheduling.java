import java.util.Scanner;
import java.lang.ArrayIndexOutOfBoundsException;

class FCFS {
    Scanner sc = new Scanner(System.in);

    int numOfProcesses;
    int[] arrivalTime = new int[numOfProcesses];
    int[] burstTime = new int[numOfProcesses];
    int[] turnAroundTime = new int[numOfProcesses];
    int[] waitingTime = new int[numOfProcesses];
    int[] completionTime = new int[numOfProcesses];
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
            if(i == 0) {
                this.waitingTime[i] = 0;
                this.completionTime[i] = this.arrivalTime[i] + this.burstTime[i];
                this.turnAroundTime[i] = this.waitingTime[i] + this.burstTime[i];
            } else {
                this.waitingTime[i] = this.completionTime[i - 1] - this.arrivalTime[i];

                if(this.waitingTime[i] < 0) this.waitingTime[i] = 0;

                this.completionTime[i] = this.arrivalTime[i] + this.waitingTime[i] + this.burstTime[i];
                turnAroundTime[i] = waitingTime[i] + this.burstTime[i];
            }

            this.avgWaitingTime += (float) this.waitingTime[i];
            this.avgTurnAroundTime += (float) this.turnAroundTime[i];
        }

        this.avgWaitingTime /= (float) this.numOfProcesses;
        this.avgTurnAroundTime /= (float) this.numOfProcesses;
    }

    FCFS() {
        System.out.print("Enter the number of processes: ");
        this.numOfProcesses = sc.nextInt();
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
                System.out.println("Completion Time for Process " + (i + 1) + ": " + obj1.completionTime[i]);
                System.out.println("Turn Around Time for Process " + (i + 1) + ": " + obj1.turnAroundTime[i]);
                System.out.println("Waiting Time for Process " + (i + 1) + ": " + obj1.waitingTime[i]);
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
