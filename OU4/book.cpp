#include "book.h"

Book::Book()
{

}

std::string Book::getAuthor(){
    return m_Author;
}

std::string Book::getTitle(){
    return m_Title;
}

void Book::setBookType(Enums::ItemTypes bookType){
    m_BookType = bookType;
}

Enums::ItemTypes Book::getBookType(){
    return m_BookType;
}
