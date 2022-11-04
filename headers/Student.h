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

        /// @brief Student ID
        int studentID;

        /// @brief Student name
        std::string name;

        /// @brief Student schedule
        std::list<ClassSchedule> studentSchedule;

        /// @brief Student classes
        std::list<CUClass> classes;

    public:

        // Constructors

        /// @brief Creates a Student object
        /// @param studentID Student ID
        /// @param name Student name
        /// @param cUCode Curricular Unit code
        /// @param classCode Class code
        Student(int studentID, std::string name, std::string cUCode, std::string classCode);

        // Getters

        /// @brief Get student name
        /// @return Student name
        std::string getName()  {return this->name;}

        /// @brief Get student ID
        /// @return Student ID
        int getStudentID()  {return this->studentID;}

        /// @brief Get Student Classes list
        /// @return Classes list
        std::list<CUClass> & getClasses() {return this->classes;}

        /// @brief Get Student Schedules list
        /// @return Student Schedules list
        std::list<ClassSchedule> & getStudentSched() {return this->studentSchedule;}

        // Setters

        /// @brief Adds a new class to the classes list
        /// @param cUCode Curricular Unit code
        /// @param classCode Class code
        void setClass(std::string cUCode, std::string classCode);

        /// @brief Adds a new schedule to the student schedules list
        /// @param classSchedule  Class Schedule
        void setSchedule (const ClassSchedule& classSchedule) {this->studentSchedule.push_back(classSchedule);}

        // Override

        /// @brief Overrides the operator < so it compares values instead of references.
        /// @param student Student object
        /// @return True if the value on the right is less than the value on the left.\n False otherwise
        bool operator < (const Student& student) const;

        /// @brief Overrides the operator == so it compares values instead of references
        /// @param student Student object
        /// @return True if the values are equal.\n False otherwise
        bool operator== (const Student &student) const ;

};
#endif