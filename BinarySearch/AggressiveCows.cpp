#include<iostream>

using namespace std ;

int main()
{
    int ns = 5 ;
    int nc = 3 ;
    int stalls[] = {1,2,8,4,9} ;

    sort(stalls, stalls+ns) ;

    int ans = 0 ;

    int lo = 0 ;
    int hi = stalls[ns-1] - stalls[0] ;

    while(lo <= hi)
    {
        int mid = (lo+hi)/2 ;

        if(isItPossibleToPlaceCows(stalls, ns, nc, mid))
        {
            ans = mid ;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    cout << ans << endl ;
    return 0 ;
}