/*******************************************
 * AUTHOR   : GRANT GOLDSWORTH
 * ID	    : 1164709
 * PROJECT  : A23
 * DUE DATE : 5/6/2020
*******************************************/
#include <string>
#include "bookType.h"
#include "unorderedLinkedList.h"
using namespace std;

#ifndef A4_INVENTORY_H
#define A4_INVENTORY_H

// InventoryFunction functions
int lookUpBook(unorderedLinkedList<bookType>&);

int searchDatabase(unorderedLinkedList<bookType>&,
                string,
                char);

void addBook(unorderedLinkedList<bookType>&);

string getUniqueISBN(unorderedLinkedList<bookType>&);

void editBook(unorderedLinkedList<bookType>&);

void deleteBook(unorderedLinkedList<bookType>&);

#endif //A4_INVENTORY_H
