#ifndef REQUEST_H
#define REQUEST_H

class Request{

private:

    // Attributes
    std::string request;
    std::string cUCode;
    std::string classCode;
    int ID;

public:
    //Constructors
    Request(std::string request, std::string cUCode, std::string classCode, int iD){
        this->ID = iD;
        this->cUCode = cUCode;
        this->classCode = classCode;
        this->request = request;
    }
    //Getters
    std::string getRequest() {return this->request;};
    std::string getCUCode() {return this->cUCode;};
    std::string getClassCode() {return this->classCode;};
    int getID() {return this->ID;};
};

#endif