// To Do List C++ //
// Creation Date 07/21/2024 //
// Compile Command -  gcc -std=c++11 -o todo todo.cpp -lstdc++ //

#include <iostream>
#include <string>
#include <vector>


using namespace std;

struct Task {
    string name;
    bool completed;
    int id;
};

struct TodoList {
    vector<Task> tasks;
};

void addTask(TodoList& list) {
    string taskName;
    cout << "Enter task name: ";
    cin >> taskName;

    Task task;
    task.name = taskName;
    task.completed = false;
    task.id = list.tasks.size() + 1;
    list.tasks.push_back(task);
}

void removeTask(TodoList& list, int id) {
    for (int i = 0; i < list.tasks.size(); i++) {
        if (list.tasks[i].id == id) {
            list.tasks.erase(list.tasks.begin() + i);
            cout << "Task with ID " << id << " removed successfully!" << endl;
            return;
        }
    }
    cout << "Task with ID " << id << " not found!" << endl;
}

void completeTask(TodoList& list, int id) {
    for (int i = 0; i < list.tasks.size(); i++) {
        if (list.tasks[i].id == id) {
            list.tasks[i].completed = true;
            cout << "Task with ID " << id << " marked as completed!" << endl;
            return;
        }
    }
    cout << "Task with ID " << id << " not found!" << endl;
}

void displayTasks(const TodoList& list) {
    for (int i = 0; i < list.tasks.size(); i++) {
        cout << list.tasks[i].id << ". " << list.tasks[i].name << (list.tasks[i].completed ? " [completed]" : "") << endl;
    }
}

int main() {
    TodoList list;

    while (true) {
        cout << "Options:" << endl;
        cout << "1. Add task" << endl;
        cout << "2. Remove task" << endl;
        cout << "3. Complete task" << endl;
        cout << "4. Display tasks" << endl;
        cout << "5. Quit" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(list);
                break;
            case 2: {
                int id;
                cout << "Enter task ID: ";
                cin >> id;
                removeTask(list, id);
                break;
            }
            case 3: {
                int id;
                cout << "Enter task ID: ";
                cin >> id;
                completeTask(list, id);
                break;
            }
            case 4:
                displayTasks(list);
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please choose a valid option." << endl;
        }
    }

    return 0;
}