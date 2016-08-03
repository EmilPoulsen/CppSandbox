#ifndef JOURNAL_H
#define JOURNAL_H
#include "lendingitem.h"
#include <string>

class Journal : public LendingItem
{
public:
    Journal();
    std::string getTitle();
    int getVolume();
private:
    std::string m_Title;
    int m_Volume;
};

#endif // JOURNAL_H
