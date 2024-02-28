#include<iostream>

using namespace std ;

int LCSRec(string s1, int idx1, string s2, int idx2)
{
    if(idx1 == s1.length() || idx2 == s2.length())
        return 0 ;

    int ans = 0 ;

    if(s1[idx1] == s2[idx2])
    {
        ans = LCSRec(s1, idx1+1, s2, idx2+1) + 1;
    }
    else
    {
        int c1 = LCSRec(s1, idx1, s2, idx2+1) ;
        int c2 = LCSRec(s1, idx1+1, s2, idx2) ;

        ans = max(c1,c2) ;
    }

    return ans ;
}

int LCSTD(string s1, int idx1, string s2, int idx2, int **strg)
{
    if(idx1 == s1.length() || idx2 == s2.length())
        return 0 ;

    if(strg[idx1][idx2] != -1)
        return strg[idx1][idx2] ;

    int ans = 0 ;

    if(s1[idx1] == s2[idx2])
    {
        ans = LCSTD(s1, idx1+1, s2, idx2+1, strg) + 1;
    }
    else
    {
        int c1 = LCSTD(s1, idx1, s2, idx2+1, strg) ;
        int c2 = LCSTD(s1, idx1+1, s2, idx2, strg) ;

        ans = max(c1,c2) ;
    }

    strg[idx1][idx2] = ans ;

    return ans ;
}

int LCSBU(string s1, string s2)
{
    int nr = s1.length() + 1 ;
    int nc = s2.length() + 1 ;

    int **strg = new int*[nr] ;
    for(int i = 0 ; i < nr ; i++)
    {
        strg[i] = new int[nc] ;
    }

    // td -> bc , bu -> fill
    // row fill
    for(int j = 0 ; j < nc ; j++)
        strg[nr-1][j] =  0 ;
    // col fill
    for(int i = 0 ; i < nr ; i++)
        strg[i][nc-1] = 0 ;

    // filling
    for(int i = nr-2 ; i >=0 ; i--)
    {
        for(int j = nc -2 ; j >=0 ; j--)
        {
            int ans ;

            if(s1[i] == s2[j])
            {
                ans = strg[i+1][j+1] + 1;
            }
            else
            {
                int c1 = strg[i][j+1] ;
                int c2 = strg[i+1][j] ;

                ans = max(c1,c2) ;
            }

            strg[i][j] = ans ;
        }
    }

    return strg[0][0] ;

}

int main()
{
    string s1 = "abcdgfdsgfcyuegucfehwuchvweiuhcvuweihcfiuwegvcuehvicuehcdhsjbcjshdb" ;
    string s2 = "agcfdcbjhdsbcvhjwbegucfwgehufhweuifhewuihfiuewgfuieghrfuegwhufihiufheiufggheriughfeui cbjdshbvgbdvjhcgsudvchjs" ;

    // cout << LCSRec(s1,0,s2,0) << endl ;

    int **strg = new int*[s1.length()] ;

    for(int i = 0 ; i < s1.length() ; i++)
    {
        strg[i] = new int[s2.length()] ;

        for(int j=0 ; j < s2.length() ; j++)
            strg[i][j] = -1 ;
    }

    cout << LCSTD(s1,0,s2,0,strg) << endl ;

    cout << LCSBU(s1,s2) << endl ;

    return 0 ; 
}