/*******************************************
 * AUTHOR   : GRANT GOLDSWORTH
 * ID	    : 1164709
 * PROJECT  : A5
 * DUE DATE : 2/10/2020
*******************************************/

#include <iostream>
#include <iomanip>
#include <windows.h>
#include <string>

#include "inventory.h"
#include "reports.h"
#include "bookType.h"
using namespace std;

#ifndef A1_FUNCTIONS_H
#define A1_FUNCTIONS_H

const int DBSIZE = 20; // GLOBAL CONSTANT FOR PROGRAM - USED AS TESTING DATABASE SIZE

// helper functions used throughout entire program
char GetChoice(int min,
                int max);

string tolowerstring(string);

void BookInformation(bookType, bool cashier = false);

// main menu modules
void CashierFunction(int &, bookType []);

void InventoryFunction(int&,
                        bookType []);

void ReportsFunction();



#endif //A1_FUNCTIONS_H
