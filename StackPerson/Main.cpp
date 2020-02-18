#include <iostream>
#include <string>
#include "Persona.h"
#include "StackPerson.h"
#include <Windows.h>
int main()
{
    setlocale(LC_CTYPE, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Persona A = Persona("Алексей", "Белоусов", true, 21);
    Persona B = Persona("Екатерина", "Зябликова", false, 22);
    Persona C = Persona("Дмитрий", "Новиков", true, 30);
    Persona D = Persona("Сергей", "Смирнов", true, 34);
    StackPerson* Test =new StackPerson();
    Test->addElement(&Test, A);
    Test->addElement(&Test, B);
    Test->addElement(&Test, A);
    Test->printElements(&Test);
    Test->deleteElement(&Test, A);
    return 0;
}


