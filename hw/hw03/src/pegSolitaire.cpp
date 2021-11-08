#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "pegSolitaire.h"

using namespace std;

/***********************************************************************************
 *                                     Cell
 **********************************************************************************/

inline PegSolitaire::Cell::Cell (const string & cellCol, int cellRow, CellValue cellValue) {
    setCol(cellCol);
    setRow(cellRow); 
    setValue(cellValue); 
}

inline PegSolitaire::Cell::Cell () {
    //! NOT IMPLEMENTED YET: No Parameter Constructor
}

/* =============================== Getters ============================== */

inline void PegSolitaire::Cell::getCell (string & cellCol, int & cellRow, CellValue & cellValue) const {
    cellCol = col; 
    cellRow = row; 
    cellValue = value; 
}

inline PegSolitaire::CellValue PegSolitaire::Cell::getValue () const {
    return value;
}

inline string PegSolitaire::Cell::getCol () const {
    return col;
}

inline int PegSolitaire::Cell::getRow () const {
    return row;
}


/* =============================== Setters ============================== */

inline void PegSolitaire::Cell::setCell (string cellCol, int cellRow, CellValue cellValue) {
    setCol(cellCol);
    setRow(cellRow); 
    setValue(cellValue); 
}

inline void PegSolitaire::Cell::setValue (CellValue cellValue) {
    if (cellValue == CellValue::peg || cellValue == CellValue::empty || cellValue == CellValue::out)
        value = cellValue;
    else {
        cerr << "(!) Invalid cell value: " << static_cast<char>(cellValue) << endl;
        exit(1);
    }
}

inline void PegSolitaire::Cell::setCol (string cellCol) {
    if (1)  
    //! validate the string col
        col = cellCol;
    else {
        cerr << "(!) Invalid cell coloumn: " << cellCol << endl;
        exit(1);
    }
}

inline void PegSolitaire::Cell::setRow (int cellRow) {
    if (cellRow >= 0)
        row = cellRow;
    else {
        cerr << "(!) Invalid cell row: " << cellRow << endl;
        exit(1);
    }
}

/* =============================== Utility ============================== */

int PegSolitaire::Cell::convertCellCol (const string & col) const {
    return col[0] - 'A' + (stoi(&col[1]) - 1) * 26;
}

string PegSolitaire::Cell::convertCellCol (int col) const {
    const int ENG_LETTER_NUM = 26;    // The number of letter in english alphabet
    string r;

    while (col > 0) {
        r.push_back('A' + col % ENG_LETTER_NUM);
        col /= ENG_LETTER_NUM;
    }
    
    int s = 0, e = r.size() - 1;

    // Reverse the string r
    while (s != e) {
        int tmp = r[s];
        r[s] = r[e];
        r[e] = tmp;
        ++s, --e;
    }
    
    return r;
}

/***********************************************************************************
 *                                  PegSolitaire
 **********************************************************************************/

inline PegSolitaire::PegSolitaire (const char * fileName) {
    load(fileName); // Load cheks if the given board size is proper
}

inline PegSolitaire::PegSolitaire (int boardType) {
    setBoard(boardType);
}

inline PegSolitaire::PegSolitaire () {
    //! NOT IMPLEMENTED YET: No Parameter Constructor
}


void PegSolitaire::displayBoard () const {
    const int ENG_LETTER_NUM = 26;                  // The number of letter in english alphabet
    int margin = boardSize % ENG_LETTER_NUM  + 1;   // Define the space between coloumns

    // Print the coloumns
    for (int i = 0; i < boardSize; ++i) {
        cout << board[i][0].getCol();
        // printn(' ', margin);
    }

    for (int i = 0; i < boardSize; ++i) {
        cout << 1 + i << '\t';
        for (int j = 0; j < boardSize; ++j) {
            cout << static_cast<char>(board[i][j].getValue());
            // printn(' ', margin);
        }
        cout << endl;
    }
}


void PegSolitaire::load (const char * fileName) {
    //! NOT IMPLEMENTED YET   
}

void PegSolitaire::save (const char * fileName) const {
    //! NOT IMPLEMENTED YET   
}

void PegSolitaire::setBoard (int boardType) {
    switch (boardType) {
        case 1:
            setBoardFrench();         break;
        case 2:
            setBoardGerman();         break;
        case 3:
            setBoardAsymmetrical();   break;
        case 4:
            setBoardEnglish();        break;
        case 5:
            setBoardDiamond();        break;
        case 6:
            setBoardTriangular();     break;
        default:
            cerr << "(!) Undefined board type. Board was unable to create correctly\n";
            exit(1);
    }
}

void PegSolitaire::initBoard (int row, int col, PegSolitaire::CellValue initValue) {
    board.resize(row);
    for (int i = 0; i < row; ++i) {
        string str_col("@");    // initialize from 'A' - 1

        board[i].resize(col);
        for (int j = 0; j < col; ++j) {
            ++str_col[str_col.size() - 1];

            /* Be sure str_col does not go outside from the alphabet
               A B C ... AA AB AC ... AAA AAB AAC ...   */
            for (int k = str_col.size() - 1; str_col[k] > 'Z'; --k) {
                str_col[k] = 'A';
                // Add new digit
                if (k == 0) 
                    str_col.push_back('A');
                else
                    ++str_col[k - 1];
            }

            board[i][j].setCol(str_col);
            board[i][j].setRow(i + 1); 
            board[i][j].setValue(initValue);
        }
    }
}

void PegSolitaire::setBoardFrench () {
    initBoard(7, 7, CellValue::peg);
    
    for (int i = 0, n = 2; i < 2; ++i, --n)
        for (int j = 0; j < n; ++j)
            board[i][j].setValue(CellValue::out);

    for (int i = 0, n = 5; i < 2; ++i, ++n)
        for (int j = n; j < 7; ++j)
            board[i][j].setValue(CellValue::out);

    for (int i = 5, n = 1; i < 7; ++i, ++n)
        for (int j = 0; j < n; ++j)
            board[i][j].setValue(CellValue::out);

    for (int i = 5, n = 6; i < 7; ++i, --n)
        for (int j = n; j < 7; ++j)
            board[i][j].setValue(CellValue::out);
    
    board[2][3].setValue(CellValue::empty);
}   

void PegSolitaire::setBoardGerman () {
    initBoard(9, 9, CellValue::peg);

    fillBoard(0, 3, 0, 3, CellValue::out);
    fillBoard(0, 3, 6, 9, CellValue::out);
    fillBoard(6, 9, 0, 3, CellValue::out);
    fillBoard(6, 9, 6, 9, CellValue::out);
    board[4][4].setValue(CellValue::empty);
}   

void PegSolitaire::setBoardAsymmetrical () {
    initBoard(8, 8, CellValue::peg);

    fillBoard(0, 3, 0, 2, CellValue::out);
    fillBoard(0, 3, 5, 8, CellValue::out);
    fillBoard(6, 8, 0, 2, CellValue::out);
    fillBoard(6, 8, 5, 8, CellValue::out);
    board[4][3].setValue(CellValue::empty);
}  

void PegSolitaire::setBoardEnglish () {
    initBoard(7, 7, CellValue::peg);

    fillBoard(0, 2, 0, 2, CellValue::out);
    fillBoard(0, 2, 5, 7, CellValue::out);
    fillBoard(5, 7, 0, 2, CellValue::out);
    fillBoard(5, 7, 5, 7, CellValue::out);
    board[3][3].setValue(CellValue::empty);
}   

void PegSolitaire::setBoardDiamond () {
    initBoard(9, 9, CellValue::peg);

    for (int i = 0, n = 4; i < 4; ++i, --n)
        for (int j = 0; j < n; ++j)
            board[i][j].setValue(CellValue::out);

    for (int i = 0, n = 5; i < 4; ++i, ++n)
        for (int j = n; j < 9; ++j)
            board[i][j].setValue(CellValue::out);

    for (int i = 5, n = 1; i < 9; ++i, ++n)
        for (int j = 0; j < n; ++j)
            board[i][j].setValue(CellValue::out);

    for (int i = 5, n = 8; i < 9; ++i, --n)
        for (int j = n; j < 9; ++j)
            board[i][j].setValue(CellValue::out);
    board[4][4].setValue(CellValue::empty);
}   

void PegSolitaire::setBoardTriangular () {
    initBoard(5, 5, CellValue::out);

    board[0][0].setValue(CellValue::empty);
    for (int i = 1; i < 5; ++i)
        for (int j = 0; j <= i; ++j)
            board[i][j].setValue(CellValue::peg);
}  

void PegSolitaire::fillBoard (int outStart, int outEnd, int inStart, int inEnd, CellValue v) {
    for (int i = outStart; i < outEnd; ++i)
        for (int j = inStart; j < inEnd; ++j)
            board[i][j].setValue(v);
}
