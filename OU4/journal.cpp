#include "journal.h"

Journal::Journal()
{

}

std::string Journal::getTitle(){
    return m_Title;
}

int Journal::getVolume(){
    return m_Volume;
}
