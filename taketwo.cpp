#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct ListStud
{
    char name[32];
    char group[5];
    int grade[5];
};

int mylen(char* str)
{
    int count = 0;
    while (str[count])
        count++;
    return count;
}

const char inputfile[] = "C:\\Users\\79818\\Desktop\\list.txt";

int main()
{   //Объявление переменных и открытие файла
    ifstream filelist(inputfile);
    string text;
    ListStud list[100] = {};
    int i = 0, j = 0, buffer;
    float  mb = 0;
    char str[1];

    //Запись файла в структурный массив
    while ((!filelist.eof()))
    {
        filelist.getline(list[i].name, 32, '#');
        filelist.getline(list[i].group, 6, '#');
        filelist >> buffer;
        /*В буфере храниться пятизначное число,
        поэтому дальше разделим его и поместим в массив*/
        for (int q = 4; q > -1; q--)
        {
            list[i].grade[q] = buffer % 10;
            buffer /= 10;
        }
        filelist.getline(str, 1);
        i++;
    }
    //Закрываем файл
    filelist.close();
    
    //Разметка таблицы
    cout.setf(ios::left);
    cout.width(32);
    cout << "Student name:";
    cout.width(7);
    cout << "|Group";
    cout.width(11);
    cout << "|Grade";
    cout << "|GPA" << endl;

    //Вывод самой талицы
    for (int j = 0; j < i; j++)
    {
        cout.width(32);
        cout << list[j].name;
        cout << '|';
        cout.width(6);
        cout << list[j].group;
        cout << '|';
        for (int q = 0; q < 5; q++)
        {
            cout << list[j].grade[q] << ' ';
            mb += list[j].grade[q];
        }
        cout << '|' << mb / 5;
        mb = 0;
        cout << endl;
    }

    return 0;
}
