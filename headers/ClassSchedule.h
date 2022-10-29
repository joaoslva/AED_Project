#ifndef CLASS_SCHEDDULE_H
#define CLASS_SCHEDDULE_H

#include "Slot.h"
#include <string>
#include <list>

class ClassSchedule{
    private:
        //Attributes
        std::string cUCode;
        std::string classCode;
        std::list<Slot> slots;
    public:
        //Constructors
        ClassSchedule(std::string cUCode, std::string classCode, std::string weekDay, double startTime,
                      double duration, std::string type);
    void addSlot(std::string weekDay, double startTime, double duration,std::string type);
    std::string getCUCode() {return this->cUCode;};
    std::string getClassCode() {return this->classCode;};
};
#endif