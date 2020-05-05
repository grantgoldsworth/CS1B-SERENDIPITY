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

template <class U>
void selectionSort(U *list, const int length, char style = 'a'){

    int index;
    int smallestIndex;
    int location;
    U   temp;
    unsigned long long int l = length;

    switch (tolower(style)) {

        // ascending sort
        case 'a':
        for (index = 0; index < length; index++) {
            //step a
            smallestIndex = index;
            for (location = index + 1; location < length; location++) {
                if (*list[location] < *list[smallestIndex])
                    smallestIndex = location;
            }
            //step b
            temp = list[smallestIndex];
            list[smallestIndex] = list[index];
            list[index] = temp;
        }

        // descending sort
        case 'd':
            for (index = 0; index < length; index++) {
                //step a
                smallestIndex = index;
                for (location = index + 1; location < length; location++) {
                    if (*list[location] > *list[smallestIndex])
                        smallestIndex = location;
                }
                //step b
                temp = list[smallestIndex];
                list[smallestIndex] = list[index];
                list[index] = temp;
            }
    }
}

#endif //A4_SELECTIONSORT_H
