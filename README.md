# Permcomb

A pure C library for the iterative lexicographical enumeration of k-permutations and k-combinations, with and without replacement. 

Permcomb is small, memory efficient and provides a consistent interface for all included functions.


# Code Example

Enumerate all the k-combinations of the first [0 .. n-1] integers, for n=3 and k=2:

```c
   int n = 3;
   int k = 2;
   int comb[k];

   /* Get the total number of possible combinations */
   int ntot = number_comb( n, k );
      
   /* Store in comb[0..k-1] the first k-combination of n elements */
   first_comb( n, k, comb );

   /* Iterate through all possible k-combinations of n elements */
   do {
      /* comb[0..k-1] will hold the current combination */
   } while( next_comb( n, k, comb ) );

```

# API

Permcomb provides four sets of functions:
   - For combinations: `first_comb`, `next_comb` and `number_comb`
   - For combinations with replacement: `first_comb_wr`, `next_comb_wr` and `number_comb_wr`
   - For permutations: `first_perm`, `next_perm` and `number_perm`
   - For permutations with replacement: `first_perm_wr`, `next_perm_wr` and `number_perm_wr`

The usage is similar for all four cases:
   - To calculate the number of elements in the sequence, use the `number_*( int n, int k )` functions.
   - To bootstrap the iteration of the sequence, use the `first_*( int n, int k, int a[] )` functions.
   - To iterate over the sequence, call repeatedly the `next_*( int n, int k, int a[] )` functions until they return 0, in which
   case the sequence is over.

At each step the current item in the sequence will be stored in the array `a`, which should be an `int[]` array
of at least of length `k` for combinations and permutations with replacement, and at least of length `n` for 
permutations.

## Installation

Permcomb can be built into a static or dynamic library using cmake.

For example, to build and install a dynamic version of permcomb in /usr/local:

```bash
$ mkdir bld && cd bld && cmake -DCMAKE_INSTALL_PREFIX=/usr/local ../ && make && make install && cd ..
``` 

# Simplified BSD License
Copyright (c) 2015, Daniel Pena 

