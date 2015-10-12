//
// Created by Massimo Biancalani on 08/10/15.
//
/* @BEGIN_OF_SOURCE_CODE */
#include <iostream>
#include <vector>
#include <algorithm>
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

size_t max(size_t i, size_t j) {
    if (i > j) {
        return i;
    } else {
        return j;
    }
}
size_t min(size_t i, size_t j) {
    if (i > j) {
        return j;
    } else {
        return i;
    }
}
void Minesweeper::adjacentMines(size_t i, size_t j) {
    table[i][j] = '*';
    size_t k0 = i == 0 ? 0 : i - 1;
    size_t f0 = j == 0 ? 0 : j - 1;
    for (size_t k = k0; k <= min(i+1, this->n - 1); ++k) {
        for (size_t f = f0; f <= min(j+1, this->m -1); ++f) {
            if (table[k][f] != '*') {
                table[k][f]++;
            }
        }
    }
}


void Minesweeper::addMine(size_t i, size_t j) {
    vector<unsigned short> mine;
    mine.push_back(i);
    mine.push_back(j);
    mines.push_back(mine);
}

void Minesweeper::compute() {
    for (vector<vector<unsigned short > >::iterator it = mines.begin(); it != mines.end() ; ++it) {
        vector<unsigned short>::iterator mine = it->begin();
        this->adjacentMines(*mine, *(mine +1) );
    }

}
void Minesweeper::addMine(size_t row, string line) {
    for (size_t i = 0; i < this->m; ++i) {
        if (line.at(i) == '*') {
            this->addMine(row, i);
        }
    }
}
/*
 *
 *
 * */
 int main(int argc, char **argv) {
    size_t i, j;
    unsigned int counter = 1;
    string line;

    while (true) {
        cin >> i >> j;
        if (i == 0 || j == 0) {
            break;
        }
        Minesweeper minesweeper(i, j);
        for (size_t k = 0; k < i; ++k) {
            cin >> line;
            minesweeper.addMine(k, line);
        }
        minesweeper.compute();
        if (counter != 1) {
            cout << endl;
        }
        cout << "Field #" << counter++ << ":" << endl;
        for (size_t l = 0; l < i; ++l) {
            for (size_t k = 0; k < j; ++k) {
                cout <<minesweeper.getTable()[l][k];
            }
            cout << endl;
        }
        //cout << endl;
    }
}


/* @END_OF_SOURCE_CODE */