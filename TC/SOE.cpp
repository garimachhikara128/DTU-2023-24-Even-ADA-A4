#include<iostream>

using namespace std ;

int main()
{
    int n = 2500 ;

    int *arr = new int[n+1] ;
    
    // place true at all places
    for(int i = 0 ; i < n ; i++)
        arr[i] = true ;
    
    arr[0] = false ;
    arr[1] = false ;

    for(int table = 2 ; table * table <= n ; table++)
    {
        if(arr[table] == false)
            continue ;

        for(int multiplier = table ; table * multiplier <= n ; multiplier++)
        {
            arr[table * multiplier] = false ;
        }
    }

    for(int i = 0 ; i <= n ; i++)
    {
        if(arr[i])
            cout << i << "\t" ;
    }
    cout << endl ;

    return 0 ;
}