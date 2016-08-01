#ifndef SORTEDVECTOR_H
#define SORTEDVECTOR_H
#include <iostream>
#include "utility.h";   //for the bubble sort
#include <math.h>       //for the floor function

using namespace std;

/**
 *Class for storing arbitrary types in sorted order. The type needs to overload
 * the out print operator << and binary comparisions < and >.
 */
template<class T, int sz>
class SortedVector{

public:
    /**
     * @brief SortedVector
     * Default constructor
     */
    SortedVector();

    /**
     * @brief add
     * Add an item to the sorted array
     * @param v
     * The item to add
     * @return
     * Returns true if successful, false if the array is full.
     */
    bool add(const T& v);

    /**
     * @brief median
     * Calculates the median of the array
     * @return
     * Returns the median object
     */
    T& median();

    /**
     * @brief removeLarger
     * Removes the items in the array larger than a threshold value
     * @param v
     * The threshold value
     */
    void removeLarger(const T& v);

    /**
     * @brief print
     * Prints the items in the array. Calls overloaded operator << of the object
     * @param os
     * The colsole out stream
     */
    void print( ostream &os );

    /**
     * Destructor
     */
    ~SortedVector(){
        //nothing to do here so far..
    }

private:
    int size; //The real size of the array
    int incr; //The amount of real objects in the array. Gets incremented for each item that is put into the array.
    T arr[sz]; //The array of objects
};


template<class T, int sz>
SortedVector<T, sz>::SortedVector(): size(sz){//, arr(new T[sz]){
    incr = 0; //initialize to zero
}

template<class T, int sz>
bool SortedVector<T, sz>::add(const T& v){
    //the array is full
    if(incr == size){
        return false;
    }
    //there is space left in the array
    else{
        arr[incr] = v; //set the object in the array
        incr++; //increment the number of objects in the array
        //Perform the sorting. Note that this is a relatively inefficient method
        //since the sorting is performed each time an item is added in the array.
        //Bubble sort has complexity O(N^2). Another approach could have been to
        //Add the items in the right order directly (Complexity O(N)), but this
        //works for now.
        utility::bubble(arr, incr);
        return true;
    }
}


template<class T, int sz>
void SortedVector<T, sz>::print( ostream &os ){
    for(int i = 0; i < incr; i++){
        os << arr[i]<< endl; //call the overloaded << operator
    }
}

template<class T, int sz>
T& SortedVector<T, sz>::median(){
    int middleIndex = (incr - 1) / 2; //calculate the mid index
    middleIndex = floor (middleIndex); //in case of even sized arrays, pick the lower
    return arr[middleIndex]; //return the object at this position

}

template<class T, int sz>
void SortedVector<T, sz>::removeLarger(const T& v){
    for(int i = 0; i < incr; i++){
        if(arr[i] > v){
            //found the array item larger than v.
            for(int j = i; j < incr; j++){
                //remove the items with indices larger than i.
                arr[j] = 0;
            }
            incr = i + 1; //update the incrementor
            return;
        }
    }
}


#endif // SORTEDVECTOR_H
