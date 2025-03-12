#pragma once
#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include "domain/Task.h"
#include "core/BinaryTree.h"
#include "infrastructure/DataStructureManager.h"
#include "logger/Logger.h"

class TaskManager {
private:
    list<Task> tasks;
    unordered_map<string, Task*> taskMap;
    BinaryTree<int> tree;
    DataStructureManager dsm;
    void saveTasksToFile();
    void loadTasksFromFile();

public:
    TaskManager();
    void addTask(const string& desc);
    void completeTask();
    void showTasks() const;
    void demoStructures();
};

#endif