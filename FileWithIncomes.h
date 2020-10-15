#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include "Income.h"
#include <vector>
#include "Markup.h"

class FileWithIncomes {
    const string NAME_FILE_WITH_INCOMES;

public:
    FileWithIncomes(): NAME_FILE_WITH_INCOMES("Incomes.xml") {};

    vector <Income> loadIncomesFromFile();
};

#endif // FILEWITHINCOMES_H
