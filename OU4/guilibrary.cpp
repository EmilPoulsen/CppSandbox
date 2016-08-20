#include "guilibrary.h"
#include <iostream>
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

GuiLibrary::GuiLibrary()
{


}

void GuiLibrary::startGui(){
    printUserOptions();
    readUserInput();



}

void GuiLibrary::printUserOptions(){

    cout<< "Choose one of X/C/F/N/J/H(Help)/S/B/R/Q" << endl;
}

std::string GuiLibrary::readUserInput(){
    std::string s;
    cin >> s;
    convertStringToUpper(s);
    //std::transform(s.begin(), s.end(),s.begin(), ::toupper);
    return s;
}

void GuiLibrary::convertStringToUpper(std::string &str){
    std::transform(str.begin(), str.end(),str.begin(), ::toupper);
}


string GuiLibrary::askTitleOrAuthor(){

    //loop will quit when acceptable answer is given
    while(true)
    {
        cout << "Search by title (T) or author/artist (A)??";
        string input = readUserInput();
        if(input == "T"){
            return input;
        }
        else if(input == "A"){
            return input;
        }
        else{
            printInvalidInput(input);
        }
    }
}

void GuiLibrary::printHelp(){
    cout << "C - insert new CD" << endl;
    cout << "F - insert new Fiction book" << endl;
    cout << "N - insert new Non-Fiction book" << endl;
    cout << "J - insert new Journal" << endl;
    cout << "X - remove an object from the library" << endl;
    cout << "H - show this text" << endl;
    cout << "S - search" << endl;
    cout << "B - borrow a object" << endl;
    cout << "R - return an object" << endl;
    cout << "Q - quit the program" << endl;
}


void GuiLibrary::printInvalidInput(std::string &input){
    cout << "Invalid input '" << input << "'. Please try again." << endl;
}

bool GuiLibrary::userSelectedExitOption(std::string &input){
    return input == "Q";
}

void GuiLibrary::printExitMessege(){
    cout << "The application will now exit" << endl;
}
