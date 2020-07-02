/*
 * Workshop 10 Solutions: Baked Beans Bundles.
 * COMP20007 Design of Algorithms
 * Semester 1 2019
 *
 * Solutions by Tobias Edwards <tobias.edwards@unimelb.edu.au>
 *
 * NOTE: Please read the solutions to Workshop 10 Question 5, which explains
 * in detail the algorithm which this program implements.
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* Reads in n and an array of n prices (note that the price for a bundle of
 * size k is in index k - 1). */
void read_input(int **prices, int *n);

int main(int argc, char **argv) {
  int n, i, k, j;
  int max_price, max_k;
  int *prices;
  int *P, *B;

  /* After this function call n will be the number of prices to be input,
   * and prices will point to an array with n prices.
   * Note that prices must be manually freed. */
  read_input(&prices, &n);

  /* Initialise P and B to hold n + 1 zeroes (using calloc()).
   * Note that calloc() is just like malloc, except it initialises the whole
   * array to 0. */
  P = calloc(n + 1, sizeof(int));
  B = calloc(n + 1, sizeof(int));
  assert(P != NULL && B != NULL);

  /* Compute the maximum price we can get for i items, for i = 1..n */
  for (i = 1; i <= n; i++) {
    max_price = 0;
    max_k = 0;

    /* Check each possible value of k we could use (note this is up to O(n)) */
    for (k = 1; k <= i; k++) {
      if ((prices[k - 1] + P[i - k]) > max_price) {
        max_price = prices[k - 1] + P[i - k];
        max_k = k;
      }
    }

    P[i] = max_price;
    /* B holds the k we chose so that we can reconstruct the solution */
    B[i] = max_k;
  }

  /* Output the maximum price we can get. */
  printf("%d\n", P[n]);

  /* Back-trace the elements in B to determine which bundles were sold. */
  j = n;
  while (B[j] > 0) {
    printf("%d\n", B[j]);
    j = j - B[j];
  }

  /* Free the memory after we're done with these arrays! */
  free(prices);
  free(P);
  free(B);

  return 0;
}

/* Reads in n and an array of n prices (note that the price for a bundle of
 * size k is in index k - 1). */
void read_input(int **prices, int *n) {
  int i;

  scanf("%d", n);

  /* calloc(n, sizeof(int)) allocates (and zeroes) enough memory for n ints */
  *prices = calloc(*n, sizeof(int));
  assert(prices != NULL);

  /* read in the n prices. */
  for (i = 0; i < *n; i++) {
    scanf("%d", *prices + i);
  }
}
