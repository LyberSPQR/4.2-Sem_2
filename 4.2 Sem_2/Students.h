#pragma once
class Students
{
    char fio[40];
    unsigned int age;
    unsigned int course;
    unsigned int gender;
    double grade;

public:
    // Гетеры
    unsigned int getCourse()
    {
        return course;
    }
    double getGrade()
    {
        return grade;
    }

    Students();
    Students(int grad);
    Students(const Students& other);
    Students(Students&& other);

    void outputDatabase();
    void fillData();
    void writeBinaryFile(Students student);
    void readBinaryFile(Students student);
};
