#include<iostream>

using namespace std ;
int power(int, int) ;

int main()
{
    cout << power(2,10) ;
    return 0 ;
}

int power(int x, int n)
{
    if(n == 0)
        return 1 ;
    
    int sp = power(x,n/2)  ;
    int bp ;

    if(n % 2 == 0)
        bp = sp * sp ;
    else 
        bp = sp * sp * x ;

    return bp ;
}