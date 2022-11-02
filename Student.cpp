#include "headers/Student.h"

Student::Student(int studentID, std::string name, std::string cUCode, std::string classCode){
    this->studentID = studentID;
    this->name = name;
    this->classes.push_back(CUClass(cUCode, classCode));
}

void Student::setClass(std::string cUCode, std::string classCode){
    this->classes.push_back(CUClass(cUCode, classCode));
}

bool Student::operator<(const Student &student) const {
    return studentID < student.studentID;
}

bool Student::operator==(const Student &student) const {
    return this->studentID == student.studentID;
}
