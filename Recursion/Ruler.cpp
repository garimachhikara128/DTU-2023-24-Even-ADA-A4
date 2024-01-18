#include<iostream>

using namespace std ;

void draw(int) ;

int main()
{
    int inches = 5 ;
    int tick_length = 3 ;
    int i ;
    for(i = 0 ; i < inches ; i++)
    {
        // - - - - 0
        for(int j = 1 ; j <= tick_length ; j++)
            cout << "- " ;
        cout << i << endl ;

        draw(tick_length-1) ;
    }

    for(int j = 1 ; j <= tick_length ; j++)
            cout << "- " ;
        cout << i << endl ;
    
    return 0 ;
}

void draw(int n)
{
    if(n == 0)
        return ;

    // sp
    draw(n-1) ;

    // work
    for(int i = 1 ; i <= n ; i++)
        cout << "- " ;
    cout << endl ;

    // sp
    draw(n-1) ;
}