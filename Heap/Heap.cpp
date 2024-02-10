#include<iostream>

using namespace std ;

class Heap
{
    vector<int> data ;

    public :

    void add(int item)
    {
        data.push_back(item) ;
        upheapify(data.size()-1) ;
    }

    void upheapify(int ci)
    {
        int pi = (ci-1)/2 ;

        if(data[pi] > data[ci])
        {
            swap(data[pi],data[ci]) ;
            upheapify(pi) ;
        }
    }

    int remove()
    {
        swap(data[0], data[data.size()-1]) ;
        int rv = data[data.size()-1] ;
        data.pop_back() ;
        downheapify(0) ;

        return rv ;
    }

    void downheapify(int pi)
    {
        int lci = 2*pi+1 ;
        int rci = 2*pi+2 ;

        int mini = pi ;

        if(lci < data.size() && data[mini] > data[lci])
            mini = lci ;
        
        if(rci < data.size() && data[mini] > data[rci])
            mini = rci ;

        if(mini != pi)
        {
            swap(data[mini], data[pi]) ;
            downheapify(mini) ;
        }

    }

    int get()
    {
        return data[0] ;
    }

    void display()
    {
        for(int i = 0 ; i < data.size() ; i++)
        {
            cout << data[i] << "\t";
        }
        cout << endl ;
    }
} ;

int main()
{
    // Heap h ;
    // h.add(10) ;
    // h.display() ;
    // h.add(5) ;
    // h.display() ;
    // h.add(20) ;
    // h.display() ;
    // h.add(15) ;
    // h.display() ;
    // h.add(30) ;
    // h.display() ;
    // h.add(12) ;
    // h.display() ;
    // h.add(35) ;
    // h.display() ;

    // cout << h.remove() << endl ;
    // h.display() ;
    // cout << h.remove()  << endl ;
    // h.display() ;
    // cout << h.remove()  << endl ;
    // cout << h.remove()  << endl ;
    // cout << h.remove()  << endl ;
    // cout << h.remove() << endl  ;
    // cout << h.remove()  << endl ;

    // ques 

    int arr[] = {100,5,15,7,40,30,8,50,35,9} ;
    int N = sizeof(arr) / sizeof(int) ;
    int k = 3 ;

    Heap h ;

    for(int i = 0 ; i < k ; i++)
        h.add(arr[i]) ;

    for(int i = k ; i < N ; i++)
    {
        int pe = arr[i] ;
        int weakest = h.get() ;

        if(pe > weakest)
        {
            h.remove() ;
            h.add(pe) ;
        }

    }
    
    for(int i = 1 ; i <= k ; i++)
    {
        cout << h.get() << "\t" ;
        h.remove() ;
    }
    cout << endl ;

    return 0 ;
}