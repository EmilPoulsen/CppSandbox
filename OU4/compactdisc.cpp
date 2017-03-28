#include "compactdisc.h"
#include "enums.h"


//TODO: add comments and documentation
CompactDisc::CompactDisc(){

}

CompactDisc::CompactDisc(std::string artist, std::string title, std::string runtime, int id)
    :m_Artist(artist), m_Title(title), m_RunTime(runtime){
       m_ID = id;
}

std::string CompactDisc::getArtist(){
    return m_Artist;
}

std::string CompactDisc::getRunTime(){
    return m_RunTime;
}

std::string CompactDisc::getTitle(){
    return m_Title;
}

std::string CompactDisc::getOriginator(){
    return m_Artist;
}

std::string CompactDisc::getExtraInfo(){
    return m_RunTime;
}

Enums::ItemTypes CompactDisc::getItemType(){
    return Enums::CD;
}

