#ifndef LIBRARYAPP_H
#define LIBRARYAPP_H
#include "libraryhandler.h";
using namespace std;
#include <string>
#include <vector>
#include "lendingitem.h"
#include "enums.h"


class LibraryApp
{
public:
    LibraryApp();
    void Run();
    string ExePath();


    //enum Days { Saturday,Sunday,Tuesday,Wednesday,Thursday,Friday};


private:
    void ReadLibraryDb(string path);
    vector<string> ReadTextFile(string path);
    vector<LendingItem> createLendingItemsFromTxt(vector<string> database);
    LibraryHandler _handler;
    Enums::ItemTypes txtLineIsNewLendingItem(string &line);
    LendingItem* createNewLendingItem(vector<string> &database, int &startrow, int &endrow, Enums::ItemTypes type, int id);
    int generateNewId();
    int m_IdCount;
};



#endif // LIBRARYAPP_H
