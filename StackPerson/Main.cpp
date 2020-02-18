#include <iostream>
#include <string>
#include "Persona.h"
#include "StackPerson.h"
#include <Windows.h>
int main()
{
    setlocale(LC_CTYPE, "rus");//Установка кодировки для вывода
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);//Установка кодировки для ввода
    Persona A = Persona("Алексей", "Белоусов", true, 21);
    Persona B = Persona("Екатерина", "Зябликова", false, 22);
    Persona C = Persona("Дмитрий", "Новиков", true, 30);
    Persona D = Persona("Сергей", "Смирнов", true, 34);//Персоны для теста стэка
    //Далее тесты
    StackPerson* Test =NULL; //Объявляем top стэка пустым
    Test->addElement(&Test, A); 
    Test->addElement(&Test, B);
    Test->addElement(&Test, C);//Добавляем 3 элемента
    Test->printElements(&Test);//Печатаем 3 элемента
    Test->deleteElement(&Test, A);//Удаляем элемент А(Последний)
    std::cout << std::endl;
    Test->printElements(&Test);//Выводим 2 элемента
    Test->changeElement(&Test, 0, D);//Меняем С(последний, что вошел, то есть первый) на элемент D
    std::cout << std::endl;
    Test->printElements(&Test);// Печатаем массив
    return 0;
}


