#include "TaskManager.h"

#include <iostream>
#include <memory>
#include <string>
#include <fstream>
using namespace std;
#include "Application/TaskManager.h"

TaskManager::TaskManager() {
    loadTasksFromFile();
}

void TaskManager::addTask(const string& desc) {
    try {
        if (desc.empty()) {
            throw runtime_error("Task description cannot be empty.");
        }
        tasks.emplace_back(desc);
        taskMap[tasks.back().getId()] = &tasks.back();
        tree.insert(tasks.size());
        dsm.enqueue(tasks.back().getId());
        saveTasksToFile();
    } catch (const exception& e) {
        Logger::log("Error: " + string(e.what()));
    }
}

void TaskManager::completeTask() {
    try {
        if (tasks.empty()) {
            throw runtime_error("No tasks to complete.");
        }
        tasks.front().markCompleted();
        taskMap.erase(tasks.front().getId());
        tasks.pop_front();
        dsm.dequeue();
        saveTasksToFile();
    } catch (const exception& e) {
        Logger::log("Error: " + string(e.what()));
    }
}

void TaskManager::showTasks() const {
    for (const auto& task : tasks) {
        cout << task.getId() << " - " << task.getDescription() 
        << (task.isCompleted() ? " [Done]" : " [Pending]") << endl;
    }
}

void TaskManager::demoStructures() {
    cout << "Binary Tree (Task IDs in order): ";
    tree.display();
    cout << "Queue Front: " << dsm.front() << endl;
    cout << "Stack Top: " << dsm.top() << endl;
}

void TaskManager::saveTasksToFile() {
    ofstream file("tasks.txt");
    for (const auto& task : tasks) {
        file << task.getId() << "," << task.getDescription() << "," << task.isCompleted() << endl;
    }
}

void TaskManager::loadTasksFromFile() {
    ifstream file("tasks.txt");
    string id, desc, status;
    while (getline(file, id, ',') && getline(file, desc, ',') && getline(file, status)) {
        tasks.emplace_back(desc);
        taskMap[id] = &tasks.back();
        if (status == "1") {
            tasks.back().markCompleted();
        }
    }
}
