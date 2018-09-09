//
// Michal Bochnak
// Project 04, CS 474
// Assembly Language interpreter
// May 5, 2018
// UIC
//



#ifndef CS474_PROJECT04_ALI_INTERPRETER_COMMAND_H
#define CS474_PROJECT04_ALI_INTERPRETER_COMMAND_H

#include <string>

using namespace std;


//
// Command
//
// Base class for every Simple Assembly Language (SAL) instruction
//
class Command {

public:
    Command();
    virtual ~Command();

    virtual void execute();
    virtual string getStringRepresentation();

protected:


private:

};


#endif //CS474_PROJECT04_ALI_INTERPRETER_COMMAND_H
