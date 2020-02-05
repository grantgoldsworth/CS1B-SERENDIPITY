/*******************************************
 * AUTHOR   : GRANT GOLDSWORTH
 * ID	    : 1164709
 * PROJECT  : A4
 * DUE DATE : 1/27/2020
*******************************************/

#include <string>
using namespace std;

#ifndef A4_INVENTORY_H
#define A4_INVENTORY_H

// InventoryFunction functions
int lookUpBook(int,
                const string [],
                const string [],
                const string [],
                const string [],
                const string [],
                const int    [],
                const double [],
                const double []);

int searchArray(const string [],
                const string [],
                const string [],
                const string [],
                const string [],
                const string [],
                const int [],
                const double [],
                const double [],
                string,
                int);

void addBook(int&,
                string [],
                string [],
                string [],
                string [],
                string [],
                int    [],
                double [],
                double []
                );

string getUniqueISBN(const string [], const string [], int);

void editBook(int&,
              string [],
              string [],
              string [],
              string [],
              string [],
              int    [],
              double [],
              double [],
              int);

void deleteBook(int&,
                string [],
                string [],
                string [],
                string [],
                string [],
                int    [],
                double [],
                double [],
                int );

#endif //A4_INVENTORY_H
