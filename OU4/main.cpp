#include <iostream>
#include "libraryapp.h";

using namespace std;

int main(int argc, char *argv[])
{
    //THE _CORRECT_ DIRECTORY OF THE DATABASE FILE MUST BE DECLARED HERE!
    string fileLoc = "C:\\Users\\Emil\\Desktop\\input.txt";
    LibraryApp app;
    app.setDatabasePath(fileLoc);
    app.Run();
    return 0;
}
