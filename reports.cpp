/*******************************************
 * AUTHOR   : GRANT GOLDSWORTH
 * ID	    : 1164709
 * PROJECT  : A5
 * DUE DATE : 2/10/2020
*******************************************/

#include "functions.h"
#include <cmath>

/* CONTAINS ALL OF THE SOURCE CODE FOR FUNCTIONS USED IN THE REPORTS MENU */

/******************************************************************************
 * FUNCTION - repListing
 * ____________________________________________________________________________
 * This function receives the bookCount and the database of bookType pointers.
 * It will print a reports listing of all the books and allow the user to tab
 * through the listings, displaying 10 books per page.
 * ===> returns nothing.
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 * 		    bookCount   : the number of book entries in the database array, next available slot
 * 		    database    : array of bookType pointers
 *
 * POST-CONDITIONS
 *      output
 *      contents of array are not modified
 *      bookCount is not modified
 ******************************************************************************/

void repListing(int& bookCount, bookType *database[]) {

    time_t theTime = time(nullptr); // for displaying the time
    int page = 0;                   // the current page being displayed, set of ten books
    int maxPages = 1;               // the maximum number of pages, default to 1 (empty listing)
    int escStat = 0;                // holds bit key of GetKeyState for the escape key, used to exit menu
    bool quit = false;              // if user hits escape, then quit is set to true


    // set the max pages so that there are ten books per page maximum
    if (bookCount != 0) {
        maxPages = ceil(bookCount / 10.0);
    }

    char userChoice;

        /****************************************************************
         * DO-WHILE
         * Main display loop, prints a table with header and book information.
         * Only prints ten books at a time per page
         * User can navigate through the pages using Page Up/Page Down keys,
         * enter a page using F5, or leave this listing using Escape
         ****************************************************************/
        do { // while (!quit)

            // output the table, date/time, book count, and page
            cout << "|" << setw(61) << "==[ Serendipity Booksellers ]==" << setw(33) << "|\n\n";
            cout << setw(58) << "--- REPORTS LISTING ---" << endl << endl;
            cout << "DATE AND TIME: " << setw(25) << ctime(&theTime) << endl;
            cout << "|\t  PAGE" << setw(3) << page + 1 << "  of" << setw(3) << maxPages << "\t|\t" << " DATABASE SIZE:"
                 << setw(3) << DBSIZE
                 << "\t|\t" << "CURRENT BOOK COUNT:" << setw(3) << bookCount << "\t\t|\n\n";


            cout << left;
            cout << setw(28) << "TITLE" << setw(11) << "ISBN" << setw(16) << "AUTHOR" << setw(15) << "PUBLISHER"
                 << setw(11)
                 << "DATE ADDED"
                 << setw(8) << "QTY O/H" << setw(15) << "WHOLESALE COST" << setw(13) << "RETAIL PRICE" << endl;
            cout
                    << "--------------------------- ---------- --------------- -------------- ---------- ------- -------------- ------------"
                    << endl;


            /****************************************************************
             * FOR LOOP
             * Loop through the database, ten books at a time, the set depends
             * on the current "page". Only prints if there are books available
             * to print (if 15 books, 10 on first page, 5 on second)
             * Output all data for the book.
             ****************************************************************/


            for (int i = page * 10; i < 10 + page * 10 ; i++) {
                if (i < bookCount) {
                    cout << setw(28) << database[i]->bookTitle.substr(0, 27) << setw(11) << database[i]->isbn
                         << setw(16)
                         << database[i]->author.substr(0, 15)
                         << setw(15) << database[i]->publisher.substr(0, 14) << setw(11) << database[i]->dateAdded
                         << right
                         << setw(7) << database[i]->qtyOnHand
                         << setprecision(2) << fixed << "      $" << setfill('.') << setw(8) << database[i]->wholesale
                         << "   $"
                         << setfill(' ') << setw(9) << database[i]->retail
                         << left << endl << endl;
                    cout << endl;
                }
            }

            cout << right;
            cout << "[PgDn]: Next Page    [PgUp] Prev Page    [F5] Enter Page    [Esc] Exit\n";
            system("pause");


            /****************************************************************
             * KEY PRESSES
             * If the user hits ESC, the program will exit the reports listing
             * and return to the reports menu.
             * If the user hits Page Up, the "page" will be decremented, unless
             * it is already 0 in which it will rubber-band back to the last page.
             * If the user hits Page Down, the "page" will be incremented, unless
             * it is already at the max page, in which it will rubber band back
             * to the first page.
             * If the user hits F5, the program will wait for a page number input
             * and check it against bounds, defaulting to max or min if above
             * or below, respectively.
             ****************************************************************/

            // ESCAPE KEY
            if(GetKeyState(VK_ESCAPE) < 0) {
                // esc is down
                quit = true;
            }

            // PAGE UP KEY - PREV PAGE
            if(GetKeyState(VK_PRIOR) < 0) {
                if (page != 0) {
                    page --;
                }
                else {
                    // else: rubber band to the end
                    page = maxPages - 1;
                }
            }

            // PAGE DOWN KEY - NEXT PAGE
            if(GetKeyState(VK_NEXT) < 0) {
                // pages is 0 - indexed so check the adjusted value
                if (page + 1 < maxPages) {
                    page ++;
                }
                else {
                    // else: rubber band to the beginning
                    page = 0;
                }
            }

            // F5 KEY - INPUT PAGE
            if(GetKeyState(VK_F5) < 0) {
                cout << "Enter Page [1 - " << maxPages << "]: ";
                if (!(cin >> page)) {
                    if (cin.fail()) {
                        page = 0;
                        cin.clear();
                        cin.ignore(100, '\n');
                    }
                } // end integer error check
                // if page input is greater than max, set to max page
                // page is displayed as 1 base, but processed as 0 base for array. Adjusted accordingly.
                if (page - 1 >= maxPages) {
                    page = maxPages - 1;
                }
                    // if page input is less than 0, set to first page
                else if (page - 1 <= 0) {
                    page = 0;
                }

                    // page is valid, adjust to be 0 based
                else {
                    page = page - 1;
                }
            } // end if (F5)

            system("cls");
        } while (!quit); // end menu do-while
    //cin.ignore(100, '\n');

}

/******************************************************************************
 * FUNCTION - repCost
 * ____________________________________________________________________________
 * This function receives
 * ===> returns
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 *
 * POST-CONDITIONS
 *
 ******************************************************************************/

void repCost(int& bookCount, bookType *database[]) {

}

/******************************************************************************
 * FUNCTION - repWholesale
 * ____________________________________________________________________________
 * This function receives the bookCount and the database of bookType pointers.
 * It will print a reports listing of all the books, printing Title/ISBN/QOH/Wholesale
 * and allow the user to tab through the listings, displaying 10 books per page.
 * If on the last page, it will output the total wholesale value of the inventory.
 * ===> returns nothing.
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 * 		    bookCount   : the number of book entries in the database array, next available slot
 * 		    database    : array of bookType pointers
 *
 * POST-CONDITIONS
 *      output
 *      contents of array are not modified
 *      bookCount is not modified
 ******************************************************************************/

void repWholesale(int& bookCount, bookType *database[]) {
    time_t theTime = time(nullptr); // for displaying the time
    int page = 0;                   // the current page being displayed, set of ten books
    int maxPages = 1;               // the maximum number of pages, default to 1 (empty listing)
    int escStat = 0;                // holds bit key of GetKeyState for the escape key, used to exit menu
    bool quit = false;              // if user hits escape, then quit is set to true
    float totalWholesale = 0;       // total wholesale price of all books (qtyOnHand * wholesalePrice)
    char userChoice;                // user navigation


    // set the max pages so that there are ten books per page maximum
    if (bookCount != 0) {
        maxPages = ceil(bookCount / 10.0);
    }

    // calculate the total inventory wholesale
    for (int i = 0; i < bookCount; i ++) {
        totalWholesale += database[i]->wholesale * database[i]->qtyOnHand;
    }



    /****************************************************************
     * DO-WHILE
     * Main display loop, prints a table with header and book information.
     * Only prints ten books at a time per page
     * User can navigate through the pages using Page Up/Page Down keys,
     * enter a page using F5, or leave this listing using Escape
     ****************************************************************/

    do { // while (!quit)

        // output table header, date, book count, page count
        cout << "|" << setw(61) << "==[ Serendipity Booksellers ]==" << setw(33) << "|\n\n";
        cout << setw(58) << "--- WHOLESALE LISTING ---" << endl << endl;
        cout << "DATE AND TIME: " << setw(25) << ctime(&theTime) << endl;
        cout << "|\t  PAGE" << setw(3) << page + 1 << "  of" << setw(3) << maxPages << "\t|\t" << " DATABASE SIZE:"
             << setw(3) << DBSIZE
             << "\t|\t" << "CURRENT BOOK COUNT:" << setw(3) << bookCount << "\t\t|\n\n";


        // table header
        cout << left;
        cout << setw(50) << "TITLE" << setw(25) << "ISBN" << setw(25) << "QTY O/H" << setw(15) << "WHOLESALE COST" << endl;
        cout << "-----------------------------------------------   ----------               -------                  --------------\n";


        /****************************************************************
         * FOR LOOP
         * Loop through the database, ten books at a time, the set depends
         * on the current "page". Only prints if there are books available
         * to print (if 15 books, 10 on first page, 5 on second)
         * Output book title, isbn, QOH, and the wholesale
         ****************************************************************/

        for (int i = page * 10; i < 10 + page * 10 ; i++) {
            if (i < bookCount) {
                cout << setw(50) << database[i]->bookTitle.substr(0, 44)
                     << setw(25) << database[i]->isbn
                     << right
                     << setw(7) << database[i]->qtyOnHand
                     << setprecision(2) << fixed << setw(19) << "$" << setfill('.') << setw(13) << database[i]->wholesale << setfill(' ')
                     << left << endl << endl;

            }
        }

        // if on last page, output the total wholesale
        if (page + 1 == maxPages) {
            cout << "TOTAL INVENTORY WHOLESALE: $" << totalWholesale << endl << endl;
        }

        // user navigation key
        cout << right;
        cout << "[PgDn]: Next Page    [PgUp] Prev Page    [F5] Enter Page    [Esc] Exit\n";
        system("pause");

        /****************************************************************
         * KEY PRESSES
         * If the user hits ESC, the program will exit the reports listing
         * and return to the reports menu.
         * If the user hits Page Up, the "page" will be decremented, unless
         * it is already 0 in which it will rubber-band back to the last page.
         * If the user hits Page Down, the "page" will be incremented, unless
         * it is already at the max page, in which it will rubber band back
         * to the first page.
         * If the user hits F5, the program will wait for a page number input
         * and check it against bounds, defaulting to max or min if above
         * or below, respectively.
         ****************************************************************/

        // ESCAPE KEY
        if(GetKeyState(VK_ESCAPE) < 0) {
            // esc is down
            quit = true;
        }

        // PAGE UP KEY - PREV PAGE
        if(GetKeyState(VK_PRIOR) < 0) {
            if (page != 0) {
                page --;
            }
            else {
                // else: rubber band to the end
                page = maxPages - 1;
            }
        }

        // PAGE DOWN KEY - NEXT PAGE
        if(GetKeyState(VK_NEXT) < 0) {
            // pages is 0 - indexed so check the adjusted value
            if (page + 1 < maxPages) {
                page ++;
            }
            else {
                // else: rubber band to the beginning
                page = 0;
            }
        }

        // F5 KEY - INPUT PAGE
        if(GetKeyState(VK_F5) < 0) {
            cout << "Enter Page [1 - " << maxPages << "]: ";
            if (!(cin >> page)) {
                if (cin.fail()) {
                    page = 0;
                    cin.clear();
                    cin.ignore(100, '\n');
                }
            } // end integer error check
            // if page input is greater than max, set to max page
            // page is displayed as 1 base, but processed as 0 base for array. Adjusted accordingly.
            if (page - 1 >= maxPages) {
                page = maxPages - 1;
            }
            // if page input is less than 0, set to first page
            else if (page - 1 <= 0) {
                page = 0;
            }

            // page is valid, adjust to be 0 based
            else {
                page = page - 1;
            }
        } // end if (F5)

        system("cls");
    } while (!quit); // end menu do-while

}

/******************************************************************************
 * FUNCTION - repRetail
 * ____________________________________________________________________________
 * This function receives the bookCount and the database of bookType pointers.
 * It will print a reports listing of all the books, printing Title/ISBN/QOH/Retail
 * and allow the user to tab through the listings, displaying 10 books per page.
 * If on the last reports page, it will output the total retail value of the
 * inventory.
 * ===> returns nothing.
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 * 		    bookCount   : the number of book entries in the database array, next available slot
 * 		    database    : array of bookType pointers
 *
 * POST-CONDITIONS
 *      output
 *      contents of array are not modified
 *      bookCount is not modified
 ******************************************************************************/

void repRetail(int& bookCount, bookType* database[]) {
    time_t theTime = time(nullptr); // for displaying the time
    int page = 0;                   // the current page being displayed, set of ten books
    int maxPages = 1;               // the maximum number of pages, default to 1 (empty listing)
    int escStat = 0;                // holds bit key of GetKeyState for the escape key, used to exit menu
    bool quit = false;              // if user hits escape, then quit is set to true
    float totalWholesale = 0;       // total wholesale price of all books (qtyOnHand * wholesalePrice)
    char userChoice;


    // set the max pages so that there are ten books per page maximum
    if (bookCount != 0) {
        maxPages = ceil(bookCount / 10.0);
    }

    for (int i = 0; i < bookCount; i ++) {
        totalWholesale += database[i]->wholesale * database[i]->qtyOnHand;
    }



    /****************************************************************
     * DO-WHILE
     * Main display loop, prints a table with header and book information.
     * Only prints ten books at a time per page
     * User can navigate through the pages using Page Up/Page Down keys,
     * enter a page using F5, or leave this listing using Escape
     ****************************************************************/

    do { // while (!quit)

        cout << "|" << setw(61) << "==[ Serendipity Booksellers ]==" << setw(33) << "|\n\n";
        cout << setw(58) << "--- RETAIL LISTING ---" << endl << endl;
        cout << "DATE AND TIME: " << setw(25) << ctime(&theTime) << endl;
        cout << "|\t  PAGE" << setw(3) << page + 1 << "  of" << setw(3) << maxPages << "\t|\t" << " DATABASE SIZE:"
             << setw(3) << DBSIZE
             << "\t|\t" << "CURRENT BOOK COUNT:" << setw(3) << bookCount << "\t\t|\n\n";





        cout << left;
        cout << setw(50) << "TITLE" << setw(25) << "ISBN" << setw(25) << "QTY O/H" << setw(15) << "RETAIL COST" << endl;
        cout << "-----------------------------------------------   ----------               -------                  --------------\n";

        /****************************************************************
         * FOR LOOP
         * Loop through the database, ten books at a time, the set depends
         * on the current "page". Only prints if there are books available
         * to print (if 15 books, 10 on first page, 5 on second)
         * Output book title, isbn, QOH, and the retail
         ****************************************************************/

        for (int i = page * 10; i < 10 + page * 10 ; i++) {
            if (i < bookCount) {
                cout << setw(50) << database[i]->bookTitle.substr(0, 44)
                     << setw(25) << database[i]->isbn
                     << right
                     << setw(7) << database[i]->qtyOnHand
                     << setprecision(2) << fixed << setw(19) << "$" << setfill('.') << setw(13) << database[i]->retail << setfill(' ')
                     << left << endl << endl;

            }
        }

        // if on last page, output the total wholesale

        if (page + 1 == maxPages) {
            cout << setprecision(2) << fixed << "TOTAL INVENTORY RETAIL: $" << totalWholesale << endl << endl;
        }

        cout << right;
        cout << "[PgDn]: Next Page    [PgUp] Prev Page    [F5] Enter Page    [Esc] Exit\n";
        system("pause");


        /****************************************************************
        * KEY PRESSES
        * If the user hits ESC, the program will exit the reports listing
        * and return to the reports menu.
        * If the user hits Page Up, the "page" will be decremented, unless
        * it is already 0 in which it will rubber-band back to the last page.
        * If the user hits Page Down, the "page" will be incremented, unless
        * it is already at the max page, in which it will rubber band back
        * to the first page.
        * If the user hits F5, the program will wait for a page number input
        * and check it against bounds, defaulting to max or min if above
        * or below, respectively.
        ****************************************************************/

        // ESCAPE KEY
        if(GetKeyState(VK_ESCAPE) < 0) {
            // esc is down
            quit = true;
        }

        // PAGE UP KEY - PREV PAGE
        if(GetKeyState(VK_PRIOR) < 0) {
            if (page != 0) {
                page --;
            }
            else {
                // else: rubber band to the end
                page = maxPages - 1;
            }
        }

        // PAGE DOWN KEY - NEXT PAGE
        if(GetKeyState(VK_NEXT) < 0) {
            // pages is 0 - indexed so check the adjusted value
            if (page + 1 < maxPages) {
                page ++;
            }
            else {
                // else: rubber band to the beginning
                page = 0;
            }
        }

        // F5 KEY - INPUT PAGE
        if(GetKeyState(VK_F5) < 0) {
            cout << "Enter Page [1 - " << maxPages << "]: ";
            if (!(cin >> page)) {
                if (cin.fail()) {
                    page = 0;
                    cin.clear();
                    cin.ignore(100, '\n');
                }
            } // end integer error check
            // if page input is greater than max, set to max page
            // page is displayed as 1 base, but processed as 0 base for array. Adjusted accordingly.
            if (page - 1 >= maxPages) {
                page = maxPages - 1;
            }
                // if page input is less than 0, set to first page
            else if (page - 1 <= 0) {
                page = 0;
            }

                // page is valid, adjust to be 0 based
            else {
                page = page - 1;
            }
        } // end if (F5)

        system("cls");
    } while (!quit); // end menu do-while

}

/******************************************************************************
 * FUNCTION - repAge
 * ____________________________________________________________________________
 * This function receives
 * ===> returns
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 *
 * POST-CONDITIONS
 *
 ******************************************************************************/

void repAge() {
    cout << "Welcome to the reports age menu!\n";
    cout << "There's nothing here! Go back to Reports menu.\n\n";
    system("pause");
    system("cls");

}

/******************************************************************************
 * FUNCTION - repQty
 * ____________________________________________________________________________
 * This function receives
 * ===> returns
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 *
 * POST-CONDITIONS
 *
 ******************************************************************************/

void repQty() {
    cout << "Welcome to the reports Quantity menu!\n";
    cout << "There's nothing here! Go back to Reports menu.\n\n";
    system("pause");
    system("cls");

}