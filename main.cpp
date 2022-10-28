#include <iostream>
#include "headers/ScheduleManagement.h"

int main() {
    ScheduleManagement scheduleManagement = ScheduleManagement();
    scheduleManagement.createStudents("../../AED_Project/headers/students_classes.csv");
    return 0;
}
