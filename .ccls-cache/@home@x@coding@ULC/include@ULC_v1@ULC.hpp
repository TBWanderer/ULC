#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include "ULC_v1/fileReader.hpp"

using namespace std;

map<string, string> variables;


int codeProcessing(string fileName) {
	string content;
	content = readFile(fileName);

	cout << content << endl;
	return 0;
}

