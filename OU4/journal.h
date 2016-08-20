#ifndef JOURNAL_H
#define JOURNAL_H
#include "lendingitem.h"
#include <string>

class Journal : public LendingItem
{
public:
    Journal();

    Journal(std::string title, std::string volume, int id);

    std::string getTitle();
    std::string getVolume();
    std::string getOriginator();
    std::string getExtraInfo();
private:
    std::string m_Title;
    std::string m_Volume;
};

#endif // JOURNAL_H
