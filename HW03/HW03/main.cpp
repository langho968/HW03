#include <iostream>
#include "Inventory.h"
#include "Item.h"
using namespace std;

bool compareItemsByPrice(const Item& a, const Item& b)
{
    return a.GetPrice() < b.GetPrice();
}

int main()
{
    Inventory<Item>* inventory = new Inventory<Item>();
    cout << "인벤토리 최대 용량: " << inventory->GetCapacity() << endl;
    cout << "인벤토리 현재 용량: " << inventory->GetSize() << endl;
    inventory->PrintAllItems();    
    
    //인벤토리에 아이템 추가
    for (int i = 0; i < inventory->GetCapacity(); i++)
    {
        inventory->AddItem(Item(to_string(i+1)+"번 아이템", i*1000));
    }
    
    inventory->PrintAllItems();  
    
    //복사생성자
    Inventory<Item>* inventory2 = new Inventory<Item>(*inventory);
    inventory2->PrintAllItems();
    
    inventory->RemoveLastItem();
    
    inventory->PrintAllItems();  
    inventory2->PrintAllItems();
    cout << "인벤토리 최대 용량: " << inventory->GetCapacity() << endl;
    cout << "인벤토리 현재 용량: " << inventory->GetSize() << endl;
    
    int choice = -1;
    while (choice != 0)
    {
        cout << "시스템 종료 : 0 " << "아이템 추가 : 1 " << "아이템 가격 비교 : 2 " 
        << "인벤토리 확인 : 3 " << "마지막 아이템 삭제 : 4 " << "인벤토리2 복사 및 확인 : 5 "
        << "아이템 정렬 : 6"
        <<  endl;
        cin >> choice;
        
        string ItemName;
        int price;
        if (choice == 1)
        {
            cout << "아이템 이름 :" << endl;
            cin >> ItemName;
            cout << "아이템 가격 :" << endl;
            cin >> price;
        }
    
        switch (choice)
        {
        case 0:
            break;
        case 1:
            inventory->AddItem(Item(ItemName, price));
            break;
        
        case 2:
            break;
        
        case 3:
            inventory->PrintAllItems();
            inventory2->PrintAllItems();
            break;
        case 4:
            inventory->RemoveLastItem();
            break;
        case 5:
            inventory2->Assign(*inventory);
            break;
        case 6:
            inventory->SortItmes(compareItemsByPrice);
            break;
        }
    }
    
    
    if (inventory != nullptr)
    {
        delete inventory;
        inventory = nullptr;
    }
    
    if (inventory2 != nullptr)
    {
        delete inventory2;
        inventory2 = nullptr;
    }
    
    return 0;
}