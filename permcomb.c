/* 
 * Permcomb 
 * Daniel Pena, (c) 2015
 * License: Simplified BSD
 * 
 */

#include "permcomb.h"

extern int ipow(int base, int exp);
extern int binom( int n, int k );

extern int number_comb( int n, int k );
extern int first_comb( int n, int k, int comb[] );
extern int next_comb( int n, int k, int comb[] );

extern int number_comb_wr( int n, int k );
extern int first_comb_wr( int n, int k, int comb[] );
extern int next_comb_wr( int n, int k, int comb[] );

extern void perm_swap( int a[], int i, int j );
extern void perm_reverse( int a[], int i, int j );
extern int number_perm( int n, int k );
extern int first_perm( int n, int k, int perm[] );
extern int next_all_perm( int n, int perm[] );
extern int next_perm( int n, int k, int perm[] );

extern int number_perm_wr( int n, int k );
extern int first_perm_wr( int n, int k, int perm[] );
extern int next_perm_wr( int n, int k, int perm[] );

