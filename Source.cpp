#include <iostream>
using namespace std;

//�������:
//�������� ��������� ������ � ���������� x1, y1, x2, y2, ������� �������� ������������ ���� �����, 
//����� ������� �������� ������. ��� K �������� ������ ������� ��������� ������ � ���� y = ax + b

// �������� ��������� ����� (�1 �2 �1 �2)
struct Line 
{
    int xOne, yOne, xTwo, yTwo;
};

// �����, ����������� ���������� ��������� ������ � = �� + �
void EquationOfLine(Line listSpace) 
{
    float numA = (listSpace.yTwo - listSpace.yOne) / (float)(listSpace.xTwo - listSpace.xOne);
    float numB = listSpace.yOne - numA * listSpace.xOne;
    cout << "��������� ������: y = " << numA << "x + " << numB << endl;
}

int main() 
{
    setlocale(LC_ALL, "");

    // ���� ���������� ����� (�)
    int numCount;
    cout << "������� ���������� ������: ";
    cin >> numCount;
    
    // �������� ������ ���������� � ��������� ������� ���������
    Line* linesMath = new Line[numCount];
    for (int i = 0; i < numCount; i++)
    {
        cout << "������� ���������� � � � ����� 1 ��� ������ " << i + 1 << ": ";
        cin >> linesMath[i].xOne >> linesMath[i].yOne;
        cout << "������� ���������� � � � ����� 2 ��� ������ " << i + 1 << ": ";
        cin >> linesMath[i].xTwo >> linesMath[i].yTwo;
    }

    cout << endl;
    for (int i = 0; i < numCount; i++)
    {
        cout << "������ " << i + 1 << ": ";
        EquationOfLine(linesMath[i]);
    }
}