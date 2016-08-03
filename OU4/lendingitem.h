#ifndef LENDINGITEM_H
#define LENDINGITEM_H


class LendingItem
{
public:
    LendingItem();
    int getID();
    bool IsAvailable();
    int getLenderIndex();
private:
    int m_ID;
    bool m_Available;
    int m_LenderIndex;
};

#endif // LENDINGITEM_H
