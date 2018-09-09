//
// Created by Michal on 5/2/2018.
//


#pragma once

#ifndef CS474_PROJECT04_ALI_INTERPRETER_LDI_H
#define CS474_PROJECT04_ALI_INTERPRETER_LDI_H

#include "Computer.h"


//
// LDI
//
class LDI : public Command {

public:
    LDI(Computer *computer, int value);
    ~LDI();
    void execute();
    string getStringRepresentation();

private:
    Computer *computer;
    int value;

};




#endif //CS474_PROJECT04_ALI_INTERPRETER_LDI_H
