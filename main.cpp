#include <iostream>
#include <ctime>
#include <limits>
#include <fstream>
#include <sstream>
#include "headers/ScheduleManagement.h"

void check(bool& exit){
    std::string stay;
    while(true){
        std::cout << "\nDo you wish to use another function or go back ('stay'/'back')?\nEnter here: ";
        std::cin >> stay;
        if(stay == "stay"){
            break;
        }
        else if(stay == "back"){
            exit = true;
            break;
        }
        else{
            std::cout << "Not a valid input, please try again.\n";
            stay = "";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

int main() {
    bool running = true;
    time_t now = time(0);
    tm* localtm = localtime(&now);
    std::cout << "\n|==============================|\n"
                 "Welcome to the Schedule Management app!\n"
                 "To use the app simply choose one of the options presented to you.\n"
                 "In any time you can go back one step by writing 'back', "
                 "write 'quit' to close the program \nor type the command "
                 "'help' to see information about how to use the app functions.\n"
                 "Log files are available in 'Log' directory.\n";
    ScheduleManagement scheduleManager = ScheduleManagement();
    scheduleManager.setSchedule("../../AED_Project/headers/classes.csv");
    scheduleManager.setStudents("../../AED_Project/headers/students_classes.csv");
    std::ofstream management_log;
    std::ofstream request_log;
    management_log.open("../../AED_Project/Log/management_log.txt", std::ios::app);
    request_log.open("../../AED_Project/Log/request_log.txt", std::ios::app);
    if(scheduleManager.check() == 0 || scheduleManager.check2() == 0){
        std::cout << "Something went wrong while reading the files. Please check their paths in the source code\n";
        running = false;
    }

    while(running){
        std::string functionalityChoice;
        std::cout << "\nWhich functionality do you want to use, 'Management', 'Request', 'ClearLog', 'help' or 'Quit'?\nEnter here: ";
        std::cin >> functionalityChoice;
        if (functionalityChoice == "Management" || functionalityChoice == "management") {
            management_log << asctime(localtm) << '\n';
            std::cout << "\n|====== Management Area ======|";
            while(true){
                std::string managementChoice;
                std::cout << "\nWhich functionality do you want to use? 1-'Student Schedule', 2-'C.U. Occupation', "
                             "3-'Class Occupation', 4-'Year Occupation',\n"
                             " 5-'More than x C.U's, 6-'Check number of', 'help' or 'back'? (Use 'help' to see their description)\n"
                             "Enter index here: ";
                std::cin >> managementChoice;
                if(managementChoice == "1"){
                    int iD;
                    std::cout << "Enter a student ID: ";
                    std::cin >> iD;
                    while(std::cin.fail()){
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                        std::cout << "Not a valid entry. Enter a NUMBER: ";
                        std::cin >> iD;
                    }

                    scheduleManager.getStudentSchedule(iD, management_log);

                    bool exit = false;
                    check(exit);
                    if(exit){
                        exit = false;
                        std::cout << "|============================|\n";
                        break;
                    }
                }
                else if(managementChoice == "2"){
                    std::string cUCode;
                    std::string how_temp;
                    std::string how;
                    std::cout << "Please write a C.U. code: ";
                    std::cin >> cUCode;
                    while(true){
                        std::cout << "Choose a ordering method ('none', 'ascending+Name/ID/UCs', 'descending+Name/ID/UCs'): ";
                        std::cin >> how_temp;
                        if(how_temp == "none"){
                            how = "none";
                            break;
                        }
                        else if(how_temp == "ascendingName"){
                            how = "ascending name";
                            break;
                        }
                        else if(how_temp == "ascendingID"){
                            how = "ascending id";
                            break;
                        }
                        else if(how_temp == "ascendingUCs"){
                            how = "ascending UC's";
                            break;
                        }
                        else if(how_temp == "descendingName"){
                            how = "descending name";
                            break;
                        }
                        else if(how_temp == "descendingID"){
                            how = "descending id";
                            break;
                        }
                        else if(how_temp == "descendingUCs"){
                            how = "descending UC's";
                            break;
                        }
                        else{
                            std::cout << "Not a valid ordering method, please try again.\n\n";
                            how_temp = "";
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                    }

                    scheduleManager.getUCOccupation(cUCode, how, management_log);

                    bool exit = false;
                    check(exit);
                    if(exit){
                        exit = false;
                        std::cout << "|============================|\n";
                        break;
                    }
                }
                else if(managementChoice == "3"){
                    std::string cUCode;
                    std::string classCode;
                    std::string how_temp;
                    std::string how;
                    std::cout << "Please write a C.U. code: ";
                    std::cin >> cUCode;
                    std::cout << "Please write a class code: ";
                    std::cin >> classCode;
                    while(true){
                        std::cout << "Choose a ordering method ('none', 'ascending+Name/ID/UCs', 'descending+Name/ID/UCs'): ";
                        std::cin >> how_temp;
                        if(how_temp == "none"){
                            how = "none";
                            break;
                        }
                        else if(how_temp == "ascendingName"){
                            how = "ascending name";
                            break;
                        }
                        else if(how_temp == "ascendingID"){
                            how = "ascending id";
                            break;
                        }
                        else if(how_temp == "ascendingUCs"){
                            how = "ascending UC's";
                            break;
                        }
                        else if(how_temp == "descendingName"){
                            how = "descending name";
                            break;
                        }
                        else if(how_temp == "descendingID"){
                            how = "descending id";
                            break;
                        }
                        else if(how_temp == "descendingUCs"){
                            how = "descending UC's";
                            break;
                        }
                        else{
                            std::cout << "Not a valid ordering method, please try again.\n\n";
                            how_temp = "";
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                    }

                    scheduleManager.getClassOccupation(cUCode, classCode, how, management_log);

                    bool exit = false;
                    check(exit);
                    if(exit){
                        exit = false;
                        std::cout << "|============================|\n";
                        break;
                    }
                }
                else if(managementChoice == "4"){
                    char year;
                    std::string how;
                    std::string how_temp;
                    std::cout << "Please write a year: ";
                    std::cin >> year;
                    while(true){
                        std::cout << "Choose a ordering method ('none', 'ascending+Name/ID/UCs', 'descending+Name/ID/UCs'): ";
                        std::cin >> how_temp;
                        if(how_temp == "none"){
                            how = "none";
                            break;
                        }
                        else if(how_temp == "ascendingName"){
                            how = "ascending name";
                            break;
                        }
                        else if(how_temp == "ascendingID"){
                            how = "ascending id";
                            break;
                        }
                        else if(how_temp == "ascendingUCs"){
                            how = "ascending UC's";
                            break;
                        }
                        else if(how_temp == "descendingName"){
                            how = "descending name";
                            break;
                        }
                        else if(how_temp == "descendingID"){
                            how = "descending id";
                            break;
                        }
                        else if(how_temp == "descendingUCs"){
                            how = "descending UC's";
                            break;
                        }
                        else{
                            std::cout << "Not a valid ordering method, please try again.\n\n";
                            how_temp = "";
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                    }

                    scheduleManager.getYearOccupation(year, how, management_log);

                    bool exit = false;
                    check(exit);
                    if(exit){
                        exit = false;
                        std::cout << "|============================|\n";
                        break;
                    }
                }
                else if(managementChoice == "5"){
                    int n;
                    std::string how;
                    std::string how_temp;
                    std::cout << "Please write a number: ";
                    std::cin >> n;
                    while(std::cin.fail()){
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                        std::cout << "Not a valid entry. Enter a number: ";
                        std::cin >> n;
                    }
                    while(true){
                        std::cout << "Choose a ordering method ('none', 'ascending+Name/ID/UCs', 'descending+Name/ID/UCs'): ";
                        std::cin >> how_temp;
                        if(how_temp == "none"){
                            how = "none";
                            break;
                        }
                        else if(how_temp == "ascendingName"){
                            how = "ascending name";
                            break;
                        }
                        else if(how_temp == "ascendingID"){
                            how = "ascending id";
                            break;
                        }
                        else if(how_temp == "ascendingUCs"){
                            how = "ascending UC's";
                            break;
                        }
                        else if(how_temp == "descendingName"){
                            how = "descending name";
                            break;
                        }
                        else if(how_temp == "descendingID"){
                            how = "descending id";
                            break;
                        }
                        else if(how_temp == "descendingUCs"){
                            how = "descending UC's";
                            break;
                        }
                        else{
                            std::cout << "Not a valid ordering method, please try again.\n\n";
                            how_temp = "";
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                    }

                    scheduleManager.getMoreThanNUc(n, how, management_log);

                    bool exit = false;
                    check(exit);
                    if(exit){
                        exit = false;
                        std::cout << "|============================|\n";
                        break;
                    }
                }
                else if(managementChoice == "6"){
                    std::string choice;
                    while(true){
                        std::cout << "Do you you want to check how many students or schedules exist?\n"
                                     "Enter here ('Student'/'Schedule'):";
                        std::cin >> choice;
                        if(choice == "Student"){
                            int num = scheduleManager.studentNumber(management_log);
                            std::cout << "Total number of students in the stored data: " << num << ".\n";
                            break;
                        }
                        else if(choice == "Schedule"){
                            int num = scheduleManager.scheduleNumber(management_log);
                            std::cout << "Total number of different schedules in the stored data: " << num << ".\n";
                            break;
                        }
                        else if(choice == "back"){
                            break;
                        }
                        else{
                            std::cout << "Not a valid input, please try again.\n\n";
                            managementChoice = "";
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                    }
                    bool exit = false;
                    check(exit);
                    if(exit){
                        exit = false;
                        std::cout << "|============================|\n";
                        break;
                    }
                }
                else if(managementChoice == "help"){
                    std::cout << "\n|======= Management Help =======|\n"
                                 "How all the functions work: \n"
                                 "Student Schedule - Given a student ID, this function prints his schedule;\n"
                                 "C.U. Occupation - Given a C.U. code and after choosing, if you want, a ordering;\n"
                                 "  method, this functions prints the respective occupation and the students in it (if ordered);\n"
                                 "Class Occupation - Given a C.U. code, a class code and after choosing, if you want,\n"
                                 "  a ordering method, this function prints it occupation and the students in it (if ordered);\n"
                                 "Year Occupation - Given a year and after choosing, if you want, a ordering method,\n"
                                 "  this function prints the year occupation;\n"
                                 "Check number of - shows the total number of students or different schedules in\n"
                                 "  the stored data;\n"
                                 "back - allows you to go back to the previous section.\n"
                                 "|======= Management Help =======|\n";
                }
                else if(managementChoice == "back"){
                    std::cout << "|============================|\n";
                    break;
                }
                else{
                    std::cout << "Not a valid input, please try again.\n";
                    managementChoice = "";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }
        }
        else if (functionalityChoice == "Request" || functionalityChoice == "request") {
            request_log << asctime(localtm) << '\n';
            std::cout << "\n|======= Request Area =======|";
            while(true){
                std::string requestChoice;
                std::cout << "\nWhich function do you want to use, 1-'Add Request', 2-'Process Request', "
                             "3-'Remove Request', 4-'See Requests', 5-'See Failed Requests', "
                             "6-'Erase queue', 'help' or 'back'?\n"
                             "Enter index here: ";
                std::cin >> requestChoice;
                if(requestChoice == "1"){
                    std::string request;
                    std::string cUCode;
                    std::string classCode;
                    std::string remcUCode;
                    std::string remclassCode;
                    int iD;
                    std::string option;
                    std::cout << "Do you wish to use 'SwapStudentCU'? ('yes'/'no')\n"
                                 "Enter here: ";
                    std::cin >> option;
                    if(option == "yes" || option == "Yes") {
                        request = "SwapStudentCU";
                        std::cout << "Please write a C.U. code to be added to schedule: ";
                        std::cin >> cUCode;
                        std::cout << "Please write a class code to be added to schedule: ";
                        std::cin >> classCode;
                        std::cout << "Please write a C.U. code to be removed from the schedule: ";
                        std::cin >> remcUCode;
                        std::cout << "Please write a class code to be removed from the schedule: ";
                        std::cin >> remclassCode;
                        std::cout << "Please write a student ID: ";
                        std::cin >> iD;
                        while (std::cin.fail()) {
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cout << "Not a valid entry. Enter a NUMBER: ";
                            std::cin >> iD;
                        }
                        scheduleManager.addRequest(request, cUCode, classCode, remcUCode, remclassCode, iD, request_log);
                    }
                    else if (option == "no" || option == "No"){
                        std::cout << "Please write the request type ('AddStudentCU', 'RemoveStudentCU'): ";
                        std::cin >> request;
                        std::cout << "Please write a C.U. code to be added or removed: ";
                        std::cin >> cUCode;
                        std::cout << "Please write a class code to be added or removed: ";
                        std::cin >> classCode;
                        std::cout << "Please write a student ID: ";
                        std::cin >> iD;
                        while(std::cin.fail()){
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                            std::cout << "Not a valid entry. Enter a NUMBER: ";
                            std::cin >> iD;
                        }
                        scheduleManager.addRequest(request, cUCode, classCode, remcUCode, remclassCode, iD, request_log);
                    }
                    else{
                        std::cout << "Not a valid input, please try again.\n\n";
                        requestChoice = "";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                    bool exit = false;
                    check(exit);
                    if(exit){
                        exit = false;
                        std::cout << "|============================|\n";
                        break;
                    }
                }
                else if(requestChoice == "2"){
                    if(!scheduleManager.getRequests().empty()) {
                        Request temp = scheduleManager.getRequests().front();
                        std::string requestType = temp.getRequest();
                        int iD = temp.getID();
                        std::cout << "Processing request " << requestType << " for student " << iD << ".\n";
                        scheduleManager.processRequest(request_log);
                    }
                    else{
                        std::cout << "Request queue is empty, nothing to process.\n";
                    }
                    bool exit = false;
                    check(exit);
                    if(exit){
                        exit = false;
                        std::cout << "|============================|\n";
                        break;
                    }
                }
                else if (requestChoice == "3"){
                    std::queue<Request> temp2 = scheduleManager.getRequests();
                    if(temp2.empty()) {
                        std::cout << "Request queue is empty, nothing to remove.\n";
                    }
                    else{
                        Request temp = scheduleManager.getRequests().front();
                        std::string requestType = temp.getRequest();
                        int iD = temp.getID();
                        std::cout << "Removing request " << requestType << " for student " << iD
                                  << " from the queue.\n";
                        scheduleManager.removeRequest(request_log);
                    }
                    bool exit = false;
                    check(exit);
                    if(exit){
                        exit = false;
                        std::cout << "|============================|\n";
                        break;
                    }
                }
                else if(requestChoice == "4"){
                    if(!scheduleManager.getRequests().empty()) {
                        scheduleManager.seeRequests(request_log);
                    }
                    else{
                        std::cout << "Request queue is empty, nothing to see.\n";
                    }
                    bool exit = false;
                    check(exit);
                    if(exit){
                        exit = false;
                        std::cout << "|============================|\n";
                        break;
                    }
                }
                else if(requestChoice == "5"){
                    if(!scheduleManager.getFailedRequests().empty()) {
                        scheduleManager.seeFailedRequests(request_log);
                    }
                    else{
                        std::cout << "Request queue is empty, nothing to see.\n";
                    }
                    bool exit = false;
                    check(exit);
                    if(exit){
                        exit = false;
                        std::cout << "|============================|\n";
                        break;
                    }
                }
                else if(requestChoice == "6"){
                    scheduleManager.clearRequests(request_log);
                    std::string stay;
                    bool exit = false;
                    check(exit);
                    if(exit){
                        exit = false;
                        std::cout << "|============================|\n";
                        break;
                    }
                }
                else if(requestChoice == "help"){
                    std::cout << "\n|======= Request Help =======|\n"
                                 "How all the functions work:\n"
                                 "Add Request - Given a request type ('AddStudent', 'RemoveStudentUC', 'SwapStudent'),\n"
                                 "  a C.U. code (or 2 in case of Swap), a class code (or 2 in case of Swap) and a student ID,\n"
                                 "  this function will add a request with this information to the queue;\n"
                                 "Process Request - Processes the first request on the queue and removes it, in case \n"
                                 "  of success in completion or not;\n"
                                 "Remove Request - Removes the first request in the queue;\n"
                                 "See Requests - Shows all the requests in the queue;\n"
                                 "See Failed Requests - Shows all the failed requests in the queue;\n"
                                 "Erase queue - Erases, if possible, one of the request queues;\n"
                                 "back - allows you to go back to the previous section.\n"
                                 "|======= Request Help =======|\n";
                }
                else if(requestChoice == "back"){
                    std::cout << "|============================|\n";
                    break;
                }
                else{
                    std::cout << "Not a valid input, please try again.\n";
                    requestChoice = "";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }
        }
        else if(functionalityChoice == "ClearLog"){
            std::string choice;
            while(true){
                std::cout << "Do you you want to clear the management or the request log?\n"
                             "Enter here ('Management'/'Request'):";
                std::cin >> choice;
                if(choice == "Management"){
                    std::ofstream file("../../AED_Project/Log/management_log.txt");
                    file << "";
                    file.close();
                    std::cout << "Log cleared\n";
                    break;
                }
                else if(choice == "Request"){
                    std::ofstream file("../../AED_Project/Log/request_log.txt");
                    file << "";
                    file.close();
                    std::cout << "Log cleared\n";
                    break;
                }
                else if(choice == "back"){
                    break;
                }
                else{
                    std::cout << "Not a valid input, please try again.\n\n";
                    functionalityChoice = "";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }
        }
        else if (functionalityChoice == "quit" || functionalityChoice == "Quit") {
            std::cout << "Thanks for using this app!\n"
                         "|==============================|\n";
            management_log.close();
            request_log.close();
            running = false;
        }
        else if(functionalityChoice == "help" || functionalityChoice == "Help"){
            std::cout << "\n|=======Help=======|\n"
                         "Management - functions that allow you to see information about students, classes, C.U. and other stuff;\n"
                         "Request - functions that allows you to queue request, such as adding a student to a new CU;\n"
                         "ClearLog - clears t one of the log files, of choosing;\n"
                         "Quit - will close the app.\n"
                         "|=======Help=======|\n";
        }
        else{
            std::cout << "Not a valid input, please try again.\n";
            functionalityChoice = "";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return 0;
}


