// Fib.cpp - implementation file for fib() function

#include <iostream>
#include <fstream>
#include "database.h"
#include <string>
// for testing
#include <vector>

struct StudentRecord {
	std::string name;
	std::string surname;
	std::string studentnumber;
	std::string classRecord;
};

std::vector<StudentRecord> records;

std::vector<StudentRecord> databaseRec;

//struct DatabaseRecord {
//	std::string name;
//	std::string surname;
//	std::string studentnumber;
//	std::string classRecord;
//}

//std::vector<DatabaseRecord> databaseRecords;

void RHMMUH005::add_student(std::string name, std::string surname, std::string studentnumber, std::string classRecord) {
	StudentRecord student;
	student.name = name;
	student.surname = surname;
	student.studentnumber = studentnumber;
	student.classRecord = classRecord;

	records.push_back(student);
}

void RHMMUH005::print_records() {
	//std::cout << records.size() << "\n";
	for (int i = 0; i < records.size(); i++) {
		std::cout << records[i].name << "\n";
		std::cout << records[i].classRecord << "\n";
	}
}

void RHMMUH005::read_from_database(){
	StudentRecord data;
	std::string filename = "Student Database";
	std::string word;

	std::ifstream in(filename.c_str());

	if(!in)
		{ std::cout << "Couldn't open " << filename << std::endl; }

	while(getline(in, word)) {
		//std::cout << word << std::endl;
		if (word.find("Student #") != std::string::npos) {
			//std::cout << "found";
			continue;
		}
		else {
			if (word.find("Name") != std::string::npos) {
				size_t name_found = word.find_last_of(":");
				//std::cout << name_found << std::endl;
				data.name = word.substr(name_found+2);
				//std::cout << data.name << endl;
			}

			if (word.find("Surname") != std::string::npos) {
				size_t surname_found = word.find_last_of(":");
				data.surname = word.substr(surname_found+2);
			}

			if (word.find("Student Number") != std::string::npos) {
				size_t studentnum_found = word.find_last_of(":");
				data.studentnumber = word.substr(studentnum_found+2);
			}

			if (word.find("Class Record") != std::string::npos) {
				size_t classrec_found = word.find_last_of(":");
				data.classRecord = word.substr(classrec_found+2);
				databaseRec.push_back(data);
			}
		}
		//databaseRec.push_back(data);
		//databaseRecords.push_back(data);
	}
	for (int i = 0; i < databaseRec.size(); i++) {
		std::cout << databaseRec[i].name << "\n";
		std::cout << databaseRec[i].surname << "\n";
		std::cout << databaseRec[i].studentnumber << "\n";
		std::cout << databaseRec[i].classRecord << "\n";
	}
}

void RHMMUH005::write_to_database() {
	std::ofstream myfile;
	myfile.open("Student Database");
	for (int i = 0; i < records.size(); i++) {
		myfile << "Student #" << i+1 << "\n";
		myfile << "Name: " << records[i].name << "\n";
		myfile << "Surname: " << records[i].surname << "\n";
		myfile << "Student Number: " << records[i].studentnumber << "\n";
		myfile << "Class Record: " << records[i].classRecord << "\n";
		myfile << "\n";
	}
	myfile.close();
}
