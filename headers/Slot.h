#ifndef SLOT_H
#define SLOT_H

#include <string>

class Slot{
    private:
        //Attributes
        std::string weekDay;
        double startTime;
        double duration;
        std::string type;
    public:
        Slot(std::string weekDay,
            double startTime,
            double duration,
            std::string type);
};
#endif