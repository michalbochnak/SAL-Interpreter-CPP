//
// Created by Michal on 5/2/2018.
//

#ifndef CS474_PROJECT04_ALI_INTERPRETER_JMP_H
#define CS474_PROJECT04_ALI_INTERPRETER_JMP_H


#include "Computer.h"


//
// JMP
//
class JMP : public Command {

public:
    JMP(Computer *computer, int instNum);
    ~JMP();
    void execute();
    string getStringRepresentation();

private:
    Computer *computer;
    int instNum;
};


#endif //CS474_PROJECT04_ALI_INTERPRETER_JMP_H
