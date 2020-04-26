/*******************************************
 * AUTHOR   : GRANT GOLDSWORTH
 * ID	    : 1164709
 * PROJECT  : A5
 * DUE DATE : 2/10/2020
*******************************************/

#include <string>
#include <iostream>
using namespace std;

#ifndef A4_BOOKTYPE_H
#define A4_BOOKTYPE_H

struct bookType {
    string bookTitle;
    string isbn;
    string author;
    string publisher;
    string dateAdded;
    int    qtyOnHand;
    float  wholesale;
    float  retail;
};

void SetBookTitle(bookType*, string);

void SetISBN(bookType*, string);

void SetAuthor(bookType*, string);

void SetPublisher(bookType*, string);

void SetDateAdded(bookType*, string);

void SetQtyOnHand(bookType*, int);

void SetWholesale(bookType*, float);

void SetRetail(bookType*, float);


#endif //A4_BOOKTYPE_H