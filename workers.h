#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <regex>
#include "exceptions.h"
class Worker {
public:
    virtual void execute(std::vector<std::string>& text) = 0;
};

class WorkerRead : public Worker {
public:
    std::string fname;
    explicit WorkerRead(const std::vector<std::string>& parse_buffer);
   void execute(std::vector<std::string>& text) override;
};

class WorkerWrite : public Worker {
public:
    std::string fname;
    explicit WorkerWrite(const std::vector<std::string>& parse_buffer);
    void execute(std::vector<std::string>& text) override;
};

class WorkerGrep : public Worker {
public:
    std::string word;
    explicit WorkerGrep(const std::vector<std::string>& parse_buffer);
     void execute(std::vector<std::string>& text) override;
};

class WorkerSort : public Worker {
public:
    explicit WorkerSort() = default;
    void execute(std::vector<std::string>& text) override;
};

class WorkerReplace : public Worker {
public:
    std::string word1, word2;
    explicit WorkerReplace(const std::vector<std::string>& parse_buffer);
    void execute(std::vector<std::string>& text) override;
};

class WorkerDump : public Worker {
public:
    std::string filename;
    explicit WorkerDump(const std::vector<std::string>& parse_buffer);
    void execute(std::vector<std::string>& text) override;
};