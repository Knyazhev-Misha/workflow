#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <regex>
#include <iostream>
#include "exceptions.h"
#include "factories.h"
class Config_file {
private:
    std::ifstream fin;
    std::string buffer;
    std::vector<std::string> parse_buffer;
    std::vector<int> queue;
    std::map<int, Worker*> blocks;
    void  create_map();

public:
    Config_file(const std::string& filename);
    void read_Config_file();
    const std::vector<int>& get_queue() const;
    const std::map<int, Worker*>& get_blocks() const;
};