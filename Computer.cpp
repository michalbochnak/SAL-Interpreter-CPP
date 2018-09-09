//
// Michal Bochnak
// Project 04, CS 474
// Assembly Language interpreter
// May 5, 2018
// UIC
//


#include <sstream>
#include "Computer.h"
#include "LDI.h"
#include "XCH.h"
#include "DEC.h"
#include "ST.h"
#include "LDA.h"
#include "LDB.h"
#include "JMP.h"
#include "ADD.h"
#include "JZS.h"
#include "JVS.h"
#include "HLT.h"
#include "Symbol.h"


//
// Constructor
//
Computer::Computer() : programCounter{0}, regA{0}, regB{0}, zeroBit{0},
    overflowBit{0}, haltFlag{false} {

    // set all memory to nullptr
    setWholeMemoryToNullPtr();
}


//
// Destructor
//
Computer::~Computer() {
    // FIXME
    for (int i = 0; i < 256; ++i)
        delete memoryRAM[i];
}


//
// getMemoryRAM()
//
const Command *Computer::getMemoryRAM() const {
    return *memoryRAM;
}

//
// isHaltFlag()
//
bool Computer::isHaltFlag() const {
    return haltFlag;
}


//
// getOverflowBit()
//
short Computer::getOverflowBit() const {
    return overflowBit;
}


//
// getZeroBit()
//
short Computer::getZeroBit() const {
    return zeroBit;
}


//
// getOverflowBit()
//
short Computer::getProgramCounter() const {
    return programCounter;
}


//
// getRegA()
//
long long Computer::getRegA() const {
    return regA;
}


//
// getRegB()
//
long long Computer::getRegB() const {
    return regB;
}


//
// getTable()
//
const map<char, int> &Computer::getTable() const {
    return table;
}


//
// setHaltFlag()
//
void Computer::setHaltFlag(bool haltFlag) {
    Computer::haltFlag = haltFlag;
}


//
// setOverflowBit()
//
void Computer::setOverflowBit(bool overflowBit) {
    Computer::overflowBit = overflowBit;
}


//
// setZeroBit()
//
void Computer::setZeroBit(bool zeroBit) {
    Computer::zeroBit = zeroBit;
}


//
// setProgramCounter
//
void Computer::setProgramCounter(short programCounter) {
    Computer::programCounter = programCounter;
}


//
// setRegA()
//
void Computer::setRegA(int regA) {
    Computer::regA = regA;
}


//
// setRegB()
//
void Computer::setRegB(int regB) {
    Computer::regB = regB;
}


//
// getTable()
//
void Computer::setTable(const map<char, int> &table) {
    Computer::table = table;
}


//
// displayMemoryStateAll()
//
void Computer::displayMemoryStateAll() {
    cout << endl << "Memory: " << endl;
    for (int i = 0; i < 256; ++i) {
        if (this->programCounter == i)
            cout << ">" ;
        else
            cout << " ";
        if (memoryRAM[i] != nullptr) {
            cout << setw(3) << i << ": " << setw(8)
                 << memoryRAM[i]->getStringRepresentation();
        }
        else {
            cout << setw(3) << right << i << setw(10) << left << ": null";
        }
        if ((i+1) % 8 == 0) cout << endl;
    }
    cout << endl;
}


//
// displayMemoryStateUsed()
//
void Computer::displayMemoryStateUsed() {
    // FIXME Symbol: X 12515, check what should be displayed compare
    // to default long value
    cout << endl << "       Memory State: " << endl;
    for (int i = 0; i < 256; ++i) {
        if (memoryRAM[i] != nullptr) {
            if (this->programCounter == i)
                cout << "    >" ;
            else
                cout << "     ";

            string temp = memoryRAM[i]->getStringRepresentation();
            if (temp[1] == ' ') {
                string temp_2 = temp.substr(temp.find(" ") + 1);
                long long num = std::stoll(temp_2);
                if (num == 1099511627775) {
                    cout << setw(3) << i << ": " << temp[0] << endl;
                }
                else {
                    cout << setw(3) << i << ": " << num << endl;
                }
            }
            else {
                cout << setw(3) << i << ": " << temp << endl;
            }
        }
    }
}


//
// displayComputerState()
//
void Computer::displayComputerState() {
    this->displayMemoryStateUsed();
    cout << setw(22) << right;
    cout << endl;
    cout << "Accumulator: " << this->regA << endl;
    cout << setw(22) << right;
    cout << "Additional register: " << this->regB << endl;
    cout << setw(22) << right;
    cout << "Program counter: " << this->programCounter <<endl;
    cout << setw(22) << right;
    cout << "Zero bit: " << this->zeroBit <<endl;
    cout << setw(22) << right;
    cout << "Overflow bit: " << this->overflowBit << endl;
}


//
// setWholeMemoryToNullPtr()
//
void Computer::setWholeMemoryToNullPtr() {
    for (int i = 0; i < 256; ++i)
        memoryRAM[i] = nullptr;
}


//
// loadProgramIntoMemory()
//
void Computer::loadProgramIntoMemory() {
    ifstream inFile;
    inFile.open("input.sal");
    if (!inFile) {
        cout << "Opening file input.sal failed." << endl;
        exit(-1);
    }
    string line;
    // get id

    short index = 0;
    while (getline(inFile, line)) {
        memoryRAM[index++] = instantiateInstructionObject(line);
    }
}


//
// incrementProgramCounter()
//
void Computer::incrementProgramCounter(int val) {
    this->programCounter = this->programCounter + val;
}


//
// executeWholeProgram()
//
void Computer::executeWholeProgram() {
    while (!this->isHaltFlag()) {
        executeNextInstruction();
    }
}


//
// executeNextInstruction()
//
void Computer::executeNextInstruction() {
    if (memoryRAM[this->programCounter] != nullptr)
        memoryRAM[this->programCounter]->execute();
    else {
        this->setHaltFlag(true);
    }
}


//
// instantiateInstructionObject()
//
// Returns the instance of the Command object based on
// string instruction from parameter
//
Command* Computer::instantiateInstructionObject(string line) {

    string instrType = line.substr(0, 3);

    if (instrType == "DEC") {
        return new DEC(this, line[4]);
    } else if (instrType == "LDA") {
        return new LDA(this, line[4]);
    } else if (instrType == "LDB") {
        return new LDB(this, line[4]);
    } else if (instrType == "LDI") {
        return new LDI(this, stoi(line.substr(4)));
    } else if (instrType == "XCH") {
        return new XCH(this);
    } else if (instrType == "JMP") {
        return new JMP(this, stoi(line.substr(4)));
    } else if (instrType == "JZS") {
        return new JZS(this, stoi(line.substr(4)));
    } else if (instrType == "JVS") {
        return new JVS(this, stoi(line.substr(4)));
    } else if (instrType == "HLT") {
        return new HLT(this);
    } else if (instrType == "ADD") {
        return new ADD(this);
    } else {
        // check if instruction is "ST"
        instrType = line.substr(0, 2);
        if (instrType == "ST") {
            return new ST(this, line[3]);
        }
    }

    // instruction invalid
    return nullptr;
}


//
// addNewSymbolToTable()
//
void Computer::addNewSymbolToTable(char sym, int val) {
    this->table.insert(std::make_pair(sym, val));
}


//
// setMemory()
//
void Computer::setMemory(int index, Command *cmd) {
    if (inMemoryRange(index)) {
        this->memoryRAM[index] = cmd;
    }
}


//
// inMemoryRange()
//
bool Computer::inMemoryRange(int index) {
    return index >= 0 && index <= 255;
}


//
// storeAtSymbol()
//
void Computer::storeAtSymbol(char symb) {
    short index = this->findSymbolIndex(symb);
    table.erase(symb);
    table.insert(std::make_pair(symb, this->regA));
    if (index != -1) {
        delete this->memoryRAM[index];
        this->memoryRAM[index] = new Symbol(this, symb, this->regA);
    }
}


//
// findSymbolIndex()
//
short Computer::findSymbolIndex(char sym) {

    for (int i = 0; i <= 255; ++i) {
        if (memoryRAM[i] != nullptr) {
            string temp = memoryRAM[i]->getStringRepresentation();
            if (temp[0] == sym)
                return i;
        }
    }

    return -1;
}


//
// loadSymbolValueToRegA()
//
void Computer::loadSymbolValueToRegA(char sym) {
    this->regA = table[sym];
}


//
// loadSymbolValueToRegB()
//
void Computer::loadSymbolValueToRegB(char sym) {
    this->regB = table[sym];
}


//
// add()
//
void Computer::add() {
    // Update register A value and overflow bit
    long long result = this->regA + this->regB;
    if (isOverflow(result)) {
        this->overflowBit = 1;
        this->regA = calculateOverflowValue(result);
    }
    else {
        this->overflowBit = 0;
        this->regA = this->regA + this->regB;
    }

    // update zero bit
    this->zeroBit = (this->regA == 0) ? 1 : 0;
}


//
// isOverFlow()
//
bool Computer::isOverflow(long long value) {
    return isPositiveOverflow(value) || isNegativeOverflow(value);
}


//
// isPositiveOverflow()
//
bool Computer::isPositiveOverflow(long long value) {
    return value > 2147483647;
}


//
// isNegativeOverflow()
//
bool Computer::isNegativeOverflow(long long value) {
    return value < -2147483648;
}


//
// calculateOverflowValue()
//
long Computer::calculateOverflowValue(long long value) {
    if (isPositiveOverflow(value)) {
        return (-2147483648 + (-2147483648 + value));
    }
    else if (isNegativeOverflow(value)) {
        return ((2*(2147483648)) + value);
    }
}


//
// saveStateToFile()
//
void Computer::saveStateToFile(string filename) {
    ofstream myFile;
    myFile.open(filename);

    myFile << "Computer state:\r\n";
    // save memory state
    myFile << "       Memory State:\r\n";
    for (int i = 0; i < 256; ++i) {
        if (memoryRAM[i] != nullptr) {
            if (this->programCounter == i)
                myFile << "    >" ;
            else
                myFile << "     ";

            string temp = memoryRAM[i]->getStringRepresentation();
            if (temp[1] == ' ') {
                temp = temp.substr(temp.find(" "));
                long long num = stoll(temp);
                if (num == 1099511627775) {
                    myFile << setw(3) << i << ": " << temp[0] << "\r\n";
                }
                else {
                    myFile << setw(3) << i << ": " << num << "\r\n";
                }
            }
            else {
                myFile << setw(3) << i << ": " << temp << "\r\n";
            }
        }
    }

    // save other computer's variables
    myFile << "\r\n";
    myFile << setw(22) << right;
    myFile << "Accumulator: " << this->regA << "\r\n";
    myFile << setw(22) << right;
    myFile << "Additional register: " << this->regB << "\r\n";
    myFile << setw(22) << right;
    myFile << "Program counter: " << this->programCounter << "\r\n";
    myFile << setw(22) << right;
    myFile << "Zero bit: " << this->zeroBit << "\r\n";
    myFile << setw(22) << right;
    myFile << "Overflow bit: " << this->overflowBit << "\r\n";
}