//
// Created by Michal on 5/2/2018.
//

#include "HLT.h"

//
// Constructor
//
HLT::HLT(Computer *comp) : computer{comp} {

}

//
// Destructor
//
HLT::~HLT() {

}


//
// execute()
//
void HLT::execute() {
    computer->setHaltFlag(true);
}


//
// getStringRepresentation()
//
string HLT::getStringRepresentation() {
    return "HLT";
}