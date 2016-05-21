//
// Created by Massimo Biancalani on 23/04/16.
//
#include <iostream>
#include <string>
#include <math.h>
#include <sstream>
#include <stdlib.h>
using namespace std;
unsigned int get_cents(const string amount);
unsigned int get_average(const unsigned int* amounts, unsigned int number_of_students);
void trips();
template<typename T>
void pad(basic_string<T>& s,
         typename basic_string<T>::size_type n, T c) {
    if (n > s.length())
        s.insert(0, n - s.length(), c);
}


unsigned int round_div(unsigned int dividend, unsigned int divisor) {
    return (dividend + (divisor >> 1)) / divisor;
}
unsigned int get_cents(const string amount) {
    string::size_type indexOfDecimalPoint = amount.find('.');
    unsigned int integer_part = atoi(amount.substr(0, indexOfDecimalPoint + 1 ).c_str());
    unsigned int decimal_part = atoi(amount.substr(indexOfDecimalPoint + 1,  2 ).c_str());
    return integer_part * 100 + decimal_part;
}

unsigned int get_average(const unsigned int* amounts, unsigned int number_of_students) {
    unsigned int total_amount = 0;
    for (unsigned int i = 0; i < number_of_students ; ++i) {
        total_amount += amounts[i];
    }
    return round_div(total_amount, number_of_students);
}

void trips() {
    unsigned int n;
    string amount_str;
    unsigned int amounts[1000];
    cin>>n;
    while (n != 0) {
        for (unsigned int i = 0; i < n; i++) {
            cin >> amount_str;
            amounts[i] = get_cents(amount_str);
        }
        unsigned int average = get_average(amounts, n);
        unsigned int refund = 0;
        unsigned int debit = 0;

        for (unsigned int i = 0; i < n; i++) {
            if (amounts[i] > average) {
                refund += amounts[i] - average;
            } else {
                debit += average - amounts[i] ;
            }
        }
        ostringstream convert;
        unsigned int equalizer = refund < debit ? refund: debit ;
        convert << (equalizer % 100);
        string decimal = convert.str();
        pad(decimal, 2, '0');
        cout << "$" << equalizer/100 << "." << decimal << endl;
        cin>>n;
    }

}


int main(int argc, char **argv) {
    trips();
    return 0;
}
