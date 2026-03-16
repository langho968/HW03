#pragma once
#include <iostream>

using namespace std;

template <typename T>
class Inventory
{
public:
    
    Inventory(int capacity = 5);    
    ~Inventory();
    
    void AddItem(const T& item);
    void RemoveLastItem();
    int GetSize() const;
    int GetCapacity() const;
    void PrintAllItems() const;
    
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
        ++this->size_;
    }
    else
    {
       
        cout << "인벤토리가 꽉 찼습니다." << endl;
    }

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
