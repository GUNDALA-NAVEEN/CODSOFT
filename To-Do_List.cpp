#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

vector<Task> tasks;

void addTask() {
    Task newTask;
    cout << "Enter the task description: ";
    
    // To clear the input buffer
    cin.ignore(); 

    getline(cin, newTask.description);
    newTask.completed = false;
    tasks.push_back(newTask);
    cout << "Task added!" << endl;
}

void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks available." << endl;
    } else {
        cout << "Tasks List:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]" << endl;
        }
    }
}

string markTaskCompleted() {
    int taskNumber;
    cout << "Enter the task number to mark as completed: ";
    cin >> taskNumber;
    
    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks[taskNumber - 1].completed = true;
        cout << "Task marked as completed!" << endl;
    } else {
        cout << "Invalid task number!" << endl;
    }
}

void removeTask() {
    int taskNumber;
    cout << "Enter the task number to remove: ";
    cin >> taskNumber;
    
    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks.erase(tasks.begin() + taskNumber - 1);
        cout << "Task removed!" << endl;
    } else {
        cout << "Invalid task number!" << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "\nTo-Do List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                markTaskCompleted();
                break;
            case 4:
                removeTask();
                break;
            case 5:
                cout << "Exiting the program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);
    
    return 0;
}
