// Fib.cpp - implementation file for fib() function

#include <iostream>
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

void RHMMUH005::add_student(std::string name, std::string surname, std::string studentnumber, std::string classRecord) {
	StudentRecord student;
	student.name = name;
	student.surname = surname;
	student.studentnumber = studentnumber;
	student.classRecord = classRecord;

	records.push_back(student);
}