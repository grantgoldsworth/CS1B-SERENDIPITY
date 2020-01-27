/*******************************************
 * AUTHOR   : GRANT GOLDSWORTH
 * ID	    : 1164709
 * PROJECT  : A4
 * DUE DATE : 1/27/2020
*******************************************/

#include "functions.h"

int main() {

    const int MENU_INDENT = 30;     // Used to format the main menu

    char choice;    // the user's input choice

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

        // determine which module to navigate to based on user input
        switch (choice) {

            case '1':
                CashierFunction();
                break;

            case '2':
                InventoryFunction();
                break;

            case '3':
                ReportsFunction();
                break;

        } // end switch (choice)
        system("cls");

    } while (choice != '4');


    return 0;
}
