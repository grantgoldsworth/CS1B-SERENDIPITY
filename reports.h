/*******************************************
 * AUTHOR   : GRANT GOLDSWORTH
 * ID	    : 1164709
 * PROJECT  : A5
 * DUE DATE : 2/10/2020
*******************************************/

#include "bookType.h"

#ifndef A4_REPORTS_H
#define A4_REPORTS_H

// ReportsFunction functions
void repListing(int&, bookType* []);

void repCost(int& bookCount, bookType *database[]);

void repWholesale(int& bookCount, bookType *database[]);

void repRetail();

void repAge();

void repQty();

#endif //A4_REPORTS_H
