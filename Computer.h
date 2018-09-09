//
// Michal Bochnak
// Project 04, CS 474
// Assembly Language interpreter
// May 5, 2018
// UIC
//


#ifndef CS474_PROJECT04_ALI_INTERPRETER_COMPUTER_H
#define CS474_PROJECT04_ALI_INTERPRETER_COMPUTER_H

#include "Command.h"
#include <map>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;



//
// Computer
//
// Class to represent a basic hardware for the computer
//
class Computer {

public:
    Computer();
    ~Computer();

    const Command *getMemoryRAM() const;
    bool isHaltFlag() const;
    short getOverflowBit() const;
    short getZeroBit() const;
    short getProgramCounter() const;
    long long getRegA() const;
    long long getRegB() const;
    const map<char, int> &getTable() const;

    void setHaltFlag(bool haltFlag);
    void setOverflowBit(bool overflowBit);
    void setZeroBit(bool zeroBit);
    void setProgramCounter(short programCounter);
    void setRegA(int regA);
    void setRegB(int regB);
    void setTable(const map<char, int> &table);
    void setMemory(int index, Command *cmd);

    void displayMemoryStateAll();
    void displayComputerState();
    void loadProgramIntoMemory();
    void displayMemoryStateUsed();
    void incrementProgramCounter(int val);
    void executeWholeProgram();
    void executeNextInstruction();
    void addNewSymbolToTable(char sym, int val);
    bool inMemoryRange(int index);
    void storeAtSymbol(char sym);
    short findSymbolIndex(char symbol);
    void loadSymbolValueToRegA(char sym);
    void loadSymbolValueToRegB(char sym);
    void add();
    bool isOverflow(long long value);
    bool isPositiveOverflow(long long  value);
    bool isNegativeOverflow(long long value);
    long calculateOverflowValue(long long value);
    void saveStateToFile(string filename);


private:
    Command *memoryRAM[256];
    short programCounter;
    long long regA;
    long long regB;
    map<char, int> table;
    int zeroBit;
    int overflowBit;
    bool haltFlag;

    void setWholeMemoryToNullPtr();
    Command* instantiateInstructionObject(string line);

};


#endif //CS474_PROJECT04_ALI_INTERPRETER_COMPUTER_H
