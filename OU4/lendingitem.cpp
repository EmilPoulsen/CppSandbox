#include "lendingitem.h"

LendingItem::LendingItem()
{

}

int LendingItem::getID(){
    return m_ID;
}

bool LendingItem::IsLentOut(){
    return m_IsLentOut;
}

int LendingItem::getLenderIndex(){
    return m_LenderIndex;
}

void LendingItem::setLenderIndex(int index){
    m_LenderIndex = index;
}

void LendingItem::setItemType(Enums::ItemTypes itemType){
    m_ItemType = itemType;
}

Enums::ItemTypes LendingItem::getItemType(){
    return m_ItemType;
}

std::string LendingItem::getItemTypeString(){
   return Enums::ToString(m_ItemType);
}

std::string LendingItem::getIdString(){
    std::string s = std::to_string(m_ID);
    return s;
}
