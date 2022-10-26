#include "headers/ScheduleManagement.h"
#include <fstream>
#include <sstream>
#include <iostream>

//Constructors

//Methods
void ScheduleManagement::addStudent(const Student& student){
    this->students.insert(student);
}

void ScheduleManagement::createStudents(std::string csv_file){
    int count2 = 0;

    int iD;
    std::string name;
    std::string cUCode;
    std::string classCode;

    std::ifstream file;
    file.open(csv_file);

    int count = 0;
    Student student(0, "", "", "");

    for(std::string line; std::getline(file, line);){
        count2++;
        if(count == 0){
            count++;
            continue;
        }

        std::stringstream inputString(line);
        std::string data;

        std::getline(inputString, data, ',');
        iD = std::stoi(data);
        std::getline(inputString, data, ',');
        name = data;
        std::getline(inputString, data, ',');
        cUCode = data;
        std::getline(inputString, data, '\r');
        classCode = data;

        if(iD == student.getStudentID()){
            student.addClass(cUCode, classCode);
        }
        else{
            if(student.getStudentID() != 0) this->addStudent(student);
            student = Student(iD, name, cUCode, classCode);
        }
    }
    this->addStudent(student);
    std::cout << "count2: " << count2 << " size: " << students.size() <<'\n';
     /*
    int studentID;
    std::string name;
    std::string cUCode;
    std::string classCode;
    int count;
    Student student(0, "", "", "");

    std::fstream file(csv_file);
    if(file.is_open()){
        std::string line;
        while(!file.eof()){
            std::getline(file, line);
            count2++;
            if(count == 0){
                count++;
                continue;
            }
            std::stringstream ss(line);
            ss >> studentID >> name >> cUCode >> classCode;

            if(studentID == student.getStudentID()){
                student.addClass(cUCode, classCode);
            }
            else{
                if(student.getStudentID() != 0){
                    this->addStudent(student);
                }
                student = Student(studentID, name, cUCode, classCode);
            }
        }
        this->addStudent(student);
        std::cout << "count2: " << count2 << "size: " << students.size() <<'\n';
    }
     */
}
