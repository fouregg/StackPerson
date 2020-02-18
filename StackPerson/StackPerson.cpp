#include "StackPerson.h"
#include <iostream>



StackPerson::StackPerson()
{
	
}

void StackPerson::addElement(StackPerson** top, Persona element)
{
	StackPerson* tmp = new StackPerson();
	tmp->info = element;
	if (top != NULL)
	{
		tmp->next = *top;
		*top = tmp;
	}
	else
	{
		*top = tmp;
	}
}


void StackPerson::deleteElement(StackPerson** top, Persona element)
{
	StackPerson* tmp = *top;
	StackPerson* prev = NULL;
	while (tmp != NULL) {
		if (tmp->info.equals(element))
		{
			cout << "OU MAI!" << endl;
			if (tmp->info.equals((*top)->info))
			{
				*top = tmp->next;
				delete tmp;
			}
			else
			{
				prev->next = tmp->next;
				delete tmp;
				
			}
		}
		prev = tmp;
		tmp = tmp->next;
	}

	if ((*top)->next != NULL) {
		
		*top = (*top)->next;
		delete tmp;
	}
	else
		std::cout << "Стэк пустой, нельзя удалять!" << std::endl;
}

void StackPerson::changeElement(StackPerson** top, Persona newelement)
{
	StackPerson* tmp = *top;
	tmp->info=newelement;
}

void StackPerson::printElements(StackPerson** top)
{
	StackPerson* tmp = this;
	while (tmp->next != NULL) 
	{
		tmp->info.output();
		tmp = tmp->next;
	}
}
