//
// Created by Michal on 5/2/2018.
//

#include <sstream>
#include "LDA.h"


//
// Constructor
//
LDA::LDA(Computer *comp, char val) : computer{comp}, symbol{val} {

}

//
// Destructor
//
LDA::~LDA() {

}


//
// execute()
//
void LDA::execute() {
    if (!computer->isHaltFlag()) {
        computer->loadSymbolValueToRegA(symbol);
        computer->incrementProgramCounter(1);
    }
}


//
// getStringRepresentation()
//
string LDA::getStringRepresentation() {
    stringstream ss;
    string temp;
    ss << symbol;
    ss >>  temp;
    return "LDA " + temp;
}