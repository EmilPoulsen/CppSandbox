#include "libraryapp.h"
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <vector>
#include "enums.h"
#include "compactdisc.h"
#include "book.h"
#include "journal.h"
#include <algorithm>

using namespace std;

LibraryApp::LibraryApp()
{
    m_IdCount = 0;
}

void LibraryApp::Run(){
    //string fileLoc = "input.txt";//"C:\\Users\\Emil\\Desktop\\input.txt";
    string fileLoc = "C:\\Users\\Emil\\Desktop\\input.txt";
    //string s2 = ExePath();
    //cout << s2 << endl;
    ReadLibraryDb(fileLoc);
    //m_GuiLibrary = new GuiLibrary();
    runMainLoop();


}



void LibraryApp::runMainLoop(){


    bool quitApp = false;
    while(!quitApp){
        m_GuiLibrary.printUserOptions();
        std::string input = m_GuiLibrary.readUserInput();
        processUserInput(input);
        quitApp = m_GuiLibrary.userSelectedExitOption(input);
    }
}


void LibraryApp::startSearchDialog(){

    vector<LendingItem*> foundObjects;
    string titleOrAuthor = m_GuiLibrary.askTitleOrAuthor();
    string searchString = m_GuiLibrary.enterSearchString();
    foundObjects = searchInLibrary(searchString, titleOrAuthor);

    if(foundObjects.size() == 0){
        string message = "Sorry, no objects found on search string '" + searchString + "'";
        m_GuiLibrary.printString(message);
    }
    else{
        printFoundObjects(foundObjects);
    }
}

void LibraryApp::printFoundObjects(vector<LendingItem*> &foundItems){
    vector<string> outputPerFoundItem;
    string separator = "-----------------------------";

    for(int i = 0; i < foundItems.size(); i++){
        outputPerFoundItem.clear();
        outputPerFoundItem.push_back(separator);
        LendingItem* currentItem = foundItems[i];
        outputPerFoundItem.push_back(currentItem->getItemTypeString());
        outputPerFoundItem.push_back(currentItem->getOriginator());
        outputPerFoundItem.push_back(currentItem->getTitle());
        outputPerFoundItem.push_back(currentItem->getIdString());
        outputPerFoundItem.push_back(separator);
        m_GuiLibrary.printStringVectorOnSeparateLines(outputPerFoundItem);
    }
}



vector<LendingItem*> LibraryApp::searchInLibrary(string &searchString, string &TitleorAuthor){
    vector<LendingItem*> foundObjects;

    for(int i = 0; i < m_LibraryDatabase.size(); i++)
    {
        LendingItem* currObject =   m_LibraryDatabase[i];
        string searchProperty;
        if(TitleorAuthor == "T"){
            searchProperty = currObject->getTitle();
        }
        else if(TitleorAuthor == "A"){
            searchProperty = currObject->getOriginator();
        }
        else{

        }

        if(stringContainsOtherString(searchString, searchProperty)){
            foundObjects.push_back(currObject);
        }
    }

    return foundObjects;
}

bool LibraryApp::stringContainsOtherString(string word, string substring){
    string s2 = word;
    string s1 = substring;

    m_GuiLibrary.convertStringToUpper(s1);
    m_GuiLibrary.convertStringToUpper(s2);
    bool found = (s1.find(s2) != std::string::npos);

    return found;

    }


void LibraryApp::processUserInput(std::string &input){
    //std::transform(input.begin(), input.end(),input.begin(), ::toupper);


    if(input == "X"){

    }

    else if(input == "H"){
        m_GuiLibrary.printHelp();
    }
    else if(input == "C"){
        //m_GuiLibrary.printHelp();
    }
    else if(input == "F"){
        //m_GuiLibrary.printHelp();
    }
    else if(input == "N"){
        //m_GuiLibrary.printHelp();
    }
    else if(input == "J"){
        //m_GuiLibrary.printHelp();
    }
    else if(input == "H"){
        //m_GuiLibrary.printHelp();
    }
    else if(input == "S"){
        startSearchDialog();
        //m_GuiLibrary.printHelp();
    }
    else if(input == "B"){
        //m_GuiLibrary.printHelp();
    }
    else if(input == "R"){
        //m_GuiLibrary.printHelp();
    }
    else if(input == "Q"){
        m_GuiLibrary.printExitMessege();
    }

    else{
        m_GuiLibrary.printInvalidInput(input);

    }

}


 void LibraryApp::ReadLibraryDb(string path){
    vector<string> database;
     database = ReadTextFile(path);
     vector<LendingItem> libraryDatabase;
     libraryDatabase = createLendingItemsFromTxt(database);




 }

 vector<LendingItem> LibraryApp:: createLendingItemsFromTxt(vector<string> database){
     //vector<LendingItem*> lendingItems;
     LendingItem* newLibraryEntity;
     int startRowOfObject;
     int endRowOfObject;
     Enums::ItemTypes prevItem;

     for(int i=0; i < database.size(); i++){
        //cout << database[i] << endl;
         Enums::ItemTypes item;
        item = txtLineIsNewLendingItem(database[i]);

        if(item != Enums::NonApplicable){
            //for the first item
            if(i != 0){
                //create the object if not equal to zero
                newLibraryEntity = createNewLendingItem(database, startRowOfObject, endRowOfObject, prevItem, generateNewId());
                m_LibraryDatabase.push_back(newLibraryEntity);
            }

            startRowOfObject = i;
            endRowOfObject = i;
            prevItem = item;
        }
        else{
            endRowOfObject++;
        }

        //for the last item
        if(i == database.size() -1){
            newLibraryEntity = createNewLendingItem(database, startRowOfObject, endRowOfObject, prevItem, generateNewId());
            m_LibraryDatabase.push_back(newLibraryEntity);
        }

     }

 }

 LendingItem* LibraryApp::createNewLendingItem(vector<string> &database, int &startrow, int &endrow, Enums::ItemTypes type, int id){
     LendingItem* newItem;
     switch(type)
     {
     case Enums::CD:
         newItem = new CompactDisc(database[startrow+1], database[startrow+2],  database[startrow+2], id);
       //cout << "-----CD\n";
       break;
     case Enums::Fiction:
       newItem = new Book(type, database[startrow+1],  database[startrow+2], id);
         //cout << "-----fiction\n";
       break;
     case Enums::Journal:
         newItem = new Journal(database[startrow+1], database[startrow+2], id);
       //    Journal(std::string title, std::string volume, int id);
       //cout << "------journal\n";
       break;
     case Enums::NonFiction:
        newItem = new Book(type, database[startrow+1],  database[startrow+2], id);
       //cout << "-----nonfiction\n";
       break;
     default:
       cout << "Invalid Selection\n";
       break;
     }
     newItem->setItemType(type);

     return newItem;
 }

 Enums::ItemTypes LibraryApp::txtLineIsNewLendingItem(string &line){

     for ( int fooInt = Enums::Fiction; fooInt != Enums::Last; fooInt++ )
     {
        Enums::ItemTypes foo = static_cast<Enums::ItemTypes>(fooInt);
        string strEnum = Enums::ToString(foo);

        if(line == strEnum)
            return foo;
     }

     return Enums::NonApplicable;

 }
int LibraryApp::generateNewId(){
    m_IdCount++;
    return 1000 + m_IdCount;
}






 vector<string> LibraryApp::ReadTextFile(string path){
     std::ifstream file(path);
     std::string str;
     vector<string> strVec;

     while (std::getline(file, str))
     {
         strVec.push_back(str);
         //cout << str << endl;
     }
     return strVec;

 }


LibraryApp:: ~LibraryApp(){
    //delete the library items
    for(int i = 0; i < m_LibraryDatabase.size(); ++i){
       delete m_LibraryDatabase[i];
    }
}

