//
// Created by Michal on 5/2/2018.
//

#ifndef CS474_PROJECT04_ALI_INTERPRETER_JZS_H
#define CS474_PROJECT04_ALI_INTERPRETER_JZS_H


#include "Computer.h"


//
// JZS
//
class JZS : public Command {

public:
    JZS(Computer *computer, int instNum);
    ~JZS();
    void execute();
    string getStringRepresentation();

private:
    Computer *computer;
    int instNum;
};



#endif //CS474_PROJECT04_ALI_INTERPRETER_JZS_H
