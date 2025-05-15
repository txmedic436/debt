#ifndef DEBT_H
#define DEBT_H

#include <iostream>

struct Debt {
    std::string name;
    float balance;
    float rate;
    float min_payment;
};

inline int makePayment(Debt* d){
    if(d->min_payment > d->balance){
        d->min_payment = d->balance;
        return 0;
    }
    float monthlyInterest = d->balance / d->rate;

    d->balance = d->balance - (d->min_payment - (monthlyInterest / 12));
    return 1;

}

#endif
