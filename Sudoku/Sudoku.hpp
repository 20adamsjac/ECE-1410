#ifndef SUDOKU
#define SUDOKU
#include <iostream>
#include <istream>
using namespace std;

class Sudoku 
{
public:
    Sudoku();
    ~Sudoku() {}
    bool solve();
    void printGrid();
    bool checkValidSpot(int, int, int);
    bool isEmptySpot(int&, int&);
    int getValue(int row, int col) { return grid[row][col]; }           //return the value of the grid at the given point
    void setValue(int row, int col, int num) { grid[row][col] = num; }  //set the grid at point row, col equal to num
    friend istream& operator>>(istream& input, Sudoku& s);              //function declarations
private:
    int grid[9][9];
};

Sudoku::Sudoku()
{
    for (int i = 0; i < 9; i++)     //for every row from 0 to 8
    {
        for (int j = 0; j < 9; j++) //for every column from 0 to 8
        {
            grid[i][j] = 0;     //set element equal to zero
        }
    }
}

bool Sudoku::solve()
{
    int row, col;
    if (!isEmptySpot(row, col))         //if there are no empty spots
        return true;                    //return true
    for (int x = 1; x < 10; x++)        //for all valid answers in sudoku (1-9)
        if (checkValidSpot(row, col, x))//if the number is valid at the given spot
        {
            grid[row][col] = x;         //set the value of the spot equal to the number
            if (solve())                //if the next call of solve returns true
                return true;            //return true
            grid[row][col] = 0;         //reset the value of that spot
        }
    return false;                       //return false
}

void Sudoku::printGrid()
{
    for (int i = 0; i < 9; i++)         //for every row
    {
        for (int j = 0; j < 9; j++)     //for every column
        {
            cout << grid[i][j] << "  "; //print the value at that spot and then a space
        }
        cout << endl;                   //at the end of a row end the line
    }
    cout << endl;                       //at the end of the grid end the line
}

bool Sudoku::checkValidSpot(int row, int col, int num)
{
    int rstart, cstart, a, b;

    rstart = row - (row % 3);   //start row is equal to the row minus the remainder when divided by 3
    cstart = col - (col % 3);   //start column is equal to the column minus the remainder when divided by 3

    for (int i = 0; i < 9; i++) //for values 0-8
    {
        if (grid[i][col] == num)//if the value of num is present in the column
            return false;       //return false
        if (grid[row][i] == num)//if the value of num is presnt in the row 
            return false;       //return false
    }

    for (int i = 0; i < 3; i++)     //for i = 0-2
    {
        for (int j = 0; j < 3; j++) //for j = 0-2
        {
            a = rstart + i;         //a is equal to the start plus i
            b = cstart + j;         //b is equal to the start plus j

            if (grid[a][b] == num)  //if any value within the box is equal to num
                return false;       //return false
        }
    }
    return true;                    //if all tests are passed return true
}

bool Sudoku::isEmptySpot(int& row, int& col)
{
    for (row = 0; row < 9; row++)       //for all rows
        for (col = 0; col < 9; col++)   //for all columns
            if (grid[row][col] == 0)    //if any value is equal to 0
                return true;            //return true
    return false;                       //otherwise return false
}

istream& operator>>(istream& input, Sudoku& s)
{
    int x;
    for (int i = 0; i < 9; i++)     //for all rows
    {
        for (int j = 0; j < 9; j++) //for all columns
        {
            if (input >> x)         //if the file has output
                s.grid[i][j] = x;   //set the output to values of the grid
            else                    //else
                return input;       //return input
        }
    }
    return input;                   //return input
}
#endif

