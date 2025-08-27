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
	T* pItems_;  // 아이템 객체들을 저장할 동적 배열을 가리킬 포인터
	int capacity_;  // 인벤토리에 저장할 수 있는 공간
	int size_;  // 인벤토리에 저장된 아이템의 개수

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
	//소멸자
	~Inventory() 
	{
		delete[] pItems_;
		pItems_ = nullptr;  // 메모리 해제 후 혹시라도 잘못된 메모리를 가리키지 않도록 초기화
	}

	// 복사 생성자
	Inventory(const Inventory<T>& other)
		: capacity_(other.capacity_), size_(other.size_)
	{
		pItems_ = new T[capacity_];

		for (int i = 0; i < size_; ++i)
		{
			pItems_[i] = other.pItems_[i];
		}
		std::cout << "인벤토리 복사 완료" << std::endl;
	}

	//대입 함수 : Assign
	void Assign(const Inventory<T>& other)
	{
		//자기 자신에게 대입하는 경우를 방지
		if (this == &other) return;

		// 기존에 갖고 있던 메모리 해제
		delete[] pItems_;

		//other의 값들을 복사
		capacity_ = other.capacity_;
		size_ = other.size_;

		//새로운 메모리 할당
		pItems_ = new T[capacity_];

		//아이템들 하나씩 복사
		for (int i = 0; i < size_; ++i)
		{
			pItems_[i] = other.pItems_[i];
		}

		std::cout << "인벤토리 할당 완료" << std::endl;
	}

	// Resize 함수
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

		std::cout << "인벤토리 용량 업데이트!" << std::endl;
	}



	// AddItem 함수
	void AddItem(const T& item)
	{
		if (size_ >= capacity_)
		{
			Resize(capacity_ * 2);
		}
		pItems_[size_] = item;
		size_++;
	}

	// 마지막 아이템 제거 함수
	void RemoveLastItem()
	{
		if (size_ <= 0)
		{
			std::cout << "인벤토리가 비어있습니다." << std::endl;
			return;
		}
		size_--;
	}

	//현재 아이템 개수 반환
	int GetSize() const
	{
		return size_;
	}

	//최대 저장 용량 반환
	int GetCapacity() const
	{
		return capacity_;
	}

	// 모든 아이템 정보 출력
	void PrintAllItems() const
	{
		if (size_ == 0)
		{
			std::cout << "(비어있음)" << std::endl;
			return;
		}

		for (int i = 0; i < size_; i++)
		{
			pItems_[i].PrintInfo();
		}
	}

	// SortItems 함수
	void SortItems()
	{
		std::sort(pItems_, pItems_ + size_, compareItemsByPrice<T>);
	}


};

