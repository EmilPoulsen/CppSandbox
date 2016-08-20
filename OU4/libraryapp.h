#ifndef LIBRARYAPP_H
#define LIBRARYAPP_H
#include "libraryhandler.h";
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


    //enum Days { Saturday,Sunday,Tuesday,Wednesday,Thursday,Friday};

    ~LibraryApp();

private:
    void ReadLibraryDb(string path);
    vector<string> ReadTextFile(string path);
    vector<LendingItem> createLendingItemsFromTxt(vector<string> database);
    LibraryHandler _handler;
    Enums::ItemTypes txtLineIsNewLendingItem(string &line);
    LendingItem* createNewLendingItem(vector<string> &database, int &startrow, int &endrow, Enums::ItemTypes type, int id);
    int generateNewId();
    int m_IdCount;
    string m_Path;

    void runMainLoop();
    GuiLibrary m_GuiLibrary;
    vector<LendingItem*> m_LibraryDatabase;
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


    //std::shared_ptr<GuiLibrary> m_GuiLibrary;
};



#endif // LIBRARYAPP_H
