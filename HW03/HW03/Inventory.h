#pragma once
#include <iostream>
#include <algorithm>

#include "Item.h"
using namespace std;


template <typename T>
class Inventory
{
public:
    
    Inventory(int capacity = 5);    
    Inventory(const Inventory<T>& other);
    ~Inventory();
    
    void Assign(const Inventory<T>& other);
    void AddItem(const T& item);
    void RemoveLastItem();
    int GetSize() const;
    int GetCapacity() const;
    void PrintAllItems() const;
    void Resize(int newCapacity);
    void SortItmes(bool (*compare)(const Item& a, const Item& b));
    
private:
    T* pItems;
    //현재용량
    int size_;
    //최대용량
    int capacity_;
};

template <typename T>
Inventory<T>::Inventory(int capacity)
{
    if (capacity <= 0)
    {
        capacity_ = 1;
    }
    else
    {
        capacity_ = capacity;
    }
    size_=0;
    pItems = new T[capacity_];
}

template <typename T>
Inventory<T>::Inventory(const Inventory<T>& other)
{
    capacity_ = other.capacity_;
    size_ = other.size_;
    pItems = new T[capacity_];
    for (int i=0; i<size_; i++)
    {
        pItems[i] = other.pItems[i];
    }
}

template <typename T>
Inventory<T>::~Inventory()
{
    if (pItems != nullptr)
    {
        delete [] pItems;
        pItems = nullptr;
    }
    
}

template<typename T>
void Inventory<T>::AddItem(const T& item)
{
    
    if (this->size_ < this->capacity_)
    {
        pItems[this->size_] = item;
    }
    else if (this->size_ == this->capacity_)
    {
        cout << "가방 용량을 초과하여 인벤토리를 자동으로 확장합니다" << endl;
        Resize(capacity_ * 2);
        pItems[size_] = item;
        
    }
    size_++;
}

template <typename T>
void Inventory<T>::Resize(int newCapacity)
{
    T* pNewItems = new T[newCapacity];
    for (int i=0; i<size_; i++)
    {
        pNewItems[i] = pItems[i];
    }
    
    delete[] pItems;
    pItems = nullptr;
    
    pItems = pNewItems;
    capacity_ = newCapacity;
    
    
}

template<typename T>
void Inventory<T>::RemoveLastItem()
{
    if (this->size_ > 0)
    {
        --this->size_;
    }
    else
    {
        cout << "인벤토리가 비어있습니다." << endl;
    }
}

template <typename T>
int Inventory<T>::GetSize() const
{
    return this->size_;
}

template <typename T>
int Inventory<T>::GetCapacity() const
{
    return this->capacity_;
}

template <typename T>
void Inventory<T>::PrintAllItems() const
{  
    cout << "-----------인벤토리 목록-----------" << endl;
    cout << "용량 : " << this->size_ << "/" << this->capacity_ << endl;
    if (this->size_ == 0)
    {
        cout << "인벤토리가 비어있습니다." << endl;
    }
    for (int i =0; i<size_; i++)
    {
        pItems[i].PrintInfo();
    }
}

template <typename T>
void Inventory<T>::SortItmes(bool (*compare)(const Item& a, const Item& b))
{
    sort(pItems, pItems+size_, compare);
}

template <typename T>
void Inventory<T>::Assign(const Inventory<T>& other)
{
    if (this == &other)
    {
        cout << "자기 자신을 대입하려 시도했습니다." << endl;
        return;
    }
    if (pItems != nullptr)
    {
        delete [] pItems;
        pItems = nullptr;
    }
    capacity_ = other.capacity_;
    size_ = other.size_;
    pItems = new T[capacity_];
    for (int i=0; i<size_; i++)
    {
        pItems[i] = other.pItems[i];
    }
}
