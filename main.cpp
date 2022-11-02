#include <iostream>
#include "headers/ScheduleManagement.h"

int main() {
    ScheduleManagement scheduleManagement = ScheduleManagement();
    scheduleManagement.setSchedule("../../AED_Project/headers/classes.csv");
    scheduleManagement.setStudents("../../AED_Project/headers/students_classes.csv");
    //scheduleManagement.getClassOccupation("L.EIC005", "1LEIC05");
    //scheduleManagement.getUCOccupation("L.EIC001", "ascending name");
    //scheduleManagement.getClassOccupation("L.EIC012","2LEIC13")
    scheduleManagement.getStudentSchedule(202025232);
    //scheduleManagement.removeStudent("L.EIC004", "1LEIC08", 202025232);
    scheduleManagement.addstudent("L.EIC023", "3LEIC12", 202025232);
    scheduleManagement.getStudentSchedule(202025232);
    //scheduleManagement.check();

    return 0;
}
