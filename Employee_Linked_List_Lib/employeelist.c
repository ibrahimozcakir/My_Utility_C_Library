#include "employeelist.h"
#include <stdlib.h>
#include <stdio.h>


typedef struct tagNode {

	Employee edata;
	struct tagNode* pnext;
}Node;


struct EmployeeList {
	
	 Node* mp_first;
	int m_list_size;
};

static Node* create_node(void)
{

	Node* pd = (Node*)malloc(sizeof(Node));
	if (pd == NULL) {
		printf("bellek yetersiz \n");
		exit(EXIT_FAILURE);
	}
	return pd;
}

ListHandle create_employee_list(void)
{
	ListHandle p = (ListHandle)malloc(sizeof(struct EmployeeList));
	if (p == NULL) {
		printf("Hadle olusturulamadi \n");
		exit(EXIT_FAILURE);
	}
	p->mp_first = NULL;
	p->m_list_size = 0;

	return p;
}


void destroy_list(ListHandle h)
{
	make_empty(h);
	free(h);


}


int get_list_size(ListHandle h)
{
	return h->m_list_size;
}

int is_empty(ListHandle h)
{
	return h->m_list_size == 0;
}

void push_front(ListHandle h, const Employee* p)
{
	Node* p_new_node = create_node();
	p_new_node->edata = *p;
	p_new_node->pnext = h->mp_first;
	h->mp_first = p_new_node;
	++h->m_list_size;
}

void get_first(ListHandle h, Employee* p)
{

	if (is_empty(h)) {
		printf("bos listede erisim hatasi");
		exit(EXIT_FAILURE);
	}

	*p = h->mp_first->edata;
}

void print_employee_list(ListHandle h)
{
	for (Node* pn = h->mp_first; pn != NULL; pn = pn->pnext ) {

		print_employee(&pn->edata);
	}

	printf("\n**************************************************\n");

}

void pop_front(ListHandle h)
{
	if (is_empty(h)) {
		printf("bos listede pop hatasi \n");
		exit(EXIT_FAILURE);
	}
	 
	Node* temp = h->mp_first;
	h->mp_first = h->mp_first->pnext;
	free(temp);
	--h->m_list_size;

}

void make_empty(ListHandle h)
{
	while (!is_empty(h)) {
		pop_front(h);
	}
}