#include<iostream>
#include<map>
#include<queue>
#include<vector>

using namespace std ;

class Graph
{
    map<int, map<int,int> > strg ;
    int V ;
    vector<vector<int> > edgeList ;

    public :

    Graph(int V)
    {
        this->V = V ;
    }

    void addEdge(int u, int v, int cost)
    {
        strg[u][v] = cost ;
        edgeList.push_back({u,v,cost}) ;
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

    void bellmanFord(int src)
    {
        int cost[V] ;
        fill(cost,cost+V,100000) ;
        cost[src] = 0 ;

        // V-1 times, relax every edge
        for(int i = 1 ; i <= V ; i++)
        {
            for(auto edge : edgeList)
            {
                int u = edge[0] ;
                int v = edge[1] ;
                int c = edge[2] ;

                // cost
                int oc = cost[v] ;
                int nc = cost[u] + c ;
                if(nc < oc)
                {
                    if(i <= V-1)
                        cost[v] = nc ;
                    else
                    {
                        cout << "-ve wt cycle present" ;
                        return ;
                    }
                }
            }
    }

    for(int i =  0 ; i < V ; i++)
        cout << i << " -> " << cost[i] << endl ;


} ;

int main()
{

    Graph g(7) ;

    g.addEdge(0,1,2) ;
    g.addEdge(1,2,3) ;
    g.addEdge(2,3,1) ;
    g.addEdge(0,3,6) ;
    g.addEdge(3,4,8) ;
    g.addEdge(4,5,5) ;
    g.addEdge(5,6,1) ;
    g.addEdge(4,6,7) ;

    g.display() ;

    g.kruskal() ;
    
    return 0 ;
}