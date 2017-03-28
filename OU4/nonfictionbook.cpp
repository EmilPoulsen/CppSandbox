#include "nonfictionbook.h"

NonFictionBook::NonFictionBook()
{

}

NonFictionBook::NonFictionBook(std::string author, std::string title, int ID) :Book(author, title, ID){

}

Enums::ItemTypes NonFictionBook::getItemType(){
    return Enums::NonFiction;
}
