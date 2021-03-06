/*******************************************
 * AUTHOR   : GRANT GOLDSWORTH
 * ID	    : 1164709
 * PROJECT  : A23
 * DUE DATE : 5/6/2020
*******************************************/

#include <iostream>
#include "selectionSort.h"
using namespace std;

#ifndef A4_BOOKTYPE_H
#define A4_BOOKTYPE_H

class bookType {

    friend ostream& operator<<(ostream&, const bookType&);
    friend istream& operator>>(istream&, bookType&);

private:
    string bookTitle;
    string isbn;
    string author;
    string publisher;
    string dateAdded;
    int    qtyOnHand;
    float  wholesale;
    float  retail;

    static int bookCount;

public:
    /***********************************************
     * compareCode
     * Used to determine what attributes to compare
     * in overloaded boolean operators
     *
     *  0   bookTitle
     *  1   isbn
     *  2   author
     *  3   publisher
     *  4   dateAdded
     *  5   qtyOnHand
     *  6   wholesale
     *  7   retail
     *
     ***********************************************/
    static int compareCode;


    /****** CONSTRUCTORS ******/

    bookType();

    // uber constructor
    //       title   isbn    author  pub     date    qoh  whole  retail
    bookType(string, string, string, string, string, int, float, float);

    // copy constructor
    bookType(const bookType& otherBook);


    /****** SETTERS ******/

    void setBookTitle(string);

    void setISBN(string);

    void setAuthor(string);

    void setPublisher(string);

    void setDateAdded(string);

    void setQtyOnHand(int);

    void setWholesale(float);

    void setRetail(float);


    /****** GETTERS ******/

    string getBookTitle() const;

    string getISBN() const;

    string getAuthor() const;

    string getPublisher() const;

    string getDateAdded() const;

    int getQtyOnHand() const;

    float getWholesale() const;

    float getRetail() const;

    static int getBookCount();

    // destructor
    ~bookType();

    /****** OVERLOADS ******/
    bool operator<(const bookType& otherBook) const;
    //Overload the less than operator.
    //Postcondition: Returns true if the quantity of this book
    // is less than the quantity of
    // otherBook, otherwise it returns false.

    bool operator>(const bookType &otherBook) const;
    //Overload the greater than operator.
    //Postcondition: Returns true if the quantity of this book
    // is greater than the quantity of
    // otherBook, otherwise it returns false.


    bool operator<=(const bookType& otherBook) const;
    //Overload the less than or equal to operator.
    //Postcondition: Returns true if the quantity of this book
    // is less than or equal to the quantity of
    // otherBook, otherwise it returns false.

    bool operator>=(const bookType& otherBook) const;
    //Overload the greater than or equal to operator.
    //Postcondition: Returns true if the quantity of this book
    // is greater than or equal to the quantity of
    // otherBook, otherwise it returns false.

    bool operator==(const bookType& otherBook) const;
    //Overload the equality operator.
    //Postcondition: Returns true if the quantity of this book
    // is  equal to the quantity of
    // otherBook, otherwise it returns false.

    bool operator!=(const bookType& otherBook) const;
    //Overload the equality operator.
    //Postcondition: Returns true if the quantity of this book
    // is  not equal to the quantity of
    // otherBook, otherwise it returns false.
};



#endif //A4_BOOKTYPE_H