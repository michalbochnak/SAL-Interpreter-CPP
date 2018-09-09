//
// Created by Michal on 5/2/2018.
//

#include <sstream>
#include "LDB.h"


//
// Constructor
//
LDB::LDB(Computer *comp, char val) : computer{comp}, symbol{val} {

}

//
// Destructor
//
LDB::~LDB() {

}


//
// execute()
//
void LDB::execute() {
    if (!computer->isHaltFlag()) {
        computer->loadSymbolValueToRegB(symbol);
        computer->incrementProgramCounter(1);
    }
}


//
// getStringRepresentation()
//
string LDB::getStringRepresentation() {
    stringstream ss;
    string temp;
    ss << symbol;
    ss >>  temp;
    return "LDB " + temp;
}