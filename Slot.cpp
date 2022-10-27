#include <iostream>
#include "headers/Slot.h"

Slot::Slot(std::string weekDay, std::string startTime, std::string endTime, std::string room, std::string type) {
    this->weekDay = weekDay;
    this-> startTime = startTime;
    this->endTime = endTime;
    this->room = room;
    this->type = type;
}