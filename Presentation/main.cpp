#include <iostream>
#include <fstream>

using namespace std;
#include "application/TaskManager.h"

int main() {
    TaskManager manager;
    manager.addTask("Complete OOP project");
    manager.addTask("Study STL");
    manager.addTask("Implement Binary Tree");
    manager.addTask(""); // Testing exception handling
    
    cout << "Task List:\n";
    manager.showTasks();
    manager.completeTask();
    manager.completeTask();
    manager.completeTask();
    manager.completeTask(); // Testing exception handling
    
    cout << "After completing tasks:\n";
    manager.showTasks();
    
    manager.demoStructures();
    
    return 0;
}
