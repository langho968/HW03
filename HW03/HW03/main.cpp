#include <iostream>
#include "Inventory.h"
#include "Item.h"
using namespace std;

int main()
{
    Inventory<Item>* inventory = new Inventory<Item>();
    
    inventory->PrintAllItems();    
    
    for (int i = 0; i < 6; i++)
    {
        inventory->AddItem(Item(to_string(i)+"번 아이템", i*1000));
    }
    
    inventory->PrintAllItems();  
    
    inventory->RemoveLastItem();
    
    inventory->PrintAllItems();  
    
    cout << "인벤토리 최대 용량: " << inventory->GetCapacity() << endl;
    cout << "인벤토리 현재 용량: " << inventory->GetSize() << endl;
  
    
    if (inventory != nullptr)
    {
        delete inventory;
        inventory = nullptr;
    }
    return 0;
}