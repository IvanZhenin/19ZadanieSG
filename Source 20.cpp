#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//Задание:
//Список имеющегося транспорта некоторого автопредприятия имеет вид : 1) номер машины и марка; 2) для грузового траспорта —
//тоннаж, для пассажирского транспорта — количество посадочных мест, для легкового транспорта — наименование арендующего предприятия.
//Составить список легковых машин заданной марки.Список упорядочить по названию арендующих предприятий.

// Создание структуры автомобилей
struct Transport 
{
    int number;
    string brand;
    string renterName;
    int capacity;
    int seats;
};

// Метод, который используется для упорядочивания элементов из списка
bool CompareByRenterName(const Transport& modelA, const Transport& modelB) 
{
    return modelA.renterName < modelB.renterName;
}

int main() 
{
    setlocale(LC_ALL, "");
    // Создание листа или списка транспорта
    vector<Transport> transportList = 
    {
        {1, "Toyota", "Company A", 0, 0},
        {2, "Ford", "Company B", 0, 0},
        {3, "Toyota", "Company C", 0, 0},
        {4, "BMW", "Company A", 0, 0}
    };

    // Определение заданной марки
    string targetBrand = "Toyota"; 

    // Создание нового листа для отбора нужных машин
    vector<Transport> filteredList;

    for (const auto& transport : transportList) 
    {
        if (transport.brand == targetBrand) 
        {
            filteredList.push_back(transport);
        }
    }

    // Выполнение сортировки при помощи логического метода
    sort(filteredList.begin(), filteredList.end(), CompareByRenterName);

    cout << "Список легковых машин марки " << targetBrand << ":\n";
    for (const auto& transport : filteredList) 
    {
        cout << "Номер: " << transport.number << ", Арендующее предприятие: " << transport.renterName << "\n";
    }
}