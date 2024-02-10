#include<iostream>

using namespace std ;

void downheapify(int *arr, int pi, int N)
{
        int lci = 2*pi+1 ;
        int rci = 2*pi+2 ;

        int mini = pi ;

        if(lci < N && arr[mini] < arr[lci])
            mini = lci ;
        
        if(rci < N && arr[mini] < arr[rci])
            mini = rci ;

        if(mini != pi)
        {
            swap(arr[mini], arr[pi]) ;
            downheapify(arr, mini, N) ;
        }

}

void heapsort(int *arr, int N)
{
    // creating a heap
    for(int i = N/2-1 ; i >=0 ; i--)
        downheapify(arr, i, N) ;

    // sort
    for(int i = N-1 ; i >=0 ; i--)
    {
        swap(arr[0], arr[i]) ;
        downheapify(arr, 0, i) ;
    }
    
}

    void display(int *arr, int N)
    {
        for(int i = 0 ; i < N ; i++)
        {
            cout << arr[i] << "\t";
        }
        cout << endl ;
    }

int main()
{
    int arr[] = {100,2,30,4,500,60} ;
    int N = sizeof(arr) / sizeof(int) ;

    display(arr, N) ;
    heapsort(arr, N) ;
    display(arr, N) ;

    return 0 ;
}
