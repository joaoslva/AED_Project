#ifndef SLOT_H
#define SLOT_H

#include <string>

class Slot{
    private:
        //Attributes
        std::string weekDay;
        std::string startTime;
        std::string duration;
        std::string room;
        std::string type;
    public:
        Slot(std::string weekDay,
             std::string startTime,
             std::string duration,
             std::string room,
             std::string type);
};
#endif