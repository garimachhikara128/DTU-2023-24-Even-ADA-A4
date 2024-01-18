#include<iostream>

using namespace std ;

int main()
{
    int n = 10 ;
    int arr[] = {10,20,30,40,50,60,70,80,90,100} ;
    int item = 80 ;

    // binary search
    int ans = 0 ;

    int lo = 0;
    int hi = n-1 ;

    while(lo <= hi)
    {
        int mid = (lo+hi)/2 ;

        if(item < arr[mid])
        {
            hi = mid -1 ;
        }
        else if (item > arr[mid])
        {
            lo = mid + 1 ;
        }
        else
        {   
            ans = mid ;
            break ;
        }
    }

    cout << ans << endl ;

    return 0 ;

}