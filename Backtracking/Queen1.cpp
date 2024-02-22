#include<iostream>

using namespace std ;

void queen(bool **board, int row, int col, int qpsf, int n , string ans)
{   
    if(qpsf == n)
    {
        cout << ans << endl ;
        return ;
    }

    if(col == n)
    {
        row ++ ;
        col = 0 ;
        // queen(board, row+1, 0, qpsf, n , ans) ;
        // return ;
    }

    if(row == n)
        return ;

    // place
    board[row][col] = true ;
    queen(board, row, col+1, qpsf+1, n, ans + "{" + to_string(row) + "," + to_string(col) + "}") ;
    board[row][col] = false ;

    // not place
    queen(board, row, col+1, qpsf,n,  ans) ;

}

int main()
{
    int n = 2 ;

    bool **board = new bool*[n] ;

    for(int i = 0 ; i < n ; i++)
    {
        board[i] = new bool[n] ;

        for(int j=0 ; j < n ; j++)
            board[i][j] = false ; 
    }

    queen(board, 0, 0, 0, n, "") ;

    return 0 ;

}