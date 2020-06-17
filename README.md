![alt text](https://www.geeksultd.com/wp-content/uploads/2020/06/Logo.png)

# C - Sorting Algorithms & Big O
This repo is a collaborative project by Usman Abdul Jabbar and Tim McMacken.

## Description
The purpose of this project is to learn about some of the most common algorithms as well as explore concepts of calculating the BigO notation.
Some of the most common algorithms covered by this repository are:
- Bubble sort
- Insertion sort
- Selection sort
- Quick sort

## Requirements
- Linux (Recommended)
- gcc(>= 4.8.4)
- Logic File, Header, Main Files

### Added Notes:
- All logic code that requires checking by the Holberton checker must be located at the root of the repository.
- All main files offered by the intranet are located in the main_files/ directory.
- All logic code must adhere to the Betty C style format.
- The use of standard library functions is strictly prohibited unless specified.
- All prototypes and structs must be located in the 'sort.h' file and must be guarded.
- All tasks given require an extra text file containing the big O notations of the time complexity of the Quick sort algorithm, with 1 notation per line:
  - in the best case
  - in the average case
  - in the worst case
- To test, move the main file associated with the logic file to the root of the repo folder and compile the code with the following code:
```
gcc -Wall -Wextra -Werror -pedantic #-main.c #-logic_file.c [ print_array.c || print_list.c ] -o output
./output
```

## Files
Since standardized libraries are forbidden, all tasks must make use of either print_array.c or print_list.c. Tasks that make use of linked lists must use the following struct.
#### print_array.c
```
#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}
```

#### print_list.c
```
#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
    int i;

    i = 0;
    while (list)
    {
        if (i > 0)
            printf(", ");
        printf("%d", list->n);
        ++i;
        list = list->next;
    }
    printf("\n");
}
```

#### listint_s struct -> sort.h
```
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;
```

