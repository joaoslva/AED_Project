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
        std::string getWeekDay() {return weekDay;};
        double getStartTime() {return startTime;};
        double getDuration() {return duration;};
        std::string getType() {return type;};
};
#endif