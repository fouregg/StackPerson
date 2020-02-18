#include "StackPerson.h"
#include <iostream>


//���������� �� �������, ����� �� �������� Studio
StackPerson::StackPerson()
{
	
}

void StackPerson::addElement(StackPerson** top, Persona element)
{
	StackPerson* tmp = new StackPerson();
	tmp->info = element;//������� ������ ������� � ��������� ��� ���� �������, ������� ��������� � ����
	if (*top == NULL) //���� ���� ������
	{
		*top = tmp;//������ ��� ����� ����� ����������� ���������
	}
	else
	{
		tmp->next = *top; //����� ������� ��������� �� ������� �����
		*top = tmp; //����� ���������� ��������� �����������
	}
}


void StackPerson::deleteElement(StackPerson** top, Persona element)
{
	StackPerson* tmp = *top; 
	StackPerson* prev = NULL;//���������� �������. �����, ����� ������� ��� � ����� ����������
	if (tmp == NULL)//���� ����� ������, �� � ���� ������, ������� ������
	{
		std::cout << "���� ������, ������ �������!" << std::endl;
	}
	while (tmp != NULL) {//������� ����, ���� �� ������ �� �������
		if (tmp->info.equals(element)) //���� ���� �������� ����� ��������, ������� �������
		{
			if (tmp==(*top)) //���� ��� ����� �����
			{
				*top = tmp->next; // ����� ������ ������ ����� ��������� ��������
				delete tmp; //������� ����� �����
			}
			else
			{
				prev->next = tmp->next; //���������� ������� ��������� �� ���������, ����� ��������
				delete tmp; //������� ������� �����
				tmp->next = NULL;  //�� �������� ��� ���������, ����� ������
			}
		}
		prev = tmp; //���� ������� �� �������� ��� ��������, �� ������ �������, ��� �� ���������� � ������� ������� ������
		tmp = tmp->next;
	}
		
}


void StackPerson::changeElement(StackPerson** top, int number, Persona newelement)
{
	StackPerson* tmp = *top; 
	int count = 0;//������� �������
	while (tmp != NULL) { //������� ����, ���� �� ������ �� �������
		if (count == number) //���� ���������� ������� ����� ����� ��������, ������� ����� ������
		{
			tmp->info = newelement; // �������������� ���� ��������
			break;//����������� ����
		}
		else
		{
			count++;
			tmp->next = *top;// ������� ������ ����� ���������� count
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
