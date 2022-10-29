#include <iostream>
#include "headers/ScheduleManagement.h"

int main() {
    ScheduleManagement scheduleManagement = ScheduleManagement();
    scheduleManagement.addSchedule("../../AED_Project/headers/classes.csv");
    scheduleManagement.createStudents("../../AED_Project/headers/students_classes.csv");
    scheduleManagement.classOccupation("L.EIC011","2LEIC02");
    scheduleManagement.yearOccupation('1');
    scheduleManagement.uCOccupation("L.EIC001");
    scheduleManagement.studentSchedule(202025487);

    return 0;
}
