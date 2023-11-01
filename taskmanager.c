#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_TASK_LENGTH 50

struct Task {
    char description[MAX_TASK_LENGTH];
    int priority;
    int isCompleted;
};

struct Task tasks[MAX_TASKS];
int taskCount = 0;

void addTask() {
    if (taskCount < MAX_TASKS) {
        struct Task newTask;
        printf("Enter task description: ");
        scanf(" %[^\n]", newTask.description);
        printf("Enter task priority (1 - Low, 2 - Medium, 3 - High): ");
        scanf("%d", &newTask.priority);
        newTask.isCompleted = 0;
        tasks[taskCount++] = newTask;
        printf("Task added successfully!\n");
    } else {
        printf("Task list is full. Cannot add more tasks.\n");
    }
}

void markCompleted() {
    if (taskCount > 0) {
        printf("Task List:\n");
        for (int i = 0; i < taskCount; i++) {
            printf("%d. %s\n", i + 1, tasks[i].description);
        }
        printf("Enter the task number to mark as completed: ");
        int taskNumber;
        scanf("%d", &taskNumber);

        if (taskNumber >= 1 && taskNumber <= taskCount) {
            tasks[taskNumber - 1].isCompleted = 1;
            printf("Task marked as completed!\n");
        } else {
            printf("Invalid task number.\n");
        }
    } else {
        printf("Task list is empty. Nothing to mark as completed.\n");
    }
}

void displayTasks() {
    if (taskCount > 0) {
        printf("Task List:\n");
        for (int i = 0; i < taskCount; i++) {
            printf("%d. Description: %s, Priority: %d, Status: %s\n",
                   i + 1, tasks[i].description, tasks[i].priority,
                   tasks[i].isCompleted ? "Completed" : "Not Completed");
        }
    } else {
        printf("Task list is empty.\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nTo-Do List\n");
        printf("1. Add Task\n");
        printf("2. Mark Task as Completed\n");
        printf("3. Display Tasks\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                markCompleted();
                break;
            case 3:
                displayTasks();
                break;
            case 4:
                printf("Exiting the To-Do List program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}