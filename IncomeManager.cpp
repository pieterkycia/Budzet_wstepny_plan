#include "IncomeManager.h"

void IncomeManager::showAllIncomes() {
    for (int i = 0; i < incomes.size(); i++) {
        incomes[i].showDate();
    }
}

void IncomeManager::sortIncomes(vector <Income> & incomesToSort) {
    sort(incomesToSort.begin(),incomesToSort.end());
}

void IncomeManager::showIncomesWithThisMonth() {
    vector <Income> selectedIncomes;

    startingDateToShow.setLocalDate();
    startingDateToShow.setFirstDayInMonth();
    endingDateToShow.setLocalDate();
    endingDateToShow.setLastDayInMonth();

    getSelectedIncomes(selectedIncomes);
    sortIncomes(selectedIncomes);
    showSelectedIncomes(selectedIncomes);
}

void IncomeManager::showIncomesWithLastMonth() {
    vector <Income> selectedIncomes;

    startingDateToShow.setLocalDate();
    startingDateToShow.setPreviousMonth();
    startingDateToShow.setFirstDayInMonth();
    endingDateToShow.setLocalDate();
    endingDateToShow.setPreviousMonth();
    endingDateToShow.setLastDayInMonth();

    getSelectedIncomes(selectedIncomes);
    sortIncomes(selectedIncomes);
    showSelectedIncomes(selectedIncomes);
}

void IncomeManager::showIncomesWithUserDate() {
    vector <Income> selectedIncomes;

    startingDateToShow.setUserDate();
    if (startingDateToShow.getErrorDateFlag() == true)
        return;
    endingDateToShow.setUserDate();
    if (endingDateToShow.getErrorDateFlag() == true)
        return;
    getSelectedIncomes(selectedIncomes);
    sortIncomes(selectedIncomes);
    showSelectedIncomes(selectedIncomes);
}

void IncomeManager::showAllSortIncomes() {
    sortIncomes(incomes);
    showSelectedIncomes(incomes);
}

void IncomeManager::getSelectedIncomes(vector <Income> & selectedIncomes) {
    for (int i = 0; i < incomes.size(); i++) {
        if (incomes[i].getDate() >= startingDateToShow && incomes[i].getDate() <= endingDateToShow) {
            selectedIncomes.push_back(incomes[i]);
        }
    }
}

void IncomeManager::showSelectedIncomes(vector <Income> & selectedIncomes) {
    for (int i = 0; i < selectedIncomes.size(); i++) {
        selectedIncomes[i].showDate();
    }
}
