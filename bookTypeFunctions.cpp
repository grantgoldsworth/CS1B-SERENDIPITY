#include "bookType.h"
#include <string>

void SetBookTitle(bookType* book, string newTitle) {
    book->bookTitle = newTitle;
}

void SetISBN(bookType* book, string newISBN) {
    book->isbn = newISBN;
}

void SetAuthor(bookType* book, string newAuthor) {
    book->author = newAuthor;
}

void SetPublisher(bookType* book, string newPublisher) {
    book->publisher = newPublisher;
}

void SetDateAdded(bookType* book, string newDate) {
    book->dateAdded = newDate;
}

void SetQtyOnHand(bookType* book, int newQty) {
    book->qtyOnHand = newQty;
}

void SetWholesale(bookType* book, float newWholesale) {
    book->wholesale = newWholesale;
}

void SetRetail(bookType* book, float newRetail) {
    book->retail = newRetail;
}