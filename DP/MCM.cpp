#include<iostream>

using namespace std ;

int MCM_Rec(int *arr, int si, int ei)
{
    if(si+1 == ei)
        return 0 ;

    int ans = INT_MAX ;

    for(int k = si+1 ; k <= ei-1 ; k++)
    {
        int fp = MCM_Rec(arr, si, k) ;
        int sp = MCM_Rec(arr,k, ei) ;
        int sw = arr[si] * arr[k] * arr[ei] ;

        int total = fp + sp + sw ;
        ans = min(ans, total) ;
    }

    return ans ;

}

int MCM_TD(int *arr, int si, int ei, int **strg)
{
    if(si+1 == ei)
        return 0 ;

    if(strg[si][ei] != -1)
        return strg[si][ei] ;

    int ans = INT_MAX ;

    for(int k = si+1 ; k <= ei-1 ; k++)
    {
        int fp = MCM_TD(arr, si, k, strg) ;
        int sp = MCM_TD(arr,k, ei, strg) ;
        int sw = arr[si] * arr[k] * arr[ei] ;

        int total = fp + sp + sw ;
        ans = min(ans, total) ;
    }

    strg[si][ei] = ans ;

    return ans ;

}

int MCM_BU(int *arr, int n)
{
    int strg[n][n] ;

    for(int slide = 1 ; slide <= n-1 ; slide++)
    {
        for(int si = 0 ; si <= n-slide-1 ; si++)
        {
            int ei = si + slide ;

            // copy ---
            if(si+1 == ei)
                strg[si][ei] = 0;
            else 
            {
                int ans = INT_MAX ;

                for(int k = si+1 ; k <= ei-1 ; k++)
                {
                    int fp = strg[si][k] ;
                    int sp = strg[k][ei] ;
                    int sw = arr[si] * arr[k] * arr[ei] ;

                    int total = fp + sp + sw ;
                    ans = min(ans, total) ;
                }

                strg[si][ei] = ans ;
            }
            // copy --

        }
    }

    return strg[0][n-1] ;

}

int main()
{
    int arr[] = {4,2,3,5,1,4,2,3,5,1,4,2,3,5,1,4,2,3,5,1,4,2,3,5,1,4,2,3,5,1,4,2,3,5,1,4,2,3,5,1} ;
    int n = sizeof(arr)/sizeof(arr[0]) ;

    int **strg = new int*[n] ;
    for(int i = 0 ; i < n ; i++)
    {
        strg[i] = new int[n] ;
        for(int j = 0 ; j < n ; j++)
            strg[i][j] = -1 ;
    }

    // cout << MCM_Rec(arr,0,n-1) << endl ; 
    cout << MCM_TD(arr,0,n-1, strg) << endl ;

    cout << MCM_BU(arr,n) << endl ;
}