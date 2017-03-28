#ifndef FICTIONBOOK_H
#define FICTIONBOOK_H
#include "book.h"
#include <string>

class FictionBook : public Book
{
public:
    FictionBook();
    FictionBook(std::string author, std::string title, int ID);
    Enums::ItemTypes getItemType();
};

#endif // FICTIONBOOK_H
