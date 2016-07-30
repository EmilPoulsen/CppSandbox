#ifndef SORTEDVECTOR_H
#define SORTEDVECTOR_H
#include <iostream>
#include "utility.h";
#include <math.h>       /* floor */

using namespace std;

template<class T, int sz>
class SortedVector{

public:
    SortedVector();

    bool add(const T& v);
    T& median();
    void removeLarger(const T& v);
    void print( ostream &os );
    ~SortedVector(){
        //delete [] arr;
    }

private:
    int size;
    int incr;
    T arr[sz];
};



/**
 * @brief SortedVector::SortedVector
 * Default constructor
 */
template<class T, int sz>
SortedVector<T, sz>::SortedVector(): size(sz){//, arr(new T[sz]){
    incr = 0;
}

template<class T, int sz>
bool SortedVector<T, sz>::add(const T& v){

    if(incr == size){
        return false;
    }
    else{
        arr[incr] = v;
        incr++;
        utility::bubble(arr, incr);
        return true;
    }
}


template<class T, int sz>
void SortedVector<T, sz>::print( ostream &os ){
//    utility::bubble(arr, incr);
    //sort();
    for(int i = 0; i < incr; i++){
        //T curr = arr[i];
        //os << curr << endl;

        os << arr[i]<< endl;

        //os << " ";
       // T curr = arr[i];
       // output += std::to_string(curr) + " ";
    }
    //os << endl;

    //os << output << endl;
}

template<class T, int sz>
T& SortedVector<T, sz>::median(){
    int middleIndex = (incr - 1) / 2;
    middleIndex = floor (middleIndex);
    return arr[middleIndex];

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
            incr = i + 1;
            return;
        }
    }
}

#endif // SORTEDVECTOR_H
