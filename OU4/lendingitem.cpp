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
