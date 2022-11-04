#ifndef CU_CLASS_H
#define CU_CLASS_H

#include <string>

class CUClass {
    private:

        // Attributes

        /// @brief Curricular Unit code
        std::string cUCode;

        /// @brief Class code
        std::string classCode;

    public:

        // Constructors

        /// @brief Creates a CUClass object
        /// @param cUCode Curricular Unit code
        /// @param classCode Class code
        CUClass(std::string cUCode, std::string classCode);

        // Getters

        /// @brief Gets the Curricular Unit code
        /// @return Curricular Unit code
        std::string getCUCode() {return this->cUCode;};

        /// @brief Gets the Class code
        /// @return Class code
        std::string getClassCode() {return this->classCode;};

        // Override

        /// @brief Overrides the operator == so it compares values instead of references
        /// @param c A CUClass object 
        /// @return True if the values are equal.\n False if they are not equal.
        bool operator== (const CUClass& c) const;

};
#endif