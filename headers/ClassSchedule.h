#ifndef CLASS_SCHEDDULE_H
#define CLASS_SCHEDDULE_H

#include "Slot.h"
#include <string>
#include <list>

class ClassSchedule{
    private:

        //Attributes

        /// @brief Curricular Unit Code
        std::string cUCode;

        /// @brief Class Code
        std::string classCode;

        /// @brief List of slots\n Stores all the schedules of a class
        std::list<Slot> slots;

        /// @brief Maximum number of students a class can have
        static int classCap;


public:

        //Constructors

        /// @brief Creates a ClassSchedule object\n Complexity: O(1)
        /// @param cUCode Curricular Unit code
        /// @param classCode Class code
        /// @param weekDay Week day of the class
        /// @param startTime Class start time
        /// @param duration Duration of the class
        /// @param type Type of the class ("T", "TP", "PL")
        ClassSchedule(std::string cUCode, std::string classCode, std::string weekDay, double startTime,
                      double duration, std::string type);
        
        /// @brief Creates a ClassSchedule object whitout the schedule information\n Complexity: O(1)
        /// @param cUCode Curricular Unit code
        /// @param classCode Class code
        ClassSchedule(std::string cUCode, std::string classCode);

        // Getters

        /// @brief Gets the Curricular Unit code\n Complexity: O(1)
        /// @return Curricular Unit code
        std::string getCUCode() {return this->cUCode;};

        /// @brief Gets the Class code\n Complexity: O(1)
        /// @return Class code
        std::string getClassCode() {return this->classCode;};

        /// @brief Gets the Slots list\n Complexity: O(1)
        /// @return Slots list
        std::list<Slot> getSlots() {return this->slots;};

        /// @brief Gets the class cap\n Complexity: O(1)
        /// @return Class Cap
        static int getClassCap() {return classCap;};

        // Setters

        /// @brief Adds a new slot to the slots list\n Complexity: O(1)
        /// @param weekDay Week day of the class
        /// @param startTime Class start time
        /// @param duration Duration of the class
        /// @param type Type of the class ("T", "TP", "PL")
        void setSlot(std::string weekDay, double startTime, double duration,std::string type);

    // Override

        /// @brief Overrides the operator == so it compares values instead of references\n Complexity: O(1)
        /// @param c A ClassSchedule object
        /// @return True if the values are equal.\n False if they are not equal.
        bool operator== (const ClassSchedule& c) const;
};
#endif