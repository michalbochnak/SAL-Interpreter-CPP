//
// Created by Michal on 5/2/2018.
//

#ifndef CS474_PROJECT04_ALI_INTERPRETER_LDB_H
#define CS474_PROJECT04_ALI_INTERPRETER_LDB_H


#include "Computer.h"


//
// LDB
//
class LDB : public Command {

public:
    LDB(Computer *computer, char symbol);
    ~LDB();
    void execute();
    string getStringRepresentation();

private:
    Computer *computer;
    char symbol;
};


#endif //CS474_PROJECT04_ALI_INTERPRETER_LDB_H
