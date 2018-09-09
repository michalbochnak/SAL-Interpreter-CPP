//
// Michal Bochnak
// Project 04, CS 474
// Assembly Language interpreter
// May 5, 2018
// UIC
//

#ifndef CS474_PROJECT04_ALI_INTERPRETER_XCH_H
#define CS474_PROJECT04_ALI_INTERPRETER_XCH_H

#include "Computer.h"


//
// XCH
//
class XCH : public Command {
public:
    XCH(Computer *comp);
    ~XCH();
    void execute();
    string getStringRepresentation();

private:
    Computer *computer;

};


#endif //CS474_PROJECT04_ALI_INTERPRETER_XCH_H
