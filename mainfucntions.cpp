/*******************************************
 * AUTHOR   : GRANT GOLDSWORTH
 * ID	    : 1164709
 * PROJECT  : A4
 * DUE DATE : 2/5/2020
*******************************************/

#include "functions.h"

/******************************************************************************
 * FUNCTION - GetChoice
 * ____________________________________________________________________________
 * This function receives two integers representing a min and a max bound
 * ===> returns a character that holds an integer
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 * 			min: the integer to represent the minimum choice for a menu
 * 			max: the integer to represent the maximum choice for a menu
 *
 * POST-CONDITIONS
 *		This function will return a character representing the user's choice,
 *		once it has been error-checked
 ******************************************************************************/

char GetChoice(int min, int max) {
    char  input;
    int   asciiInput;
    bool  invalidInput;

    // convert boundaries to ascii so they can be compared against non-numeric chars
    int asciiMin = min + 48;
    int asciiMax = max + 48;

    do {
        cout << "Enter a choice [" << min << " - " << max << "]: ";
        cin.get(input);
        cin.ignore(1000, '\n');

        // convert input integer to ASCII
        asciiInput = input - 0;

        // determine if input is out of bounds specified in input
        invalidInput = (asciiInput > asciiMax || asciiInput < asciiMin);

        // output error message for out of bounds choice
        if (invalidInput) {
            cout << "*** Invalid Input - Please enter a valid choice. *** \n";
        }

    } while (invalidInput);

    return input;
}



/******************************************************************************
 * FUNCTION - tolowerstring
 * ____________________________________________________________________________
 * This function receives two integers representing a min and a max bound
 * ===> returns a character that holds an integer
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 * 			min: the integer to represent the minimum choice for a menu
 * 			max: the integer to represent the maximum choice for a menu
 *
 * POST-CONDITIONS
 *		This function will return a character representing the user's choice,
 *		once it has been error-checked
 ******************************************************************************/

string tolowerstring(string str) {

    for (int i = 0; i < str.length(); i ++) {
        str[i] = tolower(str[i]);
    }
    return str;
}




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

        // output the heading for the cashier module
        cout << right;
        cout << "|" << setw(61) << "==[ Serendipity Booksellers ]==" << setw(33) << "|\n\n";
        cout << setw(56) << "---[ Cashier ]---";

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
        cout << left << setw(ISBN_COL)  << ' ' << setw(48) << "Tax: " << setw(2) << "$" << right << setw(5) << subTotal * TAX_RATE   << endl;
        cout << left << setw(ISBN_COL)  << ' ' << setw(48) << "Total: " << setw(2) << "$" << right << total << endl << endl << endl;

        // ask the user if they want to check out another book
        cout << "\nWould you like to check out another book? \n [1] Yes \n [2] No\n";
        answer = GetChoice(1, 2);
        system("cls");

    } while (answer != '2');

    cout << "\n\nThank you for shopping at Serendipity!\n";
    system("pause");


    return;
}




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

void InventoryFunction(int&   bookCount,
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
    int   lookUpBookIndex;

    do {
        // output the header for this module
        cout << right;
        cout << "|" << setw(61) << "==[ Serendipity Booksellers ]==" << setw(33) << "|\n\n";
        cout << setw(56) << "--- Inventory ---\n";


        cout << left;
        cout << setw(MENU_INDENT) << " " << "[1] Look up a book\n";
        cout << setw(MENU_INDENT) << " " << "[2] Add a book\n";
        cout << setw(MENU_INDENT) << " " << "[3] Edit a book's record\n";
        cout << setw(MENU_INDENT) << " " << "[4] Delete a book\n";
        cout << setw(MENU_INDENT) << " " << "[5] Return to Main Menu\n";
        cout << right;

        choice = GetChoice(1, 5);
        system("cls");

        switch (choice) {
            case '1':
                if (bookCount != 0) {
                    lookUpBookIndex = lookUpBook(bookCount,
                                                 bookTitle,
                                                 isbn,
                                                 author,
                                                 publisher,
                                                 dateAdded,
                                                 qtyOnHand,
                                                 wholesale,
                                                 retail);

                    if (lookUpBookIndex != -1) {
                        BookInformation(bookTitle[lookUpBookIndex],
                                        isbn[lookUpBookIndex],
                                        author[lookUpBookIndex],
                                        publisher[lookUpBookIndex],
                                        dateAdded[lookUpBookIndex],
                                        qtyOnHand[lookUpBookIndex],
                                        wholesale[lookUpBookIndex],
                                        retail[lookUpBookIndex]);
                    }
                    else if (choice != '5') {
                        cout << "\nBook not found. Exiting search...\n";
                    }

                    system("pause");
                }
                else {
                    cout << "There are no books in the inventory. Returning to Inventory Menu...\n";
                    system("pause");
                    system("cls");
                }
                break;

            case '2':
                if (bookCount < DBSIZE) {
                    addBook(bookCount,
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
                if (bookCount != 0) {
                    editBook(bookCount,
                            bookTitle,
                            isbn,
                            author,
                            publisher,
                            dateAdded,
                            qtyOnHand,
                            wholesale,
                            retail);
                } else {
                    cout << "There are no books in the inventory. Returning to Inventory Menu...\n";
                    system("pause");
                    system("cls");
                }
                break;

            case '4':
                if (bookCount != 0) {
                    deleteBook();
                } else {
                    cout << "There are no books in the inventory. Returning to Inventory Menu...\n";
                    system("pause");
                    system("cls");
                }
                break;

            default:
                break;
        }

    } while (choice != '5');

    return;
}



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

void BookInformation(string title,
                     string isbn,
                     string author,
                     string publisher,
                     string date,
                     int    qty,
                     double wholesale,
                     double retail
) {

    const int MENU_SPACE = 25;

    cout << right;
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

    return;
}