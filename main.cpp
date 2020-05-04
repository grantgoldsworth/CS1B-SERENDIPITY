/*******************************************
 * AUTHOR   : GRANT GOLDSWORTH
 * ID	    : 1164709
 * PROJECT  : A23
 * DUE DATE : 5/6/2020
*******************************************/

#include "functions.h"

/*******************************************************************************
 * A19- SERENDIPITY POINTERS EDITION
 * -----------------------------------------------------------------------------
 * This is a menu driven program to simulate a management software for a bookstore.
 * It will allow a user to navigate through various modules, including a cashier
 * module to check out a book, an inventory module to look up, add, edit and delete books,
 * and a reports module (that is not yet completed).
 *
 * INPUT
 *      menu navigation choices from user
 *      data for books
 *      input information for a cashier transaction
 * OUTPUT
 *      menus for input
 *      book information
 *
 * -----------------------------------------------------------------------------
 * ALGORITHM
 *  1 Cre
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
     * VARIABLES
     * -----------------------------------------------------------------------------
     * database     : array of bookType pointers, acts as main book database
     * choice       : user input choice
     * bookCount    : the number of books in the database; index od next available slot
     *******************************************************************************/
    bookType* database[DBSIZE] = {nullptr};

    bookType* testingBook = nullptr;

    char choice;
    int  bookCount; // make static in next serendipity


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
        cout << setw(MENU_INDENT) << " " << "[4] Exit\n";
        cout << setw(MENU_INDENT) << " " << "[0] TEST STREAM OVERLOAD OPERATORS\n";
        cout << right;

        // Obtain user's choice
        choice = GetChoice(0, 4);
        system("cls");

        // determine which module to navigate to based on user input
        switch (choice) {

            // Module 1 - Cashier menu
            case '1':
                // only allow purchase if there are books in the database to purchase.
                if (bookCount > 0) {
                    CashierFunction(bookCount, database);
                }
                else {
                    system("cls");
                    cout << "No books in database, can not create transaction.\n";
                    system("pause");
                }
                break;

            // module 2 - Inventory menu - pass the arrays as they are used in submodule
            case '2':
                InventoryFunction(bookCount, database);
                break;

            // module 3 - reports menu, currently stubs
            case '3':
                ReportsFunction(bookCount, database);
                break;

            case '0':
                system("cls");

                testingBook = new bookType;

                cout << "\t\t****** TESTING BOOKTYPE INSERTION AND EXTRACTION OVERLOADS ******\n\n";
                cout << "Enter information for a new book:\n";
                cin >> *testingBook;
                cout << "\n\nContents: \n";
                cout << *testingBook << endl;
                system("pause");
                delete testingBook;
                testingBook = nullptr;
                system("cls");

            default:
                break;

        } // end switch (choice)
        system("cls");

    } while (choice != '4');


    return 0;
}
