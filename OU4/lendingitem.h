#ifndef LENDINGITEM_H
#define LENDINGITEM_H
#include <string>
#include "enums.h"

class LendingItem
{
public:
    LendingItem();
    virtual std::string getOriginator() = 0;
    virtual std::string getTitle() = 0;
    int getID();
    bool IsLentOut();
    int getLenderIndex();
    void setLenderIndex(int index);
    void setItemType(Enums::ItemTypes itemType);
    Enums::ItemTypes getItemType();
    std::string getItemTypeString();
    std::string getIdString();
protected:
    int m_ID;
    bool m_IsLentOut;
    int m_LenderIndex;
    Enums::ItemTypes m_ItemType;
private:
};

#endif // LENDINGITEM_H
