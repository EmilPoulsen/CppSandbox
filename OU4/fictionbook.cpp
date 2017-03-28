#include "fictionbook.h"
#include "enums.h"

FictionBook::FictionBook()
{
}

FictionBook::FictionBook(std::string author, std::string title, int ID):Book(author, title, ID){
}


Enums::ItemTypes FictionBook::getItemType(){
    return Enums::Fiction;
}
