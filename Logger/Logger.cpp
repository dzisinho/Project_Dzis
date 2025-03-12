#include <iostream>
#include <memory>
#include <string>
#include <fstream>

using namespace std;
#include "logger/Logger.h"

void Logger::log(const string& message) {
    ofstream logFile("log.txt", ios::app);
    if (logFile) {
        logFile << message << endl;
    }
    cout << "LOG: " << message << endl;
}
