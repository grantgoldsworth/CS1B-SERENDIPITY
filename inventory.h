/*******************************************
 * AUTHOR   : GRANT GOLDSWORTH
 * ID	    : 1164709
 * PROJECT  : A5
 * DUE DATE : 2/10/2020
*******************************************/

#include <string>
#include "bookType.h"
using namespace std;

#ifndef A4_INVENTORY_H
#define A4_INVENTORY_H

// InventoryFunction functions
int lookUpBook(int,
               bookType* []
                );

int searchDatabase(bookType* [],
                int,
                string,
                char);

void addBook(int&,
             bookType* []
                );

string getUniqueISBN(const bookType [],
                     int);

void editBook(const int&,
              bookType* []
              );

void deleteBook(int&,
                bookType* []);

#endif //A4_INVENTORY_H
