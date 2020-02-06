/*******************************************
 * AUTHOR   : GRANT GOLDSWORTH
 * ID	    : 1164709
 * PROJECT  : A5
 * DUE DATE : 2/10/2020
*******************************************/

#include "functions.h"

/* CONTAINS ALL OF THE SOURCE CODE FOR FUNCTIONS USED IN THE INVENTORY MENU*/

/******************************************************************************
 * FUNCTION - lookUpBook
 * ____________________________________________________________________________
 * This function receives the number of book sin the database, as well as the
 * series of parallel arrays containing book information.
 * It will prompt the user what they wish to search by (title, isbn, author, publisher).
 * It will either:
 *      + come up with a list of potential matches for the query and ask user to select which one
 *      they desire (or none), and will return the index of the selected match (or -1 if none)
 *      + return -1 for no matches, and inform the user
 *
 * ===> returns an integer index of a book's location in the database arrays
 *
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
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
 * POST-CONDITIONS
 *      This function will not modify the actual parameters
 *      Plenty of output, though. :)
 ******************************************************************************/

int lookUpBook( int   bookCount,            // VAL - the # of books in the database
                const string bookTitle[],   // REF - the array of book title strings
                const string isbn[],        // REF - array of isbn strings
                const string author[],      // REF - array of author strings
                const string publisher[],   // REF - array of publisher strings
                const string dateAdded[],   // REF - array of dates of book addition strings
                const int    qtyOnHand[],   // REF - array QOH's of the books
                const double wholesale[],   // REF - array of wholesale prices of the books
                const double retail[]) {    // REF - array of retail prices of the books

    string target;  // IN CALC OUT - the user input search query
    char choice;    // IN CALC     - the user's menu navigation option
    int index = -1; // CALC        - the index of the target book of the search, set to unfound be default


    // output menu screen
    cout << "\t\t===[ BOOK SEARCH ]===\n\n";
    cout << "What would you like to search by?\n";
    cout << "[1] Title\n";
    cout << "[2] Author\n";
    cout << "[3] ISBN\n";
    cout << "[4] Publisher\n";
    cout << "[5] Cancel search\n\n";

    // obtain user choice
    choice = GetChoice(1, 5);

    /******************************************************
     * SWITCH - What To Search Through
     * based on user choice from menu above, search for a book
     * match in either titles, isbn, author, or publisher
     * arrays. Obtain index via search function, then pass it
     * to book information output function.
     ******************************************************/
    switch (choice) {

        /* CASE 1 - SEARCH BY BOOK TITLE */
        case '1':
            cout << "\nEnter title to search for: ";
            getline(cin, target);
            index = searchArray(bookTitle,
                                bookTitle,
                                isbn,
                                author,
                                publisher,
                                target,
                                bookCount);
            break;


        /* CASE 2 - SEARCH BY BOOK AUTHOR */
        case '2':
            cout << "\nEnter author to search for: ";
            getline(cin, target);
            index = searchArray(author,
                                bookTitle,
                                isbn,
                                author,
                                publisher,
                                target,
                                bookCount);
            break;


        /* CASE 3 - SEARCH BY BOOK ISBN NUMBER */
        case '3':
            cout << "\nEnter ISBN to search for: ";
            getline(cin, target);
            index = searchArray(isbn,
                                bookTitle,
                                isbn,
                                author,
                                publisher,
                                target,
                                bookCount);
            break;


        /* CASE 4 - SEARCH BY BOOK PUBLISHER */
        case '4':
            cout << "\nEnter publisher to search for: ";
            getline(cin, target);
            index = searchArray(publisher,
                                bookTitle,
                                isbn,
                                author,
                                publisher,
                                target,
                                bookCount);
            break;


        /* DEFAULT - idk just break. how would you even get here though lol? */
        default:
            break;
    } // end switch (choice)

    system("cls");

    return index;
}



/******************************************************************************
 * FUNCTION - searchArray
 * ____________________________________________________________________________
 * This function receives a target array first, and then a few arrays
 * for general information display for matches during the search.
 * ===> returns the index that marks the book search match location
 *              in the arrays, or -1 if it is not found.
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 * 		        < all of the below arrays are parallel >
 * 		    targetArray     : the array to search for matches in
 * 		    bookTitle       : book title strings array
 * 		    isbn            : isbn strings array
 * 		    author          : author strings array
 * 		    publisher       : publisher strings array
 * 		    target          : the target query to search with
 * 		    bookCount       : the number of books in the database, helps make search efficient
 *
 * POST-CONDITIONS
 *      This function will not modify any of the actual parameters.
 ******************************************************************************/

int searchArray(const string targetArray[],     // REF - the array to search through for matches
                const string bookTitle[],       // REF - book titles strings array
                const string isbn[],            // REF - book isbn strings array
                const string author[],          // REF - book author strings array
                const string publisher[],       // REF - book publisher strings array
                string target,                  // VAL - the query to use for searching
                const int bookCount) {          // VAL - the number of books in the DB, used to control search length

    string matchesArray[bookCount]; // array of substring matches for the target query
    int    indexMatches[bookCount]; // array of database index locations of the matches found

    int index = -1;         // index location of the final match of the search in DB arrays. Unfound by default
    int j;                  // Loop Control Variable for outputing matches loop
    int matchCount = 0;     // the number of matches for the target query
    char choice;            // user navigation / selection choice holder

    // convert target to lowercase for case insensitive searching
    target = tolowerstring(target);


    /**********************************************************
     * FOR - LOOP - Finding matches for the query
     * Iterate through the target array. If there is a substring match
     * (lowercase and exact substring is found in target string) then add
     * the TARGET ARRAY's value to the matches list, as well as the position
     * of the match in the targetArray index (add to index holding array)
     **********************************************************/
    for (int i = 0; i < bookCount; i ++) {
       if (tolowerstring(targetArray[i]).find(target) != string::npos) {
           matchesArray[matchCount]  = targetArray[matchCount];
           indexMatches[matchCount] = i;
           matchCount ++;
       }
   } // end for (int i = 0; i < bookCount, i ++)

    // if there are matches, iterate through them all and ask the user if it is the one they were looking for
    if (matchCount != 0) {
        cout << "There were " << matchCount << " matches for the search query " << target << endl;

        j = 0;

        // while the user has not selected a match, and the list has not run out,
        // display a bit of info for each query match and ask user if it is the one they were lookin for.
        do { // while (choice != '1' && j < matchCount)
            system("cls");
            cout << "Match [" << j + 1 << " / " << matchCount << "]\n\n";

            // output a bit of info about the match
            cout << left;
            cout << setw(14) << "Title: "     << bookTitle[indexMatches[j]] << endl;
            cout << setw(14) << "ISBN: "      << isbn[indexMatches[j]] << endl;
            cout << setw(14) << "Author: "    << author[indexMatches[j]] << endl;
            cout << setw(14) << "Publisher: " << publisher[indexMatches[j]] << endl;
            cout << right;

            // ask user if this is the one they want
            cout << "\nIs this the book you were looking for? \n";
            cout << "[1] Yes\n";
            cout << "[2] No\n";
            choice = GetChoice(1, 2);
            system("cls");

            // if user selects 'Yes', assign the database-array index of the match to the return value of this function
            if (choice == '1') {
                index = indexMatches[j];
            }

            // increment j to process next match in the match list
            j ++;

            // if the user has toggled through all of the matches, output a sorry message
            if (choice == '2' && j == matchCount) {
                cout << "The book you are looking for was not found.\n";
                system("pause");
            }

        } while (choice != '1' && j < matchCount);



    } // end if (matchCount != 0)
    // if the match count is, say sorry
    else {
        cout << "There were no matches for your search.\n\n";
        system("pause");
    }
    return index;
}



/******************************************************************************
 * FUNCTION - addBook
 * ____________________________________________________________________________
 * This function receives the database size int, the book count int, and
 * the collection of parallel arrays containing information for books in the
 * database. It will allow the user to add a book to the database, prompting
 * for input for each piece of information associated with it (each parallel
 * array).
 * ===> returns nothing.
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 * 		    bookcount       : the current number of books in the DB; index of book to be added
 * 		        < all of the below arrays are parallel >
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
 *      This function will modify bookCount if user chooses to save an addition (+1)
 *      All of the arrays will have actual parameters modified in the event the user
 *      chooses to save changes to an addition
 ******************************************************************************/

void addBook(int& bookCount,
             string bookTitle[],
             string isbn[],
             string author[],
             string publisher[],
             string dateAdded[],
             int    qtyOnHand[],
             double wholesale[],
             double retail[]) {

    const int MENU_INDENT = 55;

    char choice;
    bool changes;
    bool isbnIsClone;
    string tempTitle        = "EMPTY";
    string tempISBN         = "EMPTY";
    string tempAuthor       = "EMPTY";
    string tempPublisher    = "EMPTY";
    string tempDate         = "EMPTY";
    int    tempQty          = 0;
    double tempWholesale    = 0.00f;
    double tempRetail       = 0.00f;

    changes = false;

    do { // while (choice != '4')


        // main menu screen output
        cout << right;
        cout << "|" << setw(61) << "==[ Serendipity Booksellers ]==" << setw(33) << "|\n\n";
        cout << setw(56) << "--- Add Book ---\n\n";

        cout << "CURRENT DATABASE SIZE: " << DBSIZE << setw(10) << ' ' << "BOOK COUNT: " << bookCount << endl
             << endl;

        cout << left;
        cout << setfill('=') << setw(MENU_INDENT + 25) << "=" << endl;
        cout << setfill(' ');
        cout << setw(MENU_INDENT) << "[1] Enter book title"                 << "| --  " << tempTitle     << endl;
        cout << setw(MENU_INDENT) << "[2] Enter ISBN"                       << "| --  " << tempISBN      << endl;
        cout << setw(MENU_INDENT) << "[3] Enter author"                     << "| --  " << tempAuthor    << endl;
        cout << setw(MENU_INDENT) << "[4] Enter publisher"                  << "| --  " << tempPublisher << endl;
        cout << setw(MENU_INDENT) << "[5] Enter date added (MM/DD/YYYY)"    << "| --  " << tempDate      << endl;
        cout << setw(MENU_INDENT) << "[6] Enter quantity on hand"           << "| --  " << tempQty       << endl;
        cout << setprecision(2) << fixed;
        cout << setw(MENU_INDENT) << "[7] Enter wholesale cost"             << "| --$ " << tempWholesale << endl;
        cout << setw(MENU_INDENT) << "[8] Enter retail price"               << "| --$ " << tempRetail    << endl;
        cout.unsetf(ios_base::floatfield);
        cout << setprecision(6);
        cout << "[9] Save book to database\n";
        cout << "[0] Return to Inventory Menu...\n";
        cout << setfill('=') << setw(MENU_INDENT + 25) << "=" << endl;
        cout << setfill(' ');

        cout << right;
        choice = GetChoice(0, 9);

        // determine which module to navigate to based on user input
        switch (choice) {

            case '1':
                cout << "Enter book's title: ";
                getline(cin, tempTitle);
                changes = true;
                break;

            case '2':
                tempISBN = getUniqueISBN(bookTitle, isbn, bookCount);

                changes = true;
                break;

            case '3':
                cout << "Enter author: ";
                getline(cin, tempAuthor);
                changes = true;
                break;

            case '4':
                cout << "Enter publisher: ";
                getline(cin, tempPublisher);
                changes = true;
                break;

            case '5':
                cout << "Enter date of addition: ";
                getline(cin, tempDate);
                changes = true;
                break;

            case '6':
                cout << "Enter quantity on hand: ";
                cin  >> tempQty;
                while (tempQty < 0) {
                    cout << "Error - enter valid quantity: ";
                    cin  >> tempQty;
                }
                changes = true;
                cin.ignore(1000, '\n');
                break;

            case '7':
                cout << "Enter wholesale price: ";
                cin  >> tempWholesale;
                while (tempWholesale < 0) {
                    cout << "Error - enter valid quantity: ";
                    cin  >> tempWholesale;
                }
                changes = true;
                cin.ignore(1000, '\n');
                break;

            case '8':
                cout << "Enter retail price: ";
                cin  >> tempRetail;
                while (tempRetail < 0) {
                    cout << "Error - enter valid quantity: ";
                    cin  >> tempRetail;
                }
                changes = true;
                cin.ignore(1000, '\n');
                break;

            case '9':
                if (bookCount < DBSIZE) {
                    bookTitle[bookCount] = tempTitle;
                    isbn[bookCount] = tempISBN;
                    author[bookCount] = tempAuthor;
                    publisher[bookCount] = tempPublisher;
                    dateAdded[bookCount] = tempDate;
                    qtyOnHand[bookCount] = tempQty;
                    wholesale[bookCount] = tempWholesale;
                    retail[bookCount] = tempRetail;

                    bookCount++;

                    // reset placeholders to default values for next book entry
                    tempTitle = "EMPTY";
                    tempISBN = "EMPTY";
                    tempAuthor = "EMPTY";
                    tempPublisher = "EMPTY";
                    tempDate = "EMPTY";
                    tempQty = 0;
                    tempWholesale = 0;
                    tempRetail = 0;

                    changes = false;
                }
                else {
                    cout << "\n\n****** ERROR - MAXIMUM DATABASE CAPACITY REACHED - CANNOT ADD MORE BOOKS ******\n";
                    cout << "****** DATABASE SIZE: " << DBSIZE << " --- BOOK COUNT: " << bookCount << " ******\n\n";
                    system("pause");
                }
                break;

            case '0':
                if (changes) {
                    cout << "Attention! You are about to discard changes to an unsaved book. Do you wish to continue?\n";
                    cout << "[0] Yes, return to Inventory menu without saving.\n";
                    cout << "[1] No, return to editing this book.\n";
                    choice = GetChoice(0,1);
                }

            default:
                break;

        } // end switch (choice)
        system("cls");


    } while (choice != '0' && bookCount < DBSIZE);

    system("cls");
}




/******************************************************************************
 * FUNCTION - getUniqueISBN
 * ____________________________________________________________________________
 * This function receives a bookTitle array and an isbn array as well as the
 * number of books in the databse. It will prompt the user to enter an ISBN
 * number (string), and will check the database to see if it is unique. If there
 * is another exact match, output an error message and some info about the clone.
 * Prompt for a unique ISBN until satisified.
 * ===> returns the unique isbn string
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 * 		    bookTitle   : the array of book title strings
 * 		    isbn        : the array of isbn strings
 * 		    bookCount   : the number of books in the DB
 *
 * POST-CONDITIONS
 *      This function will not modify any of the actual parameters
 *      Returns a string representing the unique ISBN
 ******************************************************************************/

string getUniqueISBN(const string bookTitle[],  // REF - array of book title strings
                     const string isbn[],       // REF - array of book isbn strings
                     const int bookCount) {     // REF - num of books in the database

    string tempISBN;    // holder for the user input
    bool isbnIsClone;   // boolean for if the entered ISBN matches another in the isbn array
    int isbnCloneIndex; // the array location of an identical match for the input ISBN - used to output
                        //      information about the matching book

    do { // while (isbnIsClone)
        // reset to 0 as user inputs a new ISBN, must search for matches to this new input
        isbnCloneIndex = 0;

        // get input from user
        cout << "Enter ISBN: ";
        getline(cin, tempISBN);

        // iterate through the isbn array and look for matches
        isbnIsClone = false;
        for (int j = 0; j < bookCount; j ++) {
            if (tempISBN == isbn[j]) {
                isbnIsClone = true;
                isbnCloneIndex = j;
            }
        }

        // output error message
        if (isbnIsClone) {
            cout << "\n***** ERROR -- DUPLICATE ISBN ENTERED! *****\n";
            cout << "Your ISBN matches the ISBN of " << bookTitle[isbnCloneIndex];
            cout << " (" << tempISBN << ")\n";
            cout << "Please enter a unique ISBN.\n";
        }

    } while (isbnIsClone);

    return tempISBN;
}





/******************************************************************************
 * FUNCTION - editBook
 * ____________________________________________________________________________
 * This function receives all of the database parallel arrays, a target index of
 * a book to edit, and the number of books in the database. It will allow
 * the user to edit any of the pieces of information about the target
 * book.
 * ===> returns nothing. changes made to array components are saved.
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 * 		    bookcount       : the current number of books in the DB; index of book to be added
 * 		        < all of the below arrays are parallel >
 * 		    bookTitle       : book title strings array
 * 		    isbn            : isbn strings array
 * 		    author          : author strings array
 * 		    publisher       : publisher strings array
 * 		    dateAdded       : book addition date strings array
 * 		    qtyOnHand       : quantity ints array
 * 		    wholesale       : wholesale price floats array
 * 		    retail          : retail price floats array
 * 		    index           : the position of the target book in the arrays
 *
 * POST-CONDITIONS
 *      Based on user input, this function can modify all of the actual array arguments
 *
 ******************************************************************************/

void editBook(const int& bookCount, // REF - # of books in the array
                string bookTitle[], // REF - array of title strings
                string isbn[],      // REF - array of unique isbn strings
                string author[],    // REF - array of author strings
                string publisher[], // REF - array of publisher strings
                string dateAdded[], // REF - array of date addition strings
                int    qtyOnHand[], // REF - array of quantities
                double wholesale[], // REF -array of wholesale prices
                double retail[],    // REF - array of retail prices
                int index) {        // VAL - the index of the target book to edit

    const int MENU_INDENT = 55;

    char choice;    // user navigation


    /*****************************************************
     * DO-WHILE LOOP - Edit Book menu
     * While the user has not specified an exit choice,
     * display information about the book being edited (update
     * every time a change is made). Error check numerical
     * inputs as well as ISBN (for uniqueness).
     *
     * Changes made to array components are saved as soon
     * as they are entered.
     *****************************************************/
    do { // while (choice != '4')


        // main menu screen output
        cout << right;
        cout << "|" << setw(61) << "==[ Serendipity Booksellers ]==" << setw(33) << "|\n\n";
        cout << setw(56) << "--- Edit Book ---\n\n";

        // output all of the information for the book being edited
        cout << left;
        cout << setfill('=') << setw(MENU_INDENT + 25) << "=" << endl;
        cout << setfill(' ');
        cout << setw(MENU_INDENT) << "[1] Enter book title"                 << "| --  " << bookTitle[index] << endl;
        cout << setw(MENU_INDENT) << "[2] Enter ISBN"                       << "| --  " << isbn[index]      << endl;
        cout << setw(MENU_INDENT) << "[3] Enter author"                     << "| --  " << author[index]    << endl;
        cout << setw(MENU_INDENT) << "[4] Enter publisher"                  << "| --  " << publisher[index] << endl;
        cout << setw(MENU_INDENT) << "[5] Enter date added (MM/DD/YYYY)"    << "| --  " << dateAdded[index] << endl;
        cout << setw(MENU_INDENT) << "[6] Enter quantity on hand"           << "| --  " << qtyOnHand[index] << endl;
        cout << setprecision(2) << fixed;
        cout << setw(MENU_INDENT) << "[7] Enter wholesale cost"             << "| --$ " << wholesale[index] << endl;
        cout << setw(MENU_INDENT) << "[8] Enter retail price"               << "| --$ " << retail[index]    << endl;
        cout.unsetf(ios_base::floatfield);
        cout << setprecision(6);
        cout << "[9] Save and return to inventory menu\n";
        cout << setfill('=') << setw(MENU_INDENT + 25) << "=" << endl;
        cout << setfill(' ');

        cout << right;
        choice = GetChoice(0, 9);

        // determine which module to navigate to based on user input
        switch (choice) {

            // Edit title
            case '1':
                cout << "Enter book's title: ";
                getline(cin, bookTitle[index]);
                break;

            // edit the ISBN once a unique one is entered
            case '2':
                isbn[index] = getUniqueISBN(bookTitle, isbn, bookCount);
                break;

            // edit author
            case '3':
                cout << "Enter author: ";
                getline(cin, author[index]);
                break;

            // edit publisher
            case '4':
                cout << "Enter publisher: ";
                getline(cin, publisher[index]);
                break;

            // edit the date the book was added
            case '5':
                cout << "Enter date of addition: ";
                getline(cin, dateAdded[index]);
                break;

            // edit the quantity of the book that is on hand, and make sure it is a positive number
            case '6':
                cout << "Enter quantity on hand: ";
                cin  >> qtyOnHand[index];
                while (qtyOnHand[index] < 0) {
                    cout << "Error - enter valid quantity: ";
                    cin  >> qtyOnHand[index];
                }
                cin.ignore(1000, '\n');
                break;

            // edit wholesale price, make sure it is a positive number
            case '7':
                cout << "Enter wholesale price: ";
                cin  >> wholesale[index];
                while ( wholesale[index] < 0) {
                    cout << "Error - enter valid quantity: ";
                    cin  >>  wholesale[index];
                }
                cin.ignore(1000, '\n');
                break;

            // edit retail price, make sure it is a positive number
            case '8':
                cout << "Enter retail price: ";
                cin  >> retail[index];
                while (retail[index] < 0) {
                    cout << "Error - enter valid quantity: ";
                    cin  >> retail[index];
                }
                cin.ignore(1000, '\n');
                break;

            // exit case
            case '9':
                cout << "Changes saved. Returning to Inventory Menu...\n";
                system("pause");
                break;


            default:
                break;

        } // end switch (choice)
        // clear screen each time a choice is made, for neatness
        system("cls");


    } while (choice != '9');

    system("cls");
}

/******************************************************************************
 * FUNCTION - deleteBook
 * ____________________________________________________________________________
 * This function receives all of the database arrays, the number of books in the
 * database, and the target book to delete. It will allow the user to
 * view the book before deleting it, and ask for a confirmation.
 * ===> returns
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 * 		    bookcount       : the current number of books in the DB; index of book to be added
 * 		        < all of the below arrays are parallel >
 * 		    bookTitle       : book title strings array
 * 		    isbn            : isbn strings array
 * 		    author          : author strings array
 * 		    publisher       : publisher strings array
 * 		    dateAdded       : book addition date strings array
 * 		    qtyOnHand       : quantity ints array
 * 		    wholesale       : wholesale price floats array
 * 		    retail          : retail price floats array
 * 		    index           : the position of the target book in the arrays
 *
 * POST-CONDITIONS
 *      This function will modify the actual array arguments and bookCount.
 *      If a book is deleted, bookCount will decrease by one
 ******************************************************************************/

void deleteBook(int& bookCount,     // REF - # of books in the array
                string bookTitle[], // REF - array of title strings
                string isbn[],      // REF - array of unique isbn strings
                string author[],    // REF - array of author strings
                string publisher[], // REF - array of publisher strings
                string dateAdded[], // REF - array of date addition strings
                int    qtyOnHand[], // REF - array of quantities
                double wholesale[], // REF -array of wholesale prices
                double retail[],    // REF - array of retail prices
                int index) {

    char choice;    // user choice for menu options

    // display information about the target book
    BookInformation(bookTitle[index],
                    isbn[index],
                    author[index],
                    publisher[index],
                    dateAdded[index],
                    qtyOnHand[index],
                    wholesale[index],
                    retail[index]);

    // output message asking for user to confirm deletion
    cout << "\nYou are about to delete this book from the database. Do you wish to continue?\n";
    cout << "[1] Yes, delete this book.\n";
    cout << "[2] No, return to the Inventory Menu.\n";

    choice = GetChoice(1,2);

    // if user says yes, decrease bookCount and replace the target book (one to delete) with
    // the information of the last book in the array (the one indexed by the now decreased bookCount).
    // The copy of the replacer in the last slot of the array will not be accounted for by bookCount, or
    // in any of the loops using bookCount.
    if (choice == '1') {
            bookCount --;

            bookTitle[index] = bookTitle[bookCount];
            author[index]    = author[bookCount];
            isbn[index]      = isbn[bookCount];
            publisher[index] = publisher[bookCount];
            dateAdded[index] = dateAdded[bookCount];
            qtyOnHand[index] = qtyOnHand[bookCount];
            wholesale[index] = wholesale[bookCount];
            retail[index]    = retail[bookCount];
    }

    system("cls");
}


