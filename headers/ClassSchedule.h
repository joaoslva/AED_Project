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
};
#endif