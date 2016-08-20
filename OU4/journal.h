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
private:
    std::string m_Title;
    std::string m_Volume;
};

#endif // JOURNAL_H
