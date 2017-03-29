#ifndef LIBRARYAPP_H
#define LIBRARYAPP_H
using namespace std;
#include <string>
#include <vector>
#include "lendingitem.h"
#include "enums.h"
#include "guilibrary.h"

class LibraryApp
{
public:
    LibraryApp();
    void Run();
    string ExePath();
    void setDatabasePath(string s);
    ~LibraryApp();
private:
     //////////////////////////////////////////
    //////////////// CLASS FIELDS /////////////
    ///////////////////////////////////////////
    int m_IdCount;
    string m_Path;
    GuiLibrary m_GuiLibrary;
    vector<LendingItem*> m_LibraryDatabase;

    //////////////////////////////////////////
   //////////////// METHODS /// //////////////
   ///////////////////////////////////////////
    bool ReadLibraryDb(string path);
    vector<string> ReadTextFile(string path);
    void createLendingItemsFromTxt(vector<string> database);
    Enums::ItemTypes txtLineIsNewLendingItem(string &line);
    LendingItem* createNewLendingItem(vector<string> &database, int &startrow, Enums::ItemTypes type);
    int generateNewId();
    void runMainLoop();
    void processUserInput(string &input);
    void startSearchDialog();
    vector<LendingItem*> searchInLibrary(string &searchString, string &TitleorAuthor);
    bool stringContainsOtherString(string word, string substring);
    void printFoundObjects(vector<LendingItem*> &foundItems);
    void borrowLibraryItem();
    LendingItem* findLendingItemFromIndex(int index);
    LendingItem* findLendingItemFromIndex(int index, int &indexInVector);
    void borrowItem(LendingItem* item, int borrower);
    void insertNewCD();
    void insertNewFictionBook();
    void insertNewNonFictionBook();
    void addBook(Enums::ItemTypes type);
    void insertNewJournal();
    void removeAnObjectFromTheLibrary();
    void returnAnObject();
    bool userWantsToSaveFile();
    void saveFile();
};

#endif // LIBRARYAPP_H
