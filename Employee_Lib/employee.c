#define _CRT_SECURE_NO_WARNINGS
#include "employee.h"
#include <stdlib.h>
#include <string.h>
#include "nutility.h"
#include <stdio.h>

Employee* set_employee_random(Employee* p)
{
	p->m_id = rand() % 2500;
	strcpy(p->m_name, random_name());
	strcpy(p->m_sname, random_sname());
	strcpy(p->m_town, random_town());
	set_date_random(&p->m_bdate);

	return p;

}

void print_employee(const Employee* p)
{
	printf("%-8d %-16s %-18s %-16s", p->m_id, p->m_name, p->m_sname, p->m_town);

	print_date(&p->m_bdate);
}

int cmp_employee_byname(const Employee* p1, const Employee* p2)
{
	return strcmp(p1->m_name, p2->m_name);
}

int cmp_employee_bysname(const Employee* p1, const Employee* p2)
{
	return strcmp(p1->m_sname, p2->m_sname);

}

int cmp_employee_bytown(const Employee* p1, const Employee* p2)
{
	return strcmp(p1->m_town, p2->m_town);

}

int cmp_employee_byid(const Employee* p1, const Employee* p2)
{
	return p1->m_id - p2->m_id;

}

int cmp_employee_bydate(const Employee* p1, const Employee* p2)
{
	return cmp_date(&p1->m_bdate, &p2->m_bdate);
}

void set_employee_array(Employee* p, size_t size)
{
	while (size--)
		set_employee_random(p++);
}

void print_employee_array(const Employee* p, size_t size)
{
	while (size--)
		print_employee(p++);
}