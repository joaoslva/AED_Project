#include "headers/CUClass.h"

//Constructors
CUClass::CUClass(std::string cUCode, std::string classCode){
    this->cUCode = cUCode;
    this->classCode = classCode;
}

//Methods
std::string CUClass::getCUCode(){
    return this->cUCode;
}

std::string CUClass::getClassCode(){
    return this->classCode;
}

bool CUClass::operator==(const CUClass &c) const {
    return this->cUCode == c.cUCode && this->classCode == c.classCode;
}
