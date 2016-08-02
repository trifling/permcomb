/* 
 * Permcomb 
 * Daniel Pena, (c) 2015
 * License: Simplified BSD
 * 
 */

#include <stdio.h>
#include <permcomb.h>

void print( int n, int a[] ) {
   for( int i=0; i<n; i++ ) {
      printf(" %d ", a[i] );
   }
   printf("\n");
}
 
int main() {

   int n = 4;
   int kmax = 4;
   int ntot;
   int comb[kmax];
   int perm[kmax];

   for( int k=1; k<=kmax; k++ ) { 
      ntot = number_comb(n,k);
      printf("\n\n%d-combinations from %d elements, total: %d\n", k, n, ntot );
      
      first_comb( n, k, comb );
      do {
         print( k, comb );
      } while( next_comb( n, k, comb ) );
   }

   for( int k=1; k<=kmax; k++ ) { 
      ntot = number_comb_wr(n,k);
      printf("\n\n%d-combinations from %d elements with replacement, total: %d\n", k, n, ntot );

      first_comb_wr( n, k, comb );
      do {
         print( k, comb );
      } while( next_comb_wr( n, k, comb ) );
   }

   for( int k=1; k<=kmax; k++ ) { 
      ntot = number_perm(n,k);
      printf("\n\n%d-permutation from %d elements, total: %d\n", k, n, ntot );

      first_perm( n, k, perm );
      do {
         print( k, perm );
      } while( next_perm( n, k, perm ) );
      
   }

   for( int k=1; k<=kmax; k++ ) { 
      ntot = number_perm_wr(n,k);
      printf("\n\n%d-permutation from %d elements with replacement, total: %d\n", k, n, ntot );

      first_perm_wr( n, k, perm );
      do {
         print( k, perm );
      } while( next_perm_wr( n, k, perm ) ); 
   }

   return 0;
}
