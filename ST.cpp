//
// Created by Michal on 5/2/2018.
//

#include <sstream>
#include "ST.h"

//
// Constructor
//
ST::ST(Computer *comp, char val) : computer{comp}, symbol{val} {

}

//
// Destructor
//
ST::~ST() {

}


//
// execute()
//
void ST::execute() {
    if (!computer->isHaltFlag()) {
        computer->storeAtSymbol(symbol);
        computer->incrementProgramCounter(1);
    }
}


//
// getStringRepresentation()
//
string ST::getStringRepresentation() {
    stringstream ss;
    string temp;
    ss << symbol;
    ss >>  temp;
    return "ST " + temp;
}