// To Do List C++ //
// Creation Date 07/21/2024 //
// Compile Command -  gcc todo.c -o todo //

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_NAME_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int completed;
    int id;
} Task;

typedef struct {
    Task* tasks;
    int size;
} TodoList;

void addTask(TodoList* list) {
    char taskName[MAX_NAME_LENGTH];

    printf("Enter task name: ");
    scanf("%s", taskName);

    Task* task = &list->tasks[list->size];
    strcpy(task->name, taskName);
    task->completed = 0;
    task->id = list->size + 1;
    list->size++;
}

void removeTask(TodoList* list, int id) {
    for (int i = 0; i < list->size; i++) {
        if (list->tasks[i].id == id) {
            for (int j = i; j < list->size - 1; j++) {
                list->tasks[j] = list->tasks[j + 1];
            }
            list->size--;
            printf("Task with ID %d removed successfully!\n", id);
            return;
        }
    }
    printf("Task with ID %d not found!\n", id);
}

int completeTask(TodoList* list, int id) {
    for (int i = 0; i < list->size; i++) {
        if (list->tasks[i].id == id) {
            list->tasks[i].completed = 1;
            printf("Task with ID %d marked as completed!\n", id);
            return 1;
        }
    }
    printf("Task with ID %d not found!\n", id);
    return 0;
}

void displayTasks(const TodoList* list) {
    for (int i = 0; i < list->size; i++) {
        printf("%d. %s %s\n", list->tasks[i].id, list->tasks[i].name, list->tasks[i].completed ? "[completed]" : "");
    }
}

int main() {
    TodoList list;
    list.size = 0;
    list.tasks = (Task*)calloc(MAX_TASKS, sizeof(Task));

    while (1) {
        printf("Options:\n");
        printf("1. Add task\n");
        printf("2. Remove task\n");
        printf("3. Complete task\n");
        printf("4. Display tasks\n");
        printf("5. Quit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask(&list);
                break;
            case 2: {
                int id;
                printf("Enter task ID: ");
                scanf("%d", &id);
                removeTask(&list, id);
                break;
            }
            case 3: {
                int id;
                printf("Enter task ID: ");
                scanf("%d", &id);
                completeTask(&list, id);
                break;
            }
            case 4:
                if (choice == 4) {
                    printf("\x1B[2J\x1B[H"); // Clear screen and move cursor to top left (Window Resize event)
                } else {
                    displayTasks(&list);
                    break;
            }
            case 5:
                return 0;
            default:
                printf("Invalid choice. Please choose a valid option.\n");
        }
    }

    free(list.tasks);

    return 0;
}