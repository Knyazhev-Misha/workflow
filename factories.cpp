#include "factories.h"

Worker* ReadFactory::create_worker(const std::vector<std::string>& parse_buffer) {
    return new WorkerRead(parse_buffer);
}

Worker* WriteFactory::create_worker(const std::vector<std::string>& parse_buffer) {
    return new WorkerWrite(parse_buffer);
}

Worker* GrepFactory::create_worker(const std::vector<std::string>& parse_buffer) {
    return new WorkerGrep(parse_buffer);
}

Worker* SortFactory::create_worker(const std::vector<std::string>& parse_buffer) {
    return new WorkerSort();
}

Worker* ReplaceFactory::create_worker(const std::vector<std::string>& parse_buffer) {
    return new WorkerReplace(parse_buffer);
}

Worker* DumpFactory::create_worker(const std::vector<std::string>& parse_buffer) {
    return new WorkerDump(parse_buffer);
}
