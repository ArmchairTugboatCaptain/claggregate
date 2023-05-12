#include <string>
#include <vector>
#include <iostream>
#include "Roster.h"
#include "Utilities.h"


Student::Student(std::string fn, std::string ln, std::string g) 
    : first_name(fn), last_name(ln), gender(g) {}

Student::~Student() {}

std::string Student::full_name() {
    return (first_name + ' ' + last_name);
}

std::ostream& operator<<(std::ostream& os, const Student& obj) {
    os << obj.first_name << ' ' << obj.last_name << ": " << obj.gender;
    return os;
}

Roster::Roster() {}
Roster::~Roster() {}

void Roster::load_students_from_file(std::string file_path, char delim, bool skip_header) {
    std::vector<std::vector<std::string>> data = util::read_delim_file(file_path, delim);

    std::size_t start_row = (skip_header) ? 1 : 0;
    for(std::size_t line = start_row; line < data.size(); ++line) {
        students.emplace_back(data[line][0], data[line][1], data[line][2]);
    }
}

void Roster::test() {
    if(not students.empty()) {
        for(Student s : students) {
            std::cout << s << std::endl;
        }
    } else {
        std::cout << "ERROR" << std::endl;
    }
}