/*
 * Main function for a program to test the linked list implementation.
 *
 * Created for Design of Algorithms 2020
 * by Tobias Edwards <tobias.edwards@unimelb.edu.au>
 */

#include <stdio.h>

#include "list.h"

int main(int argc, char **argv) {
  int x;
  List *list = new_list();

  /*
   * This program asks the user to enter some number of integers, followed
   * by an EOF signal (^D on Mac, ^Z on Windows).
   *
   * These integers will be added to the end of the list, then removed from
   * the start of the list and printed back to the user.
   */

  printf("Enter numbers, then ^D (Mac) or ^Z (Windows): ");
  while (scanf("%d", &x) == 1) {
    list_add_end(list, x);
  }

  printf("The numbers were:");
  while (list_size(list) > 0) {
    printf(" %d", list_remove_start(list));
  }
  printf("\n");

  free_list(list);
  list = NULL;

  return 0;
}
