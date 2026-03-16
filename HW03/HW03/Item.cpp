#include "Item.h"
#include <iostream>

using namespace std;

Item::Item() {}

Item::Item(string ItemName, int price) : ItemName("Unknown"), price(0)
{
    this->ItemName = ItemName;
    this->price = price;
}

void Item::PrintInfo() const
{
    cout << "이름: " << ItemName <<  ", 가격: " << price << endl;
}
