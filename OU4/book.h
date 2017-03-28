#ifndef BOOK_H
#define BOOK_H
#include "lendingitem.h"
#include <string>
#include "enums.h"

class Book : public LendingItem
{
public:
    Book();
    Book(std::string author, std::string title, int ID);
    std::string getAuthor();
    std::string getOriginator();
    std::string getTitle();
    std::string getExtraInfo();
    virtual Enums::ItemTypes getItemType() = 0;
private:
    std::string m_Author;
    std::string m_Title;
    //Enums::ItemTypes m_BookType;
};

#endif // BOOK_H
