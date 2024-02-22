#include<iostream>

using namespace std ;

bool isItSafeToPlaceQueen(bool **board, int row, int col, int n)
{
    // vertically up
    int r = row - 1;
    int c = col ;
    while(r >= 0)
    {
        if(board[r][c] == true)
            return false ;

        r-- ;
    }

    // horizontally left
    r = row ;
    c = col - 1 ;
    while(c >= 0)
    {
        if(board[r][c] == true)
            return false ;

        c-- ;
    }

    // diagonally left 
    r = row - 1;
    c = col - 1 ;
    while(r >= 0 && c >= 0)
    {
        if(board[r][c] == true)
            return false ;

        r-- ;
        c-- ;
    }

    // diagonally right
    r = row - 1;
    c = col + 1 ;
    while(r >= 0 && c < n)
    {
        if(board[r][c] == true)
            return false ;

        r-- ;
        c++ ;
    }

    return true ;
}

int c = 1 ; 
// place one queen in each row

void queen(bool **board, int row, int qpsf, int n, int k, string ans)
{   
    if(qpsf == k)
    {
        cout << c  << " " << ans << endl ;
        c++ ;
        return ;
    }

    if(row == n)
        return ;


    for(int col = 0 ; col < n ; col++)
    {
        if(isItSafeToPlaceQueen(board,row,col,n))
        {
            board[row][col] = true ;
            queen(board, row+1, qpsf+1, n,k,  ans + "{" + to_string(row) + "," + to_string(col) + "}") ;
            board[row][col] = false ;
        }
    }

    queen(board, row+1, qpsf, n,k, ans) ;
            
    
}

int main()
{
    int n = 4 ;
    int k = 3 ;
    bool **board = new bool*[n] ;

    for(int i = 0 ; i < n ; i++)
    {
        board[i] = new bool[n] ;

        for(int j=0 ; j < n ; j++)
            board[i][j] = false ; 
    }

    queen(board, 0, 0, n, k,  "") ;

    return 0 ;

}