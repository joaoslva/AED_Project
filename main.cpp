#include <iostream>
#include "headers/ScheduleManagement.h"

int main() {
    ScheduleManagement scheduleManagement = ScheduleManagement();
    scheduleManagement.setSchedule("../../AED_Project/headers/classes.csv");
    scheduleManagement.setStudents("../../AED_Project/headers/students_classes.csv");
    scheduleManagement.getUCOccupation("L.EIC001", "ascending name");
    scheduleManagement.getStudentSchedule(202025232);
    //scheduleManagement.removeStudent("L.EIC002", "1LEIC05", 202025232);
    scheduleManagement.getStudentSchedule(202025232);
    scheduleManagement.check();

    return 0;
}
