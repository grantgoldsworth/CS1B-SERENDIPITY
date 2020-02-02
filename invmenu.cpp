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

void lookUpBook(const int& DATABASE_SIZE,
                int   bookCount,
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
            index = searchArray(bookTitle, target, bookCount);
            break;

        case '2':
            cout << "\nEnter author to search for: ";
            getline(cin, target);
            index = searchArray(author, target, bookCount);
            break;

        case '3':
            cout << "\nEnter ISBN to search for: ";
            getline(cin, target);
            index = searchArray(isbn, target, bookCount);
            break;

        case '4':
            cout << "\nEnter publisher to search for: ";
            getline(cin, target);
            index = searchArray(publisher, target, bookCount);
            break;

        default:
            break;
    }

    if (index != -1) {
        BookInformation(bookTitle[index],
                isbn[index],
                author[index],
                publisher[index],
                dateAdded[index],
                qtyOnHand[index],
                wholesale[index],
                retail[index]);
    }
    else if (choice != '5') {
        cout << "\nBook not found. Exiting search...\n";
    }

    system("pause");
    system("cls");

    return;
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

int searchArray(const string array[], string target, int bookCount) {

    int index = -1;

    target = tolowerstring(target);

    for (int i = 0; i < bookCount; i ++) {
       if (tolowerstring(array[i]).find(target) != string::npos) {
           index = i;
       }
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

void addBook(const int& DATABASE_SIZE,
             int& bookCount,
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
    char saveChoice;

    string tempTitle        = "EMPTY";
    string tempISBN         = "EMPTY";
    string tempAuthor       = "EMPTY";
    string tempPublisher    = "EMPTY";
    string tempDate         = "EMPTY";
    int    tempQty          = 0;
    double tempWholesale    = 0;
    double tempRetail       = 0;


    if (bookCount < DATABASE_SIZE) {
        do { // while (choice != '4')

            // main menu screen output
            cout << right;
            cout << "|" << setw(61) << "==[ Serendipity Booksellers ]==" << setw(33) << "|\n\n";
            cout << setw(56) << "--- Add Book ---\n\n";

            cout << "CURRENT DATABASE SIZE: " << DATABASE_SIZE << setw(10) << ' ' << "BOOK COUNT: " << bookCount << endl
                 << endl;

            cout << left;
            cout << setfill('=') << setw(MENU_INDENT + 25) << "=" << endl;
            cout << setfill(' ');
            cout << setw(MENU_INDENT) << "[1] Enter book title" << "| -- " << tempTitle << endl;
            cout << setw(MENU_INDENT) << "[2] Enter ISBN" << "| -- " << tempISBN << endl;
            cout << setw(MENU_INDENT) << "[3] Enter author" << "| -- " << tempAuthor << endl;
            cout << setw(MENU_INDENT) << "[4] Enter publisher" << "| -- " << tempPublisher << endl;
            cout << setw(MENU_INDENT) << "[5] Enter date added (MM/DD/YYYY)" << "| -- " << tempDate << endl;
            cout << setw(MENU_INDENT) << "[6] Enter quantity on hand" << "| -- " << tempQty << endl;
            cout << setw(MENU_INDENT) << "[7] Enter wholesale cost" << "| -- " << tempWholesale << endl;
            cout << setw(MENU_INDENT) << "[8] Enter retail price" << "| -- " << tempRetail << endl;
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
                    break;

                case '2':
                    cout << "Enter ISBN: ";
                    getline(cin, tempISBN);
                    break;

                case '3':
                    cout << "Enter author: ";
                    getline(cin, tempAuthor);
                    break;

                case '4':
                    cout << "Enter publisher: ";
                    getline(cin, tempAuthor);
                    break;

                case '5':
                    cout << "Enter date of addition: ";
                    getline(cin, tempDate);
                    break;

                case '6':
                    cout << "Enter quantity on hand: ";
                    cin >> tempQty;
                    cin.ignore(1000, '\n');
                    break;

                case '7':
                    cout << "Enter wholesale price: ";
                    cin >> tempWholesale;
                    cin.ignore(1000, '\n');
                    break;

                case '8':
                    cout << "Enter retail price: ";
                    cin >> tempRetail;
                    cin.ignore(1000, '\n');
                    break;

                case '9':
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

                    break;

                default:
                    break;

            } // end switch (choice)
            system("cls");


        } while (choice != '0');
    }
    else {
        cout << "\n\n****** ERROR - MAXIMUM DATABASE CAPACITY REACHED - CANNOT ADD MORE BOOKS ******\n";
        cout << "****** DATABASE SIZE: " << DATABASE_SIZE << " --- BOOK COUNT: " << bookCount << " ******\n\n";
        system("pause");
    }
    system("cls");
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

void editBook() {
    cout << "Welcome to the edit book menu!\n";
    cout << "There's nothing here! Go back to Inventory menu.\n\n";
    system("pause");
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


