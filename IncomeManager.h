#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include <iostream>
#include <vector>
#include "Income.h"
#include "FileWithIncomes.h"
#include <algorithm>

using namespace std;

class IncomeManager {
    Date startingDateToShow;
    Date endingDateToShow;
    vector <Income> incomes;
    FileWithIncomes fileWithIncomes;
    void getSelectedIncomes(vector <Income> & selectedIncomes);
    void showSelectedIncomes(vector <Income> & selectedIncomes);

public:
    IncomeManager () {
        incomes = fileWithIncomes.loadIncomesFromFile();
    };

    void showAllIncomes();
    void showAllSortIncomes();
    void sortIncomes(vector <Income> & incomesToSort);
    void showIncomesWithThisMonth();
    void showIncomesWithLastMonth();
    void showIncomesWithUserDate();
};


#endif // INCOMEMANAGER_H
