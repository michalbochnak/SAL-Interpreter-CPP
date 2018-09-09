//
// Created by Michal on 5/2/2018.
//

#ifndef CS474_PROJECT04_ALI_INTERPRETER_ST_H
#define CS474_PROJECT04_ALI_INTERPRETER_ST_H


#include "Computer.h"


//
// ST
//
class ST : public Command{

public:
    ST(Computer *computer, char sym);
    ~ST();
    void execute();
    string getStringRepresentation();

private:
    Computer *computer;
    char symbol;
};


#endif //CS474_PROJECT04_ALI_INTERPRETER_ST_H
