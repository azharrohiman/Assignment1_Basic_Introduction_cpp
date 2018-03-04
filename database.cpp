// database.cpp - implementation file for database() functions

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

void RHMMUH005::add_student(std::string name, std::string surname, std::string studentnumber, std::string classRecord) {
	std::cout << "function addStudent() called \n";
	StudentRecord student;
	student.name = name;
	student.surname = surname;
	student.studentnumber = studentnumber;
	student.classRecord = classRecord;

	read_from_database();
	bool flag = false;
	for (int i = 0; i < databaseRec.size(); i++) {
		if (databaseRec[i].studentnumber == studentnumber) {
			flag = true;
			databaseRec[i].name = name;
			databaseRec[i].surname = surname;
			databaseRec[i].studentnumber = studentnumber;
			databaseRec[i].classRecord = classRecord;
		}
	}
	if (flag) {
		overwrite_existing_student_number();
	}
	else {
		if (records.size() == 0) {
			records.push_back(student);
		}
		else {
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
		}
	}
}

void RHMMUH005::read_from_database(){
	std::cout << "function readFromDatabase() called \n";
	databaseRec.clear();
	StudentRecord data;
	std::string filename = "Student Database";
	std::string word;

	std::ifstream in(filename.c_str());

	if(!in)
		{ std::cout << "Couldn't open " << filename << std::endl; }

	while(getline(in, word)) {
		if (word.find("Student #") != std::string::npos) {
			continue;
		}
		else {
			if (word.find("Name") != std::string::npos) {
				size_t name_found = word.find_last_of(":");
				data.name = word.substr(name_found+2);
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
	}
	std::cout << std::endl;
}

void RHMMUH005::write_to_database() {
	std::cout << "function writeToDatabase() called \n";
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
			read_from_database();
			int number_of_students = databaseRec.size();
			myfile.open("Student Database", std::ofstream::app);
			std::cout << "Adding to file... \n";
			for (int i = 0; i < records.size(); i++) {
				myfile << "Student #" << ++number_of_students << "\n";
				myfile << "Name: " << records[i].name << "\n";
				myfile << "Surname: " << records[i].surname << "\n";
				myfile << "Student Number: " << records[i].studentnumber << "\n";
				myfile << "Class Record: " << records[i].classRecord << "\n";
				myfile << "\n";
			}
			myfile.close();
		}
	}
	records.clear();
	std::cout << std::endl;
}

void RHMMUH005::overwrite_existing_student_number() {
	std::cout << "function overwriteExistingStudent() called \n";
	std::ofstream myfile;

	std::cout << "Updating student's information... \n";
	myfile.open("Student Database");
	for (int i = 0; i < databaseRec.size(); i++) {
		myfile << "Student #" << i+1 << "\n";
		myfile << "Name: " << databaseRec[i].name << "\n";
		myfile << "Surname: " << databaseRec[i].surname << "\n";
		myfile << "Student Number: " << databaseRec[i].studentnumber << "\n";
		myfile << "Class Record: " << databaseRec[i].classRecord << "\n";
		myfile << "\n";
	}
	myfile.close();
}

void RHMMUH005::print_records(std::string studentnumber) {
	std::cout << "function displayStudentData() called \n";
	read_from_database();
	bool flag = false;
	for (int i = 0; i < databaseRec.size(); i++) {
		if (databaseRec[i].studentnumber == studentnumber) {
			std::cout << "Name: " << databaseRec[i].name << "\n";
			std::cout << "Surname: "<< databaseRec[i].surname << "\n";
			std::cout << "Student Number: " << databaseRec[i].studentnumber << "\n";
			std::cout << "Class Record: " << databaseRec[i].classRecord << "\n";
			flag = true;
			break;
		}
		else {
			flag = false;
		}
	}
	if (!flag) {
		std::cout << "Student not found on database! Try saving to database before displaying student data\n";
	}
	std::cout << std::endl;
}

void RHMMUH005::grade_student(std::string studentnumber) {
	std::cout << "function gradeStudent() called \n";
	read_from_database();
	bool flag = false;
	std::string grades;
	std::string name;
	std::string surname;
	for (int i = 0; i < databaseRec.size(); i++) {
		if (databaseRec[i].studentnumber == studentnumber) {
			grades = databaseRec[i].classRecord;
			name = databaseRec[i].name;
			surname = databaseRec[i].surname;
			flag = true;
			break;
		}
		else {
			flag = false;
		}
	}
	if (!flag) {
		std::cout << "Student not found on database! Try saving to database before printing average \n";
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
		}
		std::cout << "Average grade of " << name + " " + surname + ", " << studentnumber << " is " << total/count << std::endl;
	}
	std::cout << std::endl;
}





















