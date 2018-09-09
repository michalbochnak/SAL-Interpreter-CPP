//
// Created by Michal on 5/2/2018.
//

#include <sstream>
#include "Symbol.h"

//
// Constructor
//
Symbol::Symbol(Computer *comp, char sym, long long val)
        : computer{comp}, symbol{sym}, value{val} {

}

//
// Destructor
//
Symbol::~Symbol() {

}


//
// execute()
//
void Symbol::execute() {
    computer->setHaltFlag(true);
    //computer->incrementProgramCounter(1);
}


//
// getStringRepresentation()
//
string Symbol::getStringRepresentation() {
    stringstream ss;
    string temp;
    ss << symbol;
    ss >>  temp;
    return temp + " " + to_string(value);
}