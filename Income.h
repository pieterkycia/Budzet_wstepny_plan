#ifndef INCOME_H
#define INCOME_H

#include <iostream>
#include "Date.h"

using namespace std;

class Income {
    Date date;

public:
    bool operator<(const Income & income);

    void setDateFromFile(string dateFromFile);
    void showDate();
    Date & getDate();
};

#endif // INCOME_H
