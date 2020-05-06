/*******************************************
 * AUTHOR   : GRANT GOLDSWORTH
 * ID	    : 1164709
 * PROJECT  : A23
 * DUE DATE : 5/6/2020
*******************************************/

#include "bookType.h"
int bookType::bookCount = 0;


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
int bookType::compareCode = 0;

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
    bookCount ++;
}




/******************************************************************************
 * FUNCTION - bookType::bookType(string, string, string, string, string
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
    bookCount ++;
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
    cout << "COPY CONSRUCTOR\n";
    system("pause");
    //bookCount ++; // unsure if this is appropriate in the copy constructor
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
 *      instance of bookType class is defined
 *
 * POST-CONDITIONS
 *      attribute bookTitle of bookType instance is modified
 ******************************************************************************/

void bookType::setBookTitle(string newTitle) {
    bookTitle = newTitle;
}




/******************************************************************************
 * FUNCTION - bookType::setISBN
 * ____________________________________________________________________________
 * This function receives a string and sets it as the value of attribute isbn
 * ===> returns nothing.
 *
 * PRE-CONDITIONS
 *  The following must be defined before function call:
 *      newISBN : a string
 *      instance of bookType class is defined
 *
 * POST-CONDITIONS
 *      isbn is set to value of newISBN
 ******************************************************************************/

void bookType::setISBN(string newISBN) {
    isbn = newISBN;
}




/******************************************************************************
 * FUNCTION - bookType::setAuthor
 * ____________________________________________________________________________
 * This function receives a string and sets it as the value of attribute author
 * ===> returns nothing.
 *
 * PRE-CONDITIONS
 *  The following must be defined before function call:
 *      newAuthor   : a string
 *      instance of bookType class is defined
 *
 * POST-CONDITIONS
 *      author is set to value of newAuthor
 ******************************************************************************/

void bookType::setAuthor(string newAuthor) {
    author = newAuthor;
}




/******************************************************************************
 * FUNCTION - bookType::setPublisher
 * ____________________________________________________________________________
 * This function receives a string and sets it as the value of attribute publisher
 * ===> returns nothing.
 *
 * PRE-CONDITIONS
 *  The following must be defined before function call:
 *      newPublisher   : a string
 *      instance of bookType class is defined
 *
 * POST-CONDITIONS
 *      publisher is set to value of newPublisher
 ******************************************************************************/

void bookType::setPublisher(string newPub) {
    publisher = newPub;
}




/******************************************************************************
 * FUNCTION - bookType::setDateAdded
 * ____________________________________________________________________________
 * This function receives a string and sets it as the value of attribute dateAdded
 * ===> returns nothing.
 *
 * PRE-CONDITIONS
 *  The following must be defined before function call:
 *      newDate   : a string
 *      instance of bookType class is defined
 *
 * POST-CONDITIONS
 *      dateAdded is set to value of newDate
 ******************************************************************************/

void bookType::setDateAdded(string newDate) {
    dateAdded = newDate;
}




/******************************************************************************
 * FUNCTION - bookType::setQtyOnHand
 * ____________________________________________________________________________
 * This function receives and int and sets it as the value of qtyOnHand
 * ===> returns nothing.
 *
 * PRE-CONDITIONS
 *  The following must be defined before function call:
 *      newQOH  : an int
 *      instance of bookType class is defined
 *
 * POST-CONDITIONS
 *      qtyOnHand is set to value of newQOH
 ******************************************************************************/

void bookType::setQtyOnHand(int newQOH) {
    qtyOnHand = newQOH;
}




/******************************************************************************
 * FUNCTION - bookType::setWholesale
 * ____________________________________________________________________________
 * This function receives a float and sets it as the value of wholesale
 * ===> returns nothing.
 *
 * PRE-CONDITIONS
 *  The following must be defined before function call:
 *      newWholesale  : a float
 *      instance of bookType class is defined
 *
 * POST-CONDITIONS
 *      wholesale is set to value of newWholesale
 ******************************************************************************/

void bookType::setWholesale(float newWholesale) {
    wholesale = newWholesale;
}




/******************************************************************************
 * FUNCTION - bookType::setRetail
 * ____________________________________________________________________________
 * This function receives a float and sets it as the value of attribute retail
 * ===> returns nothing.
 *
 * PRE-CONDITIONS
 *  The following must be defined before function call:
 *      newRetail   : a float
 *      instance of bookType class is defined
 *
 * POST-CONDITIONS
 *      retail is set to value of newRetail
 ******************************************************************************/

void bookType::setRetail(float newRetail) {
    retail = newRetail;
}


/****** GETTERS ******/

/******************************************************************************
 * FUNCTION - bookType::getBookTitle()
 * ____________________________________________________________________________
 * This function receives nothing. It will return a string with the value
 * of attribute bookTitle.
 * ===> returns a string
 *
 * PRE-CONDITIONS
 *  The following must be defined before function call:
 *      instance of bookType class is defined
 *
 * POST-CONDITIONS
 *      instance of bookType class is not modified
 *      a string is returned to the calling function
 ******************************************************************************/

string bookType::getBookTitle() const {
    return bookTitle;
}




/******************************************************************************
 * FUNCTION - bookType::getISBN()
 * ____________________________________________________________________________
 * This function receives nothing. It will return a string with the value
 * of attribute isbn.
 * ===> returns a string
 *
 * PRE-CONDITIONS
 *  The following must be defined before function call:
 *      instance of bookType class is defined
 *
 * POST-CONDITIONS
 *      instance of bookType class is not modified
 *      a string is returned to the calling function
 ******************************************************************************/

string bookType::getISBN() const {
    return isbn;
}




/******************************************************************************
 * FUNCTION - bookType::getAuthor()
 * ____________________________________________________________________________
 * This function receives nothing. It will return a string with the value
 * of attribute author.
 * ===> returns a string
 *
 * PRE-CONDITIONS
 *  The following must be defined before function call:
 *      instance of bookType class is defined
 *
 * POST-CONDITIONS
 *      instance of bookType class is not modified
 *      a string is returned to the calling function
 ******************************************************************************/

string bookType::getAuthor() const {
    return author;
}




/******************************************************************************
 * FUNCTION - bookType::getPublisher()
 * ____________________________________________________________________________
 * This function receives nothing. It will return a string with the value
 * of attribute publisher.
 * ===> returns a string
 *
 * PRE-CONDITIONS
 *  The following must be defined before function call:
 *      instance of bookType class is defined
 *
 * POST-CONDITIONS
 *      instance of bookType class is not modified
 *      a string is returned to the calling function
 ******************************************************************************/

string bookType::getPublisher() const {
    return publisher;
}




/******************************************************************************
 * FUNCTION - bookType::getDateAdded()
 * ____________________________________________________________________________
 * This function receives nothing. It will return a string with the value
 * of attribute dateAdded.
 * ===> returns a string
 *
 * PRE-CONDITIONS
 *  The following must be defined before function call:
 *      instance of bookType class is defined
 *
 * POST-CONDITIONS
 *      instance of bookType class is not modified
 *      a string is returned to the calling function
 ******************************************************************************/

string bookType::getDateAdded() const {
    return dateAdded;
}




/******************************************************************************
 * FUNCTION - bookType::getQtyOnHand()
 * ____________________________________________________________________________
 * This function receives nothing. It will return an int with the value
 * of attribute qtyOnHand.
 * ===> returns an int
 *
 * PRE-CONDITIONS
 *  The following must be defined before function call:
 *      instance of bookType class is defined
 *
 * POST-CONDITIONS
 *      instance of bookType class is not modified
 *      an int is returned to the calling function
 ******************************************************************************/
int bookType::getQtyOnHand() const {
    return qtyOnHand;
}




/******************************************************************************
 * FUNCTION - bookType::getWholesale()
 * ____________________________________________________________________________
 * This function receives nothing. It will return a float with the value
 * of attribute wholesale.
 * ===> returns a float
 *
 * PRE-CONDITIONS
 *  The following must be defined before function call:
 *      instance of bookType class is defined
 *
 * POST-CONDITIONS
 *      instance of bookType class is not modified
 *      a float is returned to the calling function
 ******************************************************************************/

float bookType::getWholesale() const {
    return wholesale;
}




/******************************************************************************
 * FUNCTION - bookType::getBookTitle()
 * ____________________________________________________________________________
 * This function receives nothing. It will return a float with the value
 * of attribute retail.
 * ===> returns a string
 *
 * PRE-CONDITIONS
 *  The following must be defined before function call:
 *      instance of bookType class is defined
 *
 * POST-CONDITIONS
 *      instance of bookType class is not modified
 *      a float is returned to the calling function
 ******************************************************************************/

float bookType::getRetail() const {
    return retail;
}




/******************************************************************************
 * FUNCTION - bookType::getBookCount()
 * ____________________________________________________________________________
 * This function takes no arguments. It will return the value of static bookCount to the
 * calling function.
 * ===> returns an int
 *
 * PRE-CONDITIONS
 *  The following must be defined before function call:
 *      an instance of bookType is defined
 *
 *
 * POST-CONDITIONS
 *      an int with value of static bookCount is returned
 ******************************************************************************/

int bookType::getBookCount() {
    return bookCount;
}



/******************************************************************************
 * FUNCTION - bookType::
 * ____________________________________________________________________________
 * Default destructor overload. Destroys the instance of bookType and also
 * decrements the bookCount.
 * ===> returns nothing.
 *
 * PRE-CONDITIONS
 *  The following must be defined before function call:
 *      instance of bookType is defined
 *
 *
 * POST-CONDITIONS
 *      instance of bookType is deleted
 *      bookCount is decremented
 ******************************************************************************/

bookType::~bookType() {
    cout << "Destructing " << bookTitle << " - ISBN " << isbn << "...\n";
    bookCount --;
}




/******************************************************************************
 * FUNCTION - bookType::operator<
 * ____________________________________________________________________________
 * Less than boolean operator overload. Based on static attribute compareCode,
 * this function will compare a specific attribute of parent/left operand
 * with parameter/right operand
 * ===> returns a bool.
 *
 * PRE-CONDITIONS
 *  The following must be defined before function call:
 *      instance of bookType is defined
 *      otherBook   : other instance to compare with
 *
 * POST-CONDITIONS
 *      instances of bookType are not modified
 *      a bool is returned to the calling statement
 ******************************************************************************/

bool bookType::operator<(const bookType &otherBook) const {

    bool result = false;

    switch (compareCode) {
        case 0:
            result = bookTitle  < otherBook.getBookTitle();
            break;

        case 1:
            result = isbn       < otherBook.getISBN();
            break;

        case 2:
            result = author     < otherBook.getAuthor();
            break;

        case 3:
            result = publisher  < otherBook.getPublisher();
            break;

        case 4:
            result = dateAdded  < otherBook.getDateAdded();
            break;

        case 5:
            result =  qtyOnHand < otherBook.getQtyOnHand();
            break;

        case 6:
            result = wholesale  < otherBook.getWholesale();
            break;

        case 7:
            result = retail     < otherBook.getRetail();
            break;

        default:
            break;

    }

    return result;
}




/******************************************************************************
 * FUNCTION - bookType::operator>
 * ____________________________________________________________________________
 * Greater than boolean operator overload. Based on static attribute compareCode,
 * this function will compare a specific attribute of parent/left operand
 * with parameter/right operand
 * ===> returns a bool.
 *
 * PRE-CONDITIONS
 *  The following must be defined before function call:
 *      instance of bookType is defined
 *      otherBook   : other instance to compare with
 *
 * POST-CONDITIONS
 *      instances of bookType are not modified
 *      a bool is returned to the calling statement
 ******************************************************************************/

bool bookType::operator>(const bookType &otherBook) const {

    bool result = false;

    switch (compareCode) {
        case 0:
            result = bookTitle  > otherBook.getBookTitle();
            break;

        case 1:
            result = isbn       > otherBook.getISBN();
            break;

        case 2:
            result = author     > otherBook.getAuthor();
            break;

        case 3:
            result = publisher  > otherBook.getPublisher();
            break;

        case 4:
            result = dateAdded  > otherBook.getDateAdded();
            break;

        case 5:
            result =  qtyOnHand > otherBook.getQtyOnHand();
            break;

        case 6:
            result = wholesale  > otherBook.getWholesale();
            break;

        case 7:
            result = retail     > otherBook.getRetail();
            break;

        default:
            break;

    }

    return result;
}




/******************************************************************************
 * FUNCTION - bookType::operator<=
 * ____________________________________________________________________________
 * Less than or equal to boolean operator overload. Based on static attribute compareCode,
 * this function will compare a specific attribute of parent/left operand
 * with parameter/right operand
 * ===> returns a bool.
 *
 * PRE-CONDITIONS
 *  The following must be defined before function call:
 *      instance of bookType is defined
 *      otherBook   : other instance to compare with
 *
 * POST-CONDITIONS
 *      instances of bookType are not modified
 *      a bool is returned to the calling statement
 ******************************************************************************/

bool bookType::operator<=(const bookType &otherBook) const {

    bool result = false;

    switch (compareCode) {
        case 0:
            result = bookTitle  <= otherBook.getBookTitle();
            break;

        case 1:
            result = isbn       <= otherBook.getISBN();
            break;

        case 2:
            result = author     <= otherBook.getAuthor();
            break;

        case 3:
            result = publisher  <= otherBook.getPublisher();
            break;

        case 4:
            result = dateAdded  <= otherBook.getDateAdded();
            break;

        case 5:
            result =  qtyOnHand <= otherBook.getQtyOnHand();
            break;

        case 6:
            result = wholesale  <= otherBook.getWholesale();
            break;

        case 7:
            result = retail     <= otherBook.getRetail();
            break;

        default:
            break;

    }

    return result;
}




/******************************************************************************
 * FUNCTION - bookType::operator>=
 * ____________________________________________________________________________
 * Greater than or equal to boolean operator overload. Based on static attribute compareCode,
 * this function will compare a specific attribute of parent/left operand
 * with parameter/right operand
 * ===> returns a bool.
 *
 * PRE-CONDITIONS
 *  The following must be defined before function call:
 *      instance of bookType is defined
 *      otherBook   : other instance to compare with
 *
 * POST-CONDITIONS
 *      instances of bookType are not modified
 *      a bool is returned to the calling statement
 ******************************************************************************/

bool bookType::operator>=(const bookType &otherBook) const {

    bool result = false;

    switch (compareCode) {
        case 0:
            result = bookTitle  >= otherBook.getBookTitle();
            break;

        case 1:
            result = isbn       >= otherBook.getISBN();
            break;

        case 2:
            result = author     >= otherBook.getAuthor();
            break;

        case 3:
            result = publisher  >= otherBook.getPublisher();
            break;

        case 4:
            result = dateAdded  >= otherBook.getDateAdded();
            break;

        case 5:
            result =  qtyOnHand >= otherBook.getQtyOnHand();
            break;

        case 6:
            result = wholesale  >= otherBook.getWholesale();
            break;

        case 7:
            result = retail     >= otherBook.getRetail();
            break;

        default:
            break;

    }

    return result;
}




/******************************************************************************
 * FUNCTION - bookType::operator==
 * ____________________________________________________________________________
 * Equality boolean operator overload. Based on static attribute compareCode,
 * this function will compare a specific attribute of parent/left operand
 * with parameter/right operand
 * ===> returns a bool.
 *
 * PRE-CONDITIONS
 *  The following must be defined before function call:
 *      instance of bookType is defined
 *      otherBook   : other instance to compare with
 *
 * POST-CONDITIONS
 *      instances of bookType are not modified
 *      a bool is returned to the calling statement
 ******************************************************************************/

bool bookType::operator==(const bookType &otherBook) const {

    bool result = false;

    switch (compareCode) {
        case 0:
            result = bookTitle  == otherBook.getBookTitle();
            break;

        case 1:
            result = isbn       == otherBook.getISBN();
            break;

        case 2:
            result = author     == otherBook.getAuthor();
            break;

        case 3:
            result = publisher  == otherBook.getPublisher();
            break;

        case 4:
            result = dateAdded  == otherBook.getDateAdded();
            break;

        case 5:
            result =  qtyOnHand == otherBook.getQtyOnHand();
            break;

        case 6:
            result = wholesale  == otherBook.getWholesale();
            break;

        case 7:
            result = retail     == otherBook.getRetail();
            break;

        default:
            break;

    }

    return result;
}




/******************************************************************************
 * FUNCTION - bookType::operator!=
 * ____________________________________________________________________________
 * Not equal boolean operator overload. Based on static attribute compareCode,
 * this function will compare a specific attribute of parent/left operand
 * with parameter/right operand
 * ===> returns a bool.
 *
 * PRE-CONDITIONS
 *  The following must be defined before function call:
 *      instance of bookType is defined
 *      otherBook   : other instance to compare with
 *
 * POST-CONDITIONS
 *      instances of bookType are not modified
 *      a bool is returned to the calling statement
 ******************************************************************************/

bool bookType::operator!=(const bookType &otherBook) const {

    bool result = false;

    switch (compareCode) {
        case 0:
            result = bookTitle  != otherBook.getBookTitle();
            break;

        case 1:
            result = isbn       != otherBook.getISBN();
            break;

        case 2:
            result = author     != otherBook.getAuthor();
            break;

        case 3:
            result = publisher  != otherBook.getPublisher();
            break;

        case 4:
            result = dateAdded  != otherBook.getDateAdded();
            break;

        case 5:
            result =  qtyOnHand != otherBook.getQtyOnHand();
            break;

        case 6:
            result = wholesale  != otherBook.getWholesale();
            break;

        case 7:
            result = retail     != otherBook.getRetail();
            break;

        default:
            break;

    }

    return result;
}




/******************************************************************************
 * FUNCTION - operator<< (friend)
 * ____________________________________________________________________________
 * stream inserstion operator overload for bookType. Outputs some (not all) information
 * about the book - title, author, isbn, publisher, and date added.
 *
 * to output all specifics, use the getters and implement formatting
 * ===> returns ostream reference
 *
 * PRE-CONDITIONS
 *  The following must be defined before function call:
 *      ostream : the output stream controller object
 *      book    : bookType instance
 *
 * POST-CONDITIONS
 *      contents of book instance are not modified
 *      os stream object is returned to calling function
 ******************************************************************************/

ostream &operator<<(ostream &os, const bookType &book) {

    os << book.getBookTitle() << ", by " << book.getAuthor() << " " << book.getISBN() << " pub. " << book.getPublisher() << ". Added " << book.getDateAdded();

    return os;
}




/******************************************************************************
 * FUNCTION - operator>> (friend)
 * ____________________________________________________________________________
 * stream extraction overload for bookType. Prompts for input of all attributes
 * of bookType.
 * ===> returns istream reference
 *
 * PRE-CONDITIONS
 *  The following must be defined before function call:
 *      istream : stream extraction controller object
 *      book    : bookType instance
 *
 * POST-CONDITIONS
 *      content is extracted from the input stream
 *      contents of bookType instance are modified
 *      istream object is returned to calling function
 ******************************************************************************/

istream &operator>>(istream &is, bookType &book) {

    cout << "Title:        ";
    getline(is, book.bookTitle);

    cout << "Author:       ";
    getline(is, book.author);

    cout << "Publisher:    ";
    getline(is, book.publisher);

    cout << "Date Added:   ";
    getline(is, book.dateAdded);

    cout << "ISBN:         ";
    getline(is, book.isbn);

    cout << "Quantity OH:  ";
    is >> book.qtyOnHand;

    cout << "Wholesale:  $ ";
    is >> book.wholesale;

    cout << "Retail:     $ ";
    is >> book.retail;

    is.ignore(100, '\n');

    return is;
}






