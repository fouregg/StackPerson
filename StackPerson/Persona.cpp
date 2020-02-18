#include "Persona.h"
#include <iostream>
#include <string>
using namespace std;

   
//����������� �� ���������
Persona::Persona()
{
    name = "";
    subname = "";
    age = 0;
    sex = true;
}
//����������� � �����������(����� ��� ������� ������)
Persona::Persona(string name, string subname, bool sex, int age)
{
    this->name = name;
    this->subname = subname;
    this->sex = sex;
    this->age = age;
}

void Persona::input()
    {
        cout << "������� ���:";
        cin >> name;
        cout << "������� �������:";
        cin >> subname;
        cout << "������� �������:";
        cin >> age;
        while (!flag) {
            cout << "������� ���(1-�������, 2-�������):";
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
                cout << "������ �����" << endl;
                flag = false;
            }
        }
    }

    void Persona::output()
    {
        cout << "���: " << name << "\t�������: " << subname << endl;
        if (sex)
            cout << "���: �������";
        else
            cout << "���: �������";
        cout << "\t�������: " << age << endl;
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

    //��� ��� �������� == ��� �������� �� ��������������, �� ����� ����� ���������
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
