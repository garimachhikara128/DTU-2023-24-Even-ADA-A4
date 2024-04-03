#include<iostream>
#include<map>
#include<queue>
#include<vector>

using namespace std ;

class Graph
{
    map<int, map<int,int> > strg ;
    int V ;

    public :

    Graph(int V)
    {
        this->V = V ;
    }

    void addEdge(int u, int v, int cost)
    {
        strg[u][v] = cost ; 
        strg[v][u] = cost ; 
    }

    void display()
    {
        for(int i = 0 ; i < V ; i++)
        {
            cout << i << "\t" ;

            map<int, int>::iterator itr ;

            for(itr = strg[i].begin() ; itr != strg[i].end() ; itr++)
                cout << itr->first << "@" << itr->second << ", " ;
            cout << endl ;
        }
    }

    bool isItSafe(int *path, int nbr)
    {
        for(int i = 0 ; i < V ; i++)
        {
            if(path[i] == nbr)
                return false ;
        }

        return true ;
    }

    void hamiltonainCycle(int src, int curr, int *path, int idx)
    {
        if(idx == V)
        {
            if(strg[curr].count(src) != 0)
            {
                for(int i = 0 ; i < V ; i++)
                    cout << path[i] << " " ;
                cout << endl ; 
            }
            return ;
        }

        map<int, int>::iterator itr ;
        for(itr = strg[curr].begin() ; itr != strg[curr].end() ; itr++)
        {
            int nbr = itr->first ;

            if(isItSafe(path,nbr))
            {
                path[idx] = nbr ;
                hamiltonainCycle(src, nbr, path, idx+1) ;
                path[idx] = -1 ;
            }
        }

    }

} ;

int main()
{
    int n = 4 ;
    Graph g(n) ;
    
    g.addEdge(0,1,3) ;
    g.addEdge(0,3,7) ;
    g.addEdge(1,2,2) ;
    g.addEdge(1,3,5) ;
    g.addEdge(1,4,1) ;
    g.addEdge(3,4,2) ;
    g.addEdge(2,4,2) ;

    g.display() ;
    int path[n] ;
    for(int i = 0 ; i < n ; i++)
        path[i] = -1 ;
    path[0] = 0 ;
    g.hamiltonainCycle(0,0,path,1) ;
    
    return 0 ;
}