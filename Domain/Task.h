#pragma once
#ifndef TASK_H
#define TASK_H

enum TaskStatus { PENDING, COMPLETED };

class Task {
private:
    string id;
    string description;
    TaskStatus status;

public:
    Task(const string& desc);
    void markCompleted();
    string getDescription() const;
    bool isCompleted() const;
    string getId() const;
};

#endif