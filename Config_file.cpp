#include "Config_file.h"

Config_file::Config_file(const std::string& filename) {
    fin.open(filename);

    if (!fin)
        throw fileException();
}

void Config_file::read_Config_file() {
    std::getline(fin, buffer);
    int i;

    if (buffer != "desc")
        throw DescException();

    std::getline(fin, buffer);

    while (!fin.eof() && buffer != "csed") {
        std::regex rgx("[\\w\\S]*");
        parse_buffer.resize(5);
        i = 0;

        for (std::sregex_iterator it(buffer.begin(), buffer.end(), rgx), it_end; it != it_end; ++it)
            if ((*it)[0].length() != 0) {
                parse_buffer[i] = (*it)[0];
                i += 1;
            }
               
        create_map();

        std::getline(fin, buffer);
    }

    if (buffer != "csed")
        throw CsedException();

    std::getline(fin, buffer);
  
    std::regex rgx("[0-9]*");

    for (std::sregex_iterator it(buffer.begin(), buffer.end(), rgx), it_end; it != it_end; ++it)
        if ((*it)[0].length() != 0) {
            
            if (blocks.find(stoi((*it)[0])) == blocks.end())
                throw queueException();

            queue.push_back(stoi((*it)[0]));           
        }
}

void  Config_file::create_map() {
        int num_block = stoi(parse_buffer[0]);
       
        if (parse_buffer[1] != "=")
            throw equalsException();

        if(blocks.find(num_block) != blocks.end())
            throw BlockException();
    
        if (parse_buffer[2] == "readfile") {
            ReadFactory read_factory;
            blocks[num_block] = read_factory.create_worker(parse_buffer);
        }
        else if (parse_buffer[2] == "writefile") {
            WriteFactory write_factory;
            blocks[num_block] = write_factory.create_worker(parse_buffer);
        }
        else if (parse_buffer[2] == "grep") {
            GrepFactory grep_factory;
            blocks[num_block] = grep_factory.create_worker(parse_buffer);
        }
        else if (parse_buffer[2] == "sort") {
            SortFactory sort_factory;
            blocks[num_block] = sort_factory.create_worker(parse_buffer);
        }
        else if (parse_buffer[2] == "replace") {
            ReplaceFactory replace_factory;
            blocks[num_block] = replace_factory.create_worker(parse_buffer);
        }
        else if (parse_buffer[2] == "dump") {
            DumpFactory dump_factory;
            blocks[num_block] = dump_factory.create_worker(parse_buffer);
        }
        else
            throw RightBlockException();
}

const std::vector<int>& Config_file::get_queue() const{
    return queue;
}

const std::map<int, Worker*>& Config_file::get_blocks() const{
    return blocks;
}