#include<iostream>

using namespace std ;

int rodCuttingRec(int *price, int n)
{
    int max = price[n] ;

    int left = 1 ;
    int right = n-1 ;

    while(left <= right)
    {

        int fp = rodCuttingRec(price, left) ;
        int sp = rodCuttingRec(price, right) ;

        int total = fp + sp ;

        if(total > max)
            max = total ;

        left++ ;
        right-- ;
    }
    
    return max ;
}

int rodCuttingTD(int *price, int n, int* strg)
{
    if(strg[n] != -1)
        return strg[n] ;

    int max = price[n] ;

    int left = 1 ;
    int right = n-1 ;

    while(left <= right)
    {

        int fp = rodCuttingTD(price, left, strg) ;
        int sp = rodCuttingTD(price, right, strg) ;

        int total = fp + sp ;

        if(total > max)
            max = total ;

        left++ ;
        right-- ;
    }
    
    strg[n] = max ;

    return max ;
}

int rodCuttingBU(int *price, int tl)
{
    int *strg = new int[tl+1] ;
    strg[0] = price[0];

    for(int n = 1 ; n <= tl ; n++)
    {
        int max = price[n] ;

        int left = 1 ;
        int right = n-1 ;

        while(left <= right)
        {

            int fp = strg[left] ;
            int sp = strg[right] ;

            int total = fp + sp ;

            if(total > max)
                max = total ;

            left++ ;
            right-- ;
        }

        strg[n] = max ;
    }

    for(int i = 0 ; i <= tl ; i++)
        cout << strg[i] << " " ;
    cout << endl ;

    return strg[tl] ;
}

int main()
{

    int price[] = {0,1,5,8,9,10,17,17,20} ; 
    int n = sizeof(price) / sizeof(int) ;

    // cout << rodCuttingRec(price,n-1) << endl ;

    int *strg = new int[n] ; 
    for(int i =0 ; i < n ; i++)
        strg[i]  = -1 ;

    cout << rodCuttingTD(price,n-1,strg) << endl ;
    cout << rodCuttingBU(price,n-1) << endl ;

}