#include "journal.h"

Journal::Journal(){

}

Journal::Journal(std::string title, std::string volume, int id)
    :m_Title(title), m_Volume(volume) {
    m_ID = id;
}

std::string Journal::getTitle(){
    return m_Title;
}

std::string Journal::getVolume(){
    return m_Volume;
}


std::string Journal::getOriginator(){
    return m_Volume;
}

std::string Journal::getExtraInfo(){
    return "";
}
