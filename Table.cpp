#include <iostream>
#include <iomanip>
#include <string>
#include "table.h"
#include "debt.h"

Table::Table(Debt* d){
    m_debt = *d;
    m_balanceDue = m_debt.balance;
    if(m_debt.name.empty()){
        m_debt.name = "Payment";
    }
}



void Table::Print(int itr){
    std::cout << m_debt.name << "\t|\t" << "Balance Due" <<std::endl;
    while(itr > 0){
        makePayment(&m_debt);
        std::cout << "$" << std::fixed << std::setprecision(2) << m_debt.min_payment << "\t|\t" << "$" << std::fixed << std::setprecision(2) << m_debt.balance << std::endl;
        itr--;
    }
}

size_t Table::maxLength(){
    std::string bal = std::to_string(m_debt.balance);
    size_t bal_len = bal.length();

    return (m_debt.balance > bal_len) ? m_debt.balance : bal_len;
}
