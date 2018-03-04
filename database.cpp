// Fib.cpp - implementation file for fib() function

#include <iostream>
#include <fstream>
#include "database.h"
#include <string>
#include <sstream>
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

	if (records.size() == 0) {
		records.push_back(student);
	}
	
	for (int i = 0; i < records.size(); i++) {
		if (records[i].studentnumber == studentnumber) {
			records[i].name = name;
			records[i].surname = surname;
			records[i].studentnumber = studentnumber;
			records[i].classRecord = classRecord;
			break;
		}
		else {
			records.push_back(student);
			break;
		}
	}
	std::cout << records.size() << std::endl;
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
	//for (int i = 0; i < databaseRec.size(); i++) {
		//std::cout << "\n";
		//std::cout << databaseRec[i].name << "\n";
		//std::cout << databaseRec[i].surname << "\n";
		//std::cout << databaseRec[i].studentnumber << "\n";
		//std::cout << databaseRec[i].classRecord << "\n";
	//}
}

void RHMMUH005::write_to_database() {
	if (records.size() == 0) {
		std::cout << "No student record to add to database \n";
	}
	else {
		std::ofstream myfile;

		std::cout << "Overwrite and create new database or add to existing database? Choose (1) to overwrite or (2) to add: \n";
		int choice;
		std::cin >> choice;
		std::cin.ignore();
		if (choice == 1) {
			myfile.open("Student Database");
			std::cout << "Overwriting and creating new database... \n";
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
		else {
			myfile.open("Student Database", std::ofstream::app);
			std::cout << "Adding to file... \n";
			//std::cout << records.size() << std::endl;
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
	}
	std::cout << std::endl;
}

void RHMMUH005::print_records(std::string studentnumber) {
	read_from_database();
	bool flag = false;
	for (int i = 0; i < databaseRec.size(); i++) {
		if (databaseRec[i].studentnumber == studentnumber) {
			std::cout << databaseRec[i].name << "\n";
			std::cout << databaseRec[i].surname << "\n";
			std::cout << databaseRec[i].studentnumber << "\n";
			std::cout << databaseRec[i].classRecord << "\n";
			//std::cout << "\n";
			flag = true;
			break;
		}
		else {
			flag = false;
		}
	}
	if (!flag) {
		std::cout << "Student not found on database! \n";
	}
	std::cout << std::endl;
}

void RHMMUH005::grade_student(std::string studentnumber) {
	read_from_database();
	bool flag = false;
	std::string grades;
	for (int i = 0; i < databaseRec.size(); i++) {
		if (databaseRec[i].studentnumber == studentnumber) {
			grades = databaseRec[i].classRecord;
			//std::cout << databaseRec[i].classRecord << "\n";
			flag = true;
			break;
		}
		else {
			flag = false;
		}
	}
	if (!flag) {
		std::cout << "Student not found on database! \n";
	}
	else {
		int total = 0;
		int count = 0;
		std::istringstream iss(grades);
		while (!iss.eof()) {
			count++;
			int n;
			iss >> n;
			total += n;
			//std::cout << "value=" << n << std::endl;
		}
		std::cout << "Average grade of student is " << total/count << std::endl;
	}
	std::cout << std::endl;
}





















