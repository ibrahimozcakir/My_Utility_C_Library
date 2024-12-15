# Utility_Lib

### Overview
A collection of utility functions for various operations such as number analysis, array manipulations, and basic input/output utilities in C.

### Installation
1. Clone the repository.
2. Include `nutility.h` and `nutility.c` in your project.
3. Compile and link them with your main file.

### Example Usage
```c
#include "nutility.h"
#include <stdio.h>

int main() {
    int arr[5] = {0};
    my_array_set_random(arr, 5);
    my_array_print(arr, 5);

    printf("Sum of array: %d\n", my_array_sum(arr, 5));

    my_put_star_line();
    return 0;
}
```

### Some Functions
- `int my_is_prime(int)` : Check if a number is prime.
- `void my_array_print(const int*, int)` : Print elements of an array.
- `double my_std_dev(const int*, int)` : Calculate the standard deviation of an array.

---

# Date_Lib

### Overview
A library for handling and manipulating date objects, including utilities for input/output and date arithmetic.

### Installation
1. Clone the repository.
2. Include `date.h` and `date.c` in your project.
3. Compile and link them with your main file.

### Example Usage
```c
#include "date.h"
#include <stdio.h>

int main() {
    Date today;
    set_date_today(&today);
    print_date(&today);

    Date randomDate;
    set_date_random(&randomDate);
    print_date(&randomDate);

    return 0;
}
```

### Some Functions
- `Date* set_date_today(Date*)` : Set a date object to the current date.
- `int date_diff(const Date*, const Date*)` : Calculate the difference in days between two dates.
- `Date* ndays_after(Date*, const Date*, int)` : Calculate the date after a specified number of days.

---

# Employee_Lib

### Overview
A library for creating, managing, and comparing employee records.

### Installation
1. Clone the repository.
2. Include `employee.h` and `employee.c` in your project.
3. Compile and link them with your main file.

### Example Usage
```c
#include "employee.h"
#include <stdio.h>

int main() {
    Employee emp;
    set_employee_random(&emp);
    print_employee(&emp);

    return 0;
}
```

### Some Functions
- `void print_employee(const Employee*)` : Print details of an employee.
- `Employee* set_employee_random(Employee*)` : Populate an employee record with random data.
- `int cmp_employee_byname(const Employee*, const Employee*)` : Compare employees by name.

---

# Employee_Linked_List_Lib

### Overview
A library for creating and managing linked lists of employee records.

### Installation
1. Clone the repository.
2. Include `employeelist.h` and `employeelist.c` in your project.
3. Compile and link them with your main file.

### Example Usage
```c
#include "employeelist.h"
#include <stdio.h>

int main() {
    ListHandle list = create_employee_list();

    Employee emp;
    set_employee_random(&emp);
    push_front(list, &emp);

    print_employee_list(list);

    destroy_list(list);
    return 0;
}
```

### Some Functions
- `ListHandle create_employee_list(void)` : Create a new employee linked list.
- `void push_front(ListHandle, const Employee*)` : Add an employee record to the front of the list.
- `void print_employee_list(ListHandle)` : Print all employee records in the list.

---

# Dynamic_Array_Lib

### Overview
A library for creating and managing dynamic arrays with customizable capacity.

### Installation
1. Clone the repository.
2. Include `vector.h` and `vector.c` in your project.
3. Compile and link them with your main file.

### Example Usage
```c
#include "vector.h"
#include <stdio.h>

int main() {
    HVector vec = create_vector_with_capacity(10);

    for (int i = 0; i < 10; ++i)
        push_back(vec, i);

    for (int i = 0; i < 10; ++i)
        printf("%d ", vec->mp[i]);

    destroy_vector(vec);
    return 0;
}
```

### Some Functions
- `HVector create_vector_with_capacity(size_t)` : Create a dynamic array with specified capacity.
- `int push_back(HVector, DATATYPE)` : Add an element to the end of the array.
- `int pop_back(HVector)` : Remove the last element from the array.

---

# Ctype_Lib

### Overview
A library for checking and handling character types based on a custom implementation of the C standard library's `<ctype.h>` functionality.

### Installation
1. Clone the repository.
2. Include `myctype.h` and `myctype.c` in your project.
3. Compile and link them with your main file.

### Example Usage
```c
#include "myctype.h"
#include <stdio.h>

int main() {
    char c = 'A';
    if (ISUPPER(c)) {
        printf("%c is an uppercase letter.\n", c);
    }

    return 0;
}
```

### Some Macros
- `ISUPPER(c)` : Check if a character is uppercase.
- `ISLOWER(c)` : Check if a character is lowercase.
- `ISDIGIT(c)` : Check if a character is a digit.

