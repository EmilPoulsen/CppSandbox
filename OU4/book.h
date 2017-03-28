#ifndef BOOK_H
#define BOOK_H
#include "lendingitem.h"
#include <string>
#include "enums.h"

class Book : public LendingItem
{
public:
    Book();
    Book(Enums::ItemTypes bookType, std::string author, std::string title, int ID);
    std::string getAuthor();
    //std::string getTitle();
    void setBookType(Enums::ItemTypes bookType);
    Enums::ItemTypes getBookType();
    std::string getOriginator();
    std::string getTitle();
    std::string getExtraInfo();
    Enums::ItemTypes getItemType();
private:
    std::string m_Author;
    std::string m_Title;
    Enums::ItemTypes m_BookType;
};

#endif // BOOK_H
