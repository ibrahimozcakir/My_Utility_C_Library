#define _CRT_SECURE_NO_WARNINGS
#include "utility.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>


const int sbc_[] = {
0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4,
1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8,
};


/**
 * @brief my_is_prime function control whether an integer is prime or not
 * @param x = The integer to check for prime
 * @retval int, returns 1 if the number is prime, otherwise 0.
 */
int my_is_prime(int x)
{
	if (x == 0 || x == 1)
		return 0;

	if (x % 2 == 0)
		return x == 2;

	if (x % 3 == 0)
		return x == 3;

	if (x % 5 == 0)
		return x == 5;
	                  
	for (int i = 7; i * i <= x; i += 2) {
		if (x % i == 0)
			return 0;
	}

	return 1;
}


/**
 * @brief my_ndigit function counts the number of digits in an integer.
 * @param val = The integer value which digits are to be counted.
 * @retval int, The number of digits in the given integer.
 */
int my_ndigit(int val)
{
	if (val == 0)
		return 1;

	int digit_count = 0;

	while (val){
		++digit_count;
		val /= 10;
	} 
	return digit_count;

}


/**
 * @brief my_put_star_line function prints a line of asterisks
 * @param None
 * @retval none
 */
void my_put_star_line(void)
{
	printf("\n*******************************************************************************************\n");
}


/**
 * @brief my_array_set_random function fills an array with random integers.
 *
 * @param p =  Pointer to the integer array to be filled.
 * @param size =  The size of the array.
 *
 * @retval None
 */
void my_array_set_random(int* p, int size)
{
	for (int i = 0; i < size; ++i) {

		p[i] = rand() % 500;
	}

}


/**
 * @brief my_array_print function prints the contents of an integer array.
 *
 * @param p = Pointer to the integer array to be printed.
 * @param size = The size of the array.
 *
 * @retval None
 */
void my_array_print(const int* p, int size)
{
	for (int i = 0; i < size; ++i) {

		if (i && i % 20 == 0)
			printf("\n");
		printf("%3d ", p[i]);
	}
	my_put_star_line();
}


/**
 * @brief my_clear_input_buffer function clears the input buffer.
 *
 * @param None
 *
 * @retval None
 */
void my_clear_input_buffer(void)
{
	int k;
	while ((k = getchar()) != '\n' && (k != EOF))
		; // null statement

}


/**
 * @brief my_gets function reads a line of input from the user.
 *
 * @param p = Pointer to the character array where the input string will be stored.
 *
 * @retval None
 */
void my_gets(char* p)
{
	int c;

	while ((c = getchar()) != '\n') {
		*p++ = (char)c;
	}

	*p = '\0';
}


/**
 * @brief my_swap function swaps two integer values..
 *
 * @param p1 = Pointer to the first integer.
 * @param p2 = Pointer to the second integer.
 *
 * @retval None
 */
void my_swap(int* p1, int* p2)
{
	int temp = *p1;

	*p1 = *p2;

	*p2 = temp;

}


/**
 * @brief my_array_sum function calculates the sum of an integer array.
 *
 * @param p = Pointer to the integer array.
 * @param size = The size of the array.
 *
 * @retval int, The sum of the array elements.
 */
int my_array_sum(const int* p, int size)
{
	int sum = 0;

	while (size--) {
		sum += *p++;
	}

	return sum;
}


/**
 * @brief my_get_mean function calculates the mean (average) of an integer array.
 *
 * @param p = Pointer to the integer array.
 * @param size = The size of the array.
 *
 * @retval double, The mean of the array elements.
 */
double my_get_mean(const int* p, int size)
{
	return (double)my_array_sum(p, size) / size;
}


/**
 * @brief my_std_dev function calculates the standard deviation of an integer array.
 *
 * @param p = Pointer to the integer array.
 * @param size = The size of the array.
 *
 * @retval double, The standard deviation of the array elements.
 */
double my_std_dev(const int* p, int size)
{
	double mean = my_get_mean(p, size);
	double sum_square = 0.;

	for (int i = 0; i < size; ++i) {
		sum_square += (p[i] - mean) * (p[i] - mean);
	}

	return sqrt(sum_square / size);
}


/**
 * @brief my_array_reverse function reverses the elements of an integer array.
 *
 * @param p = Pointer to the integer array.
 * @param size = The size of the array.
 *
 * @retval None
 */
void my_array_reverse(int* p, int size)
{
	for (int i = 0; i < size / 2; ++i) {

		my_swap(p + i, p + size - 1 - i);
	}
}


/**
 * @brief my_array_get_min function finds the minimum value in an integer array.
 * 
 * @param p = Pointer to the integer array.
 * @param size = The size of the array.
 *
 * @retval int, The smallest value in the array.
 */
int my_array_get_min(const int* p, int size)
{
	int min = *p;

	for (int i = 1; i < size; ++i) {
		if (min > *(p + i))
			min = *(p + i);

	}
	return min;
}


/**
 * @brief my_array_get_max functions finds the maximum value in an integer array.
 *
 * @param p = Pointer to the integer array.
 * @param size = The size of the array.
 *
 * @retval int, The largest value in the array.
 */
int my_array_get_max(const int* p, int size)
{
	int max = *p;
	for (int i = 1; i < size; ++i) {
		if (max < *(p + i))
			max = *(p + i);
	}
	return max;

}


/**
 * @brief my_array_get_min_max function finds both minimum and maximum values in an integer array.
 * 
 * @param p = Pointer to the integer array.
 * @param size = The size of the array.
 * @param pmin = Pointer to store the minimum value.
 * @param pmax = Pointer to store the maximum value.
 *
 * @retval None
 */
void my_array_get_min_max(const int* p, int size, int* pmin, int* pmax)
{

	*pmin = *pmax = *p;
	for (int i = 1; i < size; ++i) {
		if (*pmin > *(p + i))
			*pmin = *(p + i);
		else if (*pmax < *(p + i))
			*pmax = *(p + i);
	}

}


/**
 * @brief my_array_copy function copies the contents of one integer array to another.
 *
 * @param p_incopy = Pointer to the destination array.
 * @param p_source = Pointer to the source array.
 * @param size = The size of the arrays.
 *
 * @retval None
 */
void my_array_copy(int* p_incopy, const int* p_source, int size)
{
	for (int i = 0; i < size; ++i) {

		p_incopy[i] = p_source[i];
	}
}


/**
 * @brief my_array_reverse_copy function copies and reverses the contents of one array to another.
 *
 * @param p_incopy = Pointer to the destination array.
 * @param p_source = Pointer to the source array.
 * @param size = The size of the arrays.
 *
 * @retval None
 */
void my_array_reverse_copy(int* p_incopy, const int* p_source, int size)
{
	for (int i = 0; i < size; ++i) {

		p_incopy[i] = p_source[size - i - 1];
	}
	
}


/**
 * @brief my_array_bsort function sorts an array using the bubble sort algorithm.
 *
 * @param p = Pointer to the array to be sorted.
 * @param size = The size of the array.
 *
 * @retval None
 */
void my_array_bsort(int* p, int size)
{
	for (int i = 0; i < size - 1; ++i) {

		for (int j = 0; j < size - 1 - i; ++j) {

			if (p[j] > p[j + 1]) {

				my_swap(p + j, p + j + 1);

			}
		}
	}
}


/**
 * @brief my_array_get_max_adress function finds the address of the maximum element in an array.
 *
 * @param p = Pointer to the integer array.
 * @param size = The size of the array.
 * 
 * @retval int*, Address of the maximum element.
 */
int* my_array_get_max_adress(const int* p, int size)
{
	int* pmax = (int*)p;

	for (int i = 1; i < size; ++i) {

		if (p[i] > *pmax)
			pmax = (int*) (p + i);
	}
	return pmax;
}


/**
 * @brief my_array_get_min_adress function finds the address of the minimum element in an array.
 *
 * @param p = Pointer to the integer array.
 * @param size = The size of the array.
 * 
 * @retval int* , Address of the minimum element.
 */
int* my_array_get_min_adress(const int* p, int size)
{
	int* pmin = (int*)p;

	for (int i = 1; i < size; ++i) {

		if (p[i] < *pmin)
			pmin = (int*)(p + i);
	}
	return pmin;
}

/**
 * @brief my_array_selection_sort function sorts an integer array in ascending order using the selection sort algorithm.
 *
 * @param p = Pointer to the integer array.
 * @param size = The size of the array.
 * 
 * @retval None
 */

void my_array_selection_sort(int* p, int size)
{
	for (int i = 0; i < size - 1; ++i) {

		my_swap(p + i, my_array_get_min_adress(p + i, size - i));
	}
}


/**
 * @brief my_array_search function searches for a value in an array and returns its address if found.
 *
 * @param p = Pointer to the integer array.
 * @param size = The size of the array.
 * @param ival = The value to search for.
 * 
 * @retval int*, Address of the found value, or NULL if not found.
 */
int* my_array_search(const int* p, int size, int ival)
{
	for (int i = 0; i < size; ++i) {

		if (p[i] == ival)
			return (int *)(p + i);
	}

	return NULL;
}


/**
 * @brief my_puts function prints a null-terminated string followed by a newline.
 *
 * @param p = Pointer to the null-terminated string.
 * 
 * @retval None
 */
void my_puts(const char* p)
{
	for (int i = 0; p[i] != '\0'; ++i) {
		putchar(p[i]);
	}
	putchar('\n');
}


/**
 * @brief my_strlen function calculates the length of a null-terminated string.
 *
 * @param p = Pointer to the null-terminated string.
 * 
 * @retval size_t, Length of the string.
 */ 
size_t my_strlen(const char* p)
{
	size_t len = 0;
	while (*p++ != '\0')
		++len;
		
	return len;
}


/**
 * @brief my_strchr function locates the first occurrence of a character in a string.
 *
 * @param p = Pointer to the null-terminated string.
 * @param c = Character to find.
 * 
 * @retval char*, Pointer to the first occurrence of the character, or NULL if not found.
 */
char* my_strchr(const char* p, int c)
{
	while (*p != '\0') {
		if (*p == c)
			return (char*)p;
		++p;
	}

	if (c == '\0')
		return (char*)p;

	return NULL;
}


/**
 * @brief my_strrchr function locates the last occurrence of a character in a string.
 *
 * @param p = Pointer to the null-terminated string.
 * @param c = Character to find.
 * 
 * @retval char*, Pointer to the last occurrence of the character, or NULL if not found.
 */
char* my_strrchr(const char* p, int c)
{
	const char* pret = NULL;

	while (*p != '\0')
	{
		if (*p == c)
			pret = p;
		++p;
	}
	if (c == '\0')
		return (char*)p;

	return (char*) pret;
}


/**
 * @brief my_strcpy function copies the null-terminated string from source to destination.
 *
 * @param pdest = Pointer to the destination buffer.
 * @param psource = Pointer to the source null-terminated string.
 *
 * @retval char*, Pointer to the destination string.
 */
char* my_strcpy(char* pdest, const char* psource)
{
	char* pret = pdest;
	while (*pdest++ = *psource++)
		;

	return pret;
}


/**
 * @brief my_strcat function concatenates the null-terminated string from source to destination.
 *
 * @param pdest = Pointer to the destination buffer.
 * @param psource = Pointer to the source null-terminated string.
 *
 * @retval char*, Pointer to the destination string.
 */
char* my_strcat(char* pdest, const char* psource)
{
	char* pret = pdest;
	while (*pdest != '\0')
		++pdest;

	while (*pdest++ = *psource++)
		;

	return pret;
}


/**
 * @brief my_strpbrk function searches for any character in a string that matches any character in a second string.
 *
 * @param p1 = Pointer to the first null-terminated string.
 * @param p2 = Pointer to the second null-terminated string.
 *
 * @retval char*, Pointer to the first occurrence of the matched character, or NULL if no match is found.
 */
char *my_strpbrk(const char* p1, const char* p2)
{

	while (*p1 != '\0') {
	
		if (strchr(p2, *p1))
			return (char*)p1;
		p1++;
	}
	return NULL;
}


/**
 * @brief my_strstr function locates the first occurrence of a substring in a string.
 *
 * @param p1 = Pointer to the null-terminated string.
 * @param p2 = Pointer to the null-terminated substring.
 *
 * @retval char*, Pointer to the beginning of the located substring, or NULL if not found.
 */
char* my_strstr(const char* p1, const char* p2)
{
	while (*p1 != '\0') {

		const char* temp1 = p1;
		const char* temp2 = p2;

		while ((*temp1 && *temp2) && (*temp1 == *temp2)) {
			temp1++;
			temp2++;
		}
		if (*temp2 == '\0')
			return (char*)p1;

		p1++;
	}
	return NULL;
}


/**
 * @brief my_strcmp function compares two null-terminated strings.
 *
 * @param p1 = Pointer to the first null-terminated string.
 * @param p2 = Pointer to the second null-terminated string.
 *
 * @retval int, Difference between the first unmatched characters, or 0 if the strings are identical.
 */
int my_strcmp(const char* p1, const char* p2)
{
	while (*p1 == *p2) {
		if (*p1 == '\0')
			return 0;
		++p1;
		++p2;
	}
	return *p1 - *p2;
}


/**
 * @brief my_stricmp function compares two null-terminated strings case-insensitively.
 *
 * @param p1 = Pointer to the first null-terminated string.
 * @param p2 = Pointer to the second null-terminated string.
 *
 * @retval int, Difference between the first unmatched characters (case-insensitive), or 0 if the strings are identical.
 */
int my_stricmp(const char* p1, const char* p2)
{
	while (toupper(*p1) == toupper(*p2)) {
		if (*p1 == '\0')
			return 0;
		++p1;
		++p2;
	}
	return toupper(*p1) - toupper(*p2);

}

/**
 * @brief my_endswith function checks if a string ends with a specified substring.
 *
 * @param p1 = Pointer to the null-terminated string.
 * @param p2 = Pointer to the null-terminated substring.
 *
 * @retval int, 1 if the string ends with the substring, 0 otherwise.
 */
int my_endswith(const char* p1, const char* p2)
{
	size_t p1len = strlen(p1);
	size_t p2len = strlen(p2);

	if (p2len > p1len)
		return 0;

	return !strcmp(p1 + p1len - p2len, p2);
}

/**
 * @brief my_gswap function swaps the contents of two memory blocks.
 *
 * @param vp1 = Pointer to the first memory block.
 * @param vp2 = Pointer to the second memory block.
 * @param n Number of bytes to swap.
 * 
 * @retval None
 */
void my_gswap(void* vp1, void* vp2, size_t n)
{
	char* p1 = (char*)vp1;
	char* p2 = (char*)vp2;

	while (n--) {
		char temp = *p1;
		*p1++ = *p2;
		*p2++ = temp;
	}
}


/**
 * @brief my_memset function fills a memory block with a specified value.
 *
 * @param vp = Pointer to the memory block.
 * @param val = Value to set.
 * @param n = Number of bytes to fill.
 *
 * @retval void*, Pointer to the memory block.
 */
void* my_memset(void* vp, int val, size_t n)
{
	char* p = (char*)vp;
	while (n--)
		*p++ = (char)val;

	return vp;
}


/**
 * @brief my_memcpy function copies a specified number of bytes from source to destination.
 *
 * @param pdest = Pointer to the destination memory block.
 * @param psource = Pointer to the source memory block.
 * @param n = Number of bytes to copy.
 *
 * @retval void*, Pointer to the destination memory block.
 */
void* my_memcpy(void* pdest, const void* psource, size_t n)
{
	char* p1dest = (char*)pdest;
	const char* p2source = (const char*)psource;

	while (n--) {
		*p1dest++ = *p2source++;
	}
	return pdest;
}


/**
 * @brief my_memmove function safely copies a specified number of bytes from source to destination with potential overlap handling.
 *
 * @param vpdest = Pointer to the destination memory block.
 * @param vpsource = Pointer to the source memory block.
 * @param n = Number of bytes to copy.
 *
 * @retval void*, Pointer to the destination memory block.
 */ 

void* my_memmove(void* vpdest, const void* vpsource, size_t n)
{
	char* pdest = (char*)vpdest;
	const char* psource = (const char*)vpsource;

	if (pdest < psource) {

		while (n--)
			*pdest++ = *psource++;
	}
	else {
		pdest += n;
		psource += n;
		while (n--)
			*pdest-- = *psource--;
	}
	return vpdest;
}


/**
 * @brief my_memchr function scans the first n bytes of the memory block pointed to by p for the first occurrence of val.
 *
 * @param p = Pointer to the memory block to scan.
 * @param val = Value to be located within the memory block.
 * @param n = Number of bytes to be scanned.
 *
 * @retval void*, Pointer to the first occurrence of val within the memory block or NULL if not found.
 */
void* my_memchr(const void* p, int val, size_t n)
{
	const char* p1 = (const char*)p;
	while (n--) {
		if (*p1 == val) {
			return (char*)p1;
		}
		++p1;
	}

	return NULL;
}


/**
 * @brief my_memcmp function compares the first n bytes of two memory blocks pointed to by vp1 and vp2.
 *
 * @param vp1 = Pointer to the first memory block.
 * @param vp2 = Pointer to the second memory block.
 * @param n = Number of bytes to compare.
 *
 * @retval int, A value greater than, equal to, or less than zero if the first n bytes of vp1 are greater than, equal to, or less than the first n bytes of vp2, respectively.
 */
int my_memcmp(const void* vp1, const void* vp2, size_t n)
{
	const unsigned char* p1 = (const unsigned char*)vp1;
	const unsigned char* p2 = (const unsigned char*)vp2;

	while (n--) {
		if (*p1 != *p2) {
			return (*p1 - *p2); // *p1 > *p2 ? 1 : -1
		}
		p1++;
		p2++;
	}
	return 0;
}


/**
 * @brief my_array_greverse function reverses the order of elements in an array of specified size, where each element is of a given byte size.
 *
 * @param vp = Pointer to the array to be reversed.
 * @param size = Number of elements in the array.
 * @param byte = Size in bytes of each element in the array.
 *
 * @retval None
 */
void my_array_greverse(void* vp, size_t size, size_t byte)
{
	char* p = (char*)vp;

	for (size_t i = 0; i < (size / 2); ++i) {

		for (size_t j = 0; j < byte; ++j) {
			char temp = p[byte * i + j];
			p[byte * i + j] = p[(size - i - 1) * byte + j];
			p[(size - i - 1) * byte + j] = temp;
		}
	}
} 


/**
 * @brief my_array_gsearch function searches for a specific value within an array of elements, where each element is of a given byte size.
 *
 * @param vp = Pointer to the array to be searched.
 * @param val = Pointer to the value to be searched for.
 * @param size = Number of elements in the array.
 * @param byte = Size in bytes of each element in the array.
 *
 * @retval void*, Pointer to the first occurrence of the value within the array or NULL if not found.
 */
void* my_array_gsearch(void* vp, const void* val, size_t size, size_t byte)
{
	char* p = (char*)vp;
	const char* val1 = (const char*)val;
	for (size_t i = 0; i < size; ++i) {
		int flag = 1;
		for (size_t j = 0; j < byte; ++j) {

			if (p[j] != val1[j]) {

				flag = 0;
				break;
			}	
		}
		if (flag)
			return (char*)p;
		p += byte;
	}
	return NULL;
}




/**
 * @brief gbsort function sorts an array of elements using the bubble sort algorithm and a user-defined comparison function.
 *
 * @param vpa = Pointer to the array to be sorted.
 * @param size = Number of elements in the array.
 * @param byte = Size in bytes of each element in the array.
 * @param fcmp = Pointer to the comparison function used to compare two elements.
 *
 * @retval None
 */
void gbsort(void* vpa, size_t size, size_t byte, int (*fcmp)(const void*, const void*))
{
	char* pa = (char*)vpa;

	for (size_t i = 0; i < size - 1; ++i) {

		for (size_t j = 0; j < size - 1 - i; ++j) {

			if (fcmp(pa + j * byte, pa + (j + 1) * byte) > 0) {

				my_gswap(pa + j * byte, pa + (j + 1) * byte, byte);
			}
		}
	}
}


/**
 * @brief icmp function compares two integers and returns an indication of their relative order.
 *
 * @param vp1 = Pointer to the first integer.
 * @param vp2 = Pointer to the second integer.
 *
 * @retval int, Returns 1 if the first integer is greater, -1 if the second integer is greater, and 0 if they are equal.
 */
int icmp(const void* vp1, const void* vp2)
{

	const int p1 = *(const int*)vp1;
	const int p2 = *(const int*)vp2;

	if (p1 > p2)
		return 1;

	if (p2 > p1)
		return -1;

	return 0;
}



/**
 * @brief my_strdup function creates a duplicate of the given null-terminated string.
 *
 * @param p = Pointer to the null-terminated string to be duplicated.
 *
 * @retval char*, Pointer to the newly allocated string which is a duplicate of the input string, or NULL if memory allocation fails.
 */
char* my_strdup(const char* p)
{
	size_t len = strlen(p);
	char* p2 = (char*)malloc(sizeof(p) + 1);
	if (p2 == NULL)
		return NULL;

return strcpy(p2, p);
}



/**
 * @brief my_strconcat function concatenates two null-terminated strings into a newly allocated string.
 *
 * @param p1 = Pointer to the first null-terminated string.
 * @param p2 = Pointer to the second null-terminated string.
 *
 * @retval char*, Pointer to the newly allocated string containing the concatenation of p1 and p2, or NULL if memory allocation fails.
 */
char* my_strconcat(const char* p1, const char* p2)
{
	char* psw = (char*)malloc(strlen(p1) + strlen(p2) + 1);
	if (psw == NULL)
		return psw;


	strcpy(psw, p1);
	strcat(psw, p2);
	return psw;
}


/**
 * @brief random_name function returns a randomly selected name from a predefined list of names.
 *
 * @retval const char*, Pointer to the randomly selected name string.
 */
const char* random_name(void)
{
	static const char* const pnames[] = {
	"Ahmet", "Mehmet", "Ali", "Veli", "Hasan", "Huseyin", "Ayse", "Fatma", "Emre", "Zeynep",
	"Omer", "Yusuf", "Mustafa", "Serkan", "Selim", "Esra", "Gizem", "Can", "Deniz", "Derya",
	"Emir", "Elif", "Burak", "Berk", "Sinem", "Gokhan", "Meltem", "Seda", "Bora", "Tugba",
	"Ferhat", "Pelin", "Sevda", "Sibel", "Ece", "Naz", "Nehir", "Bahar", "Cem", "Berat",
	"Sahin", "Ugur", "Dogan", "Tamer", "Betul", "Ilker", "Ipek", "Damla", "Furkan", "Beril",
	"Eren", "Yilmaz", "Gul", "Ayla", "Baran", "Koray", "Nihat", "Enes", "Selda", "Okan",
	"Hayri", "Cihan", "Feyza", "Merve", "Sami", "Eda", "Ekin", "Ozan", "Cemil", "Tuna",
	"Hande", "Hakan", "Ilhan", "Sevil", "Ersin", "Pinar", "Onur", "Suat", "Beliz", "Ismet",
	"Safiye", "Bahar", "Yigit", "Lale", "Ediz", "Taner", "Saniye", "Bilal", "Dilek", "Murat",
	"Altan", "Alev", "Baris", "Arzu", "Zeki", "Buket", "Necla", "Beste", "Canan", "Merve",
	"Yesim", "Nejat", "Serdar", "Burcu", "Nazan", "Sinan", "Riza", "Leyla", "Buse", "Rahmi",
	"Cagla", "Safa", "Teoman", "Sevilay", "Halil", "Esin", "Ayhan", "Sultan", "Ahsen", "Davut",
	"Hulya", "Yalcin", "Tarik", "Emel", "Eylem", "Sezer", "Sermin", "Gokce", "Serpil", "Arif",
	"Yakup", "Erdem", "Melih", "Tan", "Akin", "Semih", "Nazli", "Ceren", "Seher", "Zuhal",
	"Evren", "Deniz", "Ayla", "Ekin", "Cihan", "Sevgi", "Mehve", "Ilayda", "Nazim", "Guney",
	"Onder", "Binnaz", "Berkay", "Ferda", "Sadi", "Zekiye", "Ulas", "Rana", "Zerrin", "Mete",
	"Talha", "Mithat", "Enis", "Umit", "Adem", "Yasar", "Nuran", "Ayca", "Tugce", "Suat",
	"Emrah", "Atilla", "Derya", "Oguz", "Sinem", "Sevda", "Ufuk", "Yesim", "Nevin", "Ceyda",
	"Elvan", "Aytac", "Yasemin", "Nail", "Funda", "Kutay", "Ozge", "Ozan", "Aykut", "Nevzat",
	"Gulcin", "Orhan", "Bilge", "Turgay", "Senay", "Filiz", "Gonca", "Berrin", "Selim", "Sami",
	"Ender", "Asil", "Burhan", "Halime", "Sezgin", "Gulsum", "Nida", "Gizem", "Selen", "Yelda"
	};

	return relem(pnames);

}

/**
 * @brief random_sname function returns a randomly selected surname from a predefined list of surnames.
 *
 * @retval const char*, Pointer to the randomly selected surname string.
 */
const char* random_sname(void)
{
	static const char* const psnames[] = {
	"Yilmaz", "Kara", "Ozdemir", "Arslan", "Dogan", "Erdogan", "Aydin", "Sahin", "Demir", "Ozturk",
	"Polat", "Akgun", "Kilic", "Kaya", "Gul", "Cetin", "Cicek", "Bayrak", "Uslu", "Celik",
	"Yildirim", "Ulusoy", "Akkaya", "Durmaz", "Gunduz", "Turkmen", "Tekin", "Balci", "Koc", "Ozkan",
	"Guler", "Yigit", "Gurbuz", "Demirel", "Sari", "Akar", "Tan", "Orhan", "Bora", "Tunc",
	"Kayaalp", "Ak", "Altin", "Ozer", "Korkmaz", "Akdeniz", "Durak", "Bayer", "Avci", "Keskin",
	"Yagci", "Ozgur", "Bicer", "Gokce", "Duman", "Goktas", "Coskun", "Sarac", "Alp", "Akyuz",
	"Esen", "Doganay", "Topal", "Gulmez", "Yalcin", "Aksu", "Tanriverdi", "Aydemir", "Toprak", "Ozmen",
	"Ay", "Ince", "Bilgin", "Sancak", "Seyhan", "Balcik", "Unal", "Aydogdu", "Ergin", "Ozgul",
	"Kose", "Yoruk", "Ates", "Yuruk", "Akalin", "Ilerisoy", "Erkan", "Bayar", "Ozgun", "Ozerkan",
	"Kartal", "Kavak", "Ozsoy", "Altay", "Gundogan", "Saglam", "Basar", "Onur", "Karaoglan", "Kiraz",
	"Kir", "Karaca", "Demirkol", "Ergul", "Ozbay", "Sag", "Aygun", "Turan", "Guven", "Gokalp",
	"Gur", "Karci", "Yesil", "Can", "Seker", "Sezer", "Ozgenc", "Gulec", "Ozdil", "Tavukcu",
	"Turker", "Ar", "Bay", "Ertugrul", "Isik", "Kiran", "Bas", "Gun", "Guney", "Bozkurt",
	"Yetkin", "Oruc", "Cosar", "Telli", "Ayturk", "Orman", "Oguz", "Acar", "Sayin", "Bilge",
	"Kabak", "Baykara", "Guler", "Esmer", "Bagci", "Ergun", "Ulker", "Elmas", "Atilgan", "Ayvaz",
	"Gungor", "Nacak", "Batur", "Ozturkcan", "Yildiz", "Durukan", "Yorulmaz", "Yasar", "Karahan", "Yar",
	"Alkan", "Kibar", "Ogul", "Tekbas", "Kurt", "Aral", "Bilal", "Gumus", "Fidan", "Akbay",
	"Kayaoglu", "Ateþci", "Demirci", "Goksu", "Turgut", "Gokmen", "Tufan", "Sagman", "Ilker", "Maden",
	"Albayrak", "Beyaz", "Yavuz", "Ergenc", "Burak", "Ipek", "Soykan", "Gullu", "Yildirimoglu", "Golge",
	"Keles", "Gokcan", "Akyol", "Guneydogdu", "Aytekin", "Dalkiran", "Bostan", "Kum", "Ok", "Cigdem"
	};

	return relem(psnames);

}


/**
 * @brief random_town function returns a randomly selected town name from a predefined list of towns.
 *
 * @retval const char*, Pointer to the randomly selected town name string.
 */

const char* random_town(void)
{
	static const char* const ptown[] = {
	"Adana", "Adiyaman", "Afyon", "Agri", "Aksaray", "Amasya", "Ankara", "Antalya", "Ardahan", "Artvin",
	"Aydin", "Balikesir", "Bartin", "Batman", "Bayburt", "Bilecik", "Bingol", "Bitlis", "Bolu", "Burdur",
	"Bursa", "Canakkale", "Cankiri", "Corum", "Denizli", "Diyarbakir", "Duzce", "Edirne", "Elazig", "Erzincan",
	"Erzurum", "Eskisehir", "Gaziantep", "Giresun", "Gumushane", "Hakkari", "Hatay", "Igdir", "Isparta", "Istanbul",
	"Izmir", "Kahramanmaras", "Karabuk", "Karaman", "Kars", "Kastamonu", "Kayseri", "Kilis", "Kirikkale", "Kirklareli",
	"Kirsehir", "Kocaeli", "Konya", "Kutahya", "Malatya", "Manisa", "Mardin", "Mersin", "Mugla", "Mus",
	"Nevsehir", "Nigde", "Ordu", "Osmaniye", "Rize", "Sakarya", "Samsun", "Siirt", "Sinop", "Sirnak",
	"Sivas", "Sanliurfa", "Tekirdag", "Tokat", "Trabzon", "Tunceli", "Usak", "Van", "Yalova", "Yozgat",
	"Zonguldak"
	};
	return relem(ptown);

}


/**
 * @brief bprint function prints the binary representation of an integer to the console.
 *
 * @param val = The integer to be printed in binary format.
 *
 * @retval None
 */
void bprint(int val)
{

	for (int i = sizeof(int) * 8 - 1; i >= 0; --i) {

		putchar((val & (1 << i)) ? '1' : '0');

	}
	putchar('\n');

}
