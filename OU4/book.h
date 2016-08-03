#ifndef BOOK_H
#define BOOK_H
#include "lendingitem.h"
#include <string>

class Book : public LendingItem
{
public:
    Book();
    std::string getAuthor();
    std::string getTitle();
private:
    std::string m_Author;
    std::string m_Title;
};

#endif // BOOK_H
