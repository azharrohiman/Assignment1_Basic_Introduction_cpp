#include <stdio.h> // pre-processor directives
#include <string>      // insert the header files
#include <iostream>
using namespace std; // makes code easier to read

int main(int argc, char *argv[])  // command line args
{
	string input;
	for (;;) {
		cout << "0: Add student \n";
		cout << "1: Read database \n";
		cout << "2: Save database \n";
		cout << "3: Display given student data \n";
		cout << "4: Grade student \n";

		cout << "Enter a number (or q to quit) and press return... \n";

		cin >> input;
		if (input == "q") {
			break;
		}
	}

	// string name;                          // name is a string
	// printf("Enter your name: ");          // write to console c style
	// cin >> name;                          // console input
	// printf("Hello %s \n", name.c_str());  // c style console output

	return 0;                         // return code; 0 = OK
}
