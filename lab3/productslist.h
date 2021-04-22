#ifndef PRODUCTSLIST_H
#define PRODUCTSLIST_H

#include <QString>
#include <QDateTime>

class Product
{
public:
    QString name;
    int count;
    double cost;
    QDateTime date;

    Product *next = nullptr;

    QString toString()
    {
        QString result;
        result += "Наименование продукта: " + name + " \n";
        result += "Количество единиц продукта: " + QString::number(count) + " \n";
        result += "Стоимость единицы продукта: " + QString::number(cost) + " \n";
        result += "Дата поступления продукта: " + date.toString("dd.mm.yyyy") + " \n";
        return result;
    }
};


class ProductsList
{
public:
    ProductsList();

    Product *head = nullptr;
    Product *tail = nullptr;

    void push(Product* item)
    {
        if (!head)
        {
            head = item;
            tail = item;
        }
        else
        {
            tail->next = item;
            tail = item;
        }
    }

    QString getAll()
    {
        QString result;
        Product* product = new Product;
        product = head;
        while (product)
        {
            result += product->toString();
            result += '\n';
            product = product->next;
        }
        return result;
    }

    QString getByName(QString value)
    {
        QString result;
        Product *product = head;
        while (product)
        {
            if (product->name == value)
            {
                result += product->toString();
                result += '\n';
            }
            product = product->next;
        }
        return result;
    }

    QString getMoreThanDays(int days)
    {
        QString result;
        Product *product = head;
        while (product)
        {
            if (getDaysFromDate(product->date) > days)
            {
                result += product->toString();
                result += '\n';
            }
            product = product->next;
        }
       return result;
    }

    QString getLowerThanPrice(double price)
    {
        QString result;
        Product *product = head;
        while (product)
        {
            if (product->cost < price)
            {
                result += product->toString();
                result += '\n';
            }
            product = product->next;
        }
        return result;
    }
    int getDaysFromDate(QDateTime date)
    {
        return date.secsTo(QDateTime::currentDateTime()) / 86400;
    }
};

#endif // PRODUCTSLIST_H
