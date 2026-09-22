#include <stdio.h>
#include <string.h>

#define MAX 100

struct Process
{
    int pid;
    char name[50];
    int priority;
    char state[20];
};

int main()
{
    struct Process p[MAX];
    int n, choice, i;

    // Enter number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Enter details of each process
    for (i = 0; i < n; i++)
    {
        printf("\nEnter details for Process %d\n", i + 1);

        printf("Process ID: ");
        scanf("%d", &p[i].pid);

        printf("Process Name: ");
        scanf("%s", p[i].name);

        printf("Priority: ");
        scanf("%d", &p[i].priority);

        printf("State (Ready/Running/Waiting): ");
        scanf("%s", p[i].state);
    }

    // Menu
    do
    {
        printf("\n========== PROCESS MANAGEMENT ==========\n");
        printf("1. Display all process details\n");
        printf("2. Display process with highest priority\n");
        printf("3. Display processes in a particular state\n");
        printf("4. Change state of a process\n");
        printf("5. Display current state of all processes\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\n----- All Process Details -----\n");

                for (i = 0; i < n; i++)
                {
                    printf("\nProcess ID: %d\n", p[i].pid);
                    printf("Process Name: %s\n", p[i].name);
                    printf("Priority: %d\n", p[i].priority);
                    printf("State: %s\n", p[i].state);
                }
                break;

            case 2:
            {
                int highest = 0;

                for (i = 1; i < n; i++)
                {
                    if (p[i].priority < p[highest].priority)
                    {
                        highest = i;
                    }
                }

                printf("\n----- Highest Priority Process -----\n");
                printf("Process ID: %d\n", p[highest].pid);
                printf("Process Name: %s\n", p[highest].name);
                printf("Priority: %d\n", p[highest].priority);
                printf("State: %s\n", p[highest].state);

                break;
            }

            case 3:
            {
                char searchState[20];
                int found = 0;

                printf("\nEnter state to search: ");
                scanf("%s", searchState);

                printf("\n----- Processes in %s State -----\n", searchState);

                for (i = 0; i < n; i++)
                {
                    if (strcmp(p[i].state, searchState) == 0)
                    {
                        printf("PID: %d | Name: %s | Priority: %d\n",
                               p[i].pid,
                               p[i].name,
                               p[i].priority);

                        found = 1;
                    }
                }

                if (found == 0)
                {
                    printf("No processes found in this state.\n");
                }

                break;
            }

            case 4:
            {
                int pid;
                char newState[20];
                int found = 0;

                printf("\nEnter Process ID whose state you want to change: ");
                scanf("%d", &pid);

                for (i = 0; i < n; i++)
                {
                    if (p[i].pid == pid)
                    {
                        printf("Current State: %s\n", p[i].state);

                        printf("Enter new state: ");
                        scanf("%s", newState);

                        strcpy(p[i].state, newState);

                        printf("Process state changed successfully.\n");

                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Process ID not found.\n");
                }

                break;
            }

            case 5:
                printf("\n----- Current State of All Processes -----\n");

                for (i = 0; i < n; i++)
                {
                    printf("PID: %d | %s | State: %s\n",
                           p[i].pid,
                           p[i].name,
                           p[i].state);
                }

                break;

            case 6:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}
