#include<iostream>

using namespace std ;
void quickSort(int *arr, int lo, int hi) ;

int main()
{
    int n ;
    cin >> n ;
    int *arr = new int[n] ;

    for(int i = 0 ; i < n ; i++)
        cin >> arr[i] ;

    quickSort(arr,0,n-1) ;

    for(int i = 0 ; i < n ; i++)
        cout << arr[i] << "\t" ;

    return 0 ;
}

void quickSort(int *arr, int lo, int hi)
{
    if(lo  >= hi)
        return ;

    // partitioning
    int mid = (lo+hi)/2 ;
    int pivot = arr[mid] ;

    int left = lo ;
    int right = hi ;

    while(left <= right)
    {
        // left problem
        while(arr[left] < pivot)
            left++ ;
        
        // right problem
        while(arr[right] > pivot)
            right -- ;
        
        // swap
        if(left <= right)
        {
            int temp = arr[left] ;
            arr[left] = arr[right] ;
            arr[right] = temp ; 
            left++ ;
            right-- ;
        }
    }

    // calls
    quickSort(arr, lo, right) ;
    quickSort(arr, left, hi) ;

}