//
// Michal Bochnak
// Project 04, CS 474
// Assembly Language interpreter
// May 5, 2018
// UIC
//


#include <iostream>
#include "Computer.h"

using namespace std;


//
// displayAuthorInfo()
//
void displayAuthorInfo() {
    cout << endl;
    cout << "---------------------------" << endl;
    cout << " Michal Bochnak" << endl;
    cout << " CS 474, May 5, 2018" << endl;
    cout << " Assembly Language Interpreter" << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << " Program simulates simple Assembly Language" << endl;
    cout << " instructions execution by using virtual hardware." << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << endl;
}


//
// displayMenuOptions()
//
void displayMenuOptions() {
    cout << endl;
    cout << " Commands available: " << endl;
    cout << " l - This command reads a SAL program from a file named input.sal.\n"
            "     The file should be in the same directory as your executable\n"
            "     ALI file. You may assume that the input program is syntactally\n"
            "     correct. The program is stored in internal ALI memory and \n"
            "     displayed on the user’s console." << endl;
    cout << " d - Execute the program in debug mode. This command causes one line\n"
            "     of code to be executed. The PC, registers, bits and the state\n"
            "     of memory are updated as a result of the execution. The value\n"
            "     of the registers, the PC, the bits and the content of memory\n"
            "     after the instruction is executed are diplayed on the user’s\n"
            "     screen." << endl;
    cout << " r - Run the program to completion. This command causes the execution\n"
            "     of program starting from the current PC instruction until the halt\n"
            "     instruction is found or the program reaches its last instruction.\n"
            "     The content of the registers, PC, bits and memory are displayed\n"
            "     on the user’s console." << endl;
    cout << " s - Save the program state. This command causes the content of memory,\n"
            "     the bits and the registers to be saved to a file named output.txt." << endl;
    cout << " p - Print computer state." << endl;
    cout << " a - Print memory state (all 256 locations)." << endl;
    cout << " h - Help." << endl;
    cout << " q - Quits the ALI." << endl;
    cout << endl;
}


//
// main()
//
int main() {

    displayAuthorInfo();

    char menuOption = 'a';
    Computer computer = Computer();

    do {
        cout << endl << "--------------------------------------------";
        cout << endl << "Enter command ('h' for help): ";
        cin >> menuOption;

        if (menuOption == 'l') {
            // load program
            computer = Computer();
            computer.loadProgramIntoMemory();
            computer.displayComputerState();
        }
        else if (menuOption == 'd') {
            // execute one line
            computer.executeNextInstruction();
            computer.displayComputerState();
        }
        else if (menuOption == 'r') {
            // run program until the end
            computer.executeWholeProgram();
            computer.displayComputerState();
        }
        else if (menuOption == 's') {
            // save save computer state to file
            computer.saveStateToFile("output.txt");
        }
        else if (menuOption == 'p') {
            // display computer state
            computer.displayComputerState();
        }
        else if (menuOption == 'a') {
            // display memory state all
            computer.displayMemoryStateAll();
        }
        else if (menuOption == 'h') {
            // show help
            displayMenuOptions();
        }
        else if (menuOption != 'q') {
            // wrong command
            cout << " *** Invalid command. ***" << endl;
            displayMenuOptions();
        }
    } while (menuOption != 'q');

    cout << endl << "-------" << endl;
    cout << "Done." << endl;
    cout << "-------" << endl << endl;

    return 0;
}