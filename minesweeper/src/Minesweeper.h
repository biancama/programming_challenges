//
// Created by Massimo Biancalani on 08/10/15.
//

#ifndef MINESWEEPER_MINESWEEPER_H
#define MINESWEEPER_MINESWEEPER_H

#import <vector>
#import <algorithm>
#include <string>

using namespace std;
class Minesweeper {

private:
    size_t n, m;
    char **table;
    vector<vector<unsigned short > > mines;
    void adjacentMines(size_t i, size_t j);
    void addMine(size_t i, size_t j);
public :

    Minesweeper(unsigned short n, unsigned short m) : n(n), m(m) {
        table = new char *[n];
        for (size_t i = 0; i < n; ++i) {
            table[i] = new char[m];
            fill_n(table[i], m, '0');
        }
    }


    virtual ~Minesweeper() {
        for (size_t i = 0; i < n; ++i) {
            delete table[i];
        }
        delete table;
    }

    void addMine(size_t row, string line);

    void compute();

    char **getTable() const {
        return table;
    }

};


#endif //MINESWEEPER_MINESWEEPER_H
