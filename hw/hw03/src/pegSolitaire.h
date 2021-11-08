#include <string>
#include <vector>

using namespace std;

#ifndef pegSolitaire
#define pegSolitaire

class PegSolitaire {
    public:
        enum class CellValue : char {peg = 'P', empty = '.', out = ' '};
        
        class Cell {
            public:
                // Constructors
                Cell (const string & cellCol, int cellRow, CellValue CellValue);
                Cell ();
                //! NOT IMPLEMENTED YET

                // Getters
                void getCell (string & cellCol, int & cellRow, CellValue & cellValue) const;
                CellValue getValue () const;
                string getCol () const;
                int getRow () const;

                // Setters
                void setCell (string cellCol, int cellRow, CellValue cellValue);
                void setValue (CellValue cellValue);
                void setCol (string cellCol);
                void setRow (int cellRow);

                int convertCellCol (const string & col) const;
                // String to int value
                string convertCellCol (int col) const;

            //* Private part cannot accessed even by the outer class
            private:
                // Cell position and value
                string col;     // A, B, C, etc
                int row;        // 1, 2, 3, etc
                CellValue value;  // peg, empty, out
        };
        // Constructors
        PegSolitaire (const char * fileName);
        // Starts with given board
        PegSolitaire (int boardType);
        // Starts with the specific board type (1 to 6)
        PegSolitaire ();

        // Getters: I don't think we need 
        int getBoardSize ();

        // Setters
        //! Setter functions should not provided to user
        void setBoard (int boardType);

        // restart game maybe?

        void displayBoard () const;
        //! NOT IMPLEMENTED YET

        // Load & Save
        void load (const char * fileName);
        //! NOT IMPLEMENTED YET
        void save (const char * fileName) const;
        //! NOT IMPLEMENTED YET

    private:
        // Board initialization
        void initBoard (int row, int col, CellValue initValue);
        //! NOT IMPLEMENTED YET
        // Allocates enough memory and initialize the board as initValue
        

        void setBoardFrench ();        
        void setBoardGerman ();        
        void setBoardAsymmetrical ();  
        void setBoardEnglish ();       
        void setBoardDiamond ();       
        void setBoardTriangular ();    

        int boardSize;
        void fillBoard (int outStart, int outEnd, int inStart, int inEnd, CellValue v);
        // fills the given rectangular area with given value v

        vector<vector<Cell>> board;
};

#endif