#include <iostream>
#include "headers/ScheduleManagement.h"

int main() {
    ScheduleManagement scheduleManagement = ScheduleManagement();
    scheduleManagement.addSchedule("../../AED_Project/headers/classes.csv");
    scheduleManagement.createStudents("../../AED_Project/headers/students_classes.csv");
//    scheduleManagement.cUOccupationOrdering("L.EIC001", "ascending name");
    scheduleManagement.studentSchedule(202025232);
    scheduleManagement.removeStudent("L.EIC002", "1LEIC05", 202025232);
    scheduleManagement.studentSchedule(202025232);

    return 0;
}
