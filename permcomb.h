/* 
 * Permcomb 
 * Daniel Pena, (c) 2015
 * License: Simplified BSD
 * 
 */

#ifndef PERMCOMB_H
#define PERMCOMB_H

/*
 * Integer exponentiation
 */
inline int ipow( int b, int e ) {
    int r = 1;
    while( e ) {
        if( e & 1 )
            r *= b;
        e >>= 1;
        b *= b;
    }
    return r;
}

/* 
 * Binomial coefficient n over k 
 */
inline int binom( int n, int k ) {
   int l[n+1];
   l[0] = 1;
   for( int i=1; i<=n; i++ ) {
      l[i] = 1;
      for( int j=i-1; j>0; j-- ) {
         l[j] += l[j-1];
      }
   } 
   return l[k];
}

/* 
 * Calculates the number of k-combinations of n elements.
 *
 */
inline int number_comb( int n, int k ) {
   return binom( n, k );
}

/* 
 * Initializes the enumeration of k-combinations of n elements.
 *
 * The length of idx[] should be at least n+1 !
 */
inline int first_comb( int n, int k, int comb[] ) {
   for( int i=0; i<k; i++ )
      comb[i] = i; 
   return 0;
}

/* 
 * Advances to the next combination in the enumeration of  
 * k-combinations of n elements.
 *
 * Returns 0 if the enumeration is finished, one otherwise.
 *
 * Example: 2-combinations of 4 elements 
 * 
 * int n = 4;
 * int k = 2;
 * int comb[k];
 * 
 * first_comb( n, k, comb );
 * while( next_comb(n,k,comb) ) {
 *    for( int i=0; i<n; i++ ) 
 *       printf(" %d ", comb[i] );
 *    printf("\n");
 * }
 *
 * It would produce this sequence:
 * 0   1    
 * 0   2 
 * 0   3 
 * 1   2 
 * 1   3 
 * 2   3 
 *
 */
inline int next_comb( int n, int k, int comb[] ) {
   for( int i=k-1; i>=0; i-- ) {
      if( comb[i] < n - k + i ) {
         comb[i]++;
         for( int j=i; j<k-1; j++ ) 
            comb[j+1] = comb[j] + 1;
         return 1;
      }
   }
   return 0;
}


/* 
 * Calculates the number of  
 * k-combinations with replacement of n elements.
 *
 */
inline int number_comb_wr( int n, int k ) {
   return binom( n+k-1, k );
}

/* 
 * Initializes the enumeration of 
 * k-combinations with replacement of n elements.
 *
 * The length of comb[] should be at least k 
 */
inline int first_comb_wr( int n, int k, int comb[] ) {
   for( int i=0; i<k; i++ )
      comb[i] = 0; 
   return 0;
}


/* 
 * Advances to the next combination in the enumeration of  
 * k-combinations with replacement of n elements.
 *
 * Returns 0 if the enumeration is finished, one otherwise.
 *
 * Example: 3-combinations of 2 elements 
 * 
 * int n = 2;
 * int k = 3;
 * int comb[k];
 * 
 * first_comb_wr( n, k, comb );
 * while( next_comb_wr(n,k,comb) ) {
 *    for( int i=0; i<n; i++ ) 
 *       printf(" %d ", comb[i] );
 *    printf("\n");
 * }
 *
 * It would produce this sequence:
 * 1   1   1
 * 1   1   2
 * 1   2   2
 * 2   2   2
 *
 */
inline int next_comb_wr( int n, int k, int comb[] ) {
   for( int i=k-1; i>=0; i-- ) {
      if( comb[i] < n-1 ) {
         comb[i]++;
         return 1;
      } else {
         if( i > 0 ) {
            for( int j=i; j<=k; j++ )
               comb[j] = comb[i-1] + 1;
         }
      }
   }
   return 0;
}

/* 
 * Calculates the number of k-permutations n elements.
 *
 */
inline int number_perm( int n, int k ) {
   int m = n;
   for( int i=1; i<k; i++ ) {
      n--;
      m *= n;
   }
   return m;
}
inline void perm_swap( int a[], int i, int j) {
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

inline void perm_reverse( int a[], int l, int r ) {
   for( int i=l, j=r; i<j; i++, j-- ) {
      perm_swap( a, i, j );
   }
}

/* 
 * Initializes the enumeration of k-permutatuions of n elements.
 *
 * The length of perm[] should be at least n 
 */
inline int first_perm( int n, int k, int perm[] ) {
   for( int i=0; i<n; i++ ) 
      perm[i] = i;
   return 0;
}

/*
 * Advances to the next permutation in the enumeration of all the permutations of n elements.
 */
inline int next_all_perm( int n, int perm[] ) {
   int i = n -2 ;
   while( i>=0 && perm[i] > perm[i+1] ) 
      i--;

   if (i<0) {
      perm_reverse( perm, 0, n-1 ); 
      return 0;
   }

   int l = n-1;
   while( l>i && perm[i] > perm[l] ) 
      l--;

   perm_swap( perm, i, l );
   perm_reverse( perm, i+1, n-1 );

   return 1;
}

/* 
 * Advances to the next permutation in the enumeration of  
 * k-permutations of n elements.
 *
 * Returns 0 if the enumeration is finished, one otherwise.
 *
 * Example: 2-permutations of 3 elements 
 * 
 * int n = 3;
 * int k = 2;
 * int perm[n];
 * 
 * first_perm( n, k, perm );
 * while( next_perm(n,k,perm) ) {
 *    for( int i=0; i<n; i++ ) 
 *       printf(" %d ", perm[i] );
 *    printf("\n");
 * }
 *
 * It would produce this sequence:
 * 0   1    
 * 0   2    
 * 1   0    
 * 1   2    
 * 2   0
 * 2   1
 *
 */
inline int next_perm( int n, int k, int perm[] ) {
   int r = next_all_perm( k, perm );
   if( r==0 )  
      return next_comb( n, k, perm );
   return r;
}

/* 
 * Calculates the number of k-permutations with replacement of n elements.
 *
 */
inline int number_perm_wr( int n, int k ) {
   return ipow( n, k );
}

inline int first_perm_wr( int n, int k, int perm[] ) {
   for( int i=0; i<k-1; i++ ) 
      perm[i] = 0;
   return 0;
}

inline int next_perm_wr( int n, int k, int perm[] ) {
   for( int i=k-1; i>=0; i-- ) {
      if( perm[i] < n-1 ) {
         perm[i]++;
         return 1;
      } else {
         perm[i] = 0;
      }
   }
   return 0;
}

#endif

