#include <iostream>
#include <map>
#include <string>
#include <fstream>

using namespace std;

map<string, string> variables;

int next() {
	ifstream text("test.txt");
	if (!text.is_open()){
		cout << "Error" << endl;
	}
	else {
		string txt;
		getline(text, txt);
		cout << txt << endl;
	}
	return 0;
}
