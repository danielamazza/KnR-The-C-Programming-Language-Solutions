/*
 * Answer to Exercise 2-6, page 49
 *
 * Write a function setbits(x,p,n,y) that returns x with the n bits that
 * begin at position p set to the rightmost n bits of y, leaving the
 * other bits unchanged.
 */

#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, int y);

main()
{
    printf("%u\n", setbits(170, 4, 3, 7));
    return 0;
}

/* getbits:  place n rightmost bits from position p at position y */
unsigned setbits(unsigned x, int p, int n, int y)
{
    int i, mask, j;
    /* The rightmost n bits of y. */
    i = (x >> (y+1-n)) & ~(~0 << n);
    /* A mask with zeros at the rightmost n bits of p. */
    mask = ~((1 << n)-1 << (p+1-n));
    /* Make rightmost n bits of p zero ... */
    j = mask & x;
    /* ... and replace them with the rightmost n bits of y. */
    return j | i << (p+1-n);
}

