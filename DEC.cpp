//
// Created by Michal on 5/2/2018.
//

#include <sstream>
#include "DEC.h"
#include "Symbol.h"

//
// Constructor
//
DEC::DEC(Computer *comp, char val) : computer{comp}, symbol{val} {

}

//
// Destructor
//
DEC::~DEC() {

}


//
// execute()
//
void DEC::execute() {
    if (!computer->isHaltFlag()) {
        computer->addNewSymbolToTable(symbol, 0);
        computer->setMemory(computer->getProgramCounter(),
                            new Symbol(computer, this->symbol, 1099511627775));
        computer->incrementProgramCounter(1);
        delete this;
    }
}


//
// getStringRepresentation()
//
string DEC::getStringRepresentation() {
    stringstream ss;
    string temp;
    ss << symbol;
    ss >>  temp;
    return "DEC " + temp;
}