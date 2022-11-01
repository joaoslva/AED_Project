#include <iostream>
#include "headers/ScheduleManagement.h"

int main() {
    ScheduleManagement scheduleManagement = ScheduleManagement();
    scheduleManagement.setSchedule("../../AED_Project/headers/classes.csv");
    scheduleManagement.setStudents("../../AED_Project/headers/students_classes.csv");
    //scheduleManagement.getClassOccupation("L.EIC005", "1LEIC05");
    //scheduleManagement.getUCOccupation("L.EIC001", "ascending name");
    scheduleManagement.getStudentSchedule(202031607);
    scheduleManagement.removeStudent("L.EIC004", "1LEIC08", 202031607);
    scheduleManagement.getStudentSchedule(202031607);
    //scheduleManagement.check();

    return 0;
}
