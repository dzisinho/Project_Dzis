#pragma once
#ifndef DATASTRUCTUREMANAGER_H
#define DATASTRUCTUREMANAGER_H

class DataStructureManager {
private:
    queue<string> q;
    stack<string> s;

public:
    void enqueue(const string& val) { q.push(val); }
    void dequeue() { if (!q.empty()) q.pop(); }
    string front() { return q.empty() ? "Empty" : q.front(); }
    void push(const string& val) { s.push(val); }
    void pop() { if (!s.empty()) s.pop(); }
    string top() { return s.empty() ? "Empty" : s.top(); }
};

#endif