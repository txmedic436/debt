#ifndef TABLE_H
#define TABLE_H

#include "debt.h"

class Table {
public:
    Table(Debt* d);
    void Print(int itr);
private:
    size_t maxLength();
private:
    float m_balanceDue;
    Debt m_debt;
};


#endif
