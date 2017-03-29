#include "lendingitem.h"

LendingItem::LendingItem(){

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

//0 markerar att objektet är tillgängligt för utlåning
void LendingItem::setLenderIndex(int index){
    m_LenderIndex = index;
}

std::string LendingItem::getItemTypeString(){
   return Enums::ToString(getItemType());
}

std::string LendingItem::getIdString(){
    std::string s = std::to_string(m_ID);
    return s;
}

LendingItem::~LendingItem(){

}
