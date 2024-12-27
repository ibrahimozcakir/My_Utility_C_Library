#ifndef UTILITY_H
#define UTILITY_H



#define is_leap(y)          ((y) % 4 == 0 && ((y) % 100 != 0 || (y) % 400 == 0))
#define randomize()         (srand((unsigned int)time(0)))
#define asize(x)            (sizeof(x) / sizeof(x[0]))
#define relem(a)            (a[rand() % asize(a)])
#define sbc(x)              (sbc_[(x) & 255] + sbc_[(x) >> 8 & 255] + sbc_[(x) >> 16 & 255] + sbc_[(x) >> 24 & 255])
#define XCOLARS             X(YELLOW) \
							X(BLUE) \
							X(GREEN) \
							X(PINK)

extern const int sbc_[];

int  my_is_prime(int);
int  my_ndigit(int);
void my_put_star_line(void);
void my_array_set_random(int* p, int size);
void my_array_print(const int* p, int size);
void my_gets(char* p);
void my_clear_input_buffer(void);
void my_swap(int*, int*);
int my_array_sum(const int* p, int size);
double my_get_mean(const int* p, int size);
double my_std_dev(const int* p, int size);
void my_array_reverse(int* p, int size);
int my_array_get_min(const int* p, int size);
int my_array_get_max(const int* p, int size);
void my_array_get_min_max(const int* p, int size, int* pmin, int* pmax);
void my_array_copy(int* p_incopy, const int* p_source, int size);
void my_array_reverse_copy(int* p_incopy, const int* p_source, int size);
void my_array_bsort(int* p, int size);
int* my_array_get_max_adress(const int* p, int size);
int* my_array_get_min_adress(const int* p, int size);
void my_array_selection_sort(int* p, int size);
int* my_array_search(const int* p, int size, int ival);

const char* random_name(void);
const char* random_sname(void);
const char* random_town(void);

void my_puts(const char* p);
size_t my_strlen(const char* p);
char* my_strchr(const char* p, int c);
char* my_strrchr(const char* p, int c);
char* my_strcpy(char* pdest, const char* psource);
char* my_strcat(char* pdest, const char* psource);
char* my_strpbrk(const char* p1, const char* p2);
char* my_strstr(const char* p1, const char* p2);
int my_strcmp(const char* p1, const char* p2);
int my_stricmp(const char* p1, const char* p2);
int my_endswith(const char* p1, const char* p2);
char* my_strdup(const char* p);
char* my_strconcat(const char* p1, const char* p2);
void bprint(int val);

//generic
void my_gswap(void* vp1, void* vp2, size_t n);
void* my_memset(void* vp, int val, size_t n);
void* my_memcpy(void* pdest, const void* psource, size_t n);
void* my_memmove(void* vpdest, const void* vpsource, size_t n);
void* my_memchr(const void* p, int val, size_t n);
int my_memcmp(const void* vp1, const void* vp2, size_t n);
void my_array_greverse(void* vp, size_t size, size_t n);
void* my_array_gsearch(const void* vp, const void* val, size_t size, size_t byte);
void gbsort(void* vpa, size_t size, size_t byte, int (*fcmp)(const void*, const void*));
int icmp(const void* vp1, const void* vp2);
//////



#endif
