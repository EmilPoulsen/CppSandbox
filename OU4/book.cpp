#include "book.h"

Book::Book()
{

}

Book::Book(Enums::ItemTypes bookType, std::string author, std::string title, int ID)
    :m_BookType(bookType), m_Author(author), m_Title(title)
{
    m_ID = ID;
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

std::string Book::getOriginator(){
    return m_Author;
}

