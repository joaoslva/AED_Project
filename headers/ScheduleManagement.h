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
};
#endif