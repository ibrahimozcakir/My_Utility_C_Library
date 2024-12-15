#ifndef DATA_H
#define DATA_H
#include <stdlib.h>
#include <stdio.h>


typedef struct {
	int md; // ayýn günü [1...31]
	int mm; // ay [1...12]
	int my; // yýl örnek --> 2024
} Date;

 // set functions
Date* set_date(Date* p, int day, int mon, int year);
void set_date_array(Date* p, size_t size);
Date* set_date_by_str(Date* p, const char *pfm);
Date* set_date_today(Date* p);
Date* set_date_random(Date* p);
Date* set_year(Date* p, int y);
Date* set_month(Date* p, int m);
Date* set_month_day(Date* p, int mday);


// accessor - get functions 
int get_year(const Date* p);
int get_month(const Date* p);
int get_month_day(const Date* p);
int get_week_day(const Date* p);
int get_year_day(const Date* p);


// input - output functions
void print_date(const Date* p);
void print_date_(FILE* f,const Date* p);
void print_date_array(Date* p, size_t size);
Date* scan_date(Date* p);


// utility functions
int cmp_date(const Date* p1, const Date* p2);
int date_diff(const Date* p1, const Date* p2);
Date* ndays_after(Date* p, const Date* psource, int n);
Date* ndays_before(Date* p, const Date* psource, int n);
int dcmp(const void* vp1, const void* vp2);
int totaldays(const Date* p);

#endif 

