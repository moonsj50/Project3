#include <iostream>
#include <string>
#include "Inventory.h" // 우리가 만든 헤더 파일 포함

// 테스트용 간단한 Item 클래스
class Item {
private:
    std::string name_;
    int price_;

public:
    Item() : name_(""), price_(0) {} // 기본 생성자

    Item(const std::string& name, int price) : name_(name), price_(price) {}

    // PrintInfo 함수 - 인벤토리 클래스에서 필요함
    void PrintInfo() const {
        std::cout << "[이름: " << name_ << ", 가격: " << price_ << "G]" << std::endl;
    }

    // GetPrice 함수 - 정렬에 필요함
    int GetPrice() const {
        return price_;
    }
};

int main() {
    // 1. 인벤토리 생성 테스트
    std::cout << "===== 인벤토리 생성 테스트 =====" << std::endl;
    Inventory<Item> myBag(5); // 용량 5짜리 인벤토리 생성
    std::cout << "인벤토리 생성! (용량: " << myBag.GetCapacity() << ")" << std::endl;

    // 2. 아이템 추가 테스트
    std::cout << "\n===== 아이템 추가 테스트 =====" << std::endl;
    myBag.AddItem(Item("검", 500));
    myBag.AddItem(Item("방패", 300));
    myBag.AddItem(Item("물약", 100));
    std::cout << "아이템 3개 추가 후 현재 개수: " << myBag.GetSize() << std::endl;

    // 3. 아이템 출력 테스트
    std::cout << "\n===== 아이템 출력 테스트 =====" << std::endl;
    myBag.PrintAllItems();

    // 4. 아이템 제거 테스트
    std::cout << "\n===== 아이템 제거 테스트 =====" << std::endl;
    myBag.RemoveLastItem();
    std::cout << "아이템 1개 제거 후 현재 개수: " << myBag.GetSize() << std::endl;
    myBag.PrintAllItems();

    // 5. 정렬 테스트
    std::cout << "\n===== 정렬 테스트 =====" << std::endl;
    myBag.AddItem(Item("활", 250));
    myBag.AddItem(Item("갑옷", 800));
    std::cout << "정렬 전:" << std::endl;
    myBag.PrintAllItems();

    myBag.SortItems();
    std::cout << "정렬 후 (가격 오름차순):" << std::endl;
    myBag.PrintAllItems();

    // 6. 자동 확장 테스트
    std::cout << "\n===== 자동 확장 테스트 =====" << std::endl;
    std::cout << "현재 용량: " << myBag.GetCapacity() << std::endl;
    myBag.AddItem(Item("지팡이", 450));
    myBag.AddItem(Item("반지", 1000));
    std::cout << "아이템 추가 후 현재 용량: " << myBag.GetCapacity() << std::endl;
    myBag.PrintAllItems();

    return 0;
}