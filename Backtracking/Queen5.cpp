#include<iostream>

using namespace std ;

int c = 1 ; 
// place one queen in each row

void queen(bool **board, int row, int qpsf, int n, string ans)
{   
    if(qpsf == n)
    {
        cout << c  << " " << ans << endl ;
        c++ ;
        return ;
    }

    if(row == n)
        return ;


    for(int col = 0 ; col < n ; col++)
    {
        board[row][col] = true ;
        queen(board, row+1, qpsf+1, n, ans + "{" + to_string(row) + "," + to_string(col) + "}") ;
        board[row][col] = false ;
    }
    
}

int main()
{
    int n = 4 ;

    bool **board = new bool*[n] ;

    for(int i = 0 ; i < n ; i++)
    {
        board[i] = new bool[n] ;

        for(int j=0 ; j < n ; j++)
            board[i][j] = false ; 
    }

    queen(board, 0, 0, n, "") ;

    return 0 ;
}