//
// Created by Michal on 5/2/2018.
//

#ifndef CS474_PROJECT04_ALI_INTERPRETER_LDA_H
#define CS474_PROJECT04_ALI_INTERPRETER_LDA_H


#include "Computer.h"


//
// LDA
//
class LDA : public Command {

public:
    LDA(Computer *computer, char symbol);
    ~LDA();
    void execute();
    string getStringRepresentation();

private:
    Computer *computer;
    char symbol;
};


#endif //CS474_PROJECT04_ALI_INTERPRETER_LDA_H
