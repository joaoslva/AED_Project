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

    // Attributes
    std::set<Student> students;
    std::vector<ClassSchedule> classSchedules;
    std::queue<Request> requests;
    std::queue<Request> failedRequests;

public:

    // Setters
    void setSchedule(const std::string& file);
    void setStudents(const std::string& file);
    void setClassSchedule(const std::vector<ClassSchedule>& classScheduleVector) {
        for (const ClassSchedule &classSchedule : classScheduleVector) {
            this->classSchedules.push_back(classSchedule);
        }
    };

    // Getters
    void getStudentSchedule(int studentID) const;
    void getUCOccupation(const std::string& ucCode, const std::string& how = "none") const;
    void getClassOccupation(const std::string& ucCode, const std::string& classCode, const std::string& how = "none") const;
    void getYearOccupation(char year, const std::string& how = "none" ) const;
    void getMoreThanNUc(int N, const std::string& how = "none");
    int  auxGetClassOccupation(const std::string& ucCode, const std::string& classCode) const;
    int studentNumber();
    int scheduleNumber();
    std::queue<Request> getRequests();
    std::queue<Request> getFailedRequests();
    // Requests
    void addRequest(std::string request, std::string cUCode, std::string classCode, int iD);
    void removeRequest();
    void removeStudent(std::string ucCode, std::string classCode, int ID, bool& success);
    bool addstudent(std::string ucCode, std::string classCode, int ID, bool& success);
    void swapStudent(int ID, std::string addUCCode, std::string addClassCode,std::string remUCCode,std::string remClassCode1, bool& success);
    bool CheckClassDifference(std::string UCCode);
    void processRequest();
    void seeRequests();
    void seeFailedRequests();
    void clearRequests();
    // Verifying
    int check();
    int check2();
};
#endif