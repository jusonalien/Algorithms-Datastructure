#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
using namespace std;

#define inf 0x3f3f3f3f
#define eps 1e-7
#define LL long long
#define ULL unsigned long long
#define MP make_pair
#define pb push_back
#define ls i << 1
#define rs ls | 1
#define md ( ( ll[i] + rr[i] ) >> 1 )
#define mxn 2000

char ip[mxn];
struct bign {
    int len, dig[mxn];
    bign() {
        len = 0, dig[0] = 0;
    }
    bool input() {
        if( scanf( "%s", ip ) == EOF )
            return 0;
        if( strcmp( ip, "0" ) == 0 ) {
            len = 0, dig[0] = 0;
            return 1;
        }
        int n = strlen( ip );
        for( int i = 0; i < n; ++i ) {
            dig[i] = ip[n-i-1] - '0';
        }
        len = n - 1;
        return 1;
    }
    void output() {
        for( int i = len; i >= 0; --i )
            printf( "%d", dig[i] );
    }
    bign operator + ( const bign &b ) const {
        int i, carry;
        bign c;
        for( i = carry = 0; i <= len || i <= b.len || carry; ++i ) {
            if( i <= len )
                carry += dig[i];
            if( i <= b.len )
                carry += b.dig[i];
            c.dig[i] = carry % 10;
            carry /= 10;
        }
        c.len = i - 1;
        return c;
    }
    bign operator + ( const int &k ) const {
        int i, b = k;
        bign c;
        for( i = 0; i <= len || b; ++i ) {
            if( i <= len )
                b += dig[i];
            c.dig[i] = b % 10;
            b /= 10;
        }
        c.len = i - 1;
        return c;
    }
    bign operator * ( const int &k ) const {
        int i, carry, b = k;
        bign c;
        for( i = carry = 0; i <= len || carry; ++i ) {
            if( i <= len )
                carry += b * dig[i];
            c.dig[i] = carry % 10;
            carry /= 10;
        }
        i--;
        while( i && !c.dig[i] ) 
            --i;
        c.len = i;
        return c;
    }
    bign operator * ( const bign &b ) const {
        int i, j, carry;
        bign c;
        for( i = len + b.len + 1; i >= 0; -- i )
            c.dig[i] = 0;
        for( i = 0; i <= len; ++i ) {
            carry = 0;
            for( j = 0; j <= b.len || carry; ++j ) {
                carry += c.dig[i+j];
                if( j <= b.len )
                    carry += dig[i] * b.dig[j];
                c.dig[i+j] = carry % 10;
                carry /= 10;
            }
        }
        i = len + b.len + 1;
        while( i && !c.dig[i] )
            --i;
        c.len = i;
        return c;
    }
};
void div( bign a, int b, bign &c, int &d ) {
    int i;
    for( i = a.len, d = 0; i >= 0; --i ) {
        d = d * 10 + a.dig[i];
        c.dig[i] = d / b;
        d = d % b;
    }
    i = a.len;
    while( i && !c.dig[i] )
        --i;
    c.len = i;
}
bign a, b;

int main() {
    int cas, kk = 1;
    scanf( "%d", &cas );
    while( cas-- ) {
        a.input(), b.input();
        printf( "Case %d:\n", kk ++ );
        a.output();
        printf( " + " );
        b.output();
        printf( " = " );
        ( a + b ).output();
        printf( "\n" );
        if( cas )
            printf( "\n" );
    }
    return 0;
}