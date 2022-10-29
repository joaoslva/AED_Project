#ifndef STUDENT_H
#define STUDENT_H

#include "CUClass.h"
#include "Slot.h"
#include "ClassSchedule.h"
#include <string>
#include <list>

class Student{
    private:
        //Attributes
        int studentID;
        std::string name;
        std::list<ClassSchedule> studentSchedule;
        std::list<CUClass> classes;

        /*
        std::list<Slot> studentSchedule;
         */

    public:
        //Constructors
        Student(int studentID, std::string name, std::string cUCode, std::string classCode);

        //Methods
        void addClass(std::string cUCode, std::string classCode);
        std::string getName();
        int getStudentID();
        bool operator < (const Student& student) const;
        std::list<CUClass> getClasses() const;
        void addSchedule (ClassSchedule classSchedule) {this->studentSchedule.push_back(classSchedule);}
        std::list<ClassSchedule> getStudentSched() {return studentSchedule;}

};
#endif