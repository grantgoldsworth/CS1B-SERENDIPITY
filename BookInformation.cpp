/*******************************************
 * AUTHOR   : GRANT GOLDSWORTH
 * ID	    : 1164709
 * PROJECT  : A4
 * DUE DATE : 1/27/2020
*******************************************/

#include "functions.h"

/******************************************************************************
 * FUNCTION - BookInformation
 * ____________________________________________________________________________
 * This function receives
 * ===> returns
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 *
 * POST-CONDITIONS
 *
 ******************************************************************************/

void BookInformation(string isbn,
                     string title,
                     string author,
                     string publisher,
                     string date,
                     int    qty,
                     double wholesale,
                     double retail
                     ) {

    const int MENU_SPACE = 25;

    cout << right;
    cout << "|" << setw(61) << "==[ Serendipity Booksellers ]==" << setw(33) << "|\n\n";
    cout << setw(62) << "---[ Book Information ]---\n\n\n";

    cout << setprecision(2) << fixed << left;
    cout << setw(MENU_SPACE) << "ISBN:"                 << isbn << endl;
    cout << setw(MENU_SPACE) <<"Title:"                 << title << endl;
    cout << setw(MENU_SPACE) <<"Author:"                << author << endl;
    cout << setw(MENU_SPACE) <<"Publisher:"             << publisher << endl;
    cout << setw(MENU_SPACE) <<"Date Added:"            << date << endl;
    cout << setw(MENU_SPACE) <<"Quantity-On-Hand:"      << qty << endl;
    cout << setw(MENU_SPACE) <<"Wholesale cost:"        << wholesale << endl;
    cout << setw(MENU_SPACE) <<"Retail Price:"          << retail << endl;

    system("pause");

    return;
}