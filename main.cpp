#include <iostream>
#include <string>
#include "Config_file.h"

int main()
{
    std::string filename = "file.txt";
    std::vector<int> queue;
    std::map<int, Worker*> blocks;
    std::vector<std::string> text;

    try {
        Config_file config(filename);
        config.read_Config_file();
        queue = config.get_queue();
        blocks = config.get_blocks();

        for (int i = 0; i < queue.size(); i += 1)
            blocks[queue[i]]->execute(text);
    }
    catch (const fileException& ex) {
        std::cout << ex.what();
    }
    catch (const DescException& ex) {
        std::cout << ex.what();
    }
    catch (const  equalsException& ex) {
        std::cout << ex.what();
    }
    catch (const BlockException& ex) {
        std::cout << ex.what();
    }
    catch (const RightBlockException& ex) {
        std::cout << ex.what();
    }
    catch (const CsedException& ex) {
        std::cout << ex.what();
    }
    catch (const textException& ex) {
        std::cout << ex.what();
    }
    catch (const queueException& ex) {
        std::cout << ex.what();
    }
}

