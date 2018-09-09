//
// Created by Michal on 5/2/2018.
//

#ifndef CS474_PROJECT04_ALI_INTERPRETER_DEC_H
#define CS474_PROJECT04_ALI_INTERPRETER_DEC_H


#include "Computer.h"


//
// DEC
//
class DEC : public Command {

public:
    DEC(Computer *computer, char symbol);
    ~DEC();
    void execute();
    string getStringRepresentation();

private:
    Computer *computer;
    char symbol;
};


#endif //CS474_PROJECT04_ALI_INTERPRETER_DEC_H
