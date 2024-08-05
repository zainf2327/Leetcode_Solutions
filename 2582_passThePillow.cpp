# include <vector>
using namespace std;
class Solution {
public:
    int passThePillow(int n, int t)  {
           
        int N = 2*n-2 ;   // total no of dintinct passes for n friends
        int T = t % N;    // exact no of pass e.g 1th pass. 
        if(T==0) T = N;   // for last reverse pass T=0, so, T=N;
        vector<int> arr(N,0);
        for (int i = 0; i < N; i++) {
            if (i < n - 1)  
                arr[i]=i+2;   
            else
               arr[i]= N-i;
            
        }

        return arr[T-1] ;
    }

};