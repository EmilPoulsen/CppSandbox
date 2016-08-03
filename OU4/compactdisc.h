#ifndef COMPACTDISC_H
#define COMPACTDISC_H
#include "lendingitem.h"
#include <string>

class CompactDisc : public LendingItem
{
public:
    CompactDisc();
    std::string getArtist();
    int getRunTime();
    std::string getTitle();

private:
    std::string m_Artist;
    std::string m_Title;
    int m_RunTime;

};

#endif // COMPACTDISC_H
