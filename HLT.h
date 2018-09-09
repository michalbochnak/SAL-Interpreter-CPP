//
// Created by Michal on 5/2/2018.
//

#ifndef CS474_PROJECT04_ALI_INTERPRETER_HLT_H
#define CS474_PROJECT04_ALI_INTERPRETER_HLT_H


#include "Computer.h"


//
// HLT
//
class HLT : public Command{

public:
    HLT(Computer *computer);
    ~HLT();
    void execute();
    string getStringRepresentation();

private:
    Computer *computer;
};


#endif //CS474_PROJECT04_ALI_INTERPRETER_HLT_H
