//
// Created by Michal on 5/2/2018.
//

#include "ADD.h"


//
// Constructor
//
ADD::ADD(Computer *comp) : computer{comp} {

}

//
// Destructor
//
ADD::~ADD() {

}

//
// execute()
//
void ADD::execute() {
    if (!computer->isHaltFlag()) {
        computer->add();
        computer->incrementProgramCounter(1);
    }
}

//
// getStringRepresentation()
//
string ADD::getStringRepresentation() {
    return "ADD";
}