#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "arrays.h"
#include "sorting.h"

#define TIME_REPETITIONS 5

// Run fn() TIME_REPETITIONS times and time how long it takes.
//
// Prints out:
//   fn_name: X.XX sec/TIME_REPETITIONS
void time_function(char *fn_name, void (*fn)(void));

// Time a sorting function called sort() which takes an array of ints A of
// length n.
//
// To provide this function you just give the name of the function, and this
// is interpreted as a "function pointer":
//   void (*sort)(int *A, int n)
//
// This function will time the function on `repeats` repititions of the
// function on randomly generated arrays of some given type and some given
// size.
//
// Also takes a label for the output as a parameter.
//
// This function will print out:
//   label {Repeats: X Type: Y Size: Z} = X.XX Seconds
void time_sorting_function(char *label, int array_size, int array_type,
                           int repeats, void (*sort)(int *, int));

// ============================ Functions to Time ============================

// Quicksort with specific partition function wrapper function.
// This is needed so that this quicksort function fits the format required
// by time_sorting_function(), i.e., just takes in two arguments
// (the array and the size).
void quicksort_first(int *array, int n);

void quicksort_random(int *array, int n);

// ============================== Main Function ==============================

int main(int argc, char **argv) {
  // Initialise the random number generator.
  srand(time(NULL));

  time_sorting_function(
    "Quicksort (Random)",
    5000,
    ARRAY_RANDOM,
    TIME_REPETITIONS,
    quicksort_random
  );

  time_sorting_function(
    "Quicksort (Random)",
    5000,
    ARRAY_SORTED,
    TIME_REPETITIONS,
    quicksort_random
  );

  time_sorting_function(
    "Quicksort (Random)",
    5000,
    ARRAY_REVERSED,
    TIME_REPETITIONS,
    quicksort_random
  );

  time_sorting_function(
    "Quicksort (Random)",
    5000,
    ARRAY_ALMOST,
    TIME_REPETITIONS,
    quicksort_random
  );

  time_sorting_function(
    "Quicksort (First)",
    5000,
    ARRAY_RANDOM,
    TIME_REPETITIONS,
    quicksort_first
  );

  global_partitions = 0;
  time_sorting_function(
    "Quicksort (First)",
    5000,
    ARRAY_SORTED,
    TIME_REPETITIONS,
    quicksort_first
  );
  printf("global_partitions = %d\n", global_partitions);

  global_partitions = 0;
  time_sorting_function(
    "Quicksort (First)",
    5000,
    ARRAY_REVERSED,
    TIME_REPETITIONS,
    quicksort_first
  );
  printf("global_partitions = %d\n", global_partitions);

  time_sorting_function(
    "Quicksort (First)",
    5000,
    ARRAY_ALMOST,
    TIME_REPETITIONS,
    quicksort_first
  );

  time_sorting_function(
    "Insertion Sort",
    5000,
    ARRAY_RANDOM,
    TIME_REPETITIONS,
    insertion_sort
  );

  time_sorting_function(
    "Insertion Sort",
    5000,
    ARRAY_SORTED,
    TIME_REPETITIONS,
    insertion_sort
  );

  time_sorting_function(
    "Insertion Sort",
    5000,
    ARRAY_REVERSED,
    TIME_REPETITIONS,
    insertion_sort
  );

  time_sorting_function(
    "Insertion Sort",
    5000,
    ARRAY_ALMOST,
    TIME_REPETITIONS,
    insertion_sort
  );

  return 0;
}

// Run fn() TIME_REPETITIONS times and time how long it takes.
//
// Prints out:
//   fn_name: X.XX sec/TIME_REPETITIONS
void time_function(char *fn_name, void (*fn)(void)) {
  clock_t start, end;
  double cpu_time_used;
  int i;

  // Run fn() TIME_REPETITIONS times and keep track of the clock() at each
  // point.
  start = clock();
  for (i = 0; i < TIME_REPETITIONS; i++) {
    fn();
  }
  end = clock();

  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

  printf("%s: %.2fs sec/%d\n", fn_name, cpu_time_used, TIME_REPETITIONS);
}

// Time a sorting function called sort() which takes an array of ints A of
// length n.
//
// To provide this function you just give the name of the function, and this
// is interpreted as a "function pointer":
//   void (*sort)(int *A, int n)
//
// This function will time the function on `repeats` repititions of the
// function on randomly generated arrays of some given type and some given
// size.
//
// Also takes a label for the output as a parameter.
//
// This function will print out:
//   label {Repeats: X Type: Y Size: Z} = X.XX Seconds
void time_sorting_function(char *label, int array_size, int array_type,
                           int repeats, void (*sort)(int *, int)) {
  clock_t start, end, total;
  double cpu_time_used;
  char *array_type_string;
  int *array;
  int i;

  // Actually time the function, by generating repeats different random arrays,
  // then timing only the sorting component.
  // total will hold the number of CPU clock ticks at the end and we will divide
  // this through by the number of CPU clock ticks per second.
  total = 0;
  for (i = 0; i < repeats; i++) {
    array = generate_array(array_size, array_type);

    start = clock();
    sort(array, array_size);
    end = clock();

    total += (end - start);

    free(array);
    array = NULL;
  }

  cpu_time_used = (double) total / CLOCKS_PER_SEC;

  // Get a nicer description of the array type than just the integer
  // representing it. Note that this should really be abstracted into its own
  // function.
  if (array_type == ARRAY_RANDOM) {
    array_type_string = "Random";
  } else if (array_type == ARRAY_SORTED) {
    array_type_string = "Sorted";
  } else if (array_type == ARRAY_REVERSED) {
    array_type_string = "Reversed";
  } else if (array_type == ARRAY_ALMOST) {
    array_type_string = "Almost Sorted";
  } else {
    fprintf(stderr, "Error: unknown array type.\n");
    exit(EXIT_FAILURE);
  }

  printf("%-18s {Repeats: %6d Type: %-14s Size: %6d} = %4.2f Seconds\n",
         label, repeats, array_type_string, array_size, cpu_time_used);
}

// Quicksort with specific partition function wrapper function.
// This is needed so that this quicksort function fits the format required
// by time_sorting_function(), i.e., just takes in two arguments
// (the array and the size).
void quicksort_first(int *array, int n) {
  quicksort(array, n, partition_first_pivot);
}

void quicksort_random(int *array, int n) {
  quicksort(array, n, partition_random_pivot);
}

// ====================== Add More Functions To Time ======================
