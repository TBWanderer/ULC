#include <fstream>
#include <iostream>
#include <string>

using namespace std;


// Function what helps to generate errors
string genError(string code, string reason){
	// Returning error string like: [ERROR <error-code>]: <reason> -> [ERROR A1]: Why aren't you buying donuts?
	return "[ERROR " + code + "]: " + reason;
}


string readFile(string fileName){
	// Reading file 
	ifstream ifStreamContent;
	ifStreamContent.open(fileName);
	
	// Loading file content to a string variable
	string content;
	getline(ifStreamContent, content);

	// Returning content as string variable
	return content;
}
