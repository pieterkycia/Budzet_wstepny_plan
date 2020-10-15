#include "Date.h"

void Date::setDay(int newDay) {
    howDaysInMonth();
    if (newDay >= 1 && newDay <= daysInMonth) {
        day = newDay;
        errorDateFlag = false;
    } else {
        cout << "Niepoprawna data." << endl;
        errorDateFlag = true;
    }
}

void Date::setMonth(int newMonth) {
    if (newMonth >= 1 && newMonth <= 12) {
        month = newMonth;
        errorDateFlag = false;
    } else {
        cout << "Niepoprawna data." << endl;
        errorDateFlag = true;
    }
}

void Date::setYear(int newYear) {
    if (newYear >= 2000 && newYear < 10000) {
        checkLeapYear();
        year = newYear;
        errorDateFlag = false;
    } else {
        cout << "Niepoprawna data." << endl;
        errorDateFlag = true;
    }
}

void Date::checkLeapYear() {
    if((year % 4 == 0 && year % 100 !=0) || (year % 4 == 0 && year % 400 == 0 && year % 100 == 0))
        leapYear = true;
    else
        leapYear = false;
}

void Date::howDaysInMonth() {
    switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        daysInMonth = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        daysInMonth = 30;
        break;
    case 2:
        if (leapYear == true)
            daysInMonth = 29;
        else
            daysInMonth = 28;
        break;
    }
}

void Date::showDate() {
    if (month < 10 && day < 10)
        cout << year << "-0" << month << "-0" << day << endl;
    else if (month < 10)
        cout << year << "-0" << month << "-" << day << endl;
    else if (day < 10)
        cout << year << "-" << month << "-0" << day << endl;
    else
        cout << year << "-" << month << "-" << day << endl;
}

void Date::setLocalDate() {
    time_t czas;
    struct tm * date;
    time(& czas);
    date = localtime(& czas);
    year = date -> tm_year + 1900;
    month = date -> tm_mon + 1;
    day = date -> tm_mday;
    checkLeapYear();
    howDaysInMonth();
    errorDateFlag = false;
}

void Date::setUserDate() {
    string userDate = "";
    cout << "Podaj date w postaci rrrr-mm-dd: ";
    cin.sync();
    getline(cin, userDate);
    separateDate(userDate);
    if (errorDateFlag == true)
        return;
}

void Date::setDateFromFile(string dateFromFile) {
    separateDate(dateFromFile);
}

void Date::separateDate(string date) {
    string line = "";
    int choice = 0;

    for (int i = 0; i <= date.length(); i++) {
        if (date[i] != '-' && date[i] != '\0') {
            line += date[i];
        } else {
            switch (choice) {
            case 0:
                this -> setYear(atoi(line.c_str()));
                break;
            case 1:
                this -> setMonth(atoi(line.c_str()));
                break;
            case 2:
                this -> setDay(atoi(line.c_str()));
                break;
            }
            if (errorDateFlag == true)
                return;

            line = "";
            choice++;
        }
    }
}

bool Date::operator<(const Date & newDate) {
    if (this -> year < newDate.year)
        return true;
    else if (this -> year == newDate.year) {
        if (this -> month < newDate.month)
            return true;
        else if (this -> month == newDate.month) {
            if (this -> day < newDate.day)
                return true;
            else
                return false;
        } else
            return false;
    } else
        return false;
}

bool Date::operator<=(const Date & newDate) {
    if (this -> year < newDate.year)
        return true;
    else if (this -> year == newDate.year) {
        if (this -> month < newDate.month)
            return true;
        else if (this -> month == newDate.month) {
            if (this -> day <= newDate.day)
                return true;
            else
                return false;
        } else
            return false;
    } else
        return false;
}

bool Date::operator>=(const Date & newDate) {
    if (this -> year > newDate.year)
        return true;
    else if (this -> year == newDate.year) {
        if (this -> month > newDate.month)
            return true;
        else if (this -> month == newDate.month) {
            if (this -> day >= newDate.day)
                return true;
            else
                return false;
        } else
            return false;
    } else
        return false;
}

void Date::setFirstDayInMonth() {
    day = 1;
}
void Date::setLastDayInMonth() {
    day = daysInMonth;
}

void Date::setPreviousMonth() {
    if (month == 1) {
        if (year == 2000) {
            cout << "Nie mozna zejsc ponizej tej daty." << endl;
        } else {
            year = year - 1;
            month = 12;
        }
    } else
        month = month - 1;
}

bool Date::getErrorDateFlag() {
    return errorDateFlag;
}
