#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "date.h"

#define MAX_NAME_LEN    20
#define MAX_SNAME_LEN   20
#define MAX_TOWN_LEN    20

typedef struct{
	int  m_id;
	char m_name[MAX_NAME_LEN];
	char m_sname[MAX_SNAME_LEN];
	char m_town[MAX_TOWN_LEN];
	Date m_bdate;
}Employee;


void print_employee(const Employee* p);
Employee* set_employee_random(Employee* p);

int cmp_employee_byname(const Employee* p1, const Employee* p2);

int cmp_employee_bysname(const Employee* p1, const Employee* p2);



int cmp_employee_bytown(const Employee* p1, const Employee* p2);

int cmp_employee_byid(const Employee* p1, const Employee* p2);

int cmp_employee_bydate(const Employee* p1, const Employee* p2);

void set_employee_array(Employee* p, size_t size);

void print_employee_array(const Employee* p, size_t size);









#endif