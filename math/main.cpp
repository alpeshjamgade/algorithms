/**************************
 * Sieve of Erastosthenes * (simple, slow version)
 **************************
 * Given a bool array, fills it in such a way that
 * prime[i] is true iff i is prime. This variant
 * requires about 2NlogN operations (under 1 second
 * for N = 100M).
 * #include <string.h>
 * #include <math.h>
 **/
bool isPrime[];
void sieve(T N )
{
    memset( prime, -1, N * sizeof( isPrime[0] ) );
    isPrime[0] = isPrime[1] = false;
    T sqrtN = (T)sqrt((double)N);
    for( T i = 2; i <= sqrtN; i++ )
      if(isPrime[i] && i*i <= N){
        for( T j = i * i; j < N; j += i ){
            isPrime[j] = false;
        }
    }
}

/**************************
 * Sieve of Erastosthenes * (fast, memory efficient version)
 **************************
 * Does some magic, after which gP(n) is non-zero iff n is
 * prime. N is the value of the largest prime you will need.
 * Requires N / 16 bytes of memory.
 * WARNING! Only works for odd numbers; deal with even numbers 
 * yourself!
 * If that is unacceptable, add "n==2||(n&1)&&" after the
 * first bracket in the gP() macro.
 * #include <string.h>
 * #include <math.h>
 **/
#define N 51000000
unsigned T prime[N / 64];
#define gP(n) (prime[n>>6]&(1<<((n>>1)&31)))
#define rP(n) (prime[n>>6]&=~(1<<((n>>1)&31)))
void sieve()
{
    memset( prime, -1, sizeof( prime ) );

    unsigned T i;
    unsigned T sqrtN = ( unsigned T )sqrt( ( double )N ) + 1;
    for( i = 3; i < sqrtN; i += 2 ) if( gP( i ) )
    {
        unsigned T i2 = i + i;
        for( unsigned T j = i * i; j < N; j += i2 ){
            rP( j );
        }
    }
}
