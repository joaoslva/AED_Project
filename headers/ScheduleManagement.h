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
        void studentSchedule(int studentID) const;
        void cUOccupationOrdering(std::string, std::string = "none") const;
        void classOccupationOrdering(std::string, std::string, std::string = "none") const;
        void yearOccupationOrdering(char , std::string ) const;
        void moreThanNUc(int, std::string = "none");
        void addRequest(Request);
        void removeStudent(std::string, std::string, int);
};
#endif