#include <stdio.h>
#include "bit_ops.h"

/* Returns the Nth bit of X. Assumes 0 <= N <= 31. */
unsigned get_bit(unsigned x, unsigned n) {
    /* YOUR CODE HERE */
    return (x>>n)&1; /* UPDATE WITH THE CORRECT RETURN VALUE*/
}

/* Set the nth bit of the value of x to v. Assumes 0 <= N <= 31, and V is 0 or 1 */
void set_bit(unsigned *x, unsigned n, unsigned v) {
   *x = (*x) | v<<n;
   *x = ~(~(*x) | (get_bit((~v)<<n, n)<<n));
}

/* Flips the Nth bit in X. Assumes 0 <= N <= 31.*/
void flip_bit(unsigned *x, unsigned n) {
    unsigned bitatn = get_bit(*x, n);
    *x = (*x) ^ (bitatn<<n); //case if bit is one
    *x = (*x) | (get_bit(~bitatn<<n, n)<<n); //case if bit is zero

}