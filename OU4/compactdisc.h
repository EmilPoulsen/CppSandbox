#ifndef COMPACTDISC_H
#define COMPACTDISC_H
#include "lendingitem.h"
#include <string>

class CompactDisc : public LendingItem
{
public:
    CompactDisc();
    CompactDisc(std::string artist, std::string title, std::string runtime, int id);
    std::string getArtist();
    std::string getRunTime();
    std::string getTitle();
    std::string getOriginator();
    std::string getExtraInfo();

private:
    std::string m_Artist;
    std::string m_Title;
    std::string m_RunTime;

};

#endif // COMPACTDISC_H
