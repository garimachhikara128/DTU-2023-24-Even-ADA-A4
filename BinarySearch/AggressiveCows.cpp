#include<iostream>

using namespace std ;
bool isItPossibleToPlaceCows(int *stalls, int ns, int nc, int mid) ;

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

bool isItPossibleToPlaceCows(int *stalls, int ns, int nc, int mid)
{
    int noCowsPlaced = 1 ;
    int pos = stalls[0] ;

    for(int i =  1; i <= ns-1 ; i++)
    {
        if(stalls[i] - pos >= mid)
        {
            noCowsPlaced++ ;
            pos = stalls[i] ;
            
            if(noCowsPlaced == nc)
                return true ;
        }



    }

    return false ;
}