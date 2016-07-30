#ifndef SORTEDVECTOR_H
#define SORTEDVECTOR_H
#include <iostream>
using namespace std;

template<class T, int sz>
class SortedVector{

public:
    SortedVector();

    bool add(const T& v);
//    T& median(); TO BE IMPLENTED
//    void removeLarger(const T& v); TO BE IMPLENTED
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
        return true;
    }
}

template<class T, int sz>
void SortedVector<T, sz>::print( ostream &os ){
    //string output;
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



//template<class T>
//T& SortedVector<T>::median(){

//}
//template<class T>
//void SortedVector<T>::removeLarger(const T& v){
//}

#endif // SORTEDVECTOR_H
