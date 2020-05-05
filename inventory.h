/*******************************************
 * AUTHOR   : GRANT GOLDSWORTH
 * ID	    : 1164709
 * PROJECT  : A23
 * DUE DATE : 5/6/2020
*******************************************/
#include <string>
#include "bookType.h"
using namespace std;

#ifndef A4_INVENTORY_H
#define A4_INVENTORY_H

// InventoryFunction functions
int lookUpBook(bookType* []
                );

int searchDatabase(bookType* [],
                string,
                char);

void addBook(bookType* []);

string getUniqueISBN(bookType* []);

void editBook(bookType* []
              );

void deleteBook(bookType* []);

#endif //A4_INVENTORY_H
