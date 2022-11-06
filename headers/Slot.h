#ifndef SLOT_H
#define SLOT_H

#include <string>

class Slot{
    private:

        // Attributes

        /// @brief Week day of the class
        std::string weekDay;

        /// @brief Start Time of the class
        double startTime;

        /// @brief Duration of the class
        double duration;

        /// @brief Type of the class ("T", "TP", "PL")
        std::string type;

    public:

        // Constructor

        /// @brief Creates a Slot object\n Complexity: O(1)
        /// @param weekDay Week day to the class
        /// @param startTime Start Time of the class
        /// @param duration Duration of the class
        /// @param type Type of the class ("T", "TP", "PL")
        Slot(std::string weekDay,double startTime,double duration,std::string type);

        // Getters

        /// @brief Get the week day of the class \n Complexity: O(1)
        /// @return Week Day
        std::string getWeekDay() {return weekDay;};

        /// @brief Get the start time of the class\n Complexity: O(1)
        /// @return Start Time
        double getStartTime() {return startTime;};

        /// @brief Get the duration of the class\n Complexity: O(1)
        /// @return Duration
        double getDuration() {return duration;};

        /// @brief Get the type of the class\n Complexity: O(1)
        /// @return Type
        std::string getType() {return type;};
};
#endif