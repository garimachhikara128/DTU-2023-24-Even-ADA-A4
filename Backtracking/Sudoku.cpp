#include<iostream>

using namespace std ;

bool isItSafe(int **board, int row, int col, int val)
{
    // row
    for(int c =0; c < 9 ; c++)
    {
        if(board[row][c] == val)
            return false ;
    }

    // column
    for(int r =0; r < 9 ; r++)
    {
        if(board[r][col] == val)
            return false ;
    }

    // 3 X 3 grid
    int sr = row / 3 * 3 ;
    int sc = col / 3 * 3 ;

    for(int r = sr ; r < sr + 3 ; r++)
    {
        for(int c = sc ; c < sc + 3 ; c++)
        {
            if(board[r][c] == val)
                return false ;
        }
    }

    return true ;

}

void display(int **board)
{
    cout << endl ;
    for(int i = 0 ; i < 9 ; i++)
    {
        for(int j = 0 ; j < 9 ; j++)
        {
            cout << board[i][j] << " " ;
        }
        cout << endl ;
    }
}

void sudoku(int **board, int row, int col)
{
    if(col == 9)
    {
        row++ ;
        col = 0 ;        
    }

    if(row == 9)
    {
        display(board) ;
        return ;
    }

    if(board[row][col] != 0)
    {
        sudoku(board, row, col+1) ;
        return ;
    }

    for(int i = 1 ; i <= 9 ; i++)
    {
        if(isItSafe(board, row, col, i))
        {
            board[row][col] = i ;
            sudoku(board,row, col+1) ;
            board[row][col] = 0 ;
        }
    }

}

int main()
{
    int n = 9 ;
    int **board = new int*[n] ;

    for(int i = 0 ; i < n ; i++)
    {
        board[i] = new int[n] ;

        for(int j=0 ; j < n ; j++)
            cin >> board[i][j] ;
    }

    sudoku(board, 0, 0) ;


}


// 5 3 0 0 0 0 0 0 0
// 6 0 0 0 0 5 0 0 0
// 0 9 8 0 0 0 0 6 0
// 8 0 0 0 6 0 0 0 3
// 4 0 0 0 0 3 0 0 1
// 7 0 0 0 2 0 0 0 6
// 0 6 0 0 0 0 2 8 0
// 0 0 0 0 1 9 0 0 5
// 0 0 0 0 8 0 0 7 9