/*******************************************
 * AUTHOR   : GRANT GOLDSWORTH
 * ID	    : 1164709
 * PROJECT  : A5
 * DUE DATE : 2/10/2020
*******************************************/

#include "functions.h"

/*******************************************************************************
 * SERENDIPITY
 * -----------------------------------------------------------------------------
 * This is a menu driven program to simulate a management software for a bookstore.
 * It will allow a user to navigate through various modules, including a cashier
 * module to check out a book, an inventory module to look up, add, edit and delete books,
 * and a reports module (that is not yet completed).
 *
 * Currently in stage of Chapter 8 - managing parallel arrays. All books have information
 * stored in a series of parallel arrays passed around like a hot potato
 *
 * INPUT
 *      - User choice for menu options and navigation
 *      - information for adding a book or editing a book
 *
 * OUTPUT
 *      - output text for menus and data regarding books
 *******************************************************************************/

int main() {

    /*******************************************************************************
     * CONSTANTS
     * -----------------------------------------------------------------------------
     * MENU_INDENT  : CALC -  Used to format the main menu of serendipity
     *******************************************************************************/
    const int MENU_INDENT = 30;
    // DBSIZE is defined and declared in functions.h

    /*******************************************************************************
     * INVENTORY DATABASE ARRAYS
     * -----------------------------------------------------------------------------
     * Parallel arrays to be used to manage the database of books under Serendipity's
     * inventory. Currently only hold (for testing) information for up to DBSIZE
     * many books.
     *******************************************************************************/
    string bookTitle[DBSIZE];
    string isbn[DBSIZE];
    string author[DBSIZE];
    string publisher[DBSIZE];
    string dateAdded[DBSIZE];
    int    qtyOnHand[DBSIZE];
    double wholesale[DBSIZE];
    double retail[DBSIZE];

    char choice;    // IN CALC OUT - the user's input choice
    int  bookCount; // CALC OUT    - the number of books in the database / index of new book to be added


    // in this current run, there are no books in the database yet.
    bookCount = 0;


    /*******************************************************************************
     * DO-WHILE LOOP - Program Main Menu
     * -----------------------------------------------------------------------------
     * Output the options available to the user for navigation to the main modules.
     * This loop is essentially the life of the program - it only exits once the
     * user specifies the exit program option. Otherwise, all submodules are accessed
     * from within this loop.
     *******************************************************************************/
    do { // while (choice != '4')

        // main menu screen output
        cout << right;
        cout << "|" << setw(61) << "==[ Serendipity Booksellers ]==" << setw(33) << "|\n\n";
        cout << setw(56) << "--- Main Menu ---\n";

        cout << left;
        cout << setw(MENU_INDENT) << " " << "[1] Cashier Module\n";
        cout << setw(MENU_INDENT) << " " << "[2] Inventory Database Module\n";
        cout << setw(MENU_INDENT) << " " << "[3] Report Module\n";
        cout << setw(MENU_INDENT) << " " << "[4] Exit...\n";
        cout << right;

        // Obtain user's choice
        choice = GetChoice(1, 4);
        system("cls");

        // determine which module to navigate to based on user input
        switch (choice) {

            // Module 1 - Cashier menu
            case '1':
                CashierFunction();
                break;

            // module 2 - Inventory menu - pass the arrays as they are used in submodule
            case '2':
                InventoryFunction(bookCount,
                               bookTitle,
                               isbn,
                               author,
                               publisher,
                               dateAdded,
                               qtyOnHand,
                               wholesale,
                               retail);
                break;

            // module 3 - reports menu, currently stubs
            case '3':
                ReportsFunction();
                break;

            default:
                break;

        } // end switch (choice)
        system("cls");

    } while (choice != '4');


    return 0;
}
