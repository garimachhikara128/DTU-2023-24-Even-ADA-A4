#include<iostream>

using namespace std ;

bool isItSafeToPlaceKnight(bool **board, int row, int col, int n)
{
    int rows[] = {-1,-2,-2,-1} ;
    int cols[] = {-2,-1,1,2} ;

    for(int i = 0 ; i < 4 ; i++)
    {
        if(row+rows[i] >= 0 && row + rows[i] < n && col+cols[i] >= 0 && col + cols[i] < n && board[row+rows[i]][col+cols[i]])
            return false ;
    }

    return true ;
}

void knight(bool **board, int row, int col, int kpsf, int n , string ans)
{   
    if(kpsf == n)
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
    if(isItSafeToPlaceKnight(board, row, col, n))
    {
        board[row][col] = true ;
        knight(board, row, col+1, kpsf+1, n, ans + "{" + to_string(row) + "," + to_string(col) + "}") ;
        board[row][col] = false ;
    }
    // not place
    knight(board, row, col+1, kpsf,n,  ans) ;

}

int main()
{
    int n = 3 ;

    bool **board = new bool*[n] ;

    for(int i = 0 ; i < n ; i++)
    {
        board[i] = new bool[n] ;

        for(int j=0 ; j < n ; j++)
            board[i][j] = false ; 
    }

    knight(board, 0, 0, 0, n, "") ;

    return 0 ;

}