#include "headers/ClassSchedule.h"

int ClassSchedule::classCap = 30;

ClassSchedule::ClassSchedule(std::string cUCode, std::string classCode, std::string weekDay, double startTime,
                             double duration, std::string type) {
    this->cUCode = cUCode;
    this->classCode = classCode;
    this->slots.push_back(Slot(weekDay, startTime, duration, type));
}

void ClassSchedule::setSlot(std::string weekDay, double startTime, double duration,std::string type) {
    this->slots.push_back(Slot(weekDay, startTime, duration, type));
}

bool ClassSchedule::operator==(const ClassSchedule &c) const {
    return this->cUCode == c.cUCode && this->classCode == c.classCode;
}
