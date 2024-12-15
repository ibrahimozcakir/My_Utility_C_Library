#define _CRT_SECURE_NO_WARNINGS
#include "date.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define YEARBASE                   1900
#define PRIVATE                    static
#define PUBLIC
#define NO_OF_DAYS(y, m)           (daydabs[ISLEAP(y)][m])
#define ISLEAP(y)                  ((y) % 4 == 0 && (y) % 100 != 0 || (y) % 400 == 0)
#define	RANDOM_MIN_YEAR            1900
#define	RANDOM_MAX_YEAR            2024



PRIVATE Date* set(Date* p, int d, int m, int y);
PRIVATE int is_valid_date(int d, int m, int y);
PRIVATE int day_of_week(int d, int m, int y);
PRIVATE int totaldays(const Date* p);
PRIVATE Date* int_to_date(Date* pdest, int totaldays);


PRIVATE const int daydabs[][13] = {
	{0,31,28,31,30,31,30,31,31,30,31,30,31},
	{0,31,29,31,30,31,30,31,31,30,31,30,31},
};




/*
PUBLÝC FUNCTÝONS IMPLEMENTATIONS
*/ 

// a) get functions

PUBLIC int get_year(const Date* p)
{
	return p->my;
}
PUBLIC int get_month(const Date* p)
{
	return p->mm;
}
PUBLIC int get_month_day(const Date* p)
{
	return p->md;
}
PUBLIC int get_week_day(const Date* p)
{
	return day_of_week(get_month_day(p), 
					   get_month(p), 
				       get_year(p));
}
PUBLIC int get_year_day(const Date* p)
{
	int sum = get_month_day(p);
	int mon = get_month(p);
	int year = get_year(p);
	for (int i = 1; i < mon; ++i) {

		sum += NO_OF_DAYS(year, i);
	}
	return sum;

}


// b) print and scan functions

PUBLIC void print_date(const Date* p)
{
	static const char* pmons[] = {

		"",
		"Ocak",
		"Subat",
		"Mart",
		"Nisan",
		"Mayis",
		"Haziran",
		"Temmuz",
		"Agustos",
		"Eylul",
		"Ekim",
		"Kasim",
		"Aralik"
	};

	static const char* pdays[] = {

		"Pazar",
		"Pazartesi",
		"Sali",
		"Carsamba",
		"Persembe",
		"Cuma",
		"Cumartesi"
	};

	printf("%02d %s %d %s\n",   get_month_day(p),
								pmons[get_month(p)],
								get_year(p), 
								pdays[get_week_day(p)]);
}
PUBLIC void print_date_array(Date* p, size_t size)
{
	while (size--)
		print_date(p++);

}
PUBLIC Date* scan_date(Date* p)
{
	int day;
	int mon;
	int year;
	(void)scanf("%d%d%d", &day, &mon, &year);

	return set(p, day, mon, year);
}
PUBLIC void print_date_(FILE* f, const Date* p)
{
	static const char* pmons[] = {

		"",
		"Ocak",
		"Subat",
		"Mart",
		"Nisan",
		"Mayis",
		"Haziran",
		"Temmuz",
		"Agustos",
		"Eylul",
		"Ekim",
		"Kasim",
		"Aralik"
	};

	static const char* pdays[] = {

		"Pazar",
		"Pazartesi",
		"Sali",
		"Carsamba",
		"Persembe",
		"Cuma",
		"Cumartesi"
	};

	fprintf(f,"%02d %s %d %s\n", get_month_day(p),
		pmons[get_month(p)],
		get_year(p),
		pdays[get_week_day(p)]);
}


// c) utility functions
PUBLIC int cmp_date(const Date* p1, const Date* p2)
{
	int p1_year = get_year(p1);
	int p2_year = get_year(p2);

	if (p1_year != p2_year)
		return p1_year - p2_year;

	int p1_month = get_month(p1);
	int p2_month = get_month(p2);

	if (p1_month != p2_month)
		return p1_month - p2_month;

	return get_month_day(p1) - get_month_day(p2);

}
PUBLIC int date_diff(const Date* p1, const Date* p2)
{
	return totaldays(p1) - totaldays(p2);

}
PUBLIC Date* ndays_after(Date* p, const Date* psource, int n)
{
	return int_to_date(p,totaldays(psource) + n);
}
PUBLIC Date* ndays_before(Date* p, const Date* psource, int n)
{
	return int_to_date(p, totaldays(psource) - n);


}
PUBLIC int dcmp(const void* vp1, const void* vp2)
{
	return cmp_date((const Date*)vp1, (const Date*)vp2);
}


// d) set functions
PUBLIC Date* set_date(Date* p, int day, int mon, int year)
{
	return set(p, day, mon, year);
}
PUBLIC void set_date_array(Date* p, size_t size)
{
	while (size--) 
		set_date_random(p++);
	
}
PUBLIC Date* set_date_by_str(Date* p, const char* pfm)
{

	int day = atoi(pfm);
	int mon = atoi(pfm + 3);
	int year = atoi(pfm + 6);

	return set(p, day, mon, year);

}
PUBLIC Date* set_date_today(Date* p)
{
	time_t timer;
	time(&timer);
	struct tm* tmptr = localtime(&timer);

	return set(p,
		          tmptr->tm_mday, 
		          tmptr->tm_mon + 1, 
				  tmptr->tm_year + 1900);
}
PUBLIC Date* set_date_random(Date* p)
{
	int year = rand() % (RANDOM_MAX_YEAR - RANDOM_MIN_YEAR + 1) + RANDOM_MIN_YEAR;
	int mon = rand() % 12 + 1;
	int day = rand() % NO_OF_DAYS(year, mon) + 1;

	return set(p, day, mon, year);
}
PUBLIC Date* set_year(Date* p, int y)
{
	return set(p,get_month_day(p), get_month(p), y);
}
PUBLIC Date* set_month(Date* p, int m)
{
	return set(p, get_month_day(p), m, get_year(p));
}
PUBLIC Date* set_month_day(Date* p, int mday)
{
	return set(p, mday, get_month(p), get_year(p));
}





/* 
PRÝVATE FUNCTÝONS ÝMPLEMENTATÝONS
*/

PRIVATE int is_valid_date(int d, int m, int y)
{
	return  (y >= YEARBASE) && (m > 0 && m <= 12) && (d <= NO_OF_DAYS(y, m));

}
PRIVATE int day_of_week(int d, int m, int y)
{
	static const int t[] = { 0,3,2,5,0,3,5,1,4,6,2,4 };

	if (m < 3)
		y -= 1;
	return ((y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7);
}
PRIVATE Date* set(Date* p, int d, int m, int y)
{
	if (!is_valid_date(d, m, y)) {
		printf("gecersiz tarih %d %d %d", d, m, y);
		exit(EXIT_FAILURE);
	}

	p->md = d;
	p->mm = m;
	p->my = y;
	
	return p;
}
PRIVATE int totaldays(const Date* p)
{
	int sum = get_year_day(p);
	int year = get_year(p);
	for (int i = YEARBASE; i < year; ++i) {

		sum += ISLEAP(i) ? 366 : 365;

	}
	return sum;
}
PRIVATE Date* int_to_date(Date *p, int totaldays)
{
	int year = YEARBASE;

	while (totaldays > (ISLEAP(year) ? 366 : 365)) {

		totaldays -= ISLEAP(year) ? 366 : 365;

		++year;
	}

	int mon = 1;
	while (totaldays > (NO_OF_DAYS(year,mon))) {

		totaldays -= NO_OF_DAYS(year, mon);

		++mon;
	}

	int day = totaldays;

	return set_date(p, day, mon, year);

}




