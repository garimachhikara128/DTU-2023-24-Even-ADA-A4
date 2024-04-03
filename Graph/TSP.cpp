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

    int tsp(int src, int curr, int *path, int idx)
    {
        if(idx == V)
        {
            if(strg[curr].count(src) != 0)
                return strg[curr][src] ;
            else
                return 100000;
        }

        int ans = INT_MAX ;
        map<int, int>::iterator itr ;
        for(itr = strg[curr].begin() ; itr != strg[curr].end() ; itr++)
        {
            int nbr = itr->first ;

            if(isItSafe(path,nbr))
            {
                path[idx] = nbr ;

                int rr = tsp(src, nbr, path, idx+1) ;
                ans = min(ans, rr+strg[curr][nbr]) ;

                path[idx] = -1 ;
            }
        }

        return ans ;
    }

} ;

int main()
{
    int n = 4 ;
    Graph g(n) ;
    
    g.addEdge(0,1,3) ;
    g.addEdge(0,2,8) ;
    g.addEdge(0,3,7) ;
    g.addEdge(1,2,2) ;
    g.addEdge(1,3,5) ;
    g.addEdge(2,3,1) ;

    g.display() ;
    int path[n] ;
    for(int i = 0 ; i < n ; i++)
        path[i] = -1 ;
    path[0] = 0 ;
    cout << g.tsp(0,0,path,1) << endl ;
    
    return 0 ;
}