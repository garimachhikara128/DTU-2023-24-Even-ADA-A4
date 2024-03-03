#include<iostream>

using namespace std ;

struct Activity
{
    int start ;
    int finish ;
} ;

// item a should come before item b ?
// true : no swapping
// false : swapping
bool compare(Activity a, Activity b)
{
    return a.finish < b.finish ;
}

void activitySelection(Activity arr[], int n)
{
    sort(arr, arr+n, compare) ;

    // i -> keeping a track of last performed activity
    int i = 0 ;
    cout << arr[i].start << ", " << arr[i].finish << endl ;

    for(int j = 1 ; j < n ; j++)
    {
        if(arr[j].start >= arr[i].finish)
        {
            cout << arr[j].start << ", " << arr[j].finish << endl ;
            i = j ;
        }
    }
}

int main()
{
    Activity arr[] = {{5,9},{1,2},{3,4},{0,6},{5,7},{8,9}} ;
    int n = sizeof(arr) / sizeof(Activity) ;

    activitySelection(arr, n) ;

    return 0 ;
}