#define _CRT_SECURE_NO_WARNINGS
#include "Students.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;

void findingCntOfGoodStudents(Students student[], int cntStudents);
Students::Students(const Students& other) // Конструктор копирования
{
    strcpy(fio, other.fio);
    age = other.age;
    course = other.course;
    gender = other.gender;
    grade = other.grade;
}
Students::Students(Students&& other) // Конструктор перемещения
{
    strcpy(fio, other.fio);
    age = other.age;
    course = other.course;
    gender = other.gender;
    grade = other.grade;

    strcpy(other.fio, "");
    other.age = 0;
    other.course = 0;
    other.gender = 0;
    other.grade = 0;
}
Students::Students()
{
    strcpy(fio, "");
    age = 20;
    course = 5;
    gender = 2;
    grade = 10;
}
Students::Students(int grad)
{
    strcpy(fio, "Artyom_Rundigin");
    age = rand() % 4 + 18;
    course = rand() % 3 + 1;
    gender = rand() % 2 + 1;
    grade = grad;
}

void Students::outputDatabase()
{
    cout << "ФИО: " << fio << endl;
    cout << "Возраст: " << age << endl;
    cout << " Курс: " << course << endl;
    cout << "Пол: (1 - муж 2 - жен) " << gender << endl;
    cout << "Успеваемость: " << grade << endl << endl << endl << endl;
}
void Students::fillData()
{
    bool choice;
    cout << "1 - random values, 0 - console input" << endl;
    cin >> choice;

    if (choice)
    {
        strcpy(fio, "Вася");
        age = rand() % 4 + 18;
        course = rand() % 3 + 1;
        gender = rand() % 2 + 1;
        grade = rand() % 3 + 7;
    }
    else
    {
        cout << "Enter fio" << endl;
        cin.ignore();
        cin.getline(fio, 40);
        cout << "Enter age" << endl;
        cin >> age;
        cout << "Enter course" << endl;
        cin >> course;
        cout << "Enter gender" << endl;
        cin >> gender;
        cout << "Enter grade" << endl;
        cin >> grade;
    }
}
void Students::writeBinaryFile(Students student)
{
    ofstream outFile("database.bin", ios::binary | ios::app);
    outFile.write(reinterpret_cast<char*>(this), sizeof(Students));
    outFile.close();
}

void Students::readBinaryFile(Students student)
{
    ifstream inFile("database.bin", ios::in | ios::binary);
    if (!inFile)
    {
        cout << "Ошибка открытия файла" << endl;
        return;
    }
    cout << "ФИО: " << fio << endl;
    cout << "Возраст: " << age << endl;
    cout << " Курс: " << course << endl;
    cout << "Пол: (1 - муж 2 - жен) " << gender << endl;
    cout << "Успеваемость: " << grade << endl << endl << endl << endl;
    inFile.close();
}

