#ifndef STUDENT_H
#define STUDENT_H

#include "CUClass.h"
#include <string>
#include <list>

class Student{
    private:
        //Attributes
        int studentID;
        std::string name;
        std::list<CUClass> classes;
    public:
        //Constructors
        Student(int studentID, std::string name, std::string cUCode, std::string classCode);

        //Methods
        void addClass(std::string cUCode, std::string classCode);
        std::string getName();
        int getStudentID();
        bool operator < (const Student& student) const;
        std::list<CUClass> getClasses() const;

};
#endif