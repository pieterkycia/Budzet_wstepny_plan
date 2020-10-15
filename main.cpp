#include <iostream>
#include "IncomeManager.h"

using namespace std;


int main() {
    IncomeManager incomeManager;

    incomeManager.showAllIncomes();
    cout << endl << endl;
    incomeManager.showAllSortIncomes();
    cout << endl << endl;
    incomeManager.showIncomesWithThisMonth();
    cout << endl << endl;
    incomeManager.showIncomesWithLastMonth();
    cout << endl << endl;
    incomeManager.showIncomesWithUserDate();

    return 0;
}
