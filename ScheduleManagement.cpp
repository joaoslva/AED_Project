#include "headers/ScheduleManagement.h"
#include <fstream>
#include <sstream>
#include <iostream>

//Methods
void ScheduleManagement::addStudent(const Student& student){
    this->students.insert(student);
}

void ScheduleManagement::createStudents(std::string csv_file){
    int count2 = 0;

    int iD;
    std::string name;
    std::string cUCode;
    std::string classCode;

    std::ifstream file;
    file.open(csv_file);

    int count = 0;
    Student student(0, "", "", "");

    for(std::string line; std::getline(file, line);){
        count2++;
        if(count == 0){
            count++;
            continue;
        }

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
            student.addClass(cUCode, classCode);
        }
        else{
            if(student.getStudentID() != 0) {

                // Add the schedule to each student
                for (CUClass cUClass: student.getClasses()) {
                    for (ClassSchedule schedules: classSchedules) {
                        if (schedules.getCUCode() == cUClass.getCUCode() && schedules.getClassCode() == cUClass.getClassCode()) {
                            student.addSchedule(schedules);
                            break;
                        }
                    }
                }

                this->addStudent(student);
            }
            student = Student(iD, name, cUCode, classCode);
        }
    }

    // Add the schedule to the last student
    for (CUClass cUClass: student.getClasses()) {
        for (ClassSchedule schedules: classSchedules) {
            if (schedules.getCUCode() == cUClass.getCUCode() && schedules.getClassCode() == cUClass.getClassCode()) {
                student.addSchedule(schedules);
                break;
            }
        }
    }
    this->addStudent(student);

    std::cout << "count2: " << count2 << " size: " << students.size() <<'\n';
}

void ScheduleManagement::addSchedule(std::string csv_file) {
    int check = 0;

    // Variables that take in each line in the classes.csv file
    std::string cUCode;
    std::string classCode;
    std::string weekDay;
    double startTime;
    double duration;
    std::string type;

    // Temporary Class Schedule vector
    std::vector<ClassSchedule> temp;

    // Variable to skip first line
    int count = 0;

    // Variable that contains the file
    std::ifstream file;
    file.open(csv_file);

    // Last object added in the list
    ClassSchedule classSchedule("", "", "", 0, 0, "");

    // Loop that iterates through every line in the classes.csv and adds the information in the classSchedules vector
    for(std::string line; std::getline(file, line);){

        check++;
        // Skip first line
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

        // Add the first line to the temp vector
        if (count == 1) {
            classSchedule = ClassSchedule(cUCode, classCode, weekDay, startTime, duration, type);
            temp.push_back(classSchedule);
            count++;
            continue;
        }

        for (int index = 0; index < temp.size() ; index++) {

            if(temp[index].getCUCode() == cUCode && temp[index].getClassCode() == classCode){
                // Check if there is already a combination of CUClass and ClassCode in the vector
                temp[index].addSlot(weekDay, startTime, duration, type);
                break;
            }
            else{
                if (temp.size() - 1 == index) {
                    classSchedule = ClassSchedule(cUCode, classCode, weekDay, startTime, duration, type);
                    temp.push_back(classSchedule);
                }
            }
        }
    }
    setClassSchedule(temp);

    // Test the code
    std::cout << check << "\n";
    std::cout << classSchedules.size() << "\n";
}

void ScheduleManagement::studentSchedule(int studentID) const {
    bool match = false;
    Student student = Student(0,"","","");
    for(Student _student: students){
        if(_student.getStudentID() == studentID){
            match = true;
            student = _student;
            break;
        }
    }
    if(match){
        std::cout << "Student ID: " << student.getStudentID() << "\n";
        std::cout << "Student name: " << student.getName() << "\n\n";
        for (ClassSchedule classSchedule: student.getStudentSched()) {
            int count = 0;
            std::cout << "CUCode: " << classSchedule.getCUCode() << "\n";
            std::cout << "Class Code: " << classSchedule.getClassCode() << "\n";
            for (Slot slot: classSchedule.getSlots()) {
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
        std::cout << "No Student match\n" << "Try again\n" ;
    }
}

// Funções auxiliares para o sort
bool ascendingName(Student s1, Student s2) {return (s1.getName() < s2.getName());}
bool descendingName(Student s1, Student s2) {return s1.getName() > s2.getName();}
bool ascendingID(Student s1, Student s2) {return (s1.getStudentID() < s2.getStudentID());}
bool descendingID(Student s1, Student s2) {return s1.getStudentID() > s2.getStudentID();}
bool ascendingUC(Student s1, Student s2) {return (s1.getClasses().size() < s2.getClasses().size());}
bool descendingUC(Student s1, Student s2) {return s1.getClasses().size() > s2.getClasses().size();}

void ScheduleManagement::cUOccupationOrdering(std::string cUcode, std::string how) const {
    std::list<Student> ascendingStudents;

    for (Student student: this->students) {
        for (CUClass _class: student.getClasses()) {
            if (_class.getCUCode() == cUcode) {
                ascendingStudents.push_back(student);
                break;
            }
        }
    }

    if (how == "ascending name") {
        ascendingStudents.sort(ascendingName);
    } else if (how == "descending name") {
        ascendingStudents.sort(descendingName);
    } else if (how == "ascending id") {
        ascendingStudents.sort(ascendingID);
    } else if (how == "descending id") {
        ascendingStudents.sort(descendingID);
    } else if (how == "ascending UC's") {
        ascendingStudents.sort(ascendingUC);
    } else if (how == "descending UC's") {
        ascendingStudents.sort(descendingUC);
    }

    std::cout << "Year Occupation: " << ascendingStudents.size() << '\n';
    if (how != "none") {
        for (Student student: ascendingStudents) {
            std::cout << "Student ID: " << student.getStudentID() << " Student name: " << student.getName() << "\n";
        }
    }
}

void ScheduleManagement::classOccupationOrdering(std::string cUcode, std::string classCode, std::string how) const{
    std::list<Student> ascendingStudents;
    int count = 0;

    for(Student student: this->students){
        for(CUClass _class: student.getClasses()){
            if(_class.getCUCode() == cUcode && _class.getClassCode()== classCode) {
                ascendingStudents.push_back(student);
                count++;
                break;
            }
        }
    }

    if (how == "ascending name") {
        ascendingStudents.sort(ascendingName);
    } else if (how == "descending name") {
        ascendingStudents.sort(descendingName);
    } else if (how == "ascending id") {
        ascendingStudents.sort(ascendingID);
    } else if (how == "descending id") {
        ascendingStudents.sort(descendingID);
    } else if (how == "ascending UC's") {
        ascendingStudents.sort(ascendingUC);
    } else if (how == "descending UC's") {
        ascendingStudents.sort(descendingUC);
    }

    std::cout << "Year Occupation: " <<count<< '\n';
    if (how != "none") {
        for (Student student: ascendingStudents) {
            std::cout << "Student ID: " << student.getStudentID() << " Student name: " << student.getName() << "\n";
        }
    }
}

void ScheduleManagement::yearOccupationOrdering(char year, std::string how) const {

    std::list<Student> ascendingStudents;
    int count = 0;

    for(Student student: this->students){
        for(CUClass _class: student.getClasses()){
            if(_class.getClassCode()[0] == year){
                ascendingStudents.push_back(student);
                count++;
                break;
            }
        }
    }

    if (how == "ascending name") {
        ascendingStudents.sort(ascendingName);
    } else if (how == "descending name") {
        ascendingStudents.sort(descendingName);
    } else if (how == "ascending id") {
        ascendingStudents.sort(ascendingID);
    } else if (how == "descending id") {
        ascendingStudents.sort(descendingID);
    } else if (how == "ascending UC's") {
        ascendingStudents.sort(ascendingUC);
    } else if (how == "descending UC's") {
        ascendingStudents.sort(descendingUC);
    }

    std::cout << "Year Occupation: " <<count<< '\n';
    if (how != "none") {
        for (Student student: ascendingStudents) {
            std::cout << "Student ID: " << student.getStudentID() << " Student name: " << student.getName() << "\n";
        }
    }
}

void ScheduleManagement::moreThanNUc(int n, std::string how) {
    std::list<Student> students;

    for (Student student: this->students) {
        int numberOfUC = student.getClasses().size();
        if (numberOfUC > n) {
            students.push_back(student);
        }
    }

    if (how == "ascending name") {
        students.sort(ascendingName);
    } else if (how == "descending name") {
        students.sort(descendingName);
    } else if (how == "ascending id") {
        students.sort(ascendingID);
    } else if (how == "descending id") {
        students.sort(descendingID);
    } else if (how == "ascending UC's") {
        students.sort(ascendingUC);
    } else if (how == "descending UC's") {
        students.sort(descendingUC);
    }


    std::cout << "Number of students: " << students.size() << '\n';

    if (how != "none") {
        for (Student student: students) {
            std::cout << "Student ID: " << student.getStudentID() << " Student name: " << student.getName() << "\n";
        }
    }

}

void ScheduleManagement::addRequest(Request request) {
    this->requests.push(request);
}

void ScheduleManagement::removeStudent(std::string ucCode, std::string classCode, int ID) {

}