/*******************************************
 * AUTHOR   : GRANT GOLDSWORTH
 * ID	    : 1164709
 * PROJECT  : A4
 * DUE DATE : 1/27/2020
*******************************************/

#include "functions.h"

/******************************************************************************
 * FUNCTION - CashierFunction
 * ____________________________________________________________________________
 * This function receives nothing
 * ===> returns nothing, output function
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 * 			<none>
 * POST-CONDITIONS
 *		This function will output various data tables based on in-function
 *		user input
 ******************************************************************************/

void CashierFunction() {

    const int   QTY_COL   = 4;       // column size for quantity in receipt
    const int   ISBN_COL  = 20;      // column size for isbn in receipt
    const int   TITLE_COL = 34;      // column size for title in receipt
    const float TAX_RATE = 0.06;    // the tax rate

    string date;        // user input date -- formatted MM/DD/YY
    int    quantity;    // user input quantity of book being purchased
    string isbn;        // ISBN of book being purchased, contains numbers and hyphens
    string bookTitle;   // title of book being purchased
    float  bookPrice;   // unit price of book being purchased
    float  subTotal;    // total before tax
    float  total;       // total with tax included
    char   answer;      // whether or not user wants to check out another book (y/n)

    // output the heading for the cashier module
    cout << right;
    cout << "|" << setw(61) << "==[ Serendipity Booksellers ]==" << setw(33) << "|\n\n";
    cout << setw(56) << "---[ Cashier ]---";


    /**********************************************
    * DO-WHILE LOOP
     * ask for user input to check out a book,
     * process and output the receipt, then ask
     * user if they would like to check out another
    **********************************************/

    do { // while (answer != 'N')

        /**********************************************
         * INPUT - obtain information from user about
         * the book to purchase
         **********************************************/

        cout << "\n\nDate: ";
        getline(cin, date);

        cout << "Quantity: ";
        cin >> quantity;

        cin.ignore(1000, '\n');

        cout << "ISBN: ";
        getline(cin, isbn);

        cout << "Title: ";
        getline(cin, bookTitle);

        cout << "Price: ";
        cin >> bookPrice;

        cin.ignore(1000, '\n');
        cout << endl;

        // calculate the subtotal and total with taxes
        subTotal = quantity * bookPrice;
        total = subTotal * (1 + TAX_RATE);

        cout << "\nDate: " << date << endl << endl;

        // output the data table
        cout << left;
        cout << setw(QTY_COL) << "Qty" << setw(ISBN_COL) << "ISBN" << setw(TITLE_COL) << "Title";
        cout << setw(10) << "Price" << setw(10) << "Total" << endl;

        // create the line in the cashier menu
        cout << setfill('_') << setw(80) << '_' << endl << endl;

        // output the information about the book being purchased, the price, and subtotal
        cout << setfill(' ') << setprecision(2) << fixed << left;
        cout << setw(QTY_COL) << quantity << setw(ISBN_COL) << isbn << setw(TITLE_COL) << bookTitle;
        cout << "$" << right << setw(6) << bookPrice << setw(4) << "$" << right;
        cout << setw(6) << subTotal << endl << endl << endl;

        // output the subtotal, the tax, and final total
        cout << left << setw(ISBN_COL)  << ' ' << setw(48) << "Subtotal: " << setw(2) << "$" << right << subTotal << endl;
        cout << left << setw(ISBN_COL)  << ' ' << setw(48) << "Tax: " << setw(2) << "$" << right << subTotal * TAX_RATE   << endl;
        cout << left << setw(ISBN_COL)  << ' ' << setw(48) << "Total: " << setw(2) << "$" << right << total << endl << endl << endl;

        // ask the user if they want to check out another book
        cout << "\nWould you like to check out another book? [y/n]: ";
        cin.get(answer);
        answer = toupper(answer);
        cin.ignore(1000, '\n');

    } while (answer != 'N');

    cout << "\n\nThank you for shopping at Serendipity!\n";
    system("pause");


    return;
}