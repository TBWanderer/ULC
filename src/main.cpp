#include "ULC_v1/ULC.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv) {
	if (argc != 2){
		cout << "Usage: <command> <file-with-code>" << endl;
		return 0;
	}
	
	codeProcessing(argv[1]);

	return 0;
}
