#pragma once
#include "workers.h"
class Factory {
public:
	virtual Worker* create_worker(const std::vector<std::string>& parse_buffer) = 0;
};

class ReadFactory : public Factory {
public:
	Worker* create_worker(const std::vector<std::string>& parse_buffer) override;
};

class WriteFactory : public Factory {
public:
	Worker* create_worker(const std::vector<std::string>& parse_buffer) override;
};

class GrepFactory : public Factory {
public:
	Worker* create_worker(const std::vector<std::string>& parse_buffer) override;
};

class SortFactory : public Factory {
public:
	Worker* create_worker(const std::vector<std::string>& parse_buffer) override;
};

class ReplaceFactory : public Factory {
public:
	Worker* create_worker(const std::vector<std::string>& parse_buffer) override;
};

class DumpFactory : public Factory {
public:
	Worker* create_worker(const std::vector<std::string>& parse_buffer) override;
};