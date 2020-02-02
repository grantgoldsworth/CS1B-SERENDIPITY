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
 *
 * POST-CONDITIONS
 *
 ******************************************************************************/

void lookUpBook() {
    cout << "Welcome to the look up book menu!\n";
    cout << "There's nothing here! Go back to Inventory menu.\n\n";
    system("pause");
    system("cls");

    return;
}

/******************************************************************************
 * FUNCTION - addBook
 * ____________________________________________________________________________
 * This function receives
 * ===> returns
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 *
 * POST-CONDITIONS
 *
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


    do { // while (choice != '4')

        // main menu screen output
        cout << right;
        cout << "|" << setw(61) << "==[ Serendipity Booksellers ]==" << setw(33) << "|\n\n";
        cout << setw(56) << "--- Add Book ---\n\n";

        cout << "CURRENT DATABASE SIZE: " << DATABASE_SIZE << setw(10) << ' ' << "BOOK COUNT: " << bookCount << endl << endl;

        cout << left;
        cout << setfill('=') << setw(MENU_INDENT  + 25) << "=" << endl;
        cout << setfill(' ');
        cout << setw(MENU_INDENT) << "[1] Enter book title"                 << "| -- " << tempTitle << endl;
        cout << setw(MENU_INDENT) << "[2] Enter ISBN"                       << "| -- " << tempISBN << endl;
        cout << setw(MENU_INDENT) << "[3] Enter author"                     << "| -- " << tempAuthor << endl;
        cout << setw(MENU_INDENT) << "[4] Enter publisher"                  << "| -- " << tempPublisher << endl;
        cout << setw(MENU_INDENT) << "[5] Enter date added (MM/DD/YYYY)"    << "| -- " << tempDate << endl;
        cout << setw(MENU_INDENT) << "[6] Enter quantity on hand"           << "| -- " << tempQty << endl;
        cout << setw(MENU_INDENT) << "[7] Enter wholesale cost"             << "| -- " << tempWholesale << endl;
        cout << setw(MENU_INDENT) << "[8] Enter retail price"               << "| -- " << tempRetail << endl;
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
                cout <<  "Enter author: ";
                getline(cin, tempAuthor);
                break;

            case '4':
                cout <<  "Enter publisher: ";
                getline(cin, tempAuthor);
                break;

            case '5':
                cout <<  "Enter date of addition: ";
                getline(cin, tempDate);
                break;

            case '6':
                cout <<  "Enter quantity on hand: ";
                cin  >> tempQty;
                cin.ignore(1000, '\n');
                break;

            case '7':
                cout <<  "Enter wholesale price: ";
                cin  >> tempWholesale;
                cin.ignore(1000, '\n');
                break;

            case '8':
                cout <<  "Enter retail price: ";
                cin  >> tempRetail;
                cin.ignore(1000, '\n');
                break;

            case '9':
                cout << "You are about to add the book \"" << tempTitle << "\" to the database. Do you wish to save these changes?\n";
                cout << "[1] Yes\n";
                cout << "[2] No\n";
                saveChoice = GetChoice(1,2);

                if (saveChoice == '1') {
                    bookTitle[bookCount]    = tempTitle;
                    isbn[bookCount]         = tempISBN;
                    author[bookCount]       = tempAuthor;
                    publisher[bookCount]    = tempPublisher;
                    dateAdded[bookCount]    = tempDate;
                    qtyOnHand[bookCount]    = tempQty;
                    wholesale[bookCount]    = tempWholesale;
                    retail[bookCount]       = tempRetail;

                    bookCount ++;

                    // reset placeholders to default values for next book entry
                    tempTitle        = "EMPTY";
                    tempISBN         = "EMPTY";
                    tempAuthor       = "EMPTY";
                    tempPublisher    = "EMPTY";
                    tempDate         = "EMPTY";
                    tempQty          = 0;
                    tempWholesale    = 0;
                    tempRetail       = 0;
                }
                break;


            default:
                break;

        } // end switch (choice)
        system("cls");


    } while (choice != '0');
    system("cls");
}

/******************************************************************************
 * FUNCTION - editBook
 * ____________________________________________________________________________
 * This function receives
 * ===> returns5/24/12
2
0-333-9012-8
History of Beans
19.95
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


