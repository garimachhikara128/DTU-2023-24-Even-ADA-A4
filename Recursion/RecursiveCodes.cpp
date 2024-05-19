#include<iostream>

using namespace std ;

void toss(int, string) ;
void subsequences(string, string) ;
void validParenthesis(int n, int open, int close, string ans) ;
void climbingStairs(int curr, int n, string ans) ;
void permutations(string ques, string ans) ;
void lexicoCounting(int curr, int end) ;
void TOH(int n, string src, string dst, string helper) ;

int main()
{
    // toss(3, "") ;
    // subsequences("abc", "") ;
    // validParenthesis(3,0,0,"") ;
    // climbingStairs(0,5,"") ;
    // permutations("abb", "") ;

    // lexicoCounting(0,1000) ;

    TOH(5, "S", "D", "H") ;

    return 0 ;
}

void TOH(int n, string src, string dst, string helper)
{
    if(n == 0)
        return ;

    TOH(n-1, src, helper, dst) ;
    cout << "Move disc " << n << " from " << src << " to " << dst << endl ;
    TOH(n-1, helper, dst, src) ;
}

void lexicoCounting(int curr, int end)
{
    if(curr > end)
        return ;
    
    cout << curr << endl ;

    int i = 0 ;

    if(curr == 0)
        i = 1 ;
        
    while(i <= 9)
    {
        lexicoCounting(curr*10+i, end) ;
        i++ ;
    }
}

void permutations(string ques, string ans)
{
    if(ques.length() == 0)
    {
        cout << ans << endl ;
        return ;
    }

    for(int i = 0 ; i < ques.length() ; i++)
    {
        char ch = ques[i] ;
        string roq = ques.substr(0,i) + ques.substr(i+1) ;

        permutations(roq, ans+ch) ;
    }
}

void climbingStairs(int curr, int n, string ans)
{
    if(curr == n)
    {
        cout << ans << endl ;
        return ;
    }

    if(curr > n)
        return ;

    // climbingStairs(curr+1, n, ans+"1") ;
    // climbingStairs(curr+2, n, ans+"2") ;
    // climbingStairs(curr+3, n, ans+"3") ;

    for(int jump = 1 ; jump <= 3 ; jump++)
        climbingStairs(curr+jump, n, ans + to_string(jump)) ;

}

void validParenthesis(int n, int open, int close, string ans)
{
    if(open == n && close == n)
    {
        cout << ans << endl ;
        return ;
    }

    if(open > n || close > n || close > open)
    {
        return ;
    }

    validParenthesis(n, open+1, close, ans + "(") ;
    validParenthesis(n, open, close+1, ans + ")") ;
}

void subsequences(string ques, string ans)
{
    if(ques.length() == 0)
    {
        cout << ans << endl ;
        return ;
    }

    char ch = ques[0] ;
    string roq = ques.substr(1) ;

    subsequences(roq, ans) ; // no
    subsequences(roq, ans + ch) ; // yes
}

void toss(int n, string ans)
{
    if(n == 0)
    {
        cout << ans << endl ;
        return ;
    }

    toss(n-1, ans + "H") ;
    toss(n-1, ans + "T") ;
}



