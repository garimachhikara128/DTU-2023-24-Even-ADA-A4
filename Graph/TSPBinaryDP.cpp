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

    int tsp(int src, int curr, int visited, int **dp)
    {
        if(visited == ((1<<V)-1))
        {
            if(strg[curr].count(src) != 0)
                return strg[curr][src] ;
            else
                return 100000;
        }

        if(dp[src][visited] != -1)
            return dp[src][visited] ;

        int ans = INT_MAX ;
        map<int, int>::iterator itr ;
        for(itr = strg[curr].begin() ; itr != strg[curr].end() ; itr++)
        {
            int nbr = itr->first ;

            if((visited & (1<<nbr)) == 0)
            {
                int rr = tsp(src, nbr, (visited | (1<<nbr)), dp) ;
                ans = min(ans, rr+strg[curr][nbr]) ;

            }
        }

        dp[src][visited] = ans ;
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
 
    int **dp = new int*[n] ;
    for(int i = 0 ; i < n ; i++)
    {
        int cols = (1 << n) ;
        dp[i] = new int[cols] ;

        for(int j = 0 ; j < cols ; j++)
            dp[i][j] = -1 ;
    }

    cout << g.tsp(0,0,1,dp) << endl ;
    
    return 0 ;
}