/*******************************************
 * AUTHOR   : GRANT GOLDSWORTH
 * ID	    : 1164709
 * PROJECT  : A23
 * DUE DATE : 5/6/2020
*******************************************/

#ifndef A4_SELECTIONSORT_H
#define A4_SELECTIONSORT_H

/******************************************************************************
 * FUNCTION - selectionSort
 * ____________________________________________________________________________
 * This function receives a list of pointers and an integer for the length of
 * the list
 * ===> returns nothing.
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 * 		    list
 * 		    length
 *
 * POST-CONDITIONS
 *      the list will be sorted (currently in descending) based on the
 *      operator defined for the comparison in the class
 ******************************************************************************/

template <class Type>
void selectionSort(Type* list[], int length) {
    Type* temp;
    int smallestIndex;


    for (int i = 0; i < length; i ++) {
        smallestIndex = i;

        // inner loop: compare the unsorted segment of array
        for (int j = i + 1; j < length; j ++) {
            if (*list[j] >= *list[smallestIndex]) {
                smallestIndex = j;
            }

        } // end inner loop - for (int j = i + 1; i < bookCount; j ++)

        // perform the swap
        temp = list[smallestIndex];
        list[smallestIndex] = list[i];
        list[i] = temp;

    } // end main loop - for(int i = 0; i < bookCount; i ++)

    temp = nullptr;
}

#endif //A4_SELECTIONSORT_H
