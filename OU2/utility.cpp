#include "utility.h"

#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

namespace utility
{
string doubleToStringDecimalPlaces(double value, int decimals){
    std::stringstream stream;
    stream << std::fixed << setprecision(decimals) << value;
    string s = stream.str();
    return s;
}



/*
 string doubleToStringDecimalPlaces(double value, int decimals){
     return "";
 }


string doubleToStringDecimalPlaces(double value, int decimals){
    std::stringstream stream;
    stream << std::fixed << setprecision(decimals) << value;
    string s = stream.str();
    return s;
}
*/

}
