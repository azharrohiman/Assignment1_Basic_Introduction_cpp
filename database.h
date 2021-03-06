// database.h - header file: this should be included in any source file that needs database() functions

#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

namespace RHMMUH005 {
	void add_student(std::string name, std::string surname, std::string studentnumber, std::string classRecord);
	void read_from_database();
	void write_to_database();
	void overwrite_existing_student_number();
	void print_records(std::string studentnumber);
	void grade_student(std::string studentnumber);
}

#endif
