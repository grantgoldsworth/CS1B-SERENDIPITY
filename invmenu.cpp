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

int lookUpBook(int bookCount,            // VAL - the # of books in the database
               bookType database[]
                ) {

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
            index = searchDatabase(database, bookCount, target, 't');
            break;


        /* CASE 2 - SEARCH BY BOOK AUTHOR */
        case '2':
            cout << "\nEnter author to search for: ";
            getline(cin, target);
            index = searchDatabase(database, bookCount, target, 'a');
            break;


        /* CASE 3 - SEARCH BY BOOK ISBN NUMBER */
        case '3':
            cout << "\nEnter ISBN to search for: ";
            getline(cin, target);
            index = searchDatabase(database, bookCount, target, 'i');
            break;


        /* CASE 4 - SEARCH BY BOOK PUBLISHER */
        case '4':
            cout << "\nEnter publisher to search for: ";
            getline(cin, target);
            index = searchDatabase(database, bookCount, target, 'p');
            break;


        /* DEFAULT - idk just break. how would you even get here though lol? */
        default:
            break;
    } // end switch (choice)

    system("cls");

    return index;
}



/******************************************************************************
 * FUNCTION - searchDatabase
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

int searchDatabase(bookType database[],
                const int bookCount,
                string target,
                char flag) {

    string matchesArray[bookCount]; // array of substring matches for the target query
    int    indexMatches[bookCount]; // array of database index locations of the matches found

    int index = -1;         // index location of the final match of the search in DB arrays. Unfound by default
    int j;                  // Loop Control Variable for outputing matches loop
    int matchCount = 0;     // the number of matches for the target query
    char choice;            // user navigation / selection choice holder
    string databaseTarget;

    // convert target to lowercase for case insensitive searching
    target = tolowerstring(target);


    switch (tolower(flag)) {
        /******************************************************************************
         * CASE 't' - SEARCH BY TITLE
         *
         * Search through the struct array 'database', and compare the title member
         * of each struct to the query
         ******************************************************************************/
        case 't':
            for (int i = 0; i < bookCount; i ++) {

                databaseTarget = database[i].bookTitle;

                if (tolowerstring(databaseTarget).find(target) != string::npos) {
                    matchesArray[matchCount]  = databaseTarget;
                    indexMatches[matchCount] = i;
                    matchCount ++;
                }
            } // end for (int i = 0; i < bookCount, i ++)
            break;



        /******************************************************************************
         * CASE 'a' - SEARCH BY AUTHOR
         *
         * Search through the struct array 'database', and compare the author member
         * of each struct to the query
         ******************************************************************************/
        case 'a':
            for (int i = 0; i < bookCount; i ++) {

                databaseTarget = database[i].author;

                if (tolowerstring(databaseTarget).find(target) != string::npos) {
                    matchesArray[matchCount]  = databaseTarget;
                    indexMatches[matchCount] = i;
                    matchCount ++;
                }
            } // end for (int i = 0; i < bookCount, i ++)
            break;



        /******************************************************************************
         * CASE 'i' - SEARCH BY ISBN
         *
         * Search through the struct array 'database', and compare the ISBN member
         * of each struct to the query
         ******************************************************************************/
        case 'i':
            for (int i = 0; i < bookCount; i ++) {

                databaseTarget = database[i].isbn;

                if (tolowerstring(databaseTarget).find(target) != string::npos) {
                    matchesArray[matchCount]  = databaseTarget;
                    indexMatches[matchCount] = i;
                    matchCount ++;
                }
            } // end for (int i = 0; i < bookCount, i ++)
            break;



        /******************************************************************************
         * CASE 'p' - SEARCH BY PUBLISHER
         *
         * Search through the struct array 'database', and compare the publisher member
         * of each struct to the query
         ******************************************************************************/
        case 'p':
            for (int i = 0; i < bookCount; i ++) {

                databaseTarget = database[i].publisher;

                if (tolowerstring(databaseTarget).find(target) != string::npos) {
                    matchesArray[matchCount]  = databaseTarget;
                    indexMatches[matchCount] = i;
                    matchCount ++;
                }
            } // end for (int i = 0; i < bookCount, i ++)
            break;



        /******************************************************************************
         * DEFAULT - ERROR
         *
         * Output an error message to inform user there is an incorrect flag in a call
         * of SearchDatabase
         ******************************************************************************/
        default:
            system("cls");
            cout << "ERROR - UNRECOGNIZED FLAG IN <SearchDatabase>: " << flag << "\n\n";
            system("pause");
            system("cls");

            break;
    } // end switch(flag)



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
            cout << setw(14) << "Title: "     << database[j].bookTitle << endl;
            cout << setw(14) << "ISBN: "      << database[j].isbn << endl;
            cout << setw(14) << "Author: "    << database[j].author << endl;
            cout << setw(14) << "Publisher: " << database[j].publisher << endl;
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
             bookType database[]) {

    const int MENU_INDENT = 45;

    char choice;
    bool changes;
    bookType temporary;

    temporary.bookTitle = "EMPTY";
    temporary.isbn      = "EMPTY";
    temporary.publisher = "EMPTY";
    temporary.author    = "EMPTY";
    temporary.dateAdded = "EMPTY";
    temporary.qtyOnHand = 0;
    temporary.retail    = 0.0f;
    temporary.wholesale = 0.0f;

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
        cout << setw(MENU_INDENT) << "[1] Enter book title"                 << "| --  " << temporary.bookTitle  << endl;
        cout << setw(MENU_INDENT) << "[2] Enter ISBN"                       << "| --  " << temporary.isbn       << endl;
        cout << setw(MENU_INDENT) << "[3] Enter author"                     << "| --  " << temporary.author     << endl;
        cout << setw(MENU_INDENT) << "[4] Enter publisher"                  << "| --  " << temporary.publisher  << endl;
        cout << setw(MENU_INDENT) << "[5] Enter date added (MM/DD/YYYY)"    << "| --  " << temporary.dateAdded  << endl;
        cout << setw(MENU_INDENT) << "[6] Enter quantity on hand"           << "| --  " << temporary.qtyOnHand  << endl;
        cout << setprecision(2) << fixed;
        cout << setw(MENU_INDENT) << "[7] Enter wholesale cost"             << "| --$ " << temporary.wholesale  << endl;
        cout << setw(MENU_INDENT) << "[8] Enter retail price"               << "| --$ " << temporary.retail     << endl;
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
                getline(cin, temporary.bookTitle);
                changes = true;
                break;

            case '2':
                temporary.isbn = getUniqueISBN(database, bookCount);
                changes = true;
                break;

            case '3':
                cout << "Enter author: ";
                getline(cin, temporary.author);
                changes = true;
                break;

            case '4':
                cout << "Enter publisher: ";
                getline(cin, temporary.publisher);
                changes = true;
                break;

            case '5':
                cout << "Enter date of addition: ";
                getline(cin, temporary.dateAdded);
                changes = true;
                break;

            case '6':
                cout << "Enter quantity on hand: ";
                cin  >> temporary.qtyOnHand;
                while (temporary.qtyOnHand < 0) {
                    cout << "Error - enter valid quantity: ";
                    cin  >> temporary.qtyOnHand;
                }
                changes = true;
                cin.ignore(1000, '\n');
                break;

            case '7':
                cout << "Enter wholesale price: ";
                cin  >> temporary.wholesale;
                while (temporary.wholesale < 0) {
                    cout << "Error - enter valid quantity: ";
                    cin  >> temporary.wholesale;
                }
                changes = true;
                cin.ignore(1000, '\n');
                break;

            case '8':
                cout << "Enter retail price: ";
                cin  >> temporary.retail;
                while (temporary.retail < 0) {
                    cout << "Error - enter valid quantity: ";
                    cin  >> temporary.retail;
                }
                changes = true;
                cin.ignore(1000, '\n');
                break;

            case '9':
                if (bookCount < DBSIZE) {
                    // could have just done database[bookCount] = temporary BUUUUT
                    // we have to use these setters so here we are :|
                    // database[bookCount] = temporary;

                    SetBookTitle(database[bookCount], temporary.bookTitle);
                    SetAuthor(database[bookCount], temporary.author);
                    SetPublisher(database[bookCount], temporary.publisher);
                    SetISBN(database[bookCount], temporary.isbn);
                    SetDateAdded(database[bookCount], temporary.dateAdded);
                    SetRetail(database[bookCount], temporary.retail);
                    SetWholesale(database[bookCount], temporary.wholesale);
                    SetQtyOnHand(database[bookCount], temporary.qtyOnHand);

                    bookCount++;

                    // reset placeholders to default values for next book entry
                    temporary.bookTitle = "EMPTY";
                    temporary.isbn      = "EMPTY";
                    temporary.publisher = "EMPTY";
                    temporary.author    = "EMPTY";
                    temporary.dateAdded = "EMPTY";
                    temporary.qtyOnHand = 0;
                    temporary.retail    = 0.0f;
                    temporary.wholesale = 0.0f;

                    changes = false;
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
	
	if (bookCount == DBSIZE) {
		cout << "\n\n****** ERROR - MAXIMUM DATABASE CAPACITY REACHED - CANNOT ADD MORE BOOKS ******\n";
		cout << "****** DATABASE SIZE: " << DBSIZE << " --- BOOK COUNT: " << bookCount << " ******\n\n";
		system("pause"); 
	}

    system("cls");
}




/******************************************************************************
 * FUNCTION - getUniqueISBN
 * ____________________________________________________________________________
 * This function recieves the main database of bookTypes
 * It will ask the user to input a new ISBN, and then checks against all of the
 * ISBN members of the books in the database for duplicates. Outputs warning
 * if a match is found (info about match as well), or returns if it is unique.
 * ===> returns the unique isbn string
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 * 		    bookcount       : the current number of books in the DB; index of book to be added
 *          database        : array of bookType structs, each holding characteristic information for a book
 *
 * POST-CONDITIONS
 *      This function will not modify any of the actual parameters
 *      Returns a string representing the unique ISBN
 ******************************************************************************/

string getUniqueISBN(const bookType database[],       // REF - array of book isbn strings
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
            if (tempISBN == database[j].isbn) {
                isbnIsClone = true;
                isbnCloneIndex = j;
            }
        }

        // output error message
        if (isbnIsClone) {
            cout << "\n***** ERROR -- DUPLICATE ISBN ENTERED! *****\n";
            cout << "Your ISBN matches the ISBN of " << database[isbnCloneIndex].bookTitle;
            cout << " (" << tempISBN << ")\n";
            cout << "Please enter a unique ISBN.\n";
        }

    } while (isbnIsClone);

    return tempISBN;
}





/******************************************************************************
 * FUNCTION - editBook
 * ____________________________________________________________________________
 * This function the number of books in the database, and the main database array
 * of bookType structs. It will allow the user to modify members of a specific
 * individual book in the array.
 * ===> returns nothing. changes made to array components are saved.
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 * 		    bookcount       : the current number of books in the DB; index of book to be added
 *          database        : array of bookType structs, each holding characteristic information for a book
 *
 * POST-CONDITIONS
 *      Based on user input, this function can modify all of the actual array arguments
 ******************************************************************************/

void editBook(const int& bookCount, // REF - # of books in the array
              bookType database[]   // REF - the array of bookType structs, main database
              ) {

    const int MENU_INDENT = 55;

    int index = lookUpBook(bookCount, database);

    char choice;    // user navigation
    string strTemp; // holder for user string inputs
    int    intTemp; // holder for user int inputs
    float  fltTemp; // holder for user float inputs

    // if lookUpBook does not return -1 (for not found), then proceed
    if (index >= 0) {

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
            cout << setw(MENU_INDENT) << "[1] Enter book title" << "| --  " << database[index].bookTitle << endl;
            cout << setw(MENU_INDENT) << "[2] Enter ISBN" << "| --  " << database[index].isbn << endl;
            cout << setw(MENU_INDENT) << "[3] Enter author" << "| --  " << database[index].author << endl;
            cout << setw(MENU_INDENT) << "[4] Enter publisher" << "| --  " << database[index].publisher << endl;
            cout << setw(MENU_INDENT) << "[5] Enter date added (MM/DD/YYYY)" << "| --  " << database[index].dateAdded
                 << endl;
            cout << setw(MENU_INDENT) << "[6] Enter quantity on hand" << "| --  " << database[index].qtyOnHand << endl;
            cout << setprecision(2) << fixed;
            cout << setw(MENU_INDENT) << "[7] Enter wholesale cost" << "| --$ " << database[index].wholesale << endl;
            cout << setw(MENU_INDENT) << "[8] Enter retail price" << "| --$ " << database[index].retail << endl;
            cout.unsetf(ios_base::floatfield);
            cout << setprecision(6);
            cout << "[9] Save and return to inventory menu\n";
            cout << setfill('=') << setw(MENU_INDENT + 25) << "=" << endl;
            cout << setfill(' ');

            cout << right;
            choice = GetChoice(1, 9);

            // determine which module to navigate to based on user input
            switch (choice) {

                // Edit title
                case '1':
                    cout << "Enter book's title: ";
                    getline(cin, strTemp);
                    SetBookTitle(database[index], strTemp);
                    break;



                    // edit the ISBN once a unique one is entered
                case '2':
                    strTemp = getUniqueISBN(database, bookCount);
                    SetISBN(database[index], strTemp);
                    break;



                    // edit author
                case '3':
                    cout << "Enter author: ";
                    getline(cin, strTemp);
                    SetAuthor(database[index], strTemp);
                    break;



                    // edit publisher
                case '4':
                    cout << "Enter publisher: ";
                    getline(cin, strTemp);
                    SetPublisher(database[index], strTemp);
                    break;



                    // edit the date the book was added
                case '5':
                    cout << "Enter date of addition: ";
                    getline(cin, strTemp);
                    SetDateAdded(database[index], strTemp);
                    break;



                    // edit the quantity of the book that is on hand, and make sure it is a positive number
                case '6':
                    cout << "Enter quantity on hand: ";
                    cin >> intTemp;
                    while (intTemp < 0) {
                        cout << "Error - enter valid quantity: ";
                        cin >> intTemp;
                    }
                    cin.ignore(1000, '\n');
                    SetQtyOnHand(database[index], intTemp);
                    break;



                    // edit wholesale price, make sure it is a positive number
                case '7':
                    cout << "Enter wholesale price: ";
                    cin >> fltTemp;
                    while (fltTemp < 0) {
                        cout << "Error - enter valid quantity: ";
                        cin >> fltTemp;
                    }
                    cin.ignore(1000, '\n');
                    SetWholesale(database[index], fltTemp);
                    break;



                    // edit retail price, make sure it is a positive number
                case '8':
                    cout << "Enter retail price: ";
                    cin >> fltTemp;
                    while (fltTemp < 0) {
                        cout << "Error - enter valid quantity: ";
                        cin >> fltTemp;
                    }
                    cin.ignore(1000, '\n');
                    SetRetail(database[index], fltTemp);
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
    } // end if (index >= 0)
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
                bookType database []) {

    char choice;    // user choice for menu options

    int index;
    index = lookUpBook(bookCount, database);

    // if lookUpBook does not return -1 (for not found), then proceed
    if (index >= 0) {

        bookType t = database[index];

        // display information about the target book
        BookInformation(t);

        // output message asking for user to confirm deletion
        cout << "\nYou are about to delete this book from the database. Do you wish to continue?\n";
        cout << "[1] Yes, delete this book.\n";
        cout << "[2] No, return to the Inventory Menu.\n";

        choice = GetChoice(1, 2);

        // if user says yes, decrease bookCount and replace the target book (one to delete) with
        // the information of the last book in the array (the one indexed by the now decreased bookCount).
        // The copy of the replacer in the last slot of the array will not be accounted for by bookCount, or
        // in any of the loops using bookCount.
        if (choice == '1') {
            bookCount--;

            database[index].bookTitle = database[bookCount].bookTitle;
            database[index].author = database[bookCount].author;
            database[index].publisher = database[bookCount].publisher;
            database[index].dateAdded = database[bookCount].dateAdded;
            database[index].qtyOnHand = database[bookCount].qtyOnHand;
            database[index].wholesale = database[bookCount].wholesale;
            database[index].retail = database[bookCount].retail;
        }
    } // end (if index >= 0)
    system("cls");
}


