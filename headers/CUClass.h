#ifndef CU_CLASS_H
#define CU_CLASS_H

#include <string>

class CUClass {
    private:

        // Attributes
        std::string cUCode;
        std::string classCode;
        int classCap;
        
    public:
        // Constructors
        CUClass(std::string cUCode, std::string classCode);

        // Getters
        std::string getCUCode() {return this->cUCode;};
        std::string getClassCode() {return this->classCode;};

        // Override
        bool operator== (const CUClass& c) const;

};
#endif