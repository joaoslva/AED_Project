#ifndef REQUEST_H
#define REQUEST_H

class Request{

private:

    // Attributes

    /// @brief Name of the request
    std::string request;

    /// @brief Curricular Unit code.\n In case a swap is requested, this is the C.U. code of the new Curricular Unit
    std::string addcUCode;

    /// @brief  Class code,\n In case a swap is requested, this is the class code of the new class
    std::string addclassCode;

    /// @brief In case a swap is requested, this is the C.U. code of the Curricular Unit that will be substituted.\n If the request is not a swap, this variable should be empty
    std::string remcUCode;

    /// @brief In case a swap is requested, this is the class code of the class that will be substituted.\n If the request is not a swap, this variable should be empty
    std::string remclassCode;

    /// @brief Student ID
    int ID;

public:
    //Constructors

    /// @brief Creates a new Request object\n Complexity: O(1)
    /// @param request Request Name
    /// @param addcUCode Curricular Unit code
    /// @param addclassCode Class code
    /// @param remcUCode Curricular Unit code (in case the request is a swap)
    /// @param remclassCode Class code (in case the request is a swap)
    /// @param iD Student ID
    Request(std::string request, std::string addcUCode, std::string addclassCode, std::string remcUCode, std::string remclassCode,int iD){
        this->ID = iD;
        this->addcUCode = addcUCode;
        this->addclassCode = addclassCode;
        this->remcUCode = remcUCode;
        this->remclassCode = remclassCode;
        this->request = request;
    }
    //Getters

    /// @brief Gets the Request name\n Complexity: O(1)
    /// @return Request name
    std::string getRequest() {return this->request;};

    /// @brief Gets the Curricular Unit code\n Complexity: O(1)
    /// @return AddCurricularUnitCode
    std::string getaddCUCode() {return this->addcUCode;};

    /// @brief Gets the Class code\n Complexity: O(1)
    /// @return AddClassCode
    std::string getremCUCode() {return this->remcUCode;};

    /// @brief Gets the Curricular Unit code (in case the request is a swap)\n Complexity: O(1)
    /// @return RemCurricularUnitCode
    std::string getaddClassCode() {return this->addclassCode;};

    /// @brief Gets the Class code (in case the request is a swap)\n Complexity: O(1)
    /// @return RemClassCode
    std::string getremClassCode() {return this->remclassCode;};
    int getID() {return this->ID;};
};

#endif