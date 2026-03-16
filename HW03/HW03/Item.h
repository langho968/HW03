#pragma once
#include <string>

using namespace std;

class Item
{
public:
    Item();
    Item(string ItemName, int price);
    
    void PrintInfo() const;
    
    
private:
    string ItemName;
    int price;
    
};
