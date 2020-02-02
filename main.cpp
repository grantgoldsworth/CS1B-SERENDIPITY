/*******************************************
 * AUTHOR   : GRANT GOLDSWORTH
 * ID	    : 1164709
 * PROJECT  : A4
 * DUE DATE : 1/27/2020
*******************************************/

#include "functions.h"

int main() {

    /*******************************************************************************
     * CONSTANTS
     * -----------------------------------------------------------------------------
     * MENU_INDENT  : CALC -  Used to format the main menu of serendipity
     * DBSIZE       : CALC - the number of books that will have information stored for them
     *                          in the inventory. Controls array size for the data
     *******************************************************************************/
    const int MENU_INDENT = 30;
    const int DBSIZE      = 20;

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



    bookCount = 0;

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

        choice = GetChoice(1, 4);
        system("cls");

        // determine which module to navigate to based on user input
        switch (choice) {

            case '1':
                CashierFunction();
                break;

            case '2':
                InventoryFunction(DBSIZE,
                           bookCount,
                               bookTitle,
                               isbn,
                               author,
                               publisher,
                               dateAdded,
                               qtyOnHand,
                               wholesale,
                               retail);
                break;

            case '3':
                ReportsFunction();
                break;

        } // end switch (choice)
        system("cls");

    } while (choice != '4');


    return 0;
}
