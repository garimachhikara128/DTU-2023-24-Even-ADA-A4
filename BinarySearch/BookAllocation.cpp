#include<iostream>

using namespace std ;
bool isItPossibleToReadBooks(int *books, int nb, int ns, int mid) ;

int main()
{
    int nb = 4 ;
    int ns = 2 ;
    int pages[] = {12, 34, 67, 90} ;

    int lo = 0 ;
    int hi = 0 ;
    for(int i =0 ; i < nb ; i++)
        hi += pages[i] ;

    int ans = 0 ;

    while(lo <= hi)
    {
        int mid = (lo+hi)/2 ;

        if(isItPossibleToReadBooks(pages, nb, ns, mid))
        {
            ans = mid ;
            hi = mid-1 ;
        }
        else
        {
            lo = mid + 1;
        }
    }

    cout << ans << endl ;
 
    return 0 ;
}

bool isItPossibleToReadBooks(int *pages, int nb, int ns, int mid)
{
    int numStudents = 1 ;
    int pagesRead = 0 ;

    int i = 0;
    while(i < nb)
    {
        if(pagesRead + pages[i] <= mid)
        {
            pagesRead += pages[i] ;
            i++ ;
        }
        else
        {
            numStudents ++ ;
            pagesRead = 0 ;

            if(numStudents > ns)
                return false ;
        }
    }
    return true ;
}