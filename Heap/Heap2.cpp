#include<iostream>

using namespace std ;

class Heap
{
    int *arr ;
    int N ;

    public :

    void add(int *arr, int N)
    {
        this->arr = arr ;
        this->N = N ;

        for(int i = N/2-1 ; i >=0 ; i--)
            downheapify(i) ;

    }

    int remove()
    {
        swap(arr[0], arr[N-1]) ;
        int rv = arr[N-1] ;
        N-- ;
        downheapify(0) ;

        return rv ;
    }

    void downheapify(int pi)
    {
        int lci = 2*pi+1 ;
        int rci = 2*pi+2 ;

        int mini = pi ;

        if(lci < N && arr[mini] > arr[lci])
            mini = lci ;
        
        if(rci < N && arr[mini] > arr[rci])
            mini = rci ;

        if(mini != pi)
        {
            swap(arr[mini], arr[pi]) ;
            downheapify(mini) ;
        }

    }

    int get()
    {
        return arr[0] ;
    }

    void display()
    {
        for(int i = 0 ; i < N ; i++)
        {
            cout << arr[i] << "\t";
        }
        cout << endl ;
    }
} ;

int main()
{
    int arr[] = {10,5,15,3,4,6} ;
    int N = sizeof(arr) / sizeof(int) ;

    int k = 3 ;
    // Heap h ;
    // h.add(arr,N) ;

    // cout << h.remove() << endl ;
    // cout << h.remove() << endl ;
    // cout << h.remove() << endl ;
    // cout << h.remove() << endl ;
    // cout << h.remove() << endl ;
    // cout << h.remove() << endl ;

    return 0 ;
}