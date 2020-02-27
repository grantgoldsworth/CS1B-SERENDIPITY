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

void CashierFunction(int& bookCount, bookType database[]) {

    const int   QTY_COL   = 4;       // column size for quantity in receipt
    const int   ISBN_COL  = 20;      // column size for isbn in receipt
    const int   TITLE_COL = 34;      // column size for title in receipt
    const float TAX_RATE = 0.06;    // the tax rate

    char answer;
    float total;
    float subTotal;
    int purchaseQty;
    int lookUpBookIndex;

    bookType book;



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
        cout << setw(56) << "---[ Cashier ]---" << endl << endl;




        lookUpBookIndex = lookUpBook(bookCount, database);



        if (lookUpBookIndex >= 0) {

            book = database[lookUpBookIndex];
            BookInformation(book, 't');

            if (book.qtyOnHand > 0) {

                // obtain the number of books to be purchased
                cout << "\n\nHow many of " << book.bookTitle << " are being purchased?\n";
                // output some eye candy
                if (book.qtyOnHand == 1) {
                    cout << "There is currently ";
                }

                else {
                    cout << "There are currently ";
                }

                cout << book.qtyOnHand << " in stock.\n";
                cout << "Quantity Purchasing: ";




                do { // while ((purchaseQty > book.qtyOnHand) && (purchaseQty <= 0))
                    cin >> purchaseQty;
                    if (purchaseQty > book.qtyOnHand) {
                        cout << "Cannot purchase " << purchaseQty << " copies of " << book.bookTitle << " as there are "
                             << "only " << book.qtyOnHand << " in inventory.\n";
                        cout << "Please enter a valid amount: ";
                    } else if (purchaseQty < 0) {
                        cout << "Serendipity does not allow for the sale of negative quantities of books.\n";
                        cout << "Please enter a valid amount: ";
                    }
                    cin.ignore(1000, '\n');

                } while ((purchaseQty > book.qtyOnHand) || (purchaseQty < 0));





                subTotal = purchaseQty * book.retail;

                // output the data table
                cout << left;
                cout << setw(QTY_COL) << "Qty" << setw(ISBN_COL) << "ISBN" << setw(TITLE_COL) << "Title";
                cout << setw(10) << "Price" << setw(10) << "Total" << endl;

                // create the line in the cashier menu+
                cout << setfill('_') << setw(80) << '_' << endl << endl;

                // output the information about the book being purchased, the price, and subtotal
                cout << setfill(' ') << setprecision(2) << fixed << left;
                cout << setw(QTY_COL) << purchaseQty << setw(ISBN_COL) << book.isbn << setw(TITLE_COL)
                     << book.bookTitle;
                cout << "$" << right << setw(6) << book.retail << setw(4) << "$" << right;
                cout << setw(6) << subTotal << endl << endl << endl;

                // output the subtotal, the tax, and final total
                cout << left << setw(ISBN_COL) << ' ' << setw(48) << "Subtotal: " << setw(2) << "$" << right
                     << subTotal
                     << endl;
                cout << left << setw(ISBN_COL) << ' ' << setw(48) << "Tax: " << setw(2) << "$" << right << setw(5)
                     << subTotal * TAX_RATE << endl;
                cout << left << setw(ISBN_COL) << ' ' << setw(48) << "Total: " << setw(2) << "$" << right
                     << subTotal * (1 + TAX_RATE) << endl
                     << endl << endl;


                cout << "Confirm Purchase: \n";
                cout << " [1] Yes\n";
                cout << " [2] No\n";
                answer = GetChoice(1, 2);
                cout << endl;


                // IF USER ACCEPTS THE PURCHASE - -> PROCEED
                if (answer == '1') {
                    cout << "\nPurchase of " << purchaseQty << " copies of " << book.bookTitle << " completed.\n\n";
                    database[lookUpBookIndex].qtyOnHand -= purchaseQty;
                } // end if (answer == '1') -- continued on else below

                else {
                    // IF USER DECLINED CONFIRMING PURCHASE
                    cout << "\nPurchase cancelled.\n";
                }


            } // end if (book.qtyOnHand > 0) -- continued on else below
            else {
                cout << "There are no copies of " << book.bookTitle
                     << " in the inventory currently. Can not complete transaction.\n";
            }

            // ask the user if they want to check out another book
            cout << "\nWould you like to check out another book? \n [1] Yes \n [2] No\n";
            answer = GetChoice(1, 2);
            system("cls");

        } // end if (lookUpBookIndex >= 0)

    } while (answer != '2');

    cout << "\n\nThank you for shopping at Serendipity!\n";
    system("pause");


    return;
}



/******************************************************************************
 * FUNCTION - InventoryFunction
 * ____________________________________________________________________________
 * This function receives the number of books in the database, and all of the
 * parallel arrays containing information about the books.
 * ---This is the main driver function for the Inventory module---
 * ===> returns nothing. screen output function for a menu
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:1
 * 		    bookCount       : the number of books currently in the database
 *          database        : the array of bookType structs holding info for each book
 *
 * POST-CONDITIONS
 *      This function can modify all members of structs in the array
 *      This function outputs a lot of text
 ******************************************************************************/

void InventoryFunction(int&   bookCount,    // REF - the num of books in database
                       bookType database[]  // REF - the array of bookType structs, main database
                       )
                       {


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

                    lookUpBookIndex = lookUpBook(bookCount, database);
                    if (lookUpBookIndex >= 0) {
                        BookInformation(database[lookUpBookIndex]);
                        system("pause");
                    }
                    system("cls");
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
                    addBook(bookCount, database);
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
                        editBook(bookCount, database);
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
                    deleteBook(bookCount,
                               database);
                }
                else {
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
 * <tumbleweeds roll by this abandoned ghost town of a function>
 * ---This is the main driver function for the reports module---
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
 * 		    book    : the book to display info about
 *
 * POST-CONDITIONS
 *      This function will not modify the actual arguments
 ******************************************************************************/

void BookInformation(const bookType book,    // VAL - a bookType data structure to output info for
                     bool cashier            //       't' - in cashier, do not display wholesale
                    ) {

    const int MENU_SPACE = 25;

    cout << right;
    cout << setw(62) << "---[ Book Information ]---\n\n\n";

    cout << setprecision(2) << fixed << left;
    cout << setw(MENU_SPACE) << "ISBN:"                 << book.isbn << endl;
    cout << setw(MENU_SPACE) <<"Title:"                 << book.bookTitle << endl;
    cout << setw(MENU_SPACE) <<"Author:"                << book.author << endl;
    cout << setw(MENU_SPACE) <<"Publisher:"             << book.publisher << endl;
    cout << setw(MENU_SPACE) <<"Date Added:"            << book.dateAdded << endl;
    cout << setw(MENU_SPACE) <<"Quantity-On-Hand:"      << book.qtyOnHand << endl;
    if (!cashier) {
        cout << setw(MENU_SPACE) << "Wholesale cost:" << "$ " << book.wholesale << endl;
    }
    cout << setw(MENU_SPACE) <<"Retail Price:"          << "$ " << book.retail << endl;

    return;
}