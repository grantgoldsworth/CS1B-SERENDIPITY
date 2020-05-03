/*******************************************
 * AUTHOR   : GRANT GOLDSWORTH
 * ID	    : 1164709
 * PROJECT  : A23
 * DUE DATE : 5/6/2020
*******************************************/

#include "bookType.h"

#ifndef A4_REPORTS_H
#define A4_REPORTS_H

// ReportsFunction functions
void repListing(int&, bookType* []);

void repCost(int& bookCount, bookType *database[]);

void repWholesale(int& bookCount, bookType *database[]);

void repRetail(int&, bookType* []);

void repAge();

void repQty();

#endif //A4_REPORTS_H
