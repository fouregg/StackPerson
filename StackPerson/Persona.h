#pragma once
#include <iostream>
#include <string>
using namespace std;
class Persona
{
private:
    string name="", subname="";
    bool sex=true;
    int age=0;
    bool flag=false;
public:
    Persona();
    Persona(string name, string subname, bool sex, int age);
    void input();
    void output();
    string getName();
    string getSubname();
    bool getSex();
    int getAge();
    bool equals(Persona another);
};

