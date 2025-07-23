#include <iostream>
#include <vector>
#include <fstream>

void addTask(std::vector <std::string>& tasks,const std::string task) {
    tasks.push_back(task);
    return;
}

void updateTask(std::vector<std::string>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks available to update.\n";
        return;
    }

    std::cout << "Your Tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". " << tasks[i] << "\n";
    }

    int taskNumber;
    std::cout << "Enter the task number you want to update: ";
    std::cin >> taskNumber;
    std::cin.ignore();

    if (taskNumber < 1 || taskNumber > tasks.size()) {
        std::cout << "Invalid task number.\n";
        return;
    }

    std::string newTask;
    std::cout << "Enter the new task description: ";
    std::getline(std::cin, newTask);

    tasks[taskNumber - 1] = newTask;
    std::cout << "Task updated successfully.\n";
}

void deleteTask(std::vector<std::string>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks available to delete.\n";
        return;
    }

    std::cout << "Your Tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". " << tasks[i] << "\n";
    }

    int taskNumber;
    std::cout << "Enter the task number you want to delete: ";
    std::cin >> taskNumber;
    std::cin.ignore();

    if (taskNumber < 1 || taskNumber > tasks.size()) {
        std::cout << "Invalid task number.\n";
        return;
    }

    tasks.erase(tasks.begin() + (taskNumber - 1));
    std::cout << "Task deleted successfully.\n";
}


void viewTasks(const std::vector<std::string>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks available.\n";
        return;
    }
    std::cout << "Your Tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". " << tasks[i] << "\n";
    }
}

int main () {
    // Ask for the task
    // Mark it as complete
    // Delete the task
    std::vector<std::string> tasks;
    std::cout << "WELCOME TO YET ANOTHER TODO LIST\n";
    while (true) {
        int choice;
        std::string task;
        std::cout << " 1. Add a Task \n 2. Update a Task \n 3. Delete a Task\n 4. View Tasks \n 5. Exit\n";
        std::cin >> choice;
        std::cin.ignore();
        switch (choice) {
            case 1: {
                std::cout << "Enter a task you would like to do?\n";
                std::getline(std::cin,task);
                addTask(tasks,task);
                std::cout << "Task Added Successfully\n";
                break;
            }
            case 2: {
                updateTask(tasks);
                break;
            }
            case 3: {
                deleteTask(tasks);
                break;
            }
            case 4: {
                viewTasks(tasks);
                break;
            } 
            case 5: {
                std::cout << "Exiting\n";
                exit(0);
                break;
            }
            default: {
                std::cout << "Invalid Choice, Try Again.\n";
            }
        }   
    }
}