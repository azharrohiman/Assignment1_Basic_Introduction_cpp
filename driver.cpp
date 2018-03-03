#include <stdio.h> // pre-processor directives
#include <string>      // insert the header files
#include <iostream>

#include "database.h"

int main(int argc, char *argv[])  // command line args
{
	using namespace std; // makes code easier to read
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

		if (input == "0") {
			RHMMUH005::add_student("Mike", "John", "dffaa", "32 13 31 42 42");
			RHMMUH005::print_records();
			cout << "added" << endl;
		}
	}

	// string name;                          // name is a string
	// printf("Enter your name: ");          // write to console c style
	// cin >> name;                          // console input
	// printf("Hello %s \n", name.c_str());  // c style console output

	return 0;                         // return code; 0 = OK
}
