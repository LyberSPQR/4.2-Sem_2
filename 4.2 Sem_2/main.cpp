// 2 sem 4.2
//
#include "Students.h"
#include <iostream>
using namespace std;

void findingCntOfGoodStudents(Students student[], int cntStudents);

int main()
{
    setlocale(LC_ALL, "ru");
    const int cntStudents = 6;
    Students student[cntStudents];

    for (int i = 0; i < cntStudents; i++)
    {
        student[i].fillData();
        student[i].writeBinaryFile(student[i]);
    }

    for (int i = 0; i < cntStudents; i++)
    {
       /* student[i].outputDatabase();*/
        student[i].readBinaryFile(student[i]);
    }

    findingCntOfGoodStudents(student, cntStudents);

    //const char* data = "database.bin";
    //remove(data);
    return 0;
}

void findingCntOfGoodStudents(Students student[], int cntStudents)
{
    int course, counter = 0;
    cout << "Enter course to search: " << endl;
    cin >> course;

    for (int i = 0; i < cntStudents; i++)
    {
        if (student[i].getCourse() == course && student[i].getGrade() >= 8)
            counter++;
    }
    cout << "Count of good students: " << counter;
}