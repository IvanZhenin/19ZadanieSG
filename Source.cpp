#include <iostream>
using namespace std;

//Задание:
//Создайте структуру Прямая с элементами x1, y1, x2, y2, которые являются координатами двух точек, 
//через которые проходит прямая. Для K заданных прямых вывести уравнение прямых в виде y = ax + b

// Создание структуры линий (х1 х2 у1 у2)
struct Line 
{
    int xOne, yOne, xTwo, yTwo;
};

// Метод, выполняющий вычисление уравнения прямой у = ах + б
void EquationOfLine(Line listSpace) 
{
    float numA = (listSpace.yTwo - listSpace.yOne) / (float)(listSpace.xTwo - listSpace.xOne);
    float numB = listSpace.yOne - numA * listSpace.xOne;
    cout << "Уравнение прямой: y = " << numA << "x + " << numB << endl;
}

int main() 
{
    setlocale(LC_ALL, "");

    // Ввод количества линий (К)
    int numCount;
    cout << "Введите количество прямых: ";
    cin >> numCount;
    
    // Создание нового экземпляра с указанием размера структуры
    Line* linesMath = new Line[numCount];
    for (int i = 0; i < numCount; i++)
    {
        cout << "Введите координаты Х и У точки 1 для прямой " << i + 1 << ": ";
        cin >> linesMath[i].xOne >> linesMath[i].yOne;
        cout << "Введите координаты Х и У точки 2 для прямой " << i + 1 << ": ";
        cin >> linesMath[i].xTwo >> linesMath[i].yTwo;
    }

    cout << endl;
    for (int i = 0; i < numCount; i++)
    {
        cout << "Прямая " << i + 1 << ": ";
        EquationOfLine(linesMath[i]);
    }
}