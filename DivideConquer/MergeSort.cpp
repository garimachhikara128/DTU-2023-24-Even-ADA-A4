#include<iostream>

using namespace std ;
int* mergeTwoSortedArrays(int *arr1, int n1, int *arr2, int n2) ;
int* mergeSort(int *arr, int lo, int hi) ;

int main()
{
    int n ;
    cin >> n ;
    int *arr = new int[n] ;

    for(int i = 0 ; i < n ; i++)
        cin >> arr[i] ;

    int *res = mergeSort(arr,0,n-1) ;

    for(int i = 0 ; i < n ; i++)
        cout << res[i] << "\t" ;

    return 0 ;
}

int* mergeTwoSortedArrays(int *arr1, int n1, int *arr2, int n2)
{
    int *merged = new int[n1+n2] ;

    int i = 0 ;
    int j = 0 ;
    int k = 0 ;

    while(i < n1 && j < n2)
    {
        if(arr1[i] <= arr2[j])
            merged[k++] = arr1[i++] ;
        else 
            merged[k++] = arr2[j++] ;
    }

    if(i == n1)
    {
        while(j < n2)
            merged[k++] = arr2[j++] ;
    }

    if(j == n2)
    {
        while(i < n1)
            merged[k++] = arr1[i++] ;
    }

    return merged ;
}

int* mergeSort(int *arr, int lo, int hi)
{
    if(lo == hi)
    {
        int *bc = new int[1] ;
        bc[0] = arr[lo] ;
        return bc ;
    }

    int mid = (lo+hi)/2 ;

    int *fp = mergeSort(arr,lo,mid) ;
    int *sp = mergeSort(arr,mid+1,hi) ;

    int *ans = mergeTwoSortedArrays(fp,mid-lo+1,sp,hi-mid) ;
    return ans ;
}