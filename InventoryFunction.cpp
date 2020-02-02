/*******************************************
 * AUTHOR   : GRANT GOLDSWORTH
 * ID	    : 1164709
 * PROJECT  : A4
 * DUE DATE : 1/27/2020
*******************************************/

#include "functions.h"

/******************************************************************************
 * FUNCTION - InventoryFunction
 * ____________________________________________________________________________
 * This function receives
 * ===> returns
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 *
 * POST-CONDITIONS
 *
 ******************************************************************************/

void InventoryFunction(const int& DBSIZE,
                       int&   bookCount,
                       string bookTitle[],
                       string isbn[],
                       string author[],
                       string publisher[],
                       string dateAdded[],
                       int    qtyOnHand[],
                       double wholesale[],
                       double retail[]) {

    const int MENU_INDENT = 30;     // used to format the indent of the menu
    char  choice;                   // holds the user's choice, assigned from GetChoice()

    do {
        // output the header for this module
        cout << right;
        cout << "|" << setw(61) << "==[ Serendipity Booksellers ]==" << setw(33) << "|\n\n";
        cout << setw(56) << "--- Inventory ---\n";


        cout << left;
        cout << setw(MENU_INDENT) << " " << "[1] Look up a book\n";
        cout << setw(MENU_INDENT) << " " << "[2] Add a book\n";
        cout << setw(MENU_INDENT) << " " << "[3] Look at a book's record\n";
        cout << setw(MENU_INDENT) << " " << "[4] Delete a book\n";
        cout << setw(MENU_INDENT) << " " << "[5] Return to Main Menu\n";
        cout << right;

        choice = GetChoice(1, 5);
        system("cls");

        switch (choice) {
            case '1':
                lookUpBook();
                break;

            case '2':
                if (bookCount < DBSIZE) {
                    addBook(DBSIZE,
                            bookCount,
                            bookTitle,
                            isbn,
                            author,
                            publisher,
                            dateAdded,
                            qtyOnHand,
                            wholesale,
                            retail);
                }
                else {
                    cout << "ERROR - Cannot add book! Database has maximum amount of books stored in it!\n";
                    cout << "Database Size: "   << DBSIZE << endl;
                    cout << "Number of books: " << bookCount << endl;
                    system("pause");
                    system("cls");
                }
                break;

            case '3':
                editBook();
                break;

            case '4':
                deleteBook();
                break;

            default:
                break;
        }

    } while (choice != '5');

    return;
}