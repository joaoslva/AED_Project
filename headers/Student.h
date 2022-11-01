#ifndef STUDENT_H
#define STUDENT_H

#include "CUClass.h"
#include "Slot.h"
#include "ClassSchedule.h"
#include <string>
#include <list>

class Student{

    private:

        // Attributes
        int studentID;
        std::string name;
        std::list<ClassSchedule> studentSchedule;
        std::list<CUClass> classes;

    public:

        // Constructors
        Student(int studentID, std::string name, std::string cUCode, std::string classCode);

        // Getters
        std::string getName()  {return this->name;}
        int getStudentID()  {return this->studentID;}
        std::list<CUClass> & getClasses() {return this->classes;}
        std::list<ClassSchedule> & getStudentSched() {return this->studentSchedule;}

        // Setters
        void setClass(std::string cUCode, std::string classCode);
        void setSchedule (const ClassSchedule& classSchedule) {this->studentSchedule.push_back(classSchedule);}

        // Override
        bool operator < (const Student& student) const;

};
#endif