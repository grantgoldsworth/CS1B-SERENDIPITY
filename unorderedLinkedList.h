
#include "linkedListType.h"

#ifndef CS1B_A35_UNORDEREDLINKEDLIST_H
#define CS1B_A35_UNORDEREDLINKEDLIST_H
template <class Type>
class unorderedLinkedList: public linkedListType<Type>
{
private:
    void divideList(nodeType<Type>* first1, nodeType<Type>* &first2);

    nodeType<Type>* mergeList(nodeType<Type>* first1, nodeType<Type>* first2);

    void recMergeSort( nodeType<Type>* &head);

public:

    // search the list for an item
    bool search(const Type& searchItem) const;

    // overload insertFirst from parent
    void insertFirst(const Type& newItem);

    // overload insertLast from parent
    void insertLast(const Type& newItem);

    // delete a node
    void deleteNode(const Type& deleteItem);

    Type operator[](int index);

    void mergeSort();

};




/****** DEFINITIONS ******/

/******************************************************************************
* FUNCTION - search
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
bool unorderedLinkedList<Type>::search(const Type& searchItem) const {

    bool stop = false;                  // search while loop controller
    nodeType<Type>* current = nullptr;  // the current node navigation pointer

    current = linkedListType<Type>::head;

    while (current != nullptr && !stop) {
        // either found or passed spot item could be in
        if (searchItem == current->info) {
            // the item was found
            stop = true;
        }
        else {
            // item not found - go to the next node
            current = current->next;
        }
    } // end while(current != nullptr && !stop)

    return stop;
}




/******************************************************************************
* FUNCTION - insertFirst
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
void unorderedLinkedList<Type>::insertFirst(const Type &newItem) {
    nodeType<Type>* newNode;

    // initialize new node
    newNode = new nodeType<Type>;
    newNode->info = newItem;
    newNode->next = linkedListType<Type>::head;
    linkedListType<Type>::head = newNode;

    linkedListType<Type>::count ++;

    if (linkedListType<Type>::tail == nullptr) {
        linkedListType<Type>::tail = newNode;
    }

}




/******************************************************************************
* FUNCTION - insertLast
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
void unorderedLinkedList<Type>::insertLast(const Type &newItem) {
    nodeType<Type>* newNode;

    // initialize new node
    newNode = new nodeType<Type>;
    newNode->info = newItem;
    newNode->next = nullptr;

    if (linkedListType<Type>::head == nullptr) {
        linkedListType<Type>::head = newNode;
        linkedListType<Type>::tail = newNode;
    }
    else {
        linkedListType<Type>::tail->next = newNode;
        linkedListType<Type>::tail = newNode;
    }

    linkedListType<Type>::count ++;
}



/******************************************************************************
* FUNCTION - delete
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
void unorderedLinkedList<Type>::deleteNode(const Type &deleteItem) {
    nodeType<Type> *current;    // traversal control
    nodeType<Type> *previous;   // traversal control, points to node before current
    bool stop = false;          // traversal loop control, whether a match or no match possible point is found

    previous = nullptr;

    // case 1: the list is empty
    // case 2: item to delete is the first node
    // case 3: item to delete is in the list somewhere
    // case 4: item to delete is not in the list, and list is not empty

    // case 1:
    if (linkedListType<Type>::head == nullptr) {
        cout << "LIST IS EMPTY -- CANNOT PERFORM DELETION\n";
    } // end case 1
    else {
        // case 2
        if (linkedListType<Type>::head->info == deleteItem) {
            current = linkedListType<Type>::head;
            linkedListType<Type>::head = linkedListType<Type>::head->next;
            linkedListType<Type>::count --;

            // 1 node list
            if (linkedListType<Type>::head == nullptr) {
                linkedListType<Type>::tail = nullptr;
            }

            // delete the node
            delete current;
        } // end case 2
        else {
            // search list for target node
            stop = false;
            previous = linkedListType<Type>::head;
            current = linkedListType<Type>::head->next;

            while (current != nullptr && !stop) {
                if (current->info != deleteItem) {
                    previous = current;
                    current = current->next;
                }
                else {
                    stop = true;
                }
            } // end search while

            // case 3: item found
            if (stop) {
                previous->next = current->next;
                if (linkedListType<Type>::tail == current) {
                    // delete item is last item
                    linkedListType<Type>::tail = previous;
                }
                delete current;
            }
            else {
                cout << "Item was not found in the list. Nothing deleted.\n";
            }
        }

    }

}





/******************************************************************************
* FUNCTION - index operator overload
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
Type unorderedLinkedList<Type>::operator[](int index) {

    linkedListIterator<Type> itr = linkedListType<Type>::begin();
    Type result;

    // ensure list is not empty
    if (!linkedListType<Type>::isEmpty()) {

        // check if index is within bounds
        if (index >= 0 && index < linkedListType<Type>::count) {
            // index is within bounds

            for (int i = 0; i < index; i++) {
                ++itr;
            }

            result = *itr;
        }
        else {
            cout << "INDEX OUT OF BOUNDS\n";

        } // end if else (index >= 0 && index < linkedListType<Type>::count)

    } // end if (!linkedListType<Type>::isEmpty())

    else {
        cout << "EMPTY LIST\n";
    }

    return result;
}




/******************************************************************************
* FUNCTION - index operator overload
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
void unorderedLinkedList<Type>::divideList(nodeType<Type> *first1, nodeType<Type> *&first2) {
    nodeType<Type>* middle;
    nodeType<Type>* current;

    if (first1 == nullptr) //list is empty
        first2 = nullptr;

    else if (first1->next == nullptr) //list has only one node
        first2 = nullptr;

    else
    {
        middle = first1;
        current = first1->next;
        if (current != nullptr) //list has more than two nodes
            current = current->next;

        while (current != nullptr)
        {
            middle = middle->next;
            current = current->next;

            if (current != nullptr)
                current = current->next;
        } //end while

        first2 = middle->next; //first2 points to the first node of the second sublist
        middle->next = nullptr; //set the next of the last node of the first sublist to nullptr
    } //end else
} //end divideList






/******************************************************************************
* FUNCTION - index operator overload
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
nodeType<Type>* unorderedLinkedList<Type>::mergeList(nodeType<Type> *first1, nodeType<Type> *first2) {

    nodeType<Type> *lastSmall;  //pointer to the last node of the merged list
    nodeType<Type> *newHead;    //pointer to the merged list

    if (first1 == nullptr)      //the first sublist is empty
        return first2;

    else if (first2 == nullptr) //the second sublist is empty
        return first1;

    else {
        if (first1->info < first2->info) //compare the first nodes
        {
            newHead = first1;
            first1 = first1->next;
            lastSmall = newHead;
        } else {
            newHead = first2;
            first2 = first2->next;
            lastSmall = newHead;
        }
        while (first1 != nullptr && first2 != nullptr) {
            if (first1->info < first2->info) {
                lastSmall->next = first1;
                lastSmall = lastSmall->next;
                first1 = first1->next;
            } else {
                lastSmall->next = first2;
                lastSmall = lastSmall->next;
                first2 = first2->next;
            }
        } //end while
        if (first1 == nullptr) //first sublist exhausted first
            lastSmall->next = first2;
        else //second sublist exhausted first
            lastSmall->next = first1;
        return newHead;
    }
}





/******************************************************************************
* FUNCTION -
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
void unorderedLinkedList<Type>::recMergeSort(nodeType<Type> *&head) {
    nodeType<Type> *otherHead;
    if (head != nullptr) //if the list is not empty
        if (head->next != nullptr) //if the list has more than one node
        {
            divideList(head, otherHead);
            recMergeSort(head);
            recMergeSort(otherHead);
            head = mergeList(head, otherHead);
        }
}





/******************************************************************************
* FUNCTION -
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
void unorderedLinkedList<Type>::mergeSort() {
    recMergeSort(linkedListType<Type>::head);

    if (linkedListType<Type>::head == nullptr) {
        linkedListType<Type>::tail = nullptr;
    }
    else {
        linkedListType<Type>::tail = linkedListType<Type>::head;
        while (linkedListType<Type>::tail->next != nullptr) {
            linkedListType<Type>::tail = linkedListType<Type>::tail->next;
        }
    }

}



#endif //CS1B_A35_UNORDEREDLINKEDLIST_H
