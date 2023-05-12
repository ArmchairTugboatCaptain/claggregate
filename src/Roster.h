#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

class Student {
private:
    std::string first_name;
    std::string last_name;
    std::string gender;
public:
    Student(std::string fn, std::string ln, std::string g);
    ~Student();

    friend std::ostream& operator<<(std::ostream& os, const Student& obj);

    std::string full_name();
};

class Roster {
private:
    std::vector<Student> students;
public:
    Roster();
    ~Roster();

    void load_students_from_file(std::string file_path, char delim, bool skip_header);
    void test();
};

#endif