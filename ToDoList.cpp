#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Task class - represents a single to-do item
class Task {
public:
    string description;
    bool isCompleted;

    Task(string desc) {
        description = desc;
        isCompleted = false;
    }
};

// ToDoList class - manages the collection of tasks (OOP: Encapsulation)
class ToDoList {
private:
    vector<Task> tasks;

public:
    // Add a new task
    void addTask(string description) {
        tasks.push_back(Task(description));
        cout << "Task added successfully!\n";
    }

    // Mark a task as completed
    void completeTask(int index) {
        if (index >= 1 && index <= (int)tasks.size()) {
            tasks[index - 1].isCompleted = true;
            cout << "Task marked as completed!\n";
        } else {
            cout << "Invalid task number!\n";
        }
    }

    // Remove a task from the list
    void removeTask(int index) {
        if (index >= 1 && index <= (int)tasks.size()) {
            tasks.erase(tasks.begin() + (index - 1));
            cout << "Task removed successfully!\n";
        } else {
            cout << "Invalid task number!\n";
        }
    }

    // Display all tasks
    void displayTasks() {
        if (tasks.empty()) {
            cout << "\nNo tasks in your list!\n";
            return;
        }

        cout << "\n----- YOUR TO-DO LIST -----\n";
        for (int i = 0; i < (int)tasks.size(); i++) {
            cout << i + 1 << ". [" << (tasks[i].isCompleted ? "X" : " ") << "] "
                 << tasks[i].description << endl;
        }
        cout << "----------------------------\n";
    }
};

int main() {
    ToDoList myList;
    int choice;

    do {
        cout << "\n===== TO-DO LIST MENU =====\n";
        cout << "1. Add Task\n";
        cout << "2. Mark Task as Completed\n";
        cout << "3. Remove Task\n";
        cout << "4. Display All Tasks\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string desc;
                cout << "Enter task description: ";
                cin.ignore();
                getline(cin, desc);
                myList.addTask(desc);
                break;
            }
            case 2: {
                int num;
                myList.displayTasks();
                cout << "Enter task number to mark as completed: ";
                cin >> num;
                myList.completeTask(num);
                break;
            }
            case 3: {
                int num;
                myList.displayTasks();
                cout << "Enter task number to remove: ";
                cin >> num;
                myList.removeTask(num);
                break;
            }
            case 4:
                myList.displayTasks();
                break;
            case 5:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
