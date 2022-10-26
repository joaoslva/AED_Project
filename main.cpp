#include <iostream>
#include "headers/ScheduleManagement.h"

int main() {
    ScheduleManagement scheduleManagement = ScheduleManagement();
    scheduleManagement.createStudents("/home/juao/Desktop/Project/headers/students_classes.csv");
    return 0;
}
