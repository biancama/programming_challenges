//
// Created by Massimo Biancalani on 04/10/15.
//

#include <string>
#include <iostream>

using namespace std;

unsigned short Cycle_Length(unsigned long n);
unsigned short Max_Cycle_Length(unsigned long i, unsigned long j);

#define SIZE 1000001

static unsigned short table[SIZE];


unsigned short  Cycle_Length(unsigned long n) {
    if(n < SIZE && table[n])
        return table[n];
    if(n & 1) { /* if n is odd */
        if( n < SIZE) {
            /* calc two steps at one */
            table[n] = 2 + Cycle_Length( (3*n+1) >> 1 );
            return table[n];
        } else {
            return 2 + Cycle_Length( (3*n+1) >> 1 );
        }
    } else {
        if( n < SIZE) {
            table[n] = 1 + Cycle_Length( n >> 1 ); /* n/2 */
            return table[n];
        } else {
            return 1 + Cycle_Length( n >> 1 );
        }
    }
}
unsigned short Max_Cycle_Length(unsigned long i, unsigned long j) {
    unsigned short max = 0, new_max;
    for (unsigned long k = i ; k <= j ; ++k) {
        new_max = Cycle_Length(k);
        if (new_max > max) {
            max = new_max;
        }
    }
    return max;
}
int main() {
    table[1] = 1;
    unsigned long num1, num2;
    while (cin>>num1>>num2) {
        unsigned long i = num1;
        unsigned long j = num2;
        if (i > j) {
            swap(i, j);
        }
        unsigned short max_cycle = Max_Cycle_Length(i, j);
        cout << num1  << ' ' << num2 << ' ' << max_cycle << endl;
    }
    return 0;
}