#include "headers/CUClass.h"

CUClass::CUClass(std::string cUCode, std::string classCode){
    this->cUCode = cUCode;
    this->classCode = classCode;
}

bool CUClass::operator==(const CUClass &c) const {
    return this->cUCode == c.cUCode && this->classCode == c.classCode;
}
