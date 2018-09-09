//
// Created by Michal on 5/2/2018.
//

#include "JZS.h"

//
// Constructor
//
JZS::JZS(Computer *comp, int val) : computer{comp}, instNum{val} {

}

//
// Destructor
//
JZS::~JZS() {

}


//
// execute()
//
void JZS::execute() {
    if (!computer->isHaltFlag()) {
        if (computer->getZeroBit() == 1) {
            computer->setProgramCounter(instNum);
        }
        else {
            computer->incrementProgramCounter(1);
        }
    }
}


//
// getStringRepresentation()
//
string JZS::getStringRepresentation() {
    return "JZS " + to_string(instNum);
}