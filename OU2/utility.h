#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;
#include <string>

/**
 *Namespace for storing utillity fucntions
 */

class utility{
    public:
        //static string doubleToStringDecimalPlaces(double value, int decimals);
    static string doubleToStringDecimalPlaces(double value, int decimals){
        std::stringstream stream;
        stream << std::fixed << setprecision(decimals) << value;
        string s = stream.str();
        return s;
    }

        /**
        *Bubble sort
        */
       template <class X>
       static void bubble(X *items,int count)
           {
             X t;

             for(int a=1; a<count; a++)
               for(int b=count-1; b>=a; b--)
                 if(items[b-1] > items[b]) {
                   t = items[b-1];
                   items[b-1] = items[b];
                   items[b] = t;
                 }
           }
};

#endif // UTILITY_H
