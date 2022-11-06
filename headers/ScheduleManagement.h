#ifndef SCHEDULE_MANAGEMENT_H
#define SCHEDULE_MANAGEMENT_H

#include "Slot.h"
#include "Student.h"
#include "ClassSchedule.h"
#include "Request.h"
#include <vector>
#include <set>
#include <queue>
#include <string>

class ScheduleManagement{

private:

    // Attributes

    /// @brief Set of students.\n Stores every different student
    std::set<Student> students;
    /// @brief Vector of class schedules.\n Stores every different class schedules
    std::vector<ClassSchedule> classSchedules;
    /// @brief Queue of requests.\n Stores the different user requests
    std::queue<Request> requests;
    /// @brief Queue of failed requests\n Stores the user requests that couldn't be processed
    std::queue<Request> failedRequests; 

public:

    // Setters

    /// @brief Reads a .csv file and extracts the information about the schedules.\n Creates a new class/schedule combination in the classSchedules vector or adds to an already created class a schedule\n Complexity: O(n²)
    /// @param file Corresponds to the .csv file the program needs to read to get the class schedules information.\n In this project, the .csv file is the classes.csv
    void setSchedule(const std::string& file);

    /// @brief Reads a .csv file and extracts the information about the students.\n Creates a new student in the vector students or adds to an already created student a new class and it's corresponding schedule\n Complexity: O(n³)
    /// @param file Corresponds to the .csv file the program needs to read to get the students information.\n In this project, the .csv file is the students_classes.csv
    void setStudents(const std::string& file);

    /// @brief Reads the values of a vector.\n Extracts the values read and writes them in the classSchedule vector\n Complexity: O(n)
    /// @param classScheduleVector Corresponds to the vector that will provide it´s values to the classSchedule vector
    void setClassSchedule(const std::vector<ClassSchedule>& classScheduleVector) {
        for (const ClassSchedule &classSchedule : classScheduleVector) {
            this->classSchedules.push_back(classSchedule);
        }
    };

    // Getters

    /// @brief Prints the student information and it's class schedules\n Complexity: O(log2(n))
    /// @param studentID User wants to see this students's schedule
    void getStudentSchedule(int studentID) const;

    /// @brief Prints the number of students that have a certain Curricular Unit.\n If wanted, it prints the students name and ID in a choosen order by the user
    /// @param ucCode Defines the Curricular Unit that the user is interested in
    /// @param how Defines how the user wants the students information to be printed.\n It's default value is "none" so if left empty the method will only print the number of students in the Curricula Unit\n Complexity: O(n²)
    void getUCOccupation(const std::string& ucCode, const std::string& how = "none") const;

    /// @brief Prints the number of students that are in a certain class.\n  If wanted, it prints the students name and ID in a choosen order by the user\n Complexity: O(n²)
    /// @param ucCode Defines the Curricular Unit that the user is interested in
    /// @param classCode Defines the Class that the user is interested in
    /// @param how Defines how the user wants the students information to be printed.\n It's default value is "none" so if left empty the method will only print the number of students in that class
    void getClassOccupation(const std::string& ucCode, const std::string& classCode, const std::string& how = "none") const;

    /// @brief Prints the number of students that are in a certain year.\n If wanted, it prints the students name and ID in a choosen order by the user\n Complexity: O(n²)
    /// @param year Defines the year that the user is interested in
    /// @param how Defines how the user wants the students information to be printed.\n It's default value is "none" so if left empty the method will only print the number of students in that year
    void getYearOccupation(char year, const std::string& how = "none" ) const;

    /// @brief Prints the number of students that have nore than a certain number of Curricular Units.\n If wanted, it prints the students name and ID in a choosen order by the user\n Complexity: O(n)
    /// @param N Corresponds to the number of Curricular Units that the user wants to set as the minimum
    /// @param how Defines how the user wants the students information to be printed.\n It´s default value is "none" so if left empty the method will only print the number of students that have more than N Curricula Units
    void getMoreThanNUc(int N, const std::string& how = "none");

    /// @brief Auxiliar function that calculates the number of students that are in a certain class\n Complexity: O(n²)
    /// @param ucCode Corresponds to the Curricular Unit 
    /// @param classCode Corresponds to the class 
    /// @return Number of students that are in the class that was given in the parameters
    int  auxGetClassOccupation(const std::string& ucCode, const std::string& classCode) const;

    /// @brief Gets the number of students in the students set\n Complexity: O(1)
    /// @return Number of students in the students set
    int studentNumber();

    /// @brief Gets the number of classes in the classSchedules vector\n Complexity: O(1)
    /// @return Number of classes in the classSchedules vector
    int scheduleNumber();

    /// @brief Gets the queue of requests\n Complexity: O(1)
    /// @return Queue of requests
    std::queue<Request> getRequests();

    /// @brief Gets the queue of failed requests\n Complexity: O(1)
    /// @return Queue of failed requests
    std::queue<Request> getFailedRequests();

    // Requests

    /// @brief Adds a new request to the requests queue\n Complexity: O(1)
    /// @param request Corresponds to the name given to the request 
    /// @param addcUCode Corresponds to the Curricular Unit given by the user.\n In case of class/Curricular Unit swap this will be the new Curricular Unit added to the student
    /// @param addclassCode Corresponds to the class given by the user.\n In case of class/Curricular Unit swap this will be the new class added to the student
    /// @param remcUCode Corresponds to the Curricular Unit the user wants to substitute in case of a swap.\n It´s blank when there is no class/Curricular Unit swap
    /// @param remclassCode Corresponds to the class the user wants to substitute in case of a swap.\n It´s blank when there is no class/Curricular Unit swap
    /// @param iD Corresponds to de ID of the student
    void addRequest(std::string request, std::string addcUCode, std::string addclassCode, std::string remcUCode, std::string remclassCode,int iD);

    /// @brief Removes a request from the queue requests\n Complexity: O(1)
    void removeRequest();

    /// @brief Removes a Curricular Unit/class from a student\n Complexity: O(log2(n))
    /// @param ucCode Corresponds to the Curricular Unit that the user wants to remove
    /// @param classCode Corresponds to the class that the user wants to remove
    /// @param ID Corresponds to the student ID
    /// @param success Correspond to the success of the method (if the class/Curricular Unit got removed)
    void removeStudentCU(std::string ucCode, std::string classCode, int ID, bool& success);

    /// @brief Adds a Curricular Unit/class from a student\n Complexity: O(n²)
    /// @param ucCode Corresponds to the Curricular Unit that the user wants to add
    /// @param classCode Corresponds to the class that the user wants to add
    /// @param ID Corresponds to the student ID
    /// @param success Correspond to the success of the method (if the class/Curricular Unit got added)
    /// @return True if the class/Curricular Unit got added to the student.\n False if the class/Curricular Unit wasn´t added to the student.
    bool addstudentCU(std::string ucCode, std::string classCode, int ID, bool& success);

    /// @brief Swaps a Curricular Unit/class from a student to a Curricular Unit/class that the student doesn´t have yet\n Complexity: O(n²)
    /// @param ID Corresponds to the student ID
    /// @param addUCCode Corresponds to the Curricular Unit that the user wants to add
    /// @param addClassCode Corresponds to the class that the user wants to add
    /// @param remUCCode Corresponds to the Curricular Unit that the user wants to remove
    /// @param remClassCode Corresponds to the class that the user wants to remove
    /// @param success Correspond to the success of the method (if the swap was successfull)
    void swapStudentCU(int ID, std::string addUCCode, std::string addClassCode, std::string remUCCode, std::string remClassCode, bool& success);

    /// @brief Checks if the amplitude of the total of students in all classes of a Curricular Unit is less than 4\n Complexity: O(n)
    /// @param UCCode Corresponds to the Curricular Unit we want to use to check its amplitude
    /// @return True if the amplitude of the total of students in all classes of a Curricular Unit is less than 4.\n False if the amplitude is higher than or equal to 4
    bool CheckClassDifference(std::string UCCode);

    /// @brief Grabs the next request in the queue requests and checks if it is possible with the methods created inside the code.\n If it isn´t possible the method grabs the next request\n Complexity: O(n²)
    void processRequest();

    /// @brief Prints the requests in the requests queue\n Complexity: O(n)
    void seeRequests();

    /// @brief Prints the failed requests in the failedRequests queue\n Complexity: O(n)
    void seeFailedRequests();

    /// @brief Removes all the requests in the requests queue\n Complexity: O(n)
    void clearRequests();

    // Verifying

    /// @brief Checks if the .csv file opens\n Complexity: O(1)
    /// @return Number of students.\n If it is 0 then it is not working
    int check();

    /// @brief Checks if the .csv file opens\n Complexity: O(1)
    /// @return Number of classers.\n If it is 0 then it is not working
    int check2();
};
#endif