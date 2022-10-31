#include "headers/Student.h"

//Constructors
Student::Student(int studentID, std::string name, std::string cUCode, std::string classCode){
    this->studentID = studentID;
    this->name = name;
    this->classes.push_back(CUClass(cUCode, classCode));
}

//Methods
void Student::addClass(std::string cUCode, std::string classCode){
    this->classes.push_back(CUClass(cUCode, classCode));
}

std::string Student::getName(){
    return this->name;
}

int Student::getStudentID(){
    return this->studentID;
}


bool Student::operator<(const Student &student) const {
    return studentID < student.studentID;
}


std::list<CUClass> Student::getClasses() const{
    return classes;
}
