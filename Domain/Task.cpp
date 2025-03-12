
#include "Task.h"

#include <string>
#include <random>

using namespace std;
#include "Domain/Task.h"
#include "Logger/Logger.h"

string generateUUID() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1000, 9999);
    return "TASK-" + to_string(dis(gen));
}

Task::Task(const string& desc) : description(desc), status(PENDING), id(generateUUID()) {
    Logger::log("Task created: " + id + " - " + desc);
}

void Task::markCompleted() {
    status = COMPLETED;
    Logger::log("Task completed: " + id);
}

string Task::getDescription() const { return description; }

bool Task::isCompleted() const { return status == COMPLETED; }

string Task::getId() const { return id; }