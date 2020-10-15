#include "FileWithIncomes.h"

vector <Income> FileWithIncomes::loadIncomesFromFile() {
    vector <Income> incomes;
    string loadDate = "";
    Income income;

    CMarkup xml;
    xml.Load(NAME_FILE_WITH_INCOMES);
    if(xml.FindElem("Incomes")) {
        xml.IntoElem();
        while (xml.FindElem("Income")) {
            xml.IntoElem();
            xml.FindElem("date");
            loadDate = xml.GetData();
            income.setDateFromFile(loadDate);
            incomes.push_back(income);
            xml.OutOfElem();
        }
    } else
        cout << "Plik jest pusty." << endl;

    return incomes;
}
