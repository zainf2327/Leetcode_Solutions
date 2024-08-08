class Solution {
public:
    int passThePillow(int n, int t)  {
           
        int N = 2*n-2 ;   // total no of dintinct passes for n friends
        int T = t % N;    // # of pass(# of seconds) 
        if(T==0) T = N;   // for last reverse pass T=0, so, T=N;
        if(T<n) {     // Forward pass
            return T+1;
        }
        else    {       // Reverse Pass
            return N-T+1;
        }


    }

};