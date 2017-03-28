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
    virtual std::string getExtraInfo() = 0; //playtime for CD for example
    virtual Enums::ItemTypes getItemType() = 0;
    int getID();
    bool IsLentOut();
    int getLenderIndex();
    void setLenderIndex(int index);
    //void setItemType(Enums::ItemTypes itemType);
    std::string getItemTypeString();
    std::string getIdString();
protected:
    int m_ID;
    bool m_IsLentOut;
    int m_LenderIndex;
    //Enums::ItemTypes m_ItemType;
private:
};

#endif // LENDINGITEM_H
