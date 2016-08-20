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
    void runMainLoop();
    GuiLibrary m_GuiLibrary;
    vector<LendingItem*> m_LibraryDatabase;
    void processUserInput(string &input);
    void startSearchDialog();
    vector<LendingItem*> searchInLibrary(string &searchString, string &TitleorAuthor);
    bool stringContainsOtherString(string word, string substring);


    //std::shared_ptr<GuiLibrary> m_GuiLibrary;
};



#endif // LIBRARYAPP_H
