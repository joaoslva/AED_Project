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

    std::cout << "C.U. Occupation: " << studentsList.size() << '\n';

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
int ScheduleManagement::auxGetClassOccupation(const std::string& cUcode, const std::string& classCode) const{

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
    return studentsList.size();
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

void ScheduleManagement::removeStudent(std::string ucCode, std::string classCode, int ID, bool& success) {
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
            Student toberemoved2 = Student(ID,"","","");
            auto itr0 = students.find(toberemoved2);
            students.erase(itr0);
            students.insert(student);
            success = true;
            break;
        }
        else{
            std::cout << "Error: student doesn't exist in the data files\n";
        }

    }
}
bool ScheduleManagement::CheckClassDifference(std::string UCCode) {
    int min = 30;
    int max = 0;
    for(ClassSchedule classSchedule: this->classSchedules){
        if(classSchedule.getCUCode() == UCCode){
            if(auxGetClassOccupation(UCCode,classSchedule.getClassCode()) <= min ){
                min = auxGetClassOccupation(UCCode,classSchedule.getClassCode());
            }
            if(auxGetClassOccupation(UCCode,classSchedule.getClassCode()) >= max){
                max = auxGetClassOccupation(UCCode,classSchedule.getClassCode());
            }
        }
    }
    return max-min < 4;
}

bool ScheduleManagement::addstudent(std::string ucCode, std::string classCode, int ID, bool& success) {

    // Check whether the class is available
    bool checkClassAvailable = false; // se a turma existe e não atingiu o limite
    bool checkStudentAvailable = true; //

    // Stores the information about the TP or PL classes (The ones that can't be overlapped)
    std::string weekDay;
    double startTime;
    double duration;

    // Loops through the classSchedules vector
    for (ClassSchedule classSchedule: classSchedules) {
        if (classSchedule.getCUCode() == ucCode && classSchedule.getClassCode() == classCode && classSchedule.getClassCap()  > 0) {
            // Checks whether the class is available and if it exists
            checkClassAvailable = true;
            for (Slot slot: classSchedule.getSlots()) {
                // Gathers the information about the classes that cannot be overlapped
                if (slot.getType() == "TP" || slot.getType() == "PL") {
                    weekDay = slot.getWeekDay();
                    startTime = slot.getStartTime();
                    duration = slot.getDuration();
                }
            }
        }
    }

    // If the class can have more students
    if (checkClassAvailable) {
        // Check if the student is able to add that class to their schedule
        for (Student student: this->students) {
            if (student.getStudentID() == ID) {
                for (ClassSchedule classSchedule: student.getStudentSched()) {
                    for (Slot slot: classSchedule.getSlots()) {
                        if ((slot.getType() == "TP" || slot.getType() == "PL") && weekDay == slot.getWeekDay() && ((startTime <= slot.getStartTime() && startTime + duration >= slot.getStartTime()) || (startTime <= slot.getStartTime() + slot.getDuration() && startTime >= slot.getStartTime()))) {
                            checkStudentAvailable = false;
                            break;
                        }
                    }
                    if (!checkStudentAvailable) {
                        std::cout << "Error: Student doesn't exist in the data files\n";
                        break;
                    }
                }

                if (checkStudentAvailable ) {
                    for (ClassSchedule classSchedule: classSchedules) {
                        if (classSchedule.getCUCode() == ucCode && classSchedule.getClassCode() == classCode) {
                            student.getStudentSched().push_back(classSchedule);
                            if(CheckClassDifference(ucCode)){
                                Student toberemoved2 = Student(ID,"","","");
                                auto itr0 = students.find(toberemoved2);
                                students.erase(itr0);
                                students.insert(student);
                                success = true;
                                break;
                            }
                        }
                    }
                }
                break;
            }
        }
    }
    else{
        std::cout << "Error: class code doesn't exist in the data files\n";
    }
    if(checkStudentAvailable && checkClassAvailable && CheckClassDifference(ucCode)){
        success = true;
        return 1;
    }
    else return 0;
}

void ScheduleManagement::swapStudent(int ID, std::string addUCCode, std::string addClassCode ,std::string remUCCode,std::string remClassCode, bool& success){
    bool stub = false;
    if (this->addstudent(addUCCode, addClassCode, ID, success)) {
        this->removeStudent(remUCCode, remClassCode, ID, stub);
    }
}

int ScheduleManagement::check() {return students.size();}
int ScheduleManagement::check2() {return classSchedules.size();};

void ScheduleManagement::processRequest() {
    Request temp = this->requests.front();
    std::string requestType = temp.getRequest();
    if(requestType == "AddStudent"){
        bool success = false;
        this->addstudent(temp.getCUCode(), temp.getClassCode(), temp.getID(), success);
        if(success){
            std::cout << "Request completed successfully and removed from the queue\n";
            success = false;
            this->requests.pop();
        }
        else{
            std::cout << "Request failed, please check given data. Removing request from queue\n";
            success = false;
            this->failedRequests.push(temp);
            this->requests.pop();
        }
    }
    else if(requestType == "RemoveStudent"){
        bool success = false;
        this->removeStudent(temp.getCUCode(), temp.getClassCode(), temp.getID(), success);
        if(success){
            std::cout << "Request completed successfully and removed from the queue\n";
            success = false;
            this->requests.pop();
        }
        else{
            std::cout << "Request failed, please check given data. Removing request from queue\n";
            success = false;
            this->failedRequests.push(temp);
            this->requests.pop();
        }
    }
    else if(requestType == "SwapStudent"){
        bool success = false;
        this->removeStudent(temp.getCUCode(), temp.getClassCode(), temp.getID(), success);
        if(success){
            std::cout << "Request completed successfully and removed from the queue\n";
            success = false;
            this->requests.pop();
        }
        else{
            std::cout << "Request failed, please check given data. Removing request from queue\n";
            success = false;
            this->failedRequests.push(temp);
            this->requests.pop();
        }
    }
    else{
        std::cout << "Request type not not recognized. Removing request from the queue\n";
        this->failedRequests.push(temp);
        this->requests.pop();
    }
}

void ScheduleManagement::removeRequest() {
    int beforeSize = this->requests.size();
    this->requests.pop();
    int afterSize = this->requests.size();
    std::cout << "Before remove, size was " << beforeSize << ". Now, the queue size is " << afterSize << ".\n";
}

// Adds a Request to the Requests queue
void ScheduleManagement::addRequest(std::string request, std::string cUCode, std::string classCode, int iD) {
    if(request == "AddStudent" || request == "RemoveStudent" || request == "SwapStudent") {
        this->requests.push(Request(request, cUCode, classCode, iD));
        std::cout << "Request successfully added to the queue.\n";
    }
    else{
        std::cout << "Not a valid request type, request not added to the queue.\n";
    }
}

void ScheduleManagement::seeRequests(){
    int index = 1;
    std::cout << '\n';
    std::queue<Request> temp = this->getRequests();
    while(!temp.empty()){
        Request request = temp.front();
        std::string type = request.getRequest();
        std::string class_ = request.getClassCode();
        std::string cu = request.getCUCode();
        int iD = request.getID();
        std::cout << "Request number " << index << ":\n";
        std::cout << "Type: " << type << '\n';
        std::cout << "Class: " << class_ << '\n';
        std::cout << "C.U.: " << cu << '\n';
        std::cout << "Student ID: " << iD << '\n';
        index++;
        temp.pop();
    }
}
void ScheduleManagement::seeFailedRequests(){
    int index = 1;
    std::cout << '\n';
    std::queue<Request> temp = this->getFailedRequests();
    while(!temp.empty()){
        Request request = temp.front();
        std::string type = request.getRequest();
        std::string class_ = request.getClassCode();
        std::string cu = request.getCUCode();
        int iD = request.getID();
        std::cout << "Request number " << index << ":\n";
        std::cout << "Type: " << type << '\n';
        std::cout << "Class: " << class_ << '\n';
        std::cout << "C.U.: " << cu << '\n';
        std::cout << "Student ID: " << iD << '\n';
        index++;
        temp.pop();
    }
}
void ScheduleManagement::clearRequests(){
    while(true){
        std::string choice;
        std::cout << "Do you want to erase 'Requests' or 'FailedRequests'?\n"
                     "Enter here which one: ";
        std::cin >> choice;
        if(choice == "Requests"){
            if(!this->requests.empty()) {
                while (!this->requests.empty()) {
                    this->requests.pop();
                }
                std::cout << "Requests erase successfully\n";
                break;
            }
            else{
                std::cout << "Request queue is empty, can't erase.\n";
                break;
            }
        }
        else if(choice == "FailedRequests"){
            if(!this->failedRequests.empty()) {
                while (!this->failedRequests.empty()) {
                    this->failedRequests.pop();
                }
                std::cout << "Failed Requests erase successfully\n";
                break;
            }
            else{
                std::cout << "Failed Request queue is empty, can't erase.\n";
                break;
            }
        }
        else if(choice == "back"){
            break;
        }
        else{
            std::cout << "Not a valid input, try again\n";
            choice = "";
            std::cin.clear();
        }
    }
}

std::queue<Request> ScheduleManagement::getRequests() {
    return this->requests;
}

std::queue<Request> ScheduleManagement::getFailedRequests() {
    return this->failedRequests;
}

int ScheduleManagement::studentNumber() {
    return this->students.size();
}

int ScheduleManagement::scheduleNumber() {
    return this->classSchedules.size();
}