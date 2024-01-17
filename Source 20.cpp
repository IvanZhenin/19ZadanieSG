#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//�������:
//������ ���������� ���������� ���������� ��������������� ����� ��� : 1) ����� ������ � �����; 2) ��� ��������� ��������� �
//������, ��� ������������� ���������� � ���������� ���������� ����, ��� ��������� ���������� � ������������ ����������� �����������.
//��������� ������ �������� ����� �������� �����.������ ����������� �� �������� ���������� �����������.

// �������� ��������� �����������
struct Transport 
{
    int number;
    string brand;
    string renterName;
    int capacity;
    int seats;
};

// �����, ������� ������������ ��� �������������� ��������� �� ������
bool CompareByRenterName(const Transport& modelA, const Transport& modelB) 
{
    return modelA.renterName < modelB.renterName;
}

int main() 
{
    setlocale(LC_ALL, "");
    // �������� ����� ��� ������ ����������
    vector<Transport> transportList = 
    {
        {1, "Toyota", "Company A", 0, 0},
        {2, "Ford", "Company B", 0, 0},
        {3, "Toyota", "Company C", 0, 0},
        {4, "BMW", "Company A", 0, 0}
    };

    // ����������� �������� �����
    string targetBrand = "Toyota"; 

    // �������� ������ ����� ��� ������ ������ �����
    vector<Transport> filteredList;

    for (const auto& transport : transportList) 
    {
        if (transport.brand == targetBrand) 
        {
            filteredList.push_back(transport);
        }
    }

    // ���������� ���������� ��� ������ ����������� ������
    sort(filteredList.begin(), filteredList.end(), CompareByRenterName);

    cout << "������ �������� ����� ����� " << targetBrand << ":\n";
    for (const auto& transport : filteredList) 
    {
        cout << "�����: " << transport.number << ", ���������� �����������: " << transport.renterName << "\n";
    }
}