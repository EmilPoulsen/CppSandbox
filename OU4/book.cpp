#include "book.h"
//TODO: add comments and documentation
Book::Book(){

}

Book::Book(std::string author, std::string title, int ID)
    :m_Author(author), m_Title(title){
    m_ID = ID;
}

std::string Book::getAuthor(){
    return m_Author;
}

std::string Book::getTitle(){
    return m_Title;
}

std::string Book::getOriginator(){
    return m_Author;
}

std::string Book::getExtraInfo(){
    return "";
}

Enums::ItemTypes Book::getItemType(){
    return Enums::Fiction;
}



