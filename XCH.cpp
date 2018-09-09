//
// Michal Bochnak
// Project 04, CS 474
// Assembly Language interpreter
// May 5, 2018
// UIC
//

#include "XCH.h"


//
// Constructor
//
XCH::XCH(Computer *comp) : computer{comp} {

}

//
// Destructor
//
XCH::~XCH() {

}


//
// execute()
//
void XCH::execute() {
    if (!computer->isHaltFlag()) {
        int temp = computer->getRegA();
        computer->setRegA(computer->getRegB());
        computer->setRegB(temp);
        computer->incrementProgramCounter(1);
    }
}


//
// getStringRepresentation()
//
string XCH::getStringRepresentation() {
    return "XCH";
}