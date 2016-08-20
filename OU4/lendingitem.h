#ifndef LENDINGITEM_H
#define LENDINGITEM_H
#include <string>

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

protected:
    int m_ID;
    bool m_IsLentOut;
    int m_LenderIndex;
private:
};

#endif // LENDINGITEM_H
