//
// Created by Massimo Biancalani on 21/05/16.
//
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
/*
 * byte representation of digits
 *     - 0
 *   |1  | 2
 *     _ 3
 *   |4  | 5
 *     _ 6
 *
 */
const unsigned  char  representation []  = {0x77, 0x24, 0x5D, 0x6D, 0x2E, 0x6B, 0x7B, 0x25, 0x7F, 0x6F};
void show_pair(const string& digits, unsigned int s, unsigned exadecimal_index) {
    for (int k = 0; k < digits.length(); ++k) {
        if (k!= 0) {
            cout << ' ';
        }
        unsigned int digit = atoi(digits.substr(k, 1).c_str());

        cout << ' ';
        for (int i = 0; i < s; ++i) {
            if (representation[digit] & exadecimal_index) {
                cout << '-';
            } else {
                cout << ' ';
            }
        }
        cout << ' ';
    }
    cout << endl;
}
void show_odd(const string& digits, unsigned int s, unsigned exadecimal_index) {

    for (int i = 0; i < s; ++i) {
        for (int k = 0; k < digits.length(); ++k) {
            if (k != 0) {
                cout << ' ';
            }
            unsigned int digit = atoi(digits.substr(k, 1).c_str());
            if (representation[digit] & exadecimal_index) {
                cout << '|';
            } else {
                cout << ' ';
            }
            for (int j = 0; j < s; ++j) {
                cout << ' ';
            }
            if (representation[digit] & exadecimal_index * 2) {
                cout << '|';
            } else {
                cout << ' ';
            }
        }
        cout << endl;
    }
}
void show (const string& digits, unsigned int s) {
    // first row
    show_pair(digits, s, 0x01);
    // second row
    show_odd(digits, s, 0x02);
    // third row
    show_pair(digits, s, 0x08);
    // fourth row
    show_odd(digits, s, 0x10);
    // fifth row
    show_pair(digits, s, 0x40);

}

void display() {
    unsigned int s;
    string digits;
    while ( !(cin >> s) || s != 0) {
        cin >> digits;
        show(digits, s);
        cout << endl;
    }
}

int main(int argc, char **argv) {
    display();
    return 0;
}
