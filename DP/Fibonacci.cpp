#include<iostream>

using namespace std ;

int fibonacciRec(int n)
{
    if(n ==0 || n == 1)
        return n ;

    int fnm1 = fibonacciRec(n-1) ;
    int fnm2 = fibonacciRec(n-2) ;

    int fn = fnm1 + fnm2 ;

    return fn ;
}

int fibonacciTD(int n, int *strg)
{
    if(n ==0 || n == 1)
        return n ;

    if(strg[n] != 0) // reuse
        return strg[n] ;

    int fnm1 = fibonacciTD(n-1, strg) ;
    int fnm2 = fibonacciTD(n-2, strg) ;

    int fn = fnm1 + fnm2 ;

    strg[n] = fn ; // store

    return fn ;
}

int fibonacciBU(int n)
{
    int *strg = new int[n+1] ; // 1D Array

    // TD bc -> BU fill
    strg[0] = 0 ;
    strg[1] = 1 ;

    // filling left -> right
    for(int i = 2 ; i <= n ; i++)
        strg[i] = strg[i-1]  +strg[i-2] ;

    // answer store n index
    return strg[n] ;
}

int fibonacciBUSO(int n)
{
    int *strg = new int[2] ;

    strg[0] = 0 ;
    strg[1] = 1 ;

    for(int slide = 1 ; slide <= n-1 ; slide++)
    {
        int sum = strg[0]  +strg[1] ;
        strg[0] = strg[1] ;
        strg[1] = sum ;
    }

    return strg[1] ;
}

int main()
{
    int n = 10000 ;
    int *strg = new int[n+1] ;
    cout << fibonacciTD(n, strg) << endl ;
    cout << fibonacciBU(n) << endl ;
    cout << fibonacciBUSO(n) << endl ;

    return 0 ;
}