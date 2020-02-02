/*******************************************
 * AUTHOR   : GRANT GOLDSWORTH
 * ID	    : 1164709
 * PROJECT  : A4
 * DUE DATE : 1/27/2020
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

char GetChoice(int min, int max);

string tolowerstring(string);

void CashierFunction();

void InventoryFunction(const int&,
                        int&,
                        string [],
                        string [],
                        string [],
                        string [],
                        string [],
                        int [],
                        double [],
                        double []);

void ReportsFunction();

void BookInformation(string, string, string, string, string, int, double, double);

#endif //A1_FUNCTIONS_H
