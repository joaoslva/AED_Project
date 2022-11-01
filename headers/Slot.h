#ifndef SLOT_H
#define SLOT_H

#include <string>

class Slot{
    private:

        // Attributes
        std::string weekDay;
        double startTime;
        double duration;
        std::string type;

    public:

        // Constructor
        Slot(std::string weekDay,
            double startTime,
            double duration,
            std::string type);

        // Getters
        std::string getWeekDay() {return weekDay;};
        double getStartTime() {return startTime;};
        double getDuration() {return duration;};
        std::string getType() {return type;};
};
#endif