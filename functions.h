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
using namespace std;

#ifndef A1_FUNCTIONS_H
#define A1_FUNCTIONS_H

const int DBSIZE = 20; // GLOBAL CONSTANT FOR PROGRAM - USED AS TESTING DATABASE SIZE

// helper functions used throughout entire program
char GetChoice(int min,
                int max);

string tolowerstring(string);

void BookInformation(string,
                     string,
                     string,
                     string,
                     string,
                     int,
                     double,
                     double);

// main menu modules
void CashierFunction();

void InventoryFunction(int&,
                        string [],
                        string [],
                        string [],
                        string [],
                        string [],
                        int [],
                        double [],
                        double []);

void ReportsFunction();



#endif //A1_FUNCTIONS_H
