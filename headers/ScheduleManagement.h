#ifndef SCHEDULE_MANAGEMENT_H
#define SCHEDULE_MANAGEMENT_H

#include "Slot.h"
#include "Student.h"
#include "ClassSchedule.h"
#include "Request.h"
#include <vector>
#include <set>
#include <queue>
#include <string>

class ScheduleManagement{
    private:
        //Attributes
        std::set<Student> students;
        std::vector<ClassSchedule> classSchedules;
        std::queue<Request> requests;
    public:
        //Methods
        void createStudents(std::string file);
        void addStudent(const Student& student);
        void addSchedule(std::string file);
        void setClassSchedule(std::vector<ClassSchedule> classSchedules) {
            for (ClassSchedule & classSchedule : classSchedules) {
                this->classSchedules.push_back(classSchedule);
            }
        };
        void classOccupation(std::string cUcode, std::string classCode) const;
        void yearOccupation(char year) const;
        void uCOccupation(std::string cUcode) const;
        void studentSchedule(int studentID) const; // É preciso os 2?
};
#endif