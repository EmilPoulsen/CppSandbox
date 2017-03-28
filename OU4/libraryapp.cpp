#include "libraryapp.h"
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <vector>
#include "enums.h"
#include "compactdisc.h"
#include "book.h"
#include "fictionbook.h"
#include "nonfictionbook.h"
#include "journal.h"
#include <algorithm>
using namespace std;

//TODO: add comments and documentation
LibraryApp::LibraryApp(){
    m_Path = "";
    m_IdCount = 0;
}

void LibraryApp::Run(){
    if(m_Path == ""){
        m_GuiLibrary.printString("The path has not been set and the program cannot run.");
        return;
    }
    if(!ReadLibraryDb(m_Path)){
        m_GuiLibrary.printString("Either the database is empty or the file directory is incorrect. Program cannot run.");
        return;
    }
    runMainLoop();
}

void LibraryApp::setDatabasePath(string s){
    m_Path = s;
}

void LibraryApp::runMainLoop(){
    bool quitApp = false;
    while(!quitApp){
        m_GuiLibrary.printUserOptions();
        std::string input = m_GuiLibrary.readUserInput();
        processUserInput(input);
        quitApp = m_GuiLibrary.userSelectedExitOption(input);
    }
    if(userWantsToSaveFile())
        saveFile();
}

bool LibraryApp::userWantsToSaveFile(){
    while(true){ //loop will quit when user selects an acceptable answer
        m_GuiLibrary.printStringWithoutEndLine("Would you like to save the database? [y/n]");
        string input = m_GuiLibrary.readUserInput();
        if(input == "Y"){
            return true;
        }
        else if(input == "N"){
            return false;
        }
        else{
            m_GuiLibrary.printInvalidInput(input);
        }
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
    for(unsigned int i = 0; i < foundItems.size(); i++){
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
    for(unsigned int i = 0; i < m_LibraryDatabase.size(); i++)
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

void LibraryApp::borrowLibraryItem(){
    int id;
    int borrower;
    bool success = m_GuiLibrary.initializeBorrowProceedure(id, borrower);
    if(!success)
        return;
    LendingItem* item;
    item = findLendingItemFromIndex(id);
    if(item == nullptr){
        m_GuiLibrary.printString("No items with index " + std::to_string(id) + " was found.");
        return;
    }
    if(item->getLenderIndex() != 0){
        m_GuiLibrary.printString("Sorry, item with index " + std::to_string(id) + " is currently lent out to someone else.");
        return;
    }
    borrowItem(item, borrower);
    m_GuiLibrary.printString("Item with index " + std::to_string(id) + " was successfully lent out to borrower " + std::to_string(borrower));
}

void LibraryApp::borrowItem(LendingItem* item, int borrower){
    item->setLenderIndex(borrower);
}

LendingItem* LibraryApp::findLendingItemFromIndex(int index){
    for(unsigned int i = 0; i < m_LibraryDatabase.size(); i++){
        LendingItem* currItem = m_LibraryDatabase[i];
        if(currItem->getID() == index){
            return currItem;
        }
    }
    return nullptr;
}

LendingItem* LibraryApp::findLendingItemFromIndex(int index, int &indexInVector){
    for(unsigned int i = 0; i < m_LibraryDatabase.size(); i++){
        LendingItem* currItem = m_LibraryDatabase[i];
        if(currItem->getID() == index){
            indexInVector = i;
            return currItem;
        }
    }
    indexInVector = -1;
    return nullptr;
}

void LibraryApp::processUserInput(std::string &input){
    if(input == "X")
        removeAnObjectFromTheLibrary();
    else if(input == "C")
        insertNewCD();
    else if(input == "F")
        insertNewFictionBook();
    else if(input == "N")
        insertNewNonFictionBook();
    else if(input == "J")
        insertNewJournal();
    else if(input == "H")
        m_GuiLibrary.printHelp();
    else if(input == "S")
        startSearchDialog();
    else if(input == "B")
        borrowLibraryItem();
    else if(input == "R")
        returnAnObject();
    else if(input == "Q")
        m_GuiLibrary.printExitMessege();
    else
        m_GuiLibrary.printInvalidInput(input);
}

 bool LibraryApp::ReadLibraryDb(string path){
    vector<string> database;
     database = ReadTextFile(path);
     if(database.size() == 0){
         return false;
     }
     //vector<LendingItem> libraryDatabase;
     createLendingItemsFromTxt(database);
     return true;
 }

 void LibraryApp:: createLendingItemsFromTxt(vector<string> database){
     //vector<LendingItem*> lendingItems;
     LendingItem* newLibraryEntity;
     int startRowOfObject;
     int endRowOfObject;
     Enums::ItemTypes prevItem;

     for(unsigned int i=0; i < database.size(); i++){
        //cout << database[i] << endl;
         Enums::ItemTypes item;
        item = txtLineIsNewLendingItem(database[i]);

        if(item != Enums::NonApplicable){
            //for the first item
            if(i != 0){
                //create the object if not equal to zero
                newLibraryEntity = createNewLendingItem(database, startRowOfObject, prevItem, generateNewId());
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
            newLibraryEntity = createNewLendingItem(database, startRowOfObject, prevItem, generateNewId());
            m_LibraryDatabase.push_back(newLibraryEntity);
        }
     }
 }

 LendingItem* LibraryApp::createNewLendingItem(vector<string> &database, int &startrow, Enums::ItemTypes type, int id){
     LendingItem* newItem;
     int borrowerIndexInArray = 4; //will be 5 for CD, otherwise 4.
     switch(type){
         case Enums::CD:
             newItem = new CompactDisc(database[startrow+1], database[startrow+2],  database[startrow+2], id);
             borrowerIndexInArray = 5;
         break;
         case Enums::Fiction:
           newItem = new FictionBook(database[startrow+1],  database[startrow+2], id);//new Book(type, database[startrow+1],  database[startrow+2], id);
           break;
         case Enums::Journal:
             newItem = new Journal(database[startrow+1], database[startrow+2], id);
           break;
         case Enums::NonFiction:
            newItem = new NonFictionBook(database[startrow+1],  database[startrow+2], id); //Book(type, database[startrow+1],  database[startrow+2], id);
           break;
         default:
           cout << "Invalid Selection\n";
           break;
     }
     //newItem->setItemType(type);
     string strBorrower = database[startrow+borrowerIndexInArray];
     int iBorrower;
     m_GuiLibrary.str2int(iBorrower, strBorrower.c_str());
     newItem->setLenderIndex(iBorrower);
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
     while (std::getline(file, str)){
         strVec.push_back(str);
     }
     return strVec;
 }

 void LibraryApp::insertNewCD(){
     //read input
     m_GuiLibrary.printStringWithoutEndLine("Artist: ");
     string artist = m_GuiLibrary.readUserInput();
     m_GuiLibrary.printStringWithoutEndLine("Album: ");
     string album = m_GuiLibrary.readUserInput();
     m_GuiLibrary.printStringWithoutEndLine("Playtime: ");
     string playtime = m_GuiLibrary.readUserInput();

     //create the object
     LendingItem* newItem;
     newItem = new CompactDisc(artist, album, playtime, generateNewId());
     //newItem->setItemType(Enums::CD);
     newItem->setLenderIndex(0);
     m_LibraryDatabase.push_back(newItem);

     //announce completion
      m_GuiLibrary.printString("Album " + album + " from artist(s) " + artist + " "
                               + " was successfully added with the index "
                               + std::to_string(newItem->getID()) + "." );
 }

 void LibraryApp::insertNewFictionBook(){
     addBook(Enums::Fiction);

 }

 void LibraryApp::insertNewNonFictionBook(){
    addBook(Enums::NonFiction);
 }

void LibraryApp::addBook(Enums::ItemTypes type){
    //read input
    m_GuiLibrary.printStringWithoutEndLine("Author: ");
    string author = m_GuiLibrary.readUserInput();
    m_GuiLibrary.printStringWithoutEndLine("Title: ");
    string title = m_GuiLibrary.readUserInput();

    //create the object
    LendingItem* newItem;
    if(type == Enums::Fiction){
        newItem = new FictionBook(author, title, generateNewId());
    }
    else if(type == Enums::NonFiction){
        newItem = new NonFictionBook(author, title, generateNewId());
    }
    else{
        //throw error!
    }
    //newItem = new Book(type, author, title, generateNewId());
    //newItem->setItemType(type);
    newItem->setLenderIndex(0);
    m_LibraryDatabase.push_back(newItem);

    //announce completion
     m_GuiLibrary.printString(Enums::ToString(type) + " book with title " + title + " and author "
                              + author + " was successfully added with the index "
                              + std::to_string(newItem->getID()) + "." );
}

 void LibraryApp::insertNewJournal(){
     //read input
     m_GuiLibrary.printStringWithoutEndLine("Title: ");
     string title = m_GuiLibrary.readUserInput();
     m_GuiLibrary.printStringWithoutEndLine("Volume: ");
     string volume = m_GuiLibrary.readUserInput();

     //create the object
     LendingItem* newItem;
     newItem = new Journal(title, volume, generateNewId());
     //newItem->setItemType(Enums::Journal);
     newItem->setLenderIndex(0);
     m_LibraryDatabase.push_back(newItem);

     //announce completion
      m_GuiLibrary.printString("Journal with title " + title + " and volume "
                               + volume + " was successfully added with the index "
                               + std::to_string(newItem->getID()) + "." );

 }
 void LibraryApp::removeAnObjectFromTheLibrary(){
     int id;
     //int borrower;
     bool success = m_GuiLibrary.initializeReturnProcedure(id);

     if(!success)
         return;

     LendingItem* item;
     int vecIndex;
     item = findLendingItemFromIndex(id, vecIndex);

     if(item == nullptr){
         m_GuiLibrary.printString("No items with index " + std::to_string(id) + " was found.");
         return;
     }

     delete m_LibraryDatabase[id];
     m_LibraryDatabase.erase(m_LibraryDatabase.begin()+vecIndex);
     m_GuiLibrary.printString("Item with index " + std::to_string(id) + " was successfully deleted");
 }

 void LibraryApp::returnAnObject(){
     int id;
     //int borrower;
     bool success = m_GuiLibrary.initializeReturnProcedure(id);

     if(!success)
         return;

     LendingItem* item;
     item = findLendingItemFromIndex(id);

     if(item == nullptr){
         m_GuiLibrary.printString("No items with index " + std::to_string(id) + " was found.");
         return;
     }

     if(item->getLenderIndex() != 0){
         m_GuiLibrary.printString("Item with index " + std::to_string(id) + " is available and cannot be returned");
         return;
     }
     item->setLenderIndex(0);
     m_GuiLibrary.printString("Item with index " + std::to_string(id) + " was successfully returned");
 }

void LibraryApp::saveFile(){
    std::ofstream myfile;
    myfile.open(m_Path, std::ofstream::out | std::ofstream::trunc);
    if (myfile.is_open())
      {
        for(unsigned int i = 0; i < m_LibraryDatabase.size(); i++){
            LendingItem* currItem = m_LibraryDatabase[i];
            myfile << currItem->getItemTypeString() << endl;
            myfile << currItem->getOriginator() << endl;
            myfile << currItem->getTitle() << endl;
            if(!currItem->getExtraInfo().empty())
                myfile << currItem->getExtraInfo() << endl;
            myfile << currItem->getIdString() << endl;
            myfile << std::to_string(currItem->getLenderIndex());

            if(i != m_LibraryDatabase.size() -1)
                myfile  << endl;
        }
        myfile.close();
      }
      else
        cout << "Unable to modify file";
}

LibraryApp:: ~LibraryApp(){
    //delete the library items
    for(unsigned int i = 0; i < m_LibraryDatabase.size(); ++i){
       delete m_LibraryDatabase[i];
    }
}
