
#include <iostream>
using namespace std;

#ifndef LINKEDLISTCLASS_LINKEDLISTTYPE_H
#define LINKEDLISTCLASS_LINKEDLISTTYPE_H

/****** NODETYPE ******/
template <class Type>
struct nodeType
{
    Type info;
    nodeType<Type>* next;
};



/****** ITERATOR TYPE ******/
template <class Type>
class linkedListIterator {
public:
    // default constructor
    linkedListIterator();

    // node provided constructor
    linkedListIterator(nodeType<Type> *ptr);

    // dereference overload
    Type operator*();

    // increment overload
    linkedListIterator<Type> operator++ ();

    // equality overload
    bool operator==(const linkedListIterator<Type>&) const;

    // inequality operator overload
    bool operator!=(const linkedListIterator<Type>&) const;

private:
    // the current node that the iterator accesses
    nodeType<Type> *current;

};

/******** ITERATOR DEFINITIONS ******/

/******************************************************************************
 * FUNCTION - default constructor
 * ____________________________________________________________________________
 * Default constructor overload. Sets member current to nullptr
 * ===> returns nothing
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 *
 * POST-CONDITIONS
 *		iterator instance created
 *		member current = nullptr
 ******************************************************************************/

template <class Type>
linkedListIterator<Type>::linkedListIterator() {
    current = nullptr;
}




/******************************************************************************
 * FUNCTION - iterator constructor - node parameter
 * ____________________________________________________________________________
 * constructor overload. Sets member current node passed as parameter
 * ===> returns nothing
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 *
 * POST-CONDITIONS
 *		iterator instance created
 *		member current = nullptr
 ******************************************************************************/

template <class Type>
linkedListIterator<Type>::linkedListIterator(nodeType<Type> *ptr) {
    current = ptr;
}




/******************************************************************************
 * FUNCTION - dereference operator overload
 * ____________________________________________________________________________
 * * operator overload.
 * ===> returns the value stored in the current node
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 *          iterator instance is defined
 * POST-CONDITIONS
 *		value stored in current node is returned to calling function
 ******************************************************************************/

template <class Type>
Type linkedListIterator<Type>::operator*() {
    return current->info;
}




/******************************************************************************
 * FUNCTION - increment operator overload
 * ____________________________________________________________________________
 * ++ operator overload. sets current to the next node in the list
 * ===> returns the value of the (new) current node
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 *          iterator instance is defined
 * POST-CONDITIONS
 *		(new) current node is returned to calling function
 ******************************************************************************/

template<class Type>
linkedListIterator<Type> linkedListIterator<Type>::operator++() {

    current = current->next;

    return *this;
}




/******************************************************************************
 * FUNCTION - equality operator overload
 * ____________________________________________________________________________
 * == operator overload. compares current node against other iterator's node for equality
 * ===> returns a bool
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 *          iterator instance is defined
 * POST-CONDITIONS
 *		instances are not modified
 *		a bool is returned to the calling function
 ******************************************************************************/

template<class Type>
bool linkedListIterator<Type>::operator==(const linkedListIterator<Type>& other) const {
    return (current == other.current);
}




/******************************************************************************
 * FUNCTION - inequality operator overload
 * ____________________________________________________________________________
 * == operator overload. compares current node against other iterator's node for inequality
 * ===> returns a bool
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 *          iterator instance is defined
 * POST-CONDITIONS
 *		instances are not modified
 *		a bool is returned to the calling function
 ******************************************************************************/

template<class Type>
bool linkedListIterator<Type>::operator!=(const linkedListIterator<Type>& other) const {
    return (current != other.current);
}







/****** LINKEDLIST TYPE ******/
template <class Type>
class linkedListType {
public:

    /****** CONSTRUCTORS ******/

    // default constructor
    linkedListType();

    // copy constructor
    linkedListType(const linkedListType<Type>&);

    // destructor
    ~linkedListType();

    // assignment overload
    linkedListType<Type>& operator=(const linkedListType<Type>&);

    // set to empty list
    void initializeList();

    // returns if list is empty
    bool isEmpty() const;

    // print the list elements
    void print() const;

    // return number of elements
    int length() const;

    // destroy list and set to empty
    void destroyList();

    // return first element in the list
    Type front() const;

    //return last element in list
    Type back() const;

    /****** VIRTUAL FUNCTIONS ******/
    // sees if an item is in the list
    virtual bool search(const Type&) const = 0;

    // add item to front of list
    virtual void insertFirst(const Type&) = 0;

    // add item to end of list
    virtual void insertLast(const Type&) = 0;

    // delete a node
    virtual void deleteNode(const Type&) = 0;


    /****** ITERATOR CONTROLS ******/
    // set an iterator to the beginning of the list
    linkedListIterator<Type> begin();

    // set an iterator to the end of the list
    linkedListIterator<Type> end();



protected:
    // to be inherited as private to classes unorderedLinkedList and orderedLinkedList
    int count;
    nodeType<Type>* head;
    nodeType<Type>* tail;


private:
    // make a copy of another list
    void copyList(const linkedListType<Type>&);
};

/******** LINKED LIST TYPE DEFINITIONS ******/

/******************************************************************************
 * FUNCTION - linked list default constructor
 * ____________________________________________________________________________
 * ==
 * ===> returns
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 *
 * POST-CONDITIONS
 *
 ******************************************************************************/
template<class Type>
linkedListType<Type>::linkedListType() {
    head = nullptr;
    tail = nullptr;
    count = 0;
}




/******************************************************************************
* FUNCTION - copy constructor
* ____________________________________________________________________________
* ==
* ===> returns
* PRE-CONDITIONS
* 		Following must be defined prior to function call:
*
* POST-CONDITIONS
*
******************************************************************************/
template <class Type>
linkedListType<Type>::linkedListType(const linkedListType& other) {
    head = nullptr;
    copyList(other);
}




/******************************************************************************
 * FUNCTION - initializeList
 * ____________________________________________________________________________
 * ==
 * ===> returns
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 *
 * POST-CONDITIONS
 *
 ******************************************************************************/
template<class Type>
void linkedListType<Type>::initializeList() {
    destroyList(); // will set to empty list regardless of nodes
}




/******************************************************************************
 * FUNCTION - print
 * ____________________________________________________________________________
 * ==
 * ===> returns
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 *
 * POST-CONDITIONS
 *
 ******************************************************************************/
template<class Type>
void linkedListType<Type>::print() const {
    nodeType<Type>* current = head;
    while (current != nullptr) {
        cout << current->info << " ";
        current = current->next;
    }
}




/******************************************************************************
 * FUNCTION - length
 * ____________________________________________________________________________
 * ==
 * ===> returns
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 *
 * POST-CONDITIONS
 *
 ******************************************************************************/
template<class Type>
int linkedListType<Type>::length() const {
    return count;
}





/******************************************************************************
 * FUNCTION - isEmpty
 * ____________________________________________________________________________
 * ==
 * ===> returns
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 *
 * POST-CONDITIONS
 *
 ******************************************************************************/
template<class Type>
bool linkedListType<Type>::isEmpty() const {
    return head == nullptr;
}




/******************************************************************************
 * FUNCTION - destroyList
 * ____________________________________________________________________________
 * ==
 * ===> returns
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 *
 * POST-CONDITIONS
 *
 ******************************************************************************/
 template<class Type>
 void linkedListType<Type>::destroyList() {
     nodeType<Type>* temp;

     while (head != nullptr) {
         temp = head;       // set temp to current pointer
         head = head->next; // set head to next pointer
         delete temp;       // deallocate memory
     }

     // set list to null state
     tail = nullptr;
     count = 0;
 }




/******************************************************************************
* FUNCTION - front
* ____________________________________________________________________________
* ==
* ===> returns
* PRE-CONDITIONS
* 		Following must be defined prior to function call:
*
* POST-CONDITIONS
*
******************************************************************************/
template<class Type>
Type linkedListType<Type>::front() const {

    Type result;

    if (!isEmpty()) {
        result = head->info;
    }
    else {
        cout << "LIST IS EMPTY -- RETURN 0\n";
        result = 0;
    }

    return result;
}




/******************************************************************************
* FUNCTION - back
* ____________________________________________________________________________
* ==
* ===> returns
* PRE-CONDITIONS
* 		Following must be defined prior to function call:
*
* POST-CONDITIONS
*
******************************************************************************/
template<class Type>
Type linkedListType<Type>::back() const {

    Type result;

    if (!isEmpty()) {
        result = tail->info;
    }
    else {
        cout << "***** LIST IS EMPTY -- RETURN 0 *****\n";
        result = 0;
    }

    return result;
}




/******************************************************************************
* FUNCTION - begin
* ____________________________________________________________________________
* ==
* ===> returns
* PRE-CONDITIONS
* 		Following must be defined prior to function call:
*
* POST-CONDITIONS
*
******************************************************************************/
template<class Type>
linkedListIterator<Type> linkedListType<Type>::begin() {
    // create a temporary iterator
    // call iterator constructor and pass the head node to set
    //  iterator to the head of the list
    linkedListIterator<Type> temp(head);

    return temp;

}




/******************************************************************************
* FUNCTION - end
* ____________________________________________________________________________
* ==
* ===> returns
* PRE-CONDITIONS
* 		Following must be defined prior to function call:
*
* POST-CONDITIONS
*
******************************************************************************/
template<class Type>
linkedListIterator<Type> linkedListType<Type>::end() {
    // create a temporary iterator
    // call iterator constructor and pass nullptr to
    // have it "point" to "one past the last node"
    linkedListIterator<Type> temp(nullptr);

    return temp;

}




/******************************************************************************
* FUNCTION - copyList
* ____________________________________________________________________________
* ==
* ===> returns
* PRE-CONDITIONS
* 		Following must be defined prior to function call:
*
* POST-CONDITIONS
*
******************************************************************************/
template<class Type>
void linkedListType<Type>::copyList(const linkedListType<Type> &otherList) {
    // perform deep copy of otherList

    nodeType<Type>* newNode;    // temp node used in creating new copy
    nodeType<Type>* current;    // navigational pointer

    // make sure the instance is an empty list
    if (head != nullptr) {
        destroyList();
    }

    // other list is empty
    if (otherList.head == nullptr) {
        // set main instance to be default empty
        // not necessary?
        head = nullptr;
        tail = nullptr;
        count = 0;
    }
    else {
        // other list is not empty
        // commence deep copy
        // copy the head node and the count value
        current = otherList.head;
        count = otherList.count;

        // copy the first node over into the head and create 1 node list
        head = new nodeType<Type>;
        head->info = current->info;
        head->next = nullptr;
        tail = head;

        // move current to next node of other list
        current = current->next;

        // traverse otherList and copy values
        while (current != nullptr) {
            // create newNode for main instance
            newNode = new nodeType<Type>;
            newNode->info = current->info;
            newNode->next = current->next;

            // put the new node at the end of the main instance list
            tail->next = newNode;
            tail = newNode;

            // next node
            current = current->next;

        } // end while (current != nullptr)
    } // end if-else (otherList.isEmpty())
}




/******************************************************************************
* FUNCTION - destructor
* ____________________________________________________________________________
* ==
* ===> returns
* PRE-CONDITIONS
* 		Following must be defined prior to function call:
*
* POST-CONDITIONS
*
******************************************************************************/
template <class Type>
linkedListType<Type>::~linkedListType<Type>() {
    destroyList();
}




/******************************************************************************
* FUNCTION - assignment overload
* ____________________________________________________________________________
* ==
* ===> returns
* PRE-CONDITIONS
* 		Following must be defined prior to function call:
*
* POST-CONDITIONS
*
******************************************************************************/
template <class Type>
linkedListType<Type>& linkedListType<Type>::operator=(const linkedListType<Type>& other)  {
    // check for self assignment
    if (this != &other) {
        copyList(other);
    }
    return *this;
}
















#endif //LINKEDLISTCLASS_LINKEDLISTTYPE_H
