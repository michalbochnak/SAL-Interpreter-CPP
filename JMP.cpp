//
// Created by Michal on 5/2/2018.
//

#include "JMP.h"

//
// Constructor
//
JMP::JMP(Computer *comp, int val) : computer{comp}, instNum{val} {

}

//
// Destructor
//
JMP::~JMP() {

}


//
// execute()
//
void JMP::execute() {
    if (!computer->isHaltFlag()) {
        computer->setProgramCounter(instNum);
    }
}


//
// getStringRepresentation()
//
string JMP::getStringRepresentation() {
    return "JMP " + to_string(instNum);
}
