#include <stdio.h> // pre-processor directives
#include <string>      // insert the header files
#include <iostream>

#include "database.h"

int main(int argc, char *argv[])  // command line args
{
	using namespace std; // makes code easier to read
	string input;
	string name;
	string surname;
	string studentnumber;
	string grade;

	for (;;) {
		cout << "0: Add student \n";
		cout << "1: Read database \n";
		cout << "2: Save database \n";
		cout << "3: Display given student data \n";
		cout << "4: Grade student \n";

		cout << "Enter a number (or q to quit) and press return... \n";

		cin >> input;
		cin.ignore();
		if (input == "q") {
			break;
		}

		if (input == "0") {
			cout << "Enter student's first name: \n";
			getline(cin, name);
			cout << "Enter student's last name: \n";
			getline(cin, surname);
			cout << "Enter student's number: \n";
			getline(cin, studentnumber);
			cout << "Enter student's grades: \n";
			getline(cin, grade);

			RHMMUH005::add_student(name, surname, studentnumber, grade);
			//RHMMUH005::add_student("Mike", "John", "dffaa", "32 13 31 42 42");
			//RHMMUH005::print_records();
		}

		if (input == "1") {
			RHMMUH005::read_from_database();
		}

		if (input == "2") {
			cout << "Writing to file..." << endl;
			RHMMUH005::write_to_database();
		}
	}

	return 0;                         // return code; 0 = OK
}
