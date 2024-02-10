#include<iostream>

using namespace std ;

void blockedMaze(int arr[][4], bool visited[][4], int cr, int cc, int er, int ec, string ans)
{
    if(cr > er || cc > ec || cr < 0 || cc < 0 || arr[cr][cc] == 0 || visited[cr][cc])
        return ;

    if(cr == er && cc == ec)
    {
        cout << ans << endl ;
        return ;
    }

    visited[cr][cc] = true ;

    blockedMaze(arr, visited, cr-1, cc, er, ec, ans + "T") ; // T
    blockedMaze(arr, visited, cr+1, cc, er, ec, ans + "D") ; // D
    blockedMaze(arr, visited, cr, cc-1, er, ec, ans + "L") ; // L
    blockedMaze(arr, visited, cr, cc+1, er, ec, ans + "R") ; // R

    visited[cr][cc] = false ;
}

int main()
{
    int arr[4][4] = {{1,0,1,1},{1,1,1,1},{1,0,1,1},{1,1,0,1}} ;

    bool visited[4][4] = {{false, false, false, false},{false, false, false, false},{false, false, false, false},{false, false, false, false}} ;

    blockedMaze(arr, visited, 0, 0, 3, 3, "") ;

}