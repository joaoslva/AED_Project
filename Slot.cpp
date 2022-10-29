#include <iostream>
#include "headers/Slot.h"

Slot::Slot(std::string weekDay, double startTime, double duration, std::string type) {
    this->weekDay = weekDay;
    this-> startTime = startTime;
    this->duration = duration;
    this->type = type;
}