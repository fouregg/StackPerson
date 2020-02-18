#include "StackPerson.h"
#include <iostream>


//Констуктор по дефолту, чтобы не ругалась Studio
StackPerson::StackPerson()
{
	
}

void StackPerson::addElement(StackPerson** top, Persona element)
{
	StackPerson* tmp = new StackPerson();
	tmp->info = element;//Создаем пустой элемент и заполняем его инфо данными, которые добавляем в стэк
	if (*top == NULL) //Если стэк пустой
	{
		*top = tmp;//Значит его вверх будет добавляемым элементом
	}
	else
	{
		tmp->next = *top; //Новый элемент ссылается на текущий вверх
		*top = tmp; //вверх становится элементом добавленным
	}
}


void StackPerson::deleteElement(StackPerson** top, Persona element)
{
	StackPerson* tmp = *top; 
	StackPerson* prev = NULL;//Предыдущий элемент. Нужен, чтобы связать его с после удаленного
	if (tmp == NULL)//Если вверх пустой, то и стэк пустой, удалять нельзя
	{
		std::cout << "Стэк пустой, нельзя удалять!" << std::endl;
	}
	while (tmp != NULL) {//Обходим стэк, пока не дойдем до пустого
		if (tmp->info.equals(element)) //Если инфо текущего равно элементу, который удаляем
		{
			if (tmp==(*top)) //Если это вверх стэка
			{
				*top = tmp->next; // Вверх списка теперь будет указатель элемента
				delete tmp; //Очишаем вверх стэка
			}
			else
			{
				prev->next = tmp->next; //Предыдущий элемент ссылается на следующий, после удаления
				delete tmp; //Очишаем элемент стэка
				tmp->next = NULL;  //Не забываем про указатель, иначе ошибки
			}
		}
		prev = tmp; //Если элемент не подходит под удаление, то просто говорим, что он предыдущий и двигаем текущий дальше
		tmp = tmp->next;
	}
		
}


void StackPerson::changeElement(StackPerson** top, int number, Persona newelement)
{
	StackPerson* tmp = *top; 
	int count = 0;//Счетчик позиции
	while (tmp != NULL) { //Обходим стэк, пока не дойдем до пустого
		if (count == number) //Если количество обходов равно числу элемента, который нужно менять
		{
			tmp->info = newelement; // перезаписываем инфо элемента
			break;//заканчиваем цикл
		}
		else
		{
			count++;
			tmp->next = *top;// Двигаем список далее увеличивая count
			*top = tmp;
		}
	}
}

void StackPerson::printElements(StackPerson** top)
{
	StackPerson* tmp = *top;
	while (tmp!= NULL) 
	{
		tmp->info.output();
		tmp = tmp->next;
	}
}
