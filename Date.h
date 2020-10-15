#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <time.h>
#include <conio.h>

using namespace std;

class Date {
    int day;
    int month;
    int year;
    bool leapYear;
    bool errorDateFlag;
    int daysInMonth;
    void howDaysInMonth();
    void checkLeapYear();
    void separateDate(string date);
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);

public:
    Date() {
        setLocalDate();
    };

    bool operator<(const Date & newDate);
    bool operator<=(const Date & newDate);
    bool operator>=(const Date & newDate);

    void showDate();
    void setLocalDate();
    void setUserDate();
    void setDateFromFile(string dateFromFile);
    void setFirstDayInMonth();
    void setLastDayInMonth();
    void setPreviousMonth();
    bool getErrorDateFlag();
};

#endif // DATE_H
