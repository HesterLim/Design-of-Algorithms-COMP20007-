/* * * * * * *
 * Module for creating and manipulating singly-linked lists
 *
 * created for COMP20007 Design of Algorithms 2017
 * by Matt Farrugia <matt.farrugia@unimelb.edu.au>
 * updated in 2020 by Tobias Edwards <tobias.edwards@unimelb.ed.ua>
 */

// 'include guards': these lines (and #endif at the bottom) prevent this file
// from being included multiple times. multiple inclusion can cause errors on
// some compilers, especially if the included file contains struct definitions
// how it works: https://en.wikipedia.org/wiki/Include_guard
#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

// We can just change this typedef if we want a list of a different type.
// The obvious drawback here is that this is a global change, and thus each
// program can only have linked lists of the same type (e.g., we can't have one
// list of strings and another of integers).
// If we really need that behaviour we could use void pointers instead.
typedef int data_t;

typedef struct list List;

// create a new list and return its pointer
List *new_list();

// destroy a list and free its memory
void free_list(List *list);

// add an element to the front of a list
// this operation is O(1)
void list_add_start(List *list, data_t data);

// add an element to the back of a list
// this operation is O(1)
void list_add_end(List *list, data_t data);

// remove and return the front data element from a list
// this operation is O(1)
// error if the list is empty (so first ensure list_size() > 0)
data_t list_remove_start(List *list);

// remove and return the final data element in a list
// this operation is O(n), where n is the number of elements in the list
// error if the list is empty (so first ensure list_size() > 0)
data_t list_remove_end(List *list);

// return the number of elements contained in a list
int list_size(List *list);

// returns whether the list contains no elements (true) or some elements (false)
bool list_is_empty(List *list);

#endif
