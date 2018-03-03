// Fib.h - header file: this should be included in any source file that needs fib()

#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <iostream>

namespace RHMMUH005 {
	void add_student(std::string name, std::string surname, std::string studentnumber, std::string classRecord);
	void print_records();
}

#endif
