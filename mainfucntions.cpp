/*******************************************
 * AUTHOR   : GRANT GOLDSWORTH
 * ID	    : 1164709
 * PROJECT  : A5
 * DUE DATE : 2/10/2020
*******************************************/

#include "functions.h"

/* THIS FILE CONTAINS DEFINITIONS FOR ALL OF THE MAIN MENU MODULE FUNCTIONS AND HELPERS */

/******************************************************************************
 * FUNCTION - GetChoice
 * ____________________________________________________________________________
 * This function receives two integers representing a min and a max bound.
 * It will prompt the user to enter a digit until the conditions are satisfied:
 * it is an integer digit, and it is between the bounds
 * ===> returns integer choice
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 * 			min: the integer to represent the minimum choice for a menu
 * 			max: the integer to represent the maximum choice for a menu
 *
 * POST-CONDITIONS
 *		This function will return a character representing the user's choice,
 *		once it has been error-checked
 *
 *
 *		p.s. i was kind of indecisive about whether or not to make it return a char
 *		or int of the choice, because I only discovered this easier method AFTER
 *		implementing it throughout the program as a character-returning, which
 *		was when I had the single-character input broken down into ascii and
 *		compared that way. Replacing all of the options in like 8 switch statements
 *		wasn't appealing to me. Maybe in another program ill fix it up, and make
 *		it able to process larger choices than 0-9.
 ******************************************************************************/

char GetChoice(int min, // VAL - the minimum choice bound
               int max) // VAL - the maximum choice bound
               {

    string  input;
    int   integerInput;
    bool  invalidInput;

    do {
        cout << "Enter a choice [" << min << " - " << max << "]: ";
        getline(cin, input);

        // convert first component of input string to integer - will be garbage
        // if it is not an integer!
        // try to make a way to read in all components until reach a non-digit char?? (can process 2+ digit options, like 11)
        integerInput = (int)input[0] - 48;

        invalidInput = (!isdigit(input[0]) ||
                       (integerInput < min || integerInput > max)
                       );

        // output error message for out of bounds / 'non-integer' input
        if (invalidInput) {
            cout << "*** Invalid Input - Please enter a valid choice. *** \n";
        }

    } while (invalidInput);

    return input[0];
}



/******************************************************************************
 * FUNCTION - tolowerstring
 * ____________________________________________________________________________
 * This function receives a string to convert to lowercase
 * ===> returns a copy of the target string with alphabetical characters converted to
 *      lowercase
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 * 			str : the string to convert to lowercase
 *
 * POST-CONDITIONS
 *		This function will not modify the actual parameter
 *		This function will return a modified copy of the string
 ******************************************************************************/

string tolowerstring(string str) {

    for (char & i : str) {
        i = tolower(i);
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

        // obtain information regarding the book to be purchased
        // NOTE - NEEDS ERROR CHECKING ON INPUTS!
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
        subTotal = (float)quantity * bookPrice;
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
 * This function receives the number of books in the database, and all of the
 * parallel arrays containing information about the books
 * ===> returns nothing. screen output function for a menu
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:1
 * 		    bookCount       : the number of books currently in the database
 * 		        < all of the below arrays are parallel >
 * 		    bookcount       : the current number of books in the DB; index of book to be added
 * 		    bookTitle       : book title strings array
 * 		    isbn            : isbn strings array
 * 		    author          : author strings array
 * 		    publisher       : publisher strings array
 * 		    dateAdded       : book addition date strings array
 * 		    qtyOnHand       : quantity ints array
 * 		    wholesale       : wholesale price floats array
 * 		    retail          : retail price floats array
 *
 * POST-CONDITIONS
 *      This function will potentially modify all of the actual array arguments and the
 *      bookCount argument depending on input.
 *      This function outputs a lot of text lol
 ******************************************************************************/

void InventoryFunction(int&   bookCount,    // REF - the num of books in database
                       string bookTitle[],  // REF - array of title strings
                       string isbn[],       // REF - array of isbn strings
                       string author[],     // REF - array of author strings
                       string publisher[],  // REF - array of publisher strings
                       string dateAdded[],  // REF - array of date addition strings
                       int    qtyOnHand[],  // REF - array of quantity on hand ints
                       double wholesale[],  // REF - array of wholesale price doubles
                       double retail[]) {   // REF - array of retail price doubles


    const int MENU_INDENT = 30;     // used to format the indent of the menu
    char  choice;                   // holds the user's choice, assigned from GetChoice()
    int   lookUpBookIndex;          // target index of book found by lookUpBook()

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

            /*******************************************************
             * CASE 1 - look up a book
             *
             * check to see if there are books in the inventory
             *
             * Call lookUpBook and allow for search of a book. Obtain
             * index of target book (-1 if none)
             *
             * if -1, do not output information of book.
             *******************************************************/
            case '1':
                // check to make sure DB isn't empty
                if (bookCount != 0) {
                    // get the index of a target book
                    lookUpBookIndex = lookUpBook(bookCount,
                                                 bookTitle,
                                                 isbn,
                                                 author,
                                                 publisher
                                                 );

                    // if book is found (not -1) then display information
                    if (lookUpBookIndex != -1) {
                        BookInformation(bookTitle[lookUpBookIndex],
                                        isbn[lookUpBookIndex],
                                        author[lookUpBookIndex],
                                        publisher[lookUpBookIndex],
                                        dateAdded[lookUpBookIndex],
                                        qtyOnHand[lookUpBookIndex],
                                        wholesale[lookUpBookIndex],
                                        retail[lookUpBookIndex]);

                        // pause screen after displaying information
                        system("pause");
                        system("cls");
                    }
                }
                else {
                    cout << "There are no books in the inventory. Returning to Inventory Menu...\n";
                    system("pause");
                    system("cls");
                }

                break;

            default:
                break;


            /*******************************************************
             * CASE 2 - Add a book
             *
             * check to see if there is room for an addition
             *
             * call addBook function to add information of new book
             *******************************************************/
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
                    cout << "Database Size:   "   << DBSIZE << endl;
                    cout << "Number of books: " << bookCount << endl;
                    system("pause");
                    system("cls");
                }
                break;


            /*******************************************************
             * CASE 3 - Edit a book
             *
             * check to see if there are books in the inventory
             *
             * Call lookUpBook and allow for search of a book. Obtain
             * index of target book (-1 if none)
             *
             * Call up edit book to allow user to modify elements
             * of index targeted book. Auto saves with each change.
             *
             * if -1, do not output information of book.
             *******************************************************/
            case '3':
                if (bookCount != 0) {

                    lookUpBookIndex = lookUpBook(bookCount,
                                                 bookTitle,
                                                 isbn,
                                                 author,
                                                 publisher
                                                 );

                    if (lookUpBookIndex != -1) {

                        editBook(bookCount,
                                 bookTitle,
                                 isbn,
                                 author,
                                 publisher,
                                 dateAdded,
                                 qtyOnHand,
                                 wholesale,
                                 retail,
                                 lookUpBookIndex);
                    }
                } else {
                    cout << "There are no books in the inventory. Returning to Inventory Menu...\n";
                    system("pause");
                }

                system("cls");
                break;


            /*******************************************************
             * CASE 4 - Delete a book
             *
             * check to see if there are books in the inventory
             *
             * obtain target book index with lookUpBook
             *
             * Call delete book function and proceed with removal
             * of target book from active inventory
             *
             *******************************************************/
            case '4':
                if (bookCount != 0) {

                    lookUpBookIndex = lookUpBook(bookCount,
                                                 bookTitle,
                                                 isbn,
                                                 author,
                                                 publisher
                                                 );

                    if (lookUpBookIndex != -1) {

                        deleteBook(bookCount,
                                 bookTitle,
                                 isbn,
                                 author,
                                 publisher,
                                 dateAdded,
                                 qtyOnHand,
                                 wholesale,
                                 retail,
                                 lookUpBookIndex);
                    }
                } else {
                    cout << "There are no books in the inventory. Returning to Inventory Menu...\n";
                    system("pause");
                }

                system("cls");
                break;


        } // end switch(choice)

    } while (choice != '5');

    return;
}



/******************************************************************************
 * FUNCTION - ReportsFunction
 * ____________________________________________________________________________
 * it's a stub for now, everything inside is just a stub. all stubs. stubby.
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
 * This function receives information about a single book from all of the database
 * arrays, and outputs it in a nice display
 * ===> returns nothing. primarily an output function
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 * 		    title       : the title of the book
 * 		    isbn        : isbn of book
 * 		    author      : you get it now
 * 		    publisher   :
 * 		    date        :
 * 		    qty         :
 * 		    wholesale   :
 * 		    retail      :
 *
 * POST-CONDITIONS
 *      This function will not modify the actual arguments
 ******************************************************************************/

void BookInformation(string title,      // VAL - title of book
                     string isbn,       // VAL - isbn of book
                     string author,     // VAL - author of book
                     string publisher,  // VAL - publisher of book
                     string date,       // VAL - date of addition for the book
                     int    qty,        // VAL - quantity on hand in the inventory
                     double wholesale,  // VAL - wholesale price of book
                     double retail      // VAL - retail price of book
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
    cout << setw(MENU_SPACE) <<"Wholesale cost:"        << "$ " << wholesale << endl;
    cout << setw(MENU_SPACE) <<"Retail Price:"          << "$ " << retail << endl;

    return;
}