#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <QString>
#include <QDateTime>
#include <vector>
#include "productslist.h"

using namespace std;

class Warehouse
{
public:
    Warehouse();

    ProductsList* listProducts = new ProductsList;
};

#endif // WAREHOUSE_H
