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
        ClassSchedule(std::string cUCode, std::string classCode,
                      std::string weekDay,
                      std::string startTime,
                      std::string endTime,
                      std::string room,
                      std::string type);
        void addSlot(std::string weekDay,
                     std::string startTime,
                     std::string endTime,
                     std::string room,
                     std::string type);
};
#endif