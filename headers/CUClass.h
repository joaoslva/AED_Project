#ifndef CU_CLASS_H
#define CU_CLASS_H

#include <string>

class CUClass{
    private:
        //Attributes
        std::string cUCode;
        std::string classCode;
        
    public:
        //Constructors
        CUClass(std::string cUCode, std::string classCode);
        //Methods
        std::string getCUCode();
        std::string getClassCode();
};
#endif