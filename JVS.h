//
// Created by Michal on 5/2/2018.
//

#ifndef CS474_PROJECT04_ALI_INTERPRETER_JVS_H
#define CS474_PROJECT04_ALI_INTERPRETER_JVS_H


#include "Computer.h"


//
// JVS
//
class JVS : public Command {

public:
    JVS(Computer *computer, int instNum);
    ~JVS();
    void execute();
    string getStringRepresentation();

private:
    Computer *computer;
    int instNum;
};


#endif //CS474_PROJECT04_ALI_INTERPRETER_JVS_H
