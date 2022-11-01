#include "headers/ScheduleManagement.h"
#include <fstream>
#include <sstream>
#include <iostream>

// Setters
// Creates different schedules from the csv_file classes.csv
void ScheduleManagement::setSchedule(const std::string& csv_file) {

    // Variables that take in each line in the classes.csv file
    std::string cUCode;
    std::string classCode;
    std::string weekDay;
    double startTime;
    double duration;
    std::string type;

    // Variable to skip first line
    int count = 0;

    // Variable that contains the file
    std::ifstream file;

    file.open(csv_file);

    // Last object added in the list each time
    ClassSchedule classSchedule("", "", "", 0, 0, "");

    // Loop that iterates through every line in the classes.csv and adds the information in the classSchedules vector
    for(std::string line; std::getline(file, line);){

        // Skips first line
        if(count == 0){
            count++;
            continue;
        }

        // Getting the information that is in each line and attributing it to the right variables
        std::stringstream inputString(line);
        std::string data;

        std::getline(inputString, data, ',');
        classCode = data;
        std::getline(inputString, data, ',');
        cUCode = data;
        std::getline(inputString, data, ',');
        weekDay = data;
        std::getline(inputString, data, ',');
        startTime = std::stod(data);
        std::getline(inputString, data, ',');
        duration = std::stod(data);
        std::getline(inputString, data, '\r');
        type = data;

        // Add the first line to the classSchedules vector
        if (count == 1) {
            classSchedule = ClassSchedule(cUCode, classCode, weekDay, startTime, duration, type);
            classSchedules.push_back(classSchedule);
            count++;
            continue;
        }

        // Iterate through the classSchedules vector
        for (int index = 0; index < classSchedules.size() ; index++) {

            if(classSchedules[index].getCUCode() == cUCode && classSchedules[index].getClassCode() == classCode){
                // Check if there is already a combination of CUClass and ClassCode in the vector
                classSchedules[index].setSlot(weekDay, startTime, duration, type);
                break;
            }
            else{
                // If not add a new schedule to the vector
                if (classSchedules.size() - 1 == index) {
                    classSchedule = ClassSchedule(cUCode, classCode, weekDay, startTime, duration, type);
                    classSchedules.push_back(classSchedule);
                }
            }
        }
    }

    std::cout << "Different schedules: " << classSchedules.size() << "\n";
}

// Creates different students from the csv_file students_classes.csv
void ScheduleManagement::setStudents(const std::string& csv_file){

    // Variables that take in each line in the students_classes.csv file
    int iD;
    std::string name;
    std::string cUCode;
    std::string classCode;

    // Variable to skip first line
    int count = 0;

    // Variable that contains the file
    std::ifstream file;
    file.open(csv_file);

    // Last object added in the list each time
    Student student(0, "", "", "");

    /* Loop that iterates through each line in the students_classes.csv file
       and adds the information to the students set */
    for(std::string line; std::getline(file, line);){

        // Skips the first line
        if(count == 0){
            count++;
            continue;
        }

        // Getting the information that is in each line and attributing it to the right variables
        std::stringstream inputString(line);
        std::string data;

        std::getline(inputString, data, ',');
        iD = std::stoi(data);
        std::getline(inputString, data, ',');
        name = data;
        std::getline(inputString, data, ',');
        cUCode = data;
        std::getline(inputString, data, '\r');
        classCode = data;

        if(iD == student.getStudentID()){
            // Check if there is already a combination of CUClass and ClassCode in the vector
            student.setClass(cUCode, classCode);
        }
        else{
            // If not add a new student to the set
            if(student.getStudentID() != 0) {
                // Add the schedule to each student
                for (CUClass cUClass: student.getClasses()) {
                    for (ClassSchedule schedules: classSchedules) {
                        if (schedules.getCUCode() == cUClass.getCUCode() && schedules.getClassCode() == cUClass.getClassCode()) {
                            student.setSchedule(schedules);
                            break;
                        }
                    }
                }

                this->students.insert(student);
            }
            student = Student(iD, name, cUCode, classCode);
        }
    }

    // Add the schedule to the last student
    for (CUClass cUClass: student.getClasses()) {
        for (ClassSchedule schedules: classSchedules) {
            if (schedules.getCUCode() == cUClass.getCUCode() && schedules.getClassCode() == cUClass.getClassCode()) {
                student.setSchedule(schedules);
                break;
            }
        }
    }
    this->students.insert(student);

    std::cout << "Number of Students: " << students.size() <<'\n';
}

// Prints out the information about a certain student
void ScheduleManagement::getStudentSchedule(int studentID) const {

    // Variable to check if there is a student with the ID that's wanted
    bool match = false;

    // Default student
    Student student = Student(0,"","","");

    // Check if there is a student with the ID wanted
    for(Student _student: students){
        if(_student.getStudentID() == studentID){
            match = true;
            student = _student;
            break;
        }
    }

    // If there is, print out their information
    if(match){
        std::cout << "Student ID: " << student.getStudentID() << "\n";
        std::cout << "Student name: " << student.getName() << "\n\n";
        for (ClassSchedule & classSchedule: student.getStudentSched()) {
            int count = 0;
            std::cout << "CUCode: " << classSchedule.getCUCode() << "\n";
            std::cout << "Class Code: " << classSchedule.getClassCode() << "\n";
            for (Slot & slot: classSchedule.getSlots()) {
                if (count == 0) {
                    count++;
                    continue;
                }

                std::cout << "Week Day: " << slot.getWeekDay() << "\n";
                std::cout << "Start Time: " << slot.getStartTime() << "\n";
                std::cout << "Duration: " << slot.getDuration() << "\n";
                std::cout << "Type: " << slot.getType() << "\n\n";
            }
        }
    }
    else{
        std::cout << "No Student match\n";
    }
}

// Sort auxiliary functions
bool ascendingName(Student s1, Student s2) {return (s1.getName() < s2.getName());}
bool descendingName(Student s1, Student s2) {return s1.getName() > s2.getName();}
bool ascendingID(Student s1, Student s2) {return (s1.getStudentID() < s2.getStudentID());}
bool descendingID(Student s1, Student s2) {return s1.getStudentID() > s2.getStudentID();}
bool ascendingUC(Student s1, Student s2) {return (s1.getClasses().size() < s2.getClasses().size());}
bool descendingUC(Student s1, Student s2) {return s1.getClasses().size() > s2.getClasses().size();}

// Prints out the information about a certain Curricular Unit
void ScheduleManagement::getUCOccupation(const std::string& cUcode, const std::string& how) const {

    // List that contains all the students that belong to the Curricular Unit wanted
    std::list<Student> studentsList;

    // Checks whether a student belongs to the Curricular Unit or not
    for (Student student: this->students) {
        for (CUClass _class: student.getClasses()) {
            if (_class.getCUCode() == cUcode) {
                studentsList.push_back(student);
                break;
            }
        }
    }

    // Checks whether the user wants to order the list
    if (how == "ascending name") {
        studentsList.sort(ascendingName);
    } else if (how == "descending name") {
        studentsList.sort(descendingName);
    } else if (how == "ascending id") {
        studentsList.sort(ascendingID);
    } else if (how == "descending id") {
        studentsList.sort(descendingID);
    } else if (how == "ascending UC's") {
        studentsList.sort(ascendingUC);
    } else if (how == "descending UC's") {
        studentsList.sort(descendingUC);
    }

    std::cout << "Year Occupation: " << studentsList.size() << '\n';

    if (how != "none") {
        for (Student student: studentsList) {
            std::cout << "Student ID: " << student.getStudentID() << " Student name: " << student.getName() << "\n";
        }
    }
}

// Prints out the information about a certain class
void ScheduleManagement::getClassOccupation(const std::string& cUcode, const std::string& classCode, const std::string& how) const{

    // List that contains all the students that belong to the class wanted
    std::list<Student> studentsList;

    // Checks whether a student belongs to the Class or not
    for(Student student: this->students){
        for(CUClass _class: student.getClasses()){
            if(_class.getCUCode() == cUcode && _class.getClassCode()== classCode) {
                studentsList.push_back(student);
                break;
            }
        }
    }

    // Checks whether the user wants to order the list
    if (how == "ascending name") {
        studentsList.sort(ascendingName);
    } else if (how == "descending name") {
        studentsList.sort(descendingName);
    } else if (how == "ascending id") {
        studentsList.sort(ascendingID);
    } else if (how == "descending id") {
        studentsList.sort(descendingID);
    } else if (how == "ascending UC's") {
        studentsList.sort(ascendingUC);
    } else if (how == "descending UC's") {
        studentsList.sort(descendingUC);
    }

    std::cout << "Class Occupation: " << studentsList.size() << '\n';
    if (how != "none") {
        for (Student student: studentsList) {
            std::cout << "Student ID: " << student.getStudentID() << " Student name: " << student.getName() << "\n";
        }
    }
}

// Prints out the information about a certain Year
void ScheduleManagement::getYearOccupation(char year, const std::string& how) const {

    // List that contains all the students that belong to the class wanted
    std::list<Student> studentsList;

    // Checks whether a student belongs to the Year or not
    for(Student student: this->students){
        for(CUClass _class: student.getClasses()){
            if(_class.getClassCode()[0] == year){
                studentsList.push_back(student);
                break;
            }
        }
    }

    // Checks whether the user wants to order the list
    if (how == "ascending name") {
        studentsList.sort(ascendingName);
    } else if (how == "descending name") {
        studentsList.sort(descendingName);
    } else if (how == "ascending id") {
        studentsList.sort(ascendingID);
    } else if (how == "descending id") {
        studentsList.sort(descendingID);
    } else if (how == "ascending UC's") {
        studentsList.sort(ascendingUC);
    } else if (how == "descending UC's") {
        studentsList.sort(descendingUC);
    }

    std::cout << "Year Occupation: " << studentsList.size() << '\n';
    if (how != "none") {
        for (Student student: studentsList) {
            std::cout << "Student ID: " << student.getStudentID() << " Student name: " << student.getName() << "\n";
        }
    }
}

// Prints out the information about the students that have more than n Curricular Units
void ScheduleManagement::getMoreThanNUc(int n, const std::string& how) {

    // List that contains all the students that have more than n Curricular Units
    std::list<Student> studentsList;

    // Checks whether a student has more than n Curricular Units
    for (Student student: this->students) {
        unsigned long numberOfUC = student.getClasses().size();
        if (numberOfUC > n) {
            studentsList.push_back(student);
        }
    }

    // Checks whether the user wants to order the list
    if (how == "ascending name") {
        studentsList.sort(ascendingName);
    } else if (how == "descending name") {
        studentsList.sort(descendingName);
    } else if (how == "ascending id") {
        studentsList.sort(ascendingID);
    } else if (how == "descending id") {
        studentsList.sort(descendingID);
    } else if (how == "ascending UC's") {
        studentsList.sort(ascendingUC);
    } else if (how == "descending UC's") {
        studentsList.sort(descendingUC);
    }

    std::cout << "Number of students: " << studentsList.size() << '\n';

    if (how != "none") {
        for (Student student: studentsList) {
            std::cout << "Student ID: " << student.getStudentID() << " Student name: " << student.getName() << "\n";
        }
    }

}

// Adds a Request to the Requests queue
void ScheduleManagement::addRequest(const Request& request) {
    this->requests.push(request);
}

void ScheduleManagement::removeStudent(std::string ucCode, std::string classCode, int ID) {
    for (Student student: this->students) {
        if (student.getStudentID() == ID) {
            ClassSchedule toberemoved = ClassSchedule(ucCode, classCode, "", 0, 0, "");
            auto itr = std::remove_if(student.getStudentSched().begin(), student.getStudentSched().end(),
                                      [&](ClassSchedule a) { return a == toberemoved; });
            student.getStudentSched().erase(itr, student.getStudentSched().end());
            CUClass toberemoved1 = CUClass(ucCode,classCode);
            auto itr1 = std::remove_if(student.getClasses().begin(), student.getClasses().end(),
                                       [&](CUClass a) { return a == toberemoved1; });
            student.getClasses().erase(itr1, student.getClasses().end());
            break;
        }
    }
}

void ScheduleManagement::addstudent(std::string ucCode, std::string classCode, int ID) {

}


void ScheduleManagement::check() {std::cout << students.size();}