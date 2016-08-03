#include "compactdisc.h"

CompactDisc::CompactDisc()
{

}

std::string CompactDisc::getArtist(){
    return m_Artist;
}

int CompactDisc::getRunTime(){
    return m_RunTime;
}

std::string CompactDisc::getTitle(){
    return m_Title;
}
