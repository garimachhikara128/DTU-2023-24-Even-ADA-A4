#include<iostream>

using namespace std ;

int knapsackRec(int *weight, int*price, int n, int vidx, int cap)
{
    if(vidx == n || cap == 0)
        return 0 ;

    // exclude
    int exclude = knapsackRec(weight, price, n, vidx+1, cap) ;

    // include
    int include = 0 ;
    if(cap >= weight[vidx])
        include = knapsackRec(weight, price, n, vidx+1, cap-weight[vidx]) + price[vidx];

    int ans = max(exclude, include) ;

    return ans ;
}

int knapsackTD(int *weight, int*price, int n, int vidx, int cap, int **strg)
{
    if(vidx == n || cap == 0)
        return 0 ;

    if(strg[vidx][cap] != -1)
        return strg[vidx][cap] ;

    // exclude
    int exclude = knapsackTD(weight, price, n, vidx+1, cap, strg) ;

    // include
    int include = 0 ;
    if(cap >= weight[vidx])
        include = knapsackTD(weight, price, n, vidx+1, cap-weight[vidx], strg) + price[vidx];

    int ans = max(exclude, include) ;

    strg[vidx][cap]= ans ;

    return ans ;
}

int knapsackBU(int *weight, int*price, int n, int cap)
{
    int strg[n+1][cap+1] ;

    for(int i = 0 ; i < n+1 ; i++)
        strg[i][0] = 0 ;
    
    for(int j = 0 ; j < cap + 1 ; j++)
        strg[n][j] = 0 ;

    for(int i = n-1 ; i >=0 ; i--)
    {
        for(int j = 1 ; j <= cap ; j++)
        {
            // exclude
            int exclude = strg[i+1][j] ;

            // include
            int include = 0 ;
            if(j >= weight[i])
                include = strg[i+1][j-weight[i]] + price[i];

            int ans = max(exclude, include) ;
            strg[i][j] = ans ;
        }
    }

    for(int i = 0 ; i <= n ; i++)
    { 
        for(int j = 0 ; j <= cap ; j++)
            cout << strg[i][j] << " ";
        cout << endl ;
    }

    return strg[0][cap] ;
}

int main()
{
    int weight[] = {1,3,4,5} ;
    int price[] = {1,4,5,7} ;
    int cap = 7 ;

    int n = sizeof(weight)/ sizeof(weight[0]) ;

    cout << knapsackRec(weight, price, n, 0, cap) << endl ; 

    int **strg= new int*[n] ;
    for(int i = 0 ; i < n ; i++)
    {
        strg[i] = new int[cap+1] ;
        for(int j = 0 ; j < cap+1 ; j++)
            strg[i][j] = -1 ;
    }

    cout << knapsackTD(weight, price, n, 0, cap, strg) << endl ; 
    cout << knapsackBU(weight, price, n, cap) << endl ;


}