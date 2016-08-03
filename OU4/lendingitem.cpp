#include "lendingitem.h"

LendingItem::LendingItem()
{

}

int LendingItem::getID(){
    return m_ID;
}

bool LendingItem::IsAvailable(){
    return m_Available;
}

int LendingItem::getLenderIndex(){
    return m_LenderIndex;
}
