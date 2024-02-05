#include<iostream>

using namespace std ;

class Heap
{
    vector<int> data ;

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

    void display()
    {
        for(int i = 0 ; i < data.size() ; i++)
        {
            cout << data[i] << "\t";
        }
    }

} ;