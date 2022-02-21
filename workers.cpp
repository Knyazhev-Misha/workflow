#include "workers.h"
WorkerRead::WorkerRead(const std::vector<std::string>& parse_buffer) {
	fname = parse_buffer[3];
}

void WorkerRead::execute(std::vector<std::string>& text) {
	int i = 0;
	std::ifstream fin;
	std::string ptr;
	fin.open(fname);

	if (!fin)
		throw fileException();

	if (text.size() != 0)
		throw textException();

	while (!fin.eof()) {
		std::getline(fin, ptr);
		text.push_back(ptr);
		i += 1;
	}

	fin.close();
}

WorkerWrite::WorkerWrite(const std::vector<std::string>& parse_buffer) {
	fname = parse_buffer[3];
}

void WorkerWrite::execute(std::vector<std::string>& text) {
	std::ofstream fout;
	fout.open(fname);

	if (!fout)
		throw fileException();

	if (text.size() == 0)
		throw textException();

	for(int i = 0; i < text.size(); i += 1)
		fout << text[i] << "\n";
	
	text.clear();
	fout.close();
}

WorkerGrep::WorkerGrep(const std::vector<std::string>& parse_buffer) {
	word = parse_buffer[3];
}

void WorkerGrep::execute(std::vector<std::string>& text) {
	if (text.size() == 0)
		throw textException();

	std::vector<std::string> ptr;
	std::regex rgx("[\\w\\S]*");
	int flag;

	for (int i = 0; i < text.size(); i += 1) {
		for (std::sregex_iterator it(text[i].begin(), text[i].end(), rgx), it_end; it != it_end; ++it)
			if ((*it)[0] == word && flag == 0 && (*it)[0].length() != 0) {
				ptr.push_back(text[i]);
				flag = 1;
			}

		flag = 0;
	}

	text = ptr;
}

void WorkerSort::execute(std::vector<std::string>& text) {
	if (text.size() == 0)
		throw textException();

	sort(text.begin(), text.end());
}

WorkerReplace::WorkerReplace(const std::vector<std::string>& parse_buffer) {
	word1 = parse_buffer[3];
	word2 = parse_buffer[4];
}

void WorkerReplace::execute(std::vector<std::string>& text) {
	if (text.size() == 0)
		throw textException();

	std::vector<std::string> ptr;
	std::regex rgx("[\\w\\S]*");
	std::string change;

	for (int i = 0; i < text.size(); i += 1) {
		for (std::sregex_iterator it(text[i].begin(), text[i].end(), rgx), it_end; it != it_end; ++it)
			if ((*it)[0] == word1 && (*it)[0].length() != 0)
				change = change + " " + word2;
			else if((*it)[0].length() != 0){
				std::string ptr = (*it)[0];
				change = change + " " + ptr;
			}
		text[i] = change;
		change.clear();
	}
}

WorkerDump::WorkerDump(const std::vector<std::string>& parse_buffer) {
	filename = parse_buffer[3];
}

void WorkerDump::execute(std::vector<std::string>& text) {
	if(text.size() == 0)
		throw textException();

	std::ofstream fout;
	fout.open(filename);

	if (!fout)
		throw fileException();

	for (int i = 0; i < text.size(); i += 1)
		fout << text[i] << "\n";
	
	fout.close();
}