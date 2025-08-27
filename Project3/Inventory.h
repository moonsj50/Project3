#pragma once
#include <iostream>
#include <algorithm>


template <typename T>
bool compareItemsByPrice(const T& a, const T& b)
{
	return a.GetPrice() < b.GetPrice();
}

template <typename T>
class Inventory {
private:
	T* pItems_;  // ������ ��ü���� ������ ���� �迭�� ����ų ������
	int capacity_;  // �κ��丮�� ������ �� �ִ� ����
	int size_;  // �κ��丮�� ����� �������� ����

public:
	Inventory(int capacity = 10) 
	{
		if (capacity <= 0) 
		{
			capacity_ = 1;
		} 
		else 
		{
			capacity_ = capacity;
		}
		pItems_ = new T[capacity_];
		size_ = 0;
	}
	//�Ҹ���
	~Inventory() 
	{
		delete[] pItems_;
		pItems_ = nullptr;  // �޸� ���� �� Ȥ�ö� �߸��� �޸𸮸� ����Ű�� �ʵ��� �ʱ�ȭ
	}

	// ���� ������
	Inventory(const Inventory<T>& other)
		: capacity_(other.capacity_), size_(other.size_)
	{
		pItems_ = new T[capacity_];

		for (int i = 0; i < size_; ++i)
		{
			pItems_[i] = other.pItems_[i];
		}
		std::cout << "�κ��丮 ���� �Ϸ�" << std::endl;
	}

	//���� �Լ� : Assign
	void Assign(const Inventory<T>& other)
	{
		//�ڱ� �ڽſ��� �����ϴ� ��츦 ����
		if (this == &other) return;

		// ������ ���� �ִ� �޸� ����
		delete[] pItems_;

		//other�� ������ ����
		capacity_ = other.capacity_;
		size_ = other.size_;

		//���ο� �޸� �Ҵ�
		pItems_ = new T[capacity_];

		//�����۵� �ϳ��� ����
		for (int i = 0; i < size_; ++i)
		{
			pItems_[i] = other.pItems_[i];
		}

		std::cout << "�κ��丮 �Ҵ� �Ϸ�" << std::endl;
	}

	// Resize �Լ�
	void Resize(int newCapacity)
	{
		if (newCapacity <= capacity_) return;
		
		T* newArray = new T[newCapacity];

		for (int i = 0; i < size_; ++i)
		{
			newArray[i] = pItems_[i];
		}

		delete[] pItems_;

		pItems_ = newArray;

		capacity_ = newCapacity;

		std::cout << "�κ��丮 �뷮 ������Ʈ!" << std::endl;
	}



	// AddItem �Լ�
	void AddItem(const T& item)
	{
		if (size_ >= capacity_)
		{
			Resize(capacity_ * 2);
		}
		pItems_[size_] = item;
		size_++;
	}

	// ������ ������ ���� �Լ�
	void RemoveLastItem()
	{
		if (size_ <= 0)
		{
			std::cout << "�κ��丮�� ����ֽ��ϴ�." << std::endl;
			return;
		}
		size_--;
	}

	//���� ������ ���� ��ȯ
	int GetSize() const
	{
		return size_;
	}

	//�ִ� ���� �뷮 ��ȯ
	int GetCapacity() const
	{
		return capacity_;
	}

	// ��� ������ ���� ���
	void PrintAllItems() const
	{
		if (size_ == 0)
		{
			std::cout << "(�������)" << std::endl;
			return;
		}

		for (int i = 0; i < size_; i++)
		{
			pItems_[i].PrintInfo();
		}
	}

	// SortItems �Լ�
	void SortItems()
	{
		std::sort(pItems_, pItems_ + size_, compareItemsByPrice<T>);
	}


};

