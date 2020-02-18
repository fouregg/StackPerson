#pragma once
#include "Persona.h"
#include <cstdlib>

class StackPerson
{
public:
	Persona info;
	StackPerson* next;
	StackPerson();
	void addElement(StackPerson** last, Persona element);
	void deleteElement(StackPerson** last, Persona element);
	void changeElement(StackPerson** last, int number, Persona newelement);
	void printElements(StackPerson** last);
};

