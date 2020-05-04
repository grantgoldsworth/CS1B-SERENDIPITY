/*******************************************
 * AUTHOR   : GRANT GOLDSWORTH
 * ID	    : 1164709
 * PROJECT  : A23
 * DUE DATE : 5/6/2020
*******************************************/

#include "bookType.h"

//int bookCount = 0;

/****** CONSTRUCTORS ******/

/******************************************************************************
 * FUNCTION - professorType::professorType()
 * ____________________________________________________________________________
 * Default constructor overload. Sets all parameters to empty placeholders
 * ===> returns nothing.
 *
 * PRE-CONDITIONS
 *  The following must be defined before function call:
 *
 * POST-CONDITIONS
 *      new instance of bookType is created
 ******************************************************************************/

bookType::bookType() {
    bookTitle   = "EMPTY";
    isbn        = "EMPTY";
    author      = "EMPTY";
    publisher   = "EMPTY";
    dateAdded   = "EMPTY";
    qtyOnHand   = 0;
    wholesale   = 0.0;
    retail      = 0.0;
}




/******************************************************************************
 * FUNCTION - professorType::professorType(string, string, string, string, string
 *                                          int, float, float)
 * ____________________________________________________________________________
 * Uber constructor. Takes arguments for all members of bookType and sets them
 * accordingly
 * ===> returns nothing.
 *
 * PRE-CONDITIONS
 *  The following must be defined before function call:
 *
 * POST-CONDITIONS
 *      new instance of bookType is created
 ******************************************************************************/

bookType::bookType(string t, string i, string a, string p, string dA, int qoh, float w, float r) {
    bookTitle   = t;
    isbn        = i;
    author      = a;
    publisher   = p;
    dateAdded   = dA;
    qtyOnHand   = qoh;
    wholesale   = w;
    retail      = r;
}




/******************************************************************************
 * FUNCTION - bookType::bookType(copy)
 * ____________________________________________________________________________
 * Copy constructor. Copies values of parameter bookType object into members
 * of the new instance it is creating
 * ===> returns nothing.
 *
 * PRE-CONDITIONS
 *  The following must be defined before function call:
 *
 * POST-CONDITIONS
 *      new instance of bookType is created
 ******************************************************************************/

bookType::bookType(const bookType& otherBook) {
    /*
    bookTitle   = otherBook.getBookTitle();
    isbn        = otherBook.getISBN();
    author      = otherBook.getAuthor();
    publisher   = otherBook.getPublisher();
    dateAdded   = otherBook.getDateAdded();
    qtyOnHand   = otherBook.getQtyOnHand();
    wholesale   = otherBook.getWholesale();
    retail      = otherBook.getRetail();
     */
    *this = otherBook;
}











/****** SETTERS ******/

/******************************************************************************
 * FUNCTION - bookType::setBookTitle
 * ____________________________________________________________________________
 * This function receives a string and sets the value of member bookTitle
 * to the value of the parameter string
 * ===> returns nothing.
 *
 * PRE-CONDITIONS
 *  The following must be defined before function call:
 *      <parameters>
 *      an instance of bookType must be declared
 *
 * POST-CONDITIONS
 *      attribute bookTitle of bookType instance is modified
 ******************************************************************************/

void bookType::setBookTitle(string newTitle) {
    bookTitle = newTitle;
}




/******************************************************************************
 * FUNCTION - bookType::
 * ____________________________________________________________________________
 * This function receives
 * ===> returns nothing.
 *
 * PRE-CONDITIONS
 *  The following must be defined before function call:
 *
 *
 * POST-CONDITIONS
 *
 ******************************************************************************/

void bookType::setISBN(string newISBN) {
    isbn = newISBN;
}




/******************************************************************************
 * FUNCTION - bookType::
 * ____________________________________________________________________________
 * This function receives
 * ===> returns nothing.
 *
 * PRE-CONDITIONS
 *  The following must be defined before function call:
 *
 *
 * POST-CONDITIONS
 *
 ******************************************************************************/

void bookType::setAuthor(string newAuthor) {
    author = newAuthor;
}




/******************************************************************************
 * FUNCTION - bookType::
 * ____________________________________________________________________________
 * This function receives
 * ===> returns nothing.
 *
 * PRE-CONDITIONS
 *  The following must be defined before function call:
 *
 *
 * POST-CONDITIONS
 *
 ******************************************************************************/

void bookType::setPublisher(string newPub) {
    publisher = newPub;
}




/******************************************************************************
 * FUNCTION - bookType::
 * ____________________________________________________________________________
 * This function receives
 * ===> returns nothing.
 *
 * PRE-CONDITIONS
 *  The following must be defined before function call:
 *
 *
 * POST-CONDITIONS
 *
 ******************************************************************************/

void bookType::setDateAdded(string newDate) {
    dateAdded = newDate;
}




/******************************************************************************
 * FUNCTION - bookType::
 * ____________________________________________________________________________
 * This function receives
 * ===> returns nothing.
 *
 * PRE-CONDITIONS
 *  The following must be defined before function call:
 *
 *
 * POST-CONDITIONS
 *
 ******************************************************************************/

void bookType::setQtyOnHand(int newQOH) {
    qtyOnHand = newQOH;
}




/******************************************************************************
 * FUNCTION - bookType::
 * ____________________________________________________________________________
 * This function receives
 * ===> returns nothing.
 *
 * PRE-CONDITIONS
 *  The following must be defined before function call:
 *
 *
 * POST-CONDITIONS
 *
 ******************************************************************************/

void bookType::setWholesale(float newWholesale) {
    wholesale = newWholesale;
}




/******************************************************************************
 * FUNCTION - bookType::
 * ____________________________________________________________________________
 * This function receives
 * ===> returns nothing.
 *
 * PRE-CONDITIONS
 *  The following must be defined before function call:
 *
 *
 * POST-CONDITIONS
 *
 ******************************************************************************/

void bookType::setRetail(float newRetail) {
    retail = newRetail;
}


/****** GETTERS ******/

/******************************************************************************
 * FUNCTION - bookType::
 * ____________________________________________________________________________
 * This function receives
 * ===> returns nothing.
 *
 * PRE-CONDITIONS
 *  The following must be defined before function call:
 *
 *
 * POST-CONDITIONS
 *
 ******************************************************************************/

string bookType::getBookTitle() const {
    return bookTitle;
}




/******************************************************************************
 * FUNCTION - bookType::
 * ____________________________________________________________________________
 * This function receives
 * ===> returns nothing.
 *
 * PRE-CONDITIONS
 *  The following must be defined before function call:
 *
 *
 * POST-CONDITIONS
 *
 ******************************************************************************/

string bookType::getISBN() const {
    return isbn;
}




/******************************************************************************
 * FUNCTION - bookType::
 * ____________________________________________________________________________
 * This function receives
 * ===> returns nothing.
 *
 * PRE-CONDITIONS
 *  The following must be defined before function call:
 *
 *
 * POST-CONDITIONS
 *
 ******************************************************************************/

string bookType::getAuthor() const {
    return author;
}




/******************************************************************************
 * FUNCTION - bookType::
 * ____________________________________________________________________________
 * This function receives
 * ===> returns nothing.
 *
 * PRE-CONDITIONS
 *  The following must be defined before function call:
 *
 *
 * POST-CONDITIONS
 *
 ******************************************************************************/

string bookType::getPublisher() const {
    return publisher;
}




/******************************************************************************
 * FUNCTION - bookType::
 * ____________________________________________________________________________
 * This function receives
 * ===> returns nothing.
 *
 * PRE-CONDITIONS
 *  The following must be defined before function call:
 *
 *
 * POST-CONDITIONS
 *
 ******************************************************************************/

string bookType::getDateAdded() const {
    return dateAdded;
}




/******************************************************************************
 * FUNCTION - bookType::
 * ____________________________________________________________________________
 * This function receives
 * ===> returns nothing.
 *
 * PRE-CONDITIONS
 *  The following must be defined before function call:
 *
 *
 * POST-CONDITIONS
 *
 ******************************************************************************/
int bookType::getQtyOnHand() const {
    return qtyOnHand;
}




/******************************************************************************
 * FUNCTION - bookType::
 * ____________________________________________________________________________
 * This function receives
 * ===> returns nothing.
 *
 * PRE-CONDITIONS
 *  The following must be defined before function call:
 *
 *
 * POST-CONDITIONS
 *
 ******************************************************************************/

float bookType::getWholesale() const {
    return wholesale;
}




/******************************************************************************
 * FUNCTION - bookType::
 * ____________________________________________________________________________
 * This function receives
 * ===> returns nothing.
 *
 * PRE-CONDITIONS
 *  The following must be defined before function call:
 *
 *
 * POST-CONDITIONS
 *
 ******************************************************************************/

float bookType::getRetail() const {
    return retail;
}




/******************************************************************************
 * FUNCTION - bookType::
 * ____________________________________________________________________________
 * This function receives
 * ===> returns nothing.
 *
 * PRE-CONDITIONS
 *  The following must be defined before function call:
 *
 *
 * POST-CONDITIONS
 *
 ******************************************************************************/

bookType::~bookType() {
    //cout << "Destructing " << bookTitle << " - ISBN " << isbn << "...\n";
}




/******************************************************************************
 * FUNCTION - bookType::
 * ____________________________________________________________________________
 * This function receives
 * ===> returns nothing.
 *
 * PRE-CONDITIONS
 *  The following must be defined before function call:
 *
 *
 * POST-CONDITIONS
 *
 ******************************************************************************/

bool bookType::operator<(const bookType &otherBook) const {
    return qtyOnHand < otherBook.getQtyOnHand();
}




/******************************************************************************
 * FUNCTION - bookType::
 * ____________________________________________________________________________
 * This function receives
 * ===> returns nothing.
 *
 * PRE-CONDITIONS
 *  The following must be defined before function call:
 *
 *
 * POST-CONDITIONS
 *
 ******************************************************************************/

bool bookType::operator<=(const bookType &otherBook) const {
    /*
    cout << "comparing " << qtyOnHand << " <= " << otherBook.getQtyOnHand() << "...\n";
    if (qtyOnHand <= otherBook.getQtyOnHand()) {
        cout << "True\n";
    }
    else {
        cout << "False\n";
    }
    */
    return qtyOnHand <= otherBook.getQtyOnHand();
}




/******************************************************************************
 * FUNCTION - bookType::
 * ____________________________________________________________________________
 * This function receives
 * ===> returns nothing.
 *
 * PRE-CONDITIONS
 *  The following must be defined before function call:
 *
 *
 * POST-CONDITIONS
 *
 ******************************************************************************/

bool bookType::operator>=(const bookType &otherBook) const {
    return qtyOnHand >= otherBook.getQtyOnHand();
}




/******************************************************************************
 * FUNCTION - bookType::
 * ____________________________________________________________________________
 * This function receives
 * ===> returns nothing.
 *
 * PRE-CONDITIONS
 *  The following must be defined before function call:
 *
 *
 * POST-CONDITIONS
 *
 ******************************************************************************/

bool bookType::operator==(const bookType &otherBook) const {
    return qtyOnHand == otherBook.getQtyOnHand();
}




/******************************************************************************
 * FUNCTION - bookType::
 * ____________________________________________________________________________
 * This function receives
 * ===> returns nothing.
 *
 * PRE-CONDITIONS
 *  The following must be defined before function call:
 *
 *
 * POST-CONDITIONS
 *
 ******************************************************************************/

bool bookType::operator!=(const bookType &otherBook) const {
    return qtyOnHand != otherBook.getQtyOnHand();
}






