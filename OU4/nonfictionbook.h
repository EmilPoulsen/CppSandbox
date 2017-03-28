#ifndef NONFICTIONBOOK_H
#define NONFICTIONBOOK_H
#include "book.h"
#include <string>

class NonFictionBook : public Book
{
public:
    NonFictionBook();
    NonFictionBook(std::string author, std::string title, int ID);
    Enums::ItemTypes getItemType();
};

#endif // NONFICTIONBOOK_H
