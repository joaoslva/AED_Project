#include <iostream>
#include "headers/ClassSchedule.h"

ClassSchedule::ClassSchedule(std::string cUCode, std::string classCode, std::string weekDay, std::string startTime,
                             std::string duration, std::string room, std::string type) {
    this->cUCode = cUCode;
    this->classCode = classCode;
    this->slots.push_back(Slot(weekDay, startTime, duration, room, type));
}

void ClassSchedule::addSlot(std::string weekDay, std::string startTime, std::string duration, std::string room,
                            std::string type) {
    this->slots.push_back(Slot(weekDay, startTime, duration, room, type));
}

