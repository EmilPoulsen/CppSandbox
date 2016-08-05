#ifndef LIBRARYAPP_H
#define LIBRARYAPP_H
#include "libraryhandler.h";
using namespace std;
#include <string>

class LibraryApp
{
public:
    LibraryApp();
    void Run();
private:
    void ReadLibraryDb(string path);
    LibraryHandler _handler;

};

#endif // LIBRARYAPP_H
