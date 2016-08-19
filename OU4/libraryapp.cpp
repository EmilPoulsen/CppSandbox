#include "libraryapp.h"
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <vector>
#include "enums.h"
using namespace std;

LibraryApp::LibraryApp()
{

}

void LibraryApp::Run(){
    //string fileLoc = "input.txt";//"C:\\Users\\Emil\\Desktop\\input.txt";
    string fileLoc = "C:\\Users\\Emil\\Desktop\\input.txt";
    //string s2 = ExePath();
    //cout << s2 << endl;
    ReadLibraryDb(fileLoc);
        cout << "Hello World!" << endl;
}


 void LibraryApp::ReadLibraryDb(string path){
    vector<string> database;
     database = ReadTextFile(path);
     vector<LendingItem> libraryDatabase;
     libraryDatabase = createLendingItemsFromTxt(database);




 }

 vector<LendingItem> LibraryApp:: createLendingItemsFromTxt(vector<string> database){
     int startRowOfObject;
     int endRowOfObject;
     Enums::ItemTypes prevItem;

     for(int i=0; i < database.size(); i++){
        cout << database[i] << endl;
         Enums::ItemTypes item;
        item = txtLineIsNewLendingItem(database[i]);


        if(item != Enums::NonApplicable){
            //for the first item
            if(i != 0){
                //create the object if not equal to zero
                createNewLendingItem(database, startRowOfObject, endRowOfObject, prevItem);
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
            createNewLendingItem(database, startRowOfObject, endRowOfObject, prevItem);
        }

     }

 }

 LendingItem* LibraryApp::createNewLendingItem(vector<string> &database, int &startrow, int &endrow, Enums::ItemTypes type){
     switch(type)
     {
     case Enums::CD:
       cout << "-----CD\n";
       break;
     case Enums::Fiction:
       cout << "-----fiction\n";
       break;
     case Enums::Journal:
       cout << "------journal\n";
       break;
     case Enums::NonFiction:
       cout << "-----nonfiction\n";
       break;
     default:
       cout << "Invalid Selection\n";
       break;
     }
     return NULL;
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




