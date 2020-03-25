/*
 * Solution for Week 2 Question 3.
 *
 * Created for COMP20007 Design of Algorithms 2020
 * Solution written by Tobias Edwards <tobias.edwards@unimelb.edu.au>
 */

 #include <assert.h>
 #include <stdio.h>
 #include <stdlib.h>

#define INIT_CAPACITY 4
#define SCALING_FACTOR 2

int *read_class_array(int *n, int *capacity);

int main(int argc, char **argv) {
  int n = 0, i;
  int capacity = INIT_CAPACITY;
  int *class;

  printf("Enter the Student IDs for the class list, followed by ^D:\n");

  class = read_class_array(&n, &capacity);

  /* Print the student IDs back to the user. */
  printf("The IDs for the students in the class are:\n");
  for (i = 0; i < n - 1; i++) {
    printf("%d, ", class[i]);
  }
  printf("%d\n", class[n - 1]);

  /* Print statistics about the size o the class aray. */
  printf("The array contains %d items, and has a capacity of %d.\n",
    n, capacity);

  free(class);
  return 0;
}

/*
 * Read in Student IDs from the command line and update the size n and the
 * capacity. Returns the array of Student IDs.
 */
int *read_class_array(int *n, int *capacity) {
  int *class;
  int next_id;
  /* malloc the initial capacity for the class array. */
  class = (int *) malloc(*capacity * sizeof(int));
  assert(class);

  /* Keep reading in Student IDs until there is no input provided. */
  while (scanf("%d", &next_id) == 1) {
    if (*n == *capacity) {
      *capacity *= SCALING_FACTOR;
      /* Increase the amount of memory the class array has. */
      class = (int *) realloc(class, *capacity * sizeof(int));
      assert(class);
    }

    class[*n] = next_id;
    (*n)++;
  }

  return class;
}
