//
// Created by Michal on 5/2/2018.
//

#ifndef CS474_PROJECT04_ALI_INTERPRETER_SYMBOL_H
#define CS474_PROJECT04_ALI_INTERPRETER_SYMBOL_H

#include "Computer.h"

//
// Symbol
//
class Symbol : public Command {

    public:
        Symbol(Computer *computer, char symbol, long long value);
        ~Symbol();
        void execute();
        string getStringRepresentation();

    private:
        Computer *computer;
        char symbol;
        long long value;

};


#endif //CS474_PROJECT04_ALI_INTERPRETER_SYMBOL_H
