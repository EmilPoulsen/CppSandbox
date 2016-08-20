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
    string input = m_GuiLibrary.askTitleOrAuthor();
        if(input == "T"){

        }
        else if(input == "A"){
            //return input;
        }
        else{
            //should never hit this point.
        }
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
     vector<LendingItem*> lendingItems;
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
                lendingItems.push_back(newLibraryEntity);
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
            lendingItems.push_back(newLibraryEntity);
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
    //should m_GuiLibrary be deleted?!
    //delete [] m_GuiLibrary;
}

