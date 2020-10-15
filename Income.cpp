#include "Income.h"

Date & Income::getDate() {
    return date;
}

void Income::showDate() {
    date.showDate();
}

bool Income::operator<(const Income & income) {
    return (this -> date < income.date);
}

void Income::setDateFromFile(string dateFromFile) {
    date.setDateFromFile(dateFromFile);
}
