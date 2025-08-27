#include <iostream>
#include <string>
#include "Inventory.h" // �츮�� ���� ��� ���� ����

// �׽�Ʈ�� ������ Item Ŭ����
class Item {
private:
    std::string name_;
    int price_;

public:
    Item() : name_(""), price_(0) {} // �⺻ ������

    Item(const std::string& name, int price) : name_(name), price_(price) {}

    // PrintInfo �Լ� - �κ��丮 Ŭ�������� �ʿ���
    void PrintInfo() const {
        std::cout << "[�̸�: " << name_ << ", ����: " << price_ << "G]" << std::endl;
    }

    // GetPrice �Լ� - ���Ŀ� �ʿ���
    int GetPrice() const {
        return price_;
    }
};

int main() {
    // 1. �κ��丮 ���� �׽�Ʈ
    std::cout << "===== �κ��丮 ���� �׽�Ʈ =====" << std::endl;
    Inventory<Item> myBag(5); // �뷮 5¥�� �κ��丮 ����
    std::cout << "�κ��丮 ����! (�뷮: " << myBag.GetCapacity() << ")" << std::endl;

    // 2. ������ �߰� �׽�Ʈ
    std::cout << "\n===== ������ �߰� �׽�Ʈ =====" << std::endl;
    myBag.AddItem(Item("��", 500));
    myBag.AddItem(Item("����", 300));
    myBag.AddItem(Item("����", 100));
    std::cout << "������ 3�� �߰� �� ���� ����: " << myBag.GetSize() << std::endl;

    // 3. ������ ��� �׽�Ʈ
    std::cout << "\n===== ������ ��� �׽�Ʈ =====" << std::endl;
    myBag.PrintAllItems();

    // 4. ������ ���� �׽�Ʈ
    std::cout << "\n===== ������ ���� �׽�Ʈ =====" << std::endl;
    myBag.RemoveLastItem();
    std::cout << "������ 1�� ���� �� ���� ����: " << myBag.GetSize() << std::endl;
    myBag.PrintAllItems();

    // 5. ���� �׽�Ʈ
    std::cout << "\n===== ���� �׽�Ʈ =====" << std::endl;
    myBag.AddItem(Item("Ȱ", 250));
    myBag.AddItem(Item("����", 800));
    std::cout << "���� ��:" << std::endl;
    myBag.PrintAllItems();

    myBag.SortItems();
    std::cout << "���� �� (���� ��������):" << std::endl;
    myBag.PrintAllItems();

    // 6. �ڵ� Ȯ�� �׽�Ʈ
    std::cout << "\n===== �ڵ� Ȯ�� �׽�Ʈ =====" << std::endl;
    std::cout << "���� �뷮: " << myBag.GetCapacity() << std::endl;
    myBag.AddItem(Item("������", 450));
    myBag.AddItem(Item("����", 1000));
    std::cout << "������ �߰� �� ���� �뷮: " << myBag.GetCapacity() << std::endl;
    myBag.PrintAllItems();

    return 0;
}