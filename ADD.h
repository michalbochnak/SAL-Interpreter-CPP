//
// Created by Michal on 5/2/2018.
//

#ifndef CS474_PROJECT04_ALI_INTERPRETER_ADD_H
#define CS474_PROJECT04_ALI_INTERPRETER_ADD_H


#include "Computer.h"


//
// ADD
//
class ADD : public Command{

public:
    ADD(Computer *computer);
    ~ADD();
    void execute();
    string getStringRepresentation();

private:
    Computer *computer;
};

#endif //CS474_PROJECT04_ALI_INTERPRETER_ADD_H
