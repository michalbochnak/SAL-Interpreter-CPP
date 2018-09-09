//
// Created by Michal on 5/2/2018.
//

#include "JVS.h"

//
// Constructor
//
JVS::JVS(Computer *comp, int val) : computer{comp}, instNum{val} {

}

//
// Destructor
//
JVS::~JVS() {

}


//
// execute()
//
void JVS::execute() {
    if (!computer->isHaltFlag()) {
        if (computer->getOverflowBit() == 1) {
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
string JVS::getStringRepresentation() {
    return "JVS " + to_string(instNum);
}