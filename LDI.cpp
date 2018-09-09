//
// Created by Michal on 5/2/2018.
//

#include "LDI.h"

//
// Constructor
//
LDI::LDI(Computer *comp, int val) : computer{comp}, value{val} {

}

//
// Destructor
//
LDI::~LDI() {

}


//
// execute()
//
void LDI::execute() {
    if (!computer->isHaltFlag()) {
        computer->setRegA(this->value);
        computer->incrementProgramCounter(1);
    }
}


//
// getStringRepresentation()
//
string LDI::getStringRepresentation() {
    return "LDI " + to_string(value);
}