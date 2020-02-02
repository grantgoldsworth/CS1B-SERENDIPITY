/*******************************************
 * AUTHOR   : GRANT GOLDSWORTH
 * ID	    : 1164709
 * PROJECT  : A4
 * DUE DATE : 1/27/2020
*******************************************/

#include "functions.h"

/******************************************************************************
 * FUNCTION - ReportsFunction
 * ____________________________________________________________________________
 * This function receives
 * ===> returns
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 *
 * POST-CONDITIONS
 *
 ******************************************************************************/

void ReportsFunction() {

    const int MENU_INDENT = 30;     // used to format the indent of the menu
    char  choice;                   // holds the user's choice, assigned from GetChoice()

    do {
        // output the header for this module
        cout << right;
        cout << "|" << setw(61) << "==[ Serendipity Booksellers ]==" << setw(33) << "|\n\n";
        cout << setw(56) << "---  Reports  ---\n";

        // create switch statement for options

        cout << left;
        cout << setw(MENU_INDENT) << " " << "[1] Inventory Listing\n";
        cout << setw(MENU_INDENT) << " " << "[2] Inventory Wholesale Value\n";
        cout << setw(MENU_INDENT) << " " << "[3] Inventory Retail Value\n";
        cout << setw(MENU_INDENT) << " " << "[4] Listing by Quantity\n";
        cout << setw(MENU_INDENT) << " " << "[5] Listing by Cost\n";
        cout << setw(MENU_INDENT) << " " << "[6] Listing by Age\n";
        cout << setw(MENU_INDENT) << " " << "[7] Return to Main Menu\n";
        cout << right;

        choice = GetChoice(1, 7);
        system("cls");

        switch (choice) {
            case '1':
                repListing();
                break;

            case '2':
                repWholesale();
                break;

            case '3':
                repRetail();
                break;

            case '4':
                repQty();
                break;

            case '5':
                repCost();
                break;

            case '6':
                repAge();
                break;

            default:
                break;
        }


    } while (choice != '7');
    return;
}