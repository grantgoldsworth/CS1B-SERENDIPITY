/*******************************************
 * AUTHOR   : GRANT GOLDSWORTH
 * ID	    : 1164709
 * PROJECT  : A4
 * DUE DATE : 1/27/2020
*******************************************/

#include "functions.h"

/* CONTAINS ALL OF THE SOURCE CODE FOR FUNCTIONS USED IN THE INVENTORY MENU*/

/******************************************************************************
 * FUNCTION - lookUpBook
 * ____________________________________________________________________________
 * This function receives
 * ===> returns
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 * 		    DATABASE_SIZE   : the max number of books possible in database
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
 *
 ******************************************************************************/

int lookUpBook(int   bookCount,
                const string bookTitle[],
                const string isbn[],
                const string author[],
                const string publisher[],
                const string dateAdded[],
                const int    qtyOnHand[],
                const double wholesale[],
                const double retail[]) {

    string target;
    char choice;
    int index = -1;

    cout << "\t\t===[ BOOK SEARCH ]===\n\n";
    cout << "What would you like to search by?\n";
    cout << "[1] Title\n";
    cout << "[2] Author\n";
    cout << "[3] ISBN\n";
    cout << "[4] Publisher\n";
    cout << "[5] Cancel search\n\n";

    choice = GetChoice(1, 5);


    switch (choice) {
        case '1':
            cout << "\nEnter title to search for: ";
            getline(cin, target);
            index = searchArray(bookTitle, bookTitle,
                                isbn, author,
                                publisher, dateAdded,
                                qtyOnHand, wholesale,
                                retail, target,
                                bookCount);
            break;

        case '2':
            cout << "\nEnter author to search for: ";
            getline(cin, target);
            index = searchArray(author, bookTitle,
                                isbn, author,
                                publisher, dateAdded,
                                qtyOnHand, wholesale,
                                retail, target,
                                bookCount);
            break;

        case '3':
            cout << "\nEnter ISBN to search for: ";
            getline(cin, target);
            index = searchArray(isbn, bookTitle,
                                isbn, author,
                                publisher, dateAdded,
                                qtyOnHand, wholesale,
                                retail, target,
                                bookCount);
            break;

        case '4':
            cout << "\nEnter publisher to search for: ";
            getline(cin, target);
            index = searchArray(publisher, bookTitle,
                                isbn, author,
                                publisher, dateAdded,
                                qtyOnHand, wholesale,
                                retail, target,
                                bookCount);
            break;

        default:
            break;
    }

    system("cls");

    return index;
}


/******************************************************************************
 * FUNCTION - searchArray
 * ____________________________________________________________________________
 * This function receives
 * ===> returns
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:

 * POST-CONDITIONS
 *
 ******************************************************************************/

int searchArray(const string targetArray[],
                const string bookTitle[],
                const string isbn[],
                const string author[],
                const string publisher[],
                const string date[],
                const int    qtyOnHand[],
                const double wholesale[],
                const double retail[],
                string target,
                const int bookCount) {

    int index = -1;
    int j;
    string matchesArray[bookCount];
    int    indexMatches[bookCount];
    int matchCount = 0;
    char choice;

    target = tolowerstring(target);


    for (int i = 0; i < bookCount; i ++) {
       if (tolowerstring(targetArray[i]).find(target) != string::npos) {
           matchesArray[matchCount]  = targetArray[matchCount];
           indexMatches[matchCount] = i;
           matchCount ++;
       }
   }
    if (matchCount != 0) {
        cout << "There were " << matchCount << " matches for the search query " << target << endl;

        j = 0;

        do {
            system("cls");
            cout << "Match [" << j + 1 << " / " << matchCount << "]\n\n";

            cout << left;
            cout << setw(14) << "Title: "     << bookTitle[indexMatches[j]] << endl;
            cout << setw(14) << "ISBN: "      << isbn[indexMatches[j]] << endl;
            cout << setw(14) << "Author: "    << author[indexMatches[j]] << endl;
            cout << setw(14) << "Publisher: " << publisher[indexMatches[j]] << endl;
            cout << right;

            cout << "\nIs this the book you were looking for? \n";
            cout << "[1] Yes\n";
            cout << "[2] No\n";
            choice = GetChoice(1, 2);
            system("cls");

            if (choice == '1') {
                index = j;
            }

            j ++;

        } while (choice != '1' && j < matchCount);
    }
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
 * 		    DATABASE_SIZE   : the max number of books possible in database
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
 * This function receives
 * ===> returns
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 *
 * POST-CONDITIONS
 *
 ******************************************************************************/

string getUniqueISBN(const string bookTitle[], const string isbn[], const int bookCount) {

    string tempISBN;
    bool isbnIsClone;

    do {
        int isbnCloneIndex = 0;

        cout << "Enter ISBN: ";
        getline(cin, tempISBN);

        isbnIsClone = false;
        for (int j = 0; j < bookCount; j ++) {
            if (tempISBN == isbn[j]) {
                isbnIsClone = true;
                isbnCloneIndex = j;
            }
        }

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
 * This function receives
 * ===> returns
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 *
 * POST-CONDITIONS
 *
 ******************************************************************************/

void editBook(const int& bookCount,
                string bookTitle[],
                string isbn[],
                string author[],
                string publisher[],
                string dateAdded[],
                int    qtyOnHand[],
                double wholesale[],
                double retail[]) {

    const int MENU_INDENT = 55;

    int index;
    char choice;

    index = lookUpBook(bookCount, bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail);

    do { // while (choice != '4')


        // main menu screen output
        cout << right;
        cout << "|" << setw(61) << "==[ Serendipity Booksellers ]==" << setw(33) << "|\n\n";
        cout << setw(56) << "--- Edit Book ---\n\n";

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
                getline(cin, bookTitle[index]);
                break;

            case '2':
                isbn[index] = getUniqueISBN(bookTitle, isbn, bookCount);

                break;

            case '3':
                cout << "Enter author: ";
                getline(cin, author[index]);
                break;

            case '4':
                cout << "Enter publisher: ";
                getline(cin, publisher[index]);
                break;

            case '5':
                cout << "Enter date of addition: ";
                getline(cin, dateAdded[index]);
                break;

            case '6':
                cout << "Enter quantity on hand: ";
                cin  >> qtyOnHand[index];
                while (qtyOnHand[index] < 0) {
                    cout << "Error - enter valid quantity: ";
                    cin  >> qtyOnHand[index];
                }
                cin.ignore(1000, '\n');
                break;

            case '7':
                cout << "Enter wholesale price: ";
                cin  >> wholesale[index];
                while ( wholesale[index] < 0) {
                    cout << "Error - enter valid quantity: ";
                    cin  >>  wholesale[index];
                }
                cin.ignore(1000, '\n');
                break;

            case '8':
                cout << "Enter retail price: ";
                cin  >> retail[index];
                while (retail[index] < 0) {
                    cout << "Error - enter valid quantity: ";
                    cin  >> retail[index];
                }
                cin.ignore(1000, '\n');
                break;

            case '9':
                cout << "Changes saved. Returning to Inventory Menu...\n";
                system("pause");
                break;


            default:
                break;

        } // end switch (choice)
        system("cls");


    } while (choice != '9');

    system("cls");
}

/******************************************************************************
 * FUNCTION - deleteBook
 * ____________________________________________________________________________
 * This function receives
 * ===> returns
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 *
 * POST-CONDITIONS
 *
 ******************************************************************************/

void deleteBook() {
    cout << "Welcome to the delete book menu!\n";
    cout << "There's nothing here! Go back to Inventory menu.\n\n";
    system("pause");
    system("cls");
}


