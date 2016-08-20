#ifndef LENDINGITEM_H
#define LENDINGITEM_H


class LendingItem
{
public:
    LendingItem();
    int getID();
    bool IsLentOut();
    int getLenderIndex();
    void setLenderIndex(int index);
protected:
    int m_ID;
    bool m_IsLentOut;
    int m_LenderIndex;
private:
};

#endif // LENDINGITEM_H
