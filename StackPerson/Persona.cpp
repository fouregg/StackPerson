#include "Persona.h"
#include <iostream>
#include <string>
using namespace std;

   
//Конструктор по умолчанию
Persona::Persona()
{
    name = "";
    subname = "";
    age = 0;
    sex = true;
}
//Конструктор с параметрами(нужен для простых тестов)
Persona::Persona(string name, string subname, bool sex, int age)
{
    this->name = name;
    this->subname = subname;
    this->sex = sex;
    this->age = age;
}

void Persona::input()
    {
        cout << "Введите имя:";
        cin >> name;
        cout << "Введите фамилию:";
        cin >> subname;
        cout << "Введите возраст:";
        cin >> age;
        while (!flag) {
            cout << "Введите пол(1-мужской, 2-женский):";
            int tmp;
            cin >> tmp;
            if (tmp == 1) {
                sex = true;
                flag = true;
            }
            else if (tmp == 2) {
                sex = false;
                flag = true;
            }
            else
            {
                cout << "Ошибка ввода" << endl;
                flag = false;
            }
        }
    }

    void Persona::output()
    {
        cout << "Имя: " << name << "\tФамилия: " << subname << endl;
        if (sex)
            cout << "Пол: Мужской";
        else
            cout << "Пол: Женский";
        cout << "\tВозраст: " << age << endl;
    }

    string Persona::getName()
    {
        return name;
    }

    string Persona::getSubname()
    {
        return subname;
    }

    bool Persona::getSex()
    {
        return sex;
    }

    int Persona::getAge()
    {
        return age;
    }

    //Так как операция == для объектов не переопределена, то пишем метод сравнения
    bool Persona::equals(Persona another)
    {
        if (this->name == another.getName() && this->subname == another.getSubname() && this->sex == another.getSex() && this->age == another.age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
