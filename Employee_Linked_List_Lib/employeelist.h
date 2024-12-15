#ifndef EMPLOYEELIST_H
#define EMPLOYEELIST_H
#include "employee.h"


//struct EmployeeList;
typedef struct EmployeeList *ListHandle;


ListHandle create_employee_list(void);
void destroy_list(ListHandle);

void get_first(ListHandle, Employee* p);
void push_front(ListHandle,const Employee* p);
void pop_front(ListHandle);
int get_list_size(ListHandle);
int is_empty(ListHandle);
void print_employee_list(ListHandle);
void make_empty(ListHandle);














#endif
 